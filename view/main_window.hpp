#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QErrorMessage>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMouseEvent>

#include "history_window.hpp"
#include "../controller/controller.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{

class MainWindow;

}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public:
    auto setController(const std::shared_ptr<dvt::Controller>& controller) noexcept -> void;

protected:
    auto keyPressEvent(QKeyEvent* event) -> void override;
    auto mousePressEvent(QMouseEvent* event) -> void override;

private slots:
    auto onInputButtonClicked() noexcept -> void;
    auto onAllClearButtonClicked() noexcept -> void;
    auto onClearEntryButtonClicked() noexcept -> void;
    auto onConvertButtonClicked() noexcept -> void;
    auto onMenuTriggered(QAction* action) noexcept -> void;

private:
    auto clearEntry() noexcept -> void;
    auto convertInput() noexcept -> void;
    auto clearAll() noexcept -> void;
    auto addInput(const QString& text) noexcept -> void;

private:
    static constexpr const char* exit_action_name      {"exit_action"};
    static constexpr const char* reference_action_name {"reference_action"};
    static constexpr const char* history_action_name   {"history_action"};

private:
    Ui::MainWindow* ui {};

    std::shared_ptr<dvt::Controller> m_controller {};
    std::unique_ptr<QErrorMessage>   m_error      {};
    std::unique_ptr<HistoryWindow>   m_history    {};
};

#endif // MAIN_WINDOW_H
