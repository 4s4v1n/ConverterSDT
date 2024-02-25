#include <QGuiApplication>
#include <QCoreApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>

#include "controller/controller.hpp"

auto main(int argc, char *argv[]) -> int
{
    QGuiApplication       app    {argc, argv};
    QQmlApplicationEngine engine {};

    QGuiApplication::setOrganizationName("NSTU");
    QGuiApplication::setApplicationName("Converter");

    engine.rootContext()->setContextProperty("Controller",   dvt::Controller::getInstance());
    engine.rootContext()->setContextProperty("HistoryModel", dvt::History::getInstance());

    const QUrl url{u"qrc:Converter/view/main.qml"_qs};
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
