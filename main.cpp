#include <QGuiApplication>
#include <QCoreApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickView>

auto main(int argc, char *argv[]) -> int
{
    QGuiApplication       app    {argc, argv};
    QQmlApplicationEngine engine {};

    QGuiApplication::setOrganizationName("NSTU");
    QGuiApplication::setApplicationName("Converter");

    const QUrl url{u"qrc:Converter/view/main.qml"_qs};
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
