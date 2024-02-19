#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QErrorMessage>
#include <QMainWindow>

#include "../controller/controller.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{

class MainWindow;

}
QT_END_NAMESPACE

namespace dvt
{

// singleton
class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private slots:
    auto onInputButtonClicked() noexcept -> void;
    auto onAllClearButtonClicked() noexcept -> void;
    auto onClearEntryButtonClicked() noexcept -> void;
    auto onConvertButtonClicked() noexcept -> void;

private:
    Ui::MainWindow* ui {};

    std::unique_ptr<Controller>    m_controller {};
    std::unique_ptr<QErrorMessage> m_error      {};
};

} // namespace dvt


#endif // MAIN_WINDOW_H
