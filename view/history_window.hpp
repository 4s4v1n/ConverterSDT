#ifndef HISTORY_WINDOW_HPP
#define HISTORY_WINDOW_HPP

#include <QDialog>

#include "../controller/controller.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{

class HistoryWindow;

}
QT_END_NAMESPACE

class HistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow() override;

public:
    auto setController(const std::shared_ptr<dvt::Controller>& controller) noexcept -> void;

private:
    Ui::HistoryWindow *ui {};

    std::shared_ptr<dvt::Controller> m_controller {};
};


#endif // HISTORY_WINDOW_HPP
