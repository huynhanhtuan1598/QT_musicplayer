#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "musicload.h"
#include "customimage.h"
// #include <QtQml>
using namespace Qt::StringLiterals;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MusicLoad musicLoader;
    engine.rootContext()->setContextProperty("musicLoader", &musicLoader);

    const QUrl url(u"qrc:/qt/qml/ass_qt_01/Main.qml"_s);

    qmlRegisterType<Customimage>("Customimage", 1, 0, "Customimage");
    qmlRegisterType<MusicLoad>("MusicLoader", 1, 0, "MusicLoader");


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
