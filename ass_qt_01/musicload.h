#ifndef MUSICLOAD_H
#define MUSICLOAD_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMediaMetaData>
#include <QImage>
#include <QVector>


class MusicLoad : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isPlaying READ getIsPlaying NOTIFY isPlayingChanged)
    Q_PROPERTY(QString title READ getTitle NOTIFY titleChanged)
    Q_PROPERTY(QString artist READ getArtist NOTIFY artistChanged)
    Q_PROPERTY(QImage coverArt READ getCoverArt NOTIFY coverArtChanged)
        // Q_PROPERTY(QImage currentAlbumArt READ currentAlbumArt NOTIFY currentAlbumArtChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(qint64 duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(bool isShuffle READ isShuffle WRITE setShuffle NOTIFY shuffleChanged)

public:
    explicit MusicLoad(QObject *parent = nullptr);
    // bool getIsPlaying() const { return isPlaying; }
    bool getIsPlaying() const { return _isPlaying; }
    QString getTitle() const { return title; }
    QString getArtist() const { return artist; }
    QImage getCoverArt() const { return coverArt; }
    // QString getCoverArtPath() const { return coverArtPath; }
     // QImage currentAlbumArt() const;
    qint64 position() const { return n_mediaPlayer ? n_mediaPlayer->position() : 0; }
    qint64 duration() const { return n_mediaPlayer ? n_mediaPlayer->duration() : 0; }
    bool isShuffle() const { return n_isShuffle; }
    void setShuffle(bool value);
    Q_INVOKABLE void setVolume(qreal value);


public slots:
    void playNext();
    void playPrevious();
    void playOrPause();
    void setPosition(qint64 pos) {
        if (n_mediaPlayer) {
            n_mediaPlayer->setPosition(pos);
        }
    }


private:
    const QString m_musicPath = "C:/Users/anhtu/Desktop/Automotive/code_qt/ass_qt_01/Music";
    QStringList n_musicFiles;
    QMediaPlayer *n_mediaPlayer = nullptr;
    QAudioOutput *n_audioOutput = nullptr;
    int n_currentIndex = -1;
    bool _isPlaying = false;

    QString title;
    QString artist;
    QImage coverArt;
    QString coverArtPath;
    bool n_isShuffle = false;
    QVector<int> shuffledOrder;
    int shufflePos = -1;
    void prepareShuffledOrder();

    // QMediaPlayer *n_mediaPlayer = nullptr;
    // QAudioOutput *n_audioOutput = nullptr;

    void ScanMusicFiles();

private slots:
    void loadMusicIntoPlayer(const QStringList &musicFiles);

signals:
    void musicLoadDone(const QStringList &musicFiles);
    void isPlayingChanged();

    void titleChanged();
    void artistChanged();
    void coverArtChanged();

    void positionChanged();
    void durationChanged();
    void shuffleChanged();
};

#endif // MUSICLOAD_H
