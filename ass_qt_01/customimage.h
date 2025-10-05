#ifndef CUSTOMIMAGE_H
#define CUSTOMIMAGE_H
#include <QQuickPaintedItem>
#include <QImage>
#include <QString>

class Customimage : public QQuickPaintedItem
{
    Q_OBJECT
    // The source property holds the path to the image file.
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
public:
    // customimage();
    explicit Customimage(QQuickItem *parent = nullptr);

    // Override the paint method to draw the image.
    void paint(QPainter *painter) override;

    // Getter for the source property.
    QString source() const;
public slots:
    // Setter for the source property. Loads the image and updates the component.
    void setSource(const QString &source);
    void setImage(QImage image);

signals:
    // Notify signal for when the source changes.
    void sourceChanged();

private:
    QImage m_image;   // Holds the loaded image.
    QString m_source; // Holds the file path to the image.
};


#endif // CUSTOMIMAGE_H
