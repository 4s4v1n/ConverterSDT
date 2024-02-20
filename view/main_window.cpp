#include "main_window.hpp"
#include "ui_main_window.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow{parent},
    ui{new Ui::MainWindow},
    m_error{},
    m_history{new HistoryWindow}
{
    ui->setupUi(this);
    m_history->setController(m_controller);

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

    connect(ui->input_base_slider, &QSlider::valueChanged, ui->input_base_spinbox, &QSpinBox::setValue);
    connect(ui->input_base_spinbox, &QSpinBox::valueChanged, ui->input_base_slider, &QSlider::setValue);
    connect(ui->output_base_slider, &QSlider::valueChanged, ui->output_base_spinbox, &QSpinBox::setValue);
    connect(ui->output_base_spinbox, &QSpinBox::valueChanged, ui->output_base_slider, &QSlider::setValue);

    connect(ui->menu, &QMenu::triggered, this, &MainWindow::onMenuTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::setController(const std::shared_ptr<dvt::Controller>& controller) noexcept -> void
{
    m_controller = controller;
}

auto MainWindow::clearEntry() noexcept -> void
{
    auto &input{ui->input_line};
    if (!input->text().isEmpty())
    {
        input->setText(input->text().chopped(1));
    }
}

auto MainWindow::convertInput() noexcept -> void
{
    auto& input {ui->input_line};
    auto& output{ui->output_line};
    auto  input_degree {ui->input_base_spinbox->value()};
    auto  output_degree{ui->output_base_spinbox->value()};

    std::string result {};
    try
    {
        if (!m_controller->validate(input->text().toStdString(), input_degree))
        {
            m_error = std::make_unique<QErrorMessage>(new QErrorMessage{this});

            m_error->setWindowModality(Qt::WindowModality::WindowModal);
            m_error->showMessage("expression isn't valid");

            return;
        }
        result = m_controller->convert(input->text().toStdString(), input_degree, output_degree);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what();
        return;
    }
    output->setText(QString::fromStdString(result));
}

auto MainWindow::clearAll() noexcept -> void
{
    auto &input{ui->input_line};
    if (!input->text().isEmpty())
    {
        input->clear();
    }
}

auto MainWindow::addInput(const QString& text) noexcept -> void
{
    auto &input {ui->input_line};
    if (input->text().isEmpty())
    {
        input->setText(text);
    }
    else
    {
        input->setText(input->text() + text);
    }
}

auto MainWindow::onInputButtonClicked() noexcept -> void
{
    auto button{qobject_cast<QPushButton *>(sender())};
    if (button == nullptr)
    {
        return;
    }
    addInput(button->text());
}

auto MainWindow::onAllClearButtonClicked() noexcept -> void
{
    clearAll();
}

auto MainWindow::onClearEntryButtonClicked() noexcept -> void
{
    clearEntry();
}

auto MainWindow::onConvertButtonClicked() noexcept -> void
{
    convertInput();
}

auto MainWindow::keyPressEvent(QKeyEvent *event) -> void
{
    auto& input {ui->input_line};
    auto  key   {event->key()};

    if (key == Qt::Key_Backspace)
    {
        clearEntry();
    }
    else if (key == Qt::Key_Enter)
    {
        convertInput();
    }
    else
    {
        input->setText(input->text() + event->text());
    }
}

auto MainWindow::mousePressEvent(QMouseEvent *event) -> void
{
   setFocus();
}

auto MainWindow::onMenuTriggered(QAction* action) noexcept -> void
{
    auto action_name {action->objectName()};
    if (action_name == exit_action_name)
    {
        QApplication::exit();
    }
    else if (action_name == reference_action_name)
    {

    }
    else if (action_name == history_action_name)
    {
        m_history->show();
    }
}
