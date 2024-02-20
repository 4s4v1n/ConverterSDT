#include "history_window.hpp"
#include "ui_history_window.h"

HistoryWindow::HistoryWindow(QWidget *parent):
    QDialog{parent},
    ui{new Ui::HistoryWindow}
{
    ui->setupUi(this);

    // TODO here set model
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

auto HistoryWindow::setController(const std::shared_ptr<dvt::Controller>& controller) noexcept -> void
{
    m_controller = controller;
}
