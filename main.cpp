#include "view/main_window.hpp"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
    QApplication      app    {argc, argv};
    dvt::MainWindow   window {};

    window.show();
    return app.exec();
}
