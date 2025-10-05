#include "musicload.h"
#include <QDir>
#include <QDebug>
#include <QUrl>
#include <QMediaMetaData>
#include <QPixmap>
#include <QPixmapCache>
#include <QStandardPaths>
#include <QUuid>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <QTimer>

MusicLoad::MusicLoad(QObject *parent)
    : QObject{parent}
{
    connect(this, &MusicLoad::musicLoadDone,
            this, &MusicLoad::loadMusicIntoPlayer);

    ScanMusicFiles();
}

void MusicLoad::ScanMusicFiles()
{
    QDir musicDir(m_musicPath);

    if (!musicDir.exists()) {
        qWarning() << "Music directory does not exist:" << m_musicPath;
        return;
    }

    QStringList nameFilters;
    nameFilters << "*.mp3" << "*.wav" << "*.flac";

    n_musicFiles = musicDir.entryList(nameFilters, QDir::Files);

    emit musicLoadDone(n_musicFiles);
}

void MusicLoad::loadMusicIntoPlayer(const QStringList &musicFiles)
{
    n_mediaPlayer = new QMediaPlayer(this);
    n_audioOutput = new QAudioOutput(this);
    n_mediaPlayer->setAudioOutput(n_audioOutput);

    connect(n_mediaPlayer, &QMediaPlayer::positionChanged,
            this, &MusicLoad::positionChanged);
    connect(n_mediaPlayer, &QMediaPlayer::durationChanged,
            this, &MusicLoad::durationChanged);
    // connect(n_mediaPlayer, &QMediaPlayer::mediaStatusChanged,
    //         this, [this](QMediaPlayer::MediaStatus status) {
    //             if (status == QMediaPlayer::EndOfMedia) {
    //                 playNext();
    //             }
    //         });
    connect(n_mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            QTimer::singleShot(300, this, [this]() {
                playNext();
            });
        }
    });

    if (!musicFiles.isEmpty()) {
        n_currentIndex = 0;
        QString firstFilePath = m_musicPath + "/" + musicFiles.first();
        qDebug() << "Playing file:" << firstFilePath;

        n_mediaPlayer->setSource(QUrl::fromLocalFile(firstFilePath));
        // n_audioOutput->setVolume(0.5);
        // n_mediaPlayer->play();

        connect(n_mediaPlayer, &QMediaPlayer::metaDataChanged, this, [this]() {
            QVariant title  = n_mediaPlayer->metaData().value(QMediaMetaData::Title);
            QVariant artist = n_mediaPlayer->metaData().value(QMediaMetaData::ContributingArtist);
            QVariant coverArt  = n_mediaPlayer->metaData().value(QMediaMetaData::ThumbnailImage); // <-- dùng ThumbnailImage

            if (title.isValid()) {
                this->title = title.toString();
                emit titleChanged();
                qDebug() << "Title:" << title.toString();
            }

            if (artist.isValid()) {
                this->artist = artist.toString();
                emit artistChanged();
                qDebug() << "Artist:" << artist.toString();
            }


            if (coverArt.isValid()) {
                this->coverArt = qvariant_cast<QImage>(coverArt);
                emit coverArtChanged();
                qDebug() << "Cover art updated.";
            }

        });

    } else {
        qWarning() << "No music files found to play.";
    }
}

void MusicLoad::playNext()
{
    // if (n_musicFiles.isEmpty() || !n_mediaPlayer) return;

    // n_currentIndex++;
    // if (n_currentIndex >= n_musicFiles.size())
    //     n_currentIndex = 0;

    // QString nextFilePath = m_musicPath + "/" + n_musicFiles.at(n_currentIndex);
    // qDebug() << "Next -> Playing file:" << nextFilePath;

    // n_mediaPlayer->setSource(QUrl::fromLocalFile(nextFilePath));
    // n_mediaPlayer->play();

    // _isPlaying = true;
    //  emit isPlayingChanged();
    if (n_musicFiles.isEmpty() || !n_mediaPlayer) return;

    if (n_isShuffle) {
        // đảm bảo đã có shuffledOrder
        if (shuffledOrder.isEmpty())
            prepareShuffledOrder();

        if (shuffledOrder.size() == 1) {
            n_currentIndex = shuffledOrder.at(0);
        } else {
            int nextPos = shufflePos + 1;
            if (nextPos >= shuffledOrder.size()) {
                // đã hết order -> xáo lại
                prepareShuffledOrder();
                nextPos = 0;
            }
            shufflePos = nextPos;
            n_currentIndex = shuffledOrder.at(shufflePos);
        }
        qDebug() << "Shuffle -> Playing index" << n_currentIndex << "file:" << n_musicFiles.at(n_currentIndex);
    } else {
        // phát theo thứ tự
        n_currentIndex++;
        if (n_currentIndex >= n_musicFiles.size())
            n_currentIndex = 0;
        qDebug() << "Next -> Playing index" << n_currentIndex << "file:" << n_musicFiles.at(n_currentIndex);
    }

    QString nextFilePath = m_musicPath + "/" + n_musicFiles.at(n_currentIndex);
    n_mediaPlayer->setSource(QUrl::fromLocalFile(nextFilePath));
    n_mediaPlayer->play();

    _isPlaying = true;
    emit isPlayingChanged();
}

void MusicLoad::playPrevious()
{
    if (n_musicFiles.isEmpty() || !n_mediaPlayer) return;

    n_currentIndex--;
    if (n_currentIndex < 0)
        n_currentIndex = n_musicFiles.size() - 1;

    QString prevFilePath = m_musicPath + "/" + n_musicFiles.at(n_currentIndex);
    qDebug() << "Previous -> Playing file:" << prevFilePath;

    n_mediaPlayer->setSource(QUrl::fromLocalFile(prevFilePath));
    n_mediaPlayer->play();
}

void MusicLoad::playOrPause()
{
    if (!n_mediaPlayer) return;

    if (_isPlaying) {
        n_mediaPlayer->pause();
        qDebug() << "Music Paused";
        _isPlaying = false;
    } else {
        n_mediaPlayer->play();
        qDebug() << "Music Playing";
        _isPlaying = true;
    }
    emit isPlayingChanged();

}
void MusicLoad::prepareShuffledOrder()
{
    shuffledOrder.clear();
    int sz = n_musicFiles.size();
    if (sz <= 0) {
        shufflePos = -1;
        return;
    }

    // tạo dãy 0..sz-1
    for (int i = 0; i < sz; ++i)
        shuffledOrder.append(i);

    if (sz > 1) {
        // seed bằng QRandomGenerator để có random tốt
        std::mt19937 gen(static_cast<uint32_t>(QRandomGenerator::global()->generate()));
        std::shuffle(shuffledOrder.begin(), shuffledOrder.end(), gen);
    }

    // tìm vị trí của track hiện tại trong shuffledOrder (nếu có)
    shufflePos = shuffledOrder.indexOf(n_currentIndex);
    if (shufflePos < 0) {
        // nếu hiện tại chưa có (ví dụ n_currentIndex = -1), bắt đầu từ -1
        shufflePos = -1;
    }

    qDebug() << "Prepared shuffled order:" << shuffledOrder << "shufflePos=" << shufflePos;
}

void MusicLoad::setShuffle(bool value)
{
    if (n_isShuffle == value) return;
    n_isShuffle = value;

    if (n_isShuffle) {
        // bật shuffle: chuẩn bị order xáo
        prepareShuffledOrder();
    } else {
        // tắt shuffle: clear order
        shuffledOrder.clear();
        shufflePos = -1;
    }

    emit shuffleChanged();
    qDebug() << "Shuffle set to" << n_isShuffle;
}


void MusicLoad::setVolume(qreal value)
{
    // if (n_audioOutput)
    //     n_audioOutput->setVolume(value / 100.0);
    if (n_audioOutput) {
        n_audioOutput->setVolume(value);  // giá trị từ 0.0 đến 1.0
        qDebug() << "Volume set to:" << value;
    } else {
        qDebug() << "Audio output not initialized!";
    }

}
