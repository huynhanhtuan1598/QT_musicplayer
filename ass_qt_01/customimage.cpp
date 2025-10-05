#include "customimage.h"
#include <QPainter>
#include <QFile>
#include <QUrl>
#include <QDebug>

Customimage::Customimage(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // Optionally, set render hints or antialiasing if needed.
    setAntialiasing(true);
}

void Customimage::paint(QPainter *painter)
{
    // Only draw if the image is valid (non-null)
    if (!m_image.isNull()) {
        // Draw the loaded image scaled to the bounding rectangle of the QML item.
        painter->drawImage(boundingRect(), m_image);
    } else {
        // Optionally, you may draw a placeholder or error message if the image did not load.
        painter->setPen(Qt::red);
        painter->drawText(boundingRect(), Qt::AlignCenter, "Image not loaded");
    }
}

QString Customimage::source() const
{
    return m_source;
}

void Customimage::setSource(const QString &source)
{
    if (m_source == source)
        return;

    m_source = source;
    // Attempt to load the image from the provided source string.
    // Use QUrl to support resources or file paths if desired.
    QUrl imageUrl(source);
    QString filePath;

    // Determine if the path is a resource (":/") or a regular file.
    if (imageUrl.isLocalFile() || source.startsWith(":/")) {
        filePath = imageUrl.toLocalFile();
        if (filePath.isEmpty())
            filePath = source;
    } else {
        // For remote URLs (if needed), additional handling would be required.
        filePath = source;
    }

    if (m_image.load(filePath)) {
        // Successful load: update the view.
        update();
    } else {
        // Log error information; you might want to handle this differently in production.
        qWarning() << "Failed to load image from source:" << source;
        m_image = QImage();  // Clear the image.
        update();
    }

    emit sourceChanged();
}

void Customimage::setImage(QImage image)
{
    m_image = image;
    update();
}
