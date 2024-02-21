#include <QGuiApplication>
#include <QCoreApplication>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication::setOrganizationName("NSTU");
    QCoreApplication::setApplicationName("Converter");

    QGuiApplication app  {argc, argv};
    QQuickView      view {};

    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
    view.setSource(QUrl{"qrc:Converter/view/main.qml"});

    if (view.status() == QQuickView::Error)
    {
        return -1;
    }

    view.show();
    return app.exec();
}
