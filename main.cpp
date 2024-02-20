#include "view/main_window.hpp"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
    QApplication                     app        {argc, argv};
    MainWindow                       window     {};
    std::shared_ptr<dvt::Controller> controller {new dvt::Controller};

    window.setController(controller);
    window.show();

    return app.exec();
}
