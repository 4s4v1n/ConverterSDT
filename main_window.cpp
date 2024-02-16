#include "main_window.h"
#include "./ui_main_window.h"

namespace dvt
{
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    ui{new Ui::MainWindow}
{
    ui->setupUi(this);

    connect(ui->push_button_0, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_1, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_2, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_3, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_4, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_5, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_6, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_7, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_8, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_9, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_a, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_b, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_c, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_d, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_e, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_f, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);
    connect(ui->push_button_dot, &QPushButton::clicked, this, &MainWindow::onInputButtonClicked);

    connect(ui->push_button_ac, &QPushButton::clicked, this, &MainWindow::onAllClearButtonClicked);
    connect(ui->push_button_ce, &QPushButton::clicked, this, &MainWindow::onClearEntryButtonClicked);
    connect(ui->push_button_convert, &QPushButton::clicked, this, &MainWindow::onConvertButtonClicked);
}

auto MainWindow::onInputButtonClicked() noexcept -> void
{
    auto button{qobject_cast<QPushButton *>(sender())};
    if (button == nullptr)
    {
        return;
    }

    auto &input{ui->input_line};
    if (input->text().isEmpty())
    {
        input->setText(button->text());
    }
    else
    {
        input->setText(input->text() + button->text());
    }
}

auto MainWindow::onAllClearButtonClicked() noexcept -> void
{
    auto &input{ui->input_line};
    if (!input->text().isEmpty())
    {
        input->clear();
    }
}

auto MainWindow::onClearEntryButtonClicked() noexcept -> void
{
    auto &input{ui->input_line};
    if (!input->text().isEmpty())
    {
        input->setText(input->text().chopped(1));
    }
}

auto MainWindow::onConvertButtonClicked() noexcept -> void
{
    // TODO here call to controller
}

} // namespace dvt
