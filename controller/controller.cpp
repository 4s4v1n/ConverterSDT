#include "controller.hpp"

#include <iostream>

#include "../model/converter_p_to_decimal.hpp"
#include "../model/converter_decimal_to_p.hpp"

namespace dvt
{

auto Controller::getInstance() -> Controller*
{
    static Controller instance {};
    return &instance;
}

auto Controller::convert() noexcept -> QString
{
    std::string output {};

    auto value {m_editor.getValue()};
    if (value.find('.') != std::string::npos)
    {
        auto input {ConverterP2Decimal::pToFloat(value, m_editor.getInputBase())};
        output = ConverterDecimal2P::floatToP(input, m_editor.getOutputBase(),
                                              ConverterP2Decimal::evaluatePrecision(value));
    }
    else
    {
        auto input {ConverterP2Decimal::pToInt(value, m_editor.getInputBase())};
        output = ConverterDecimal2P::intToP(input, m_editor.getOutputBase());
    }
    History::getInstance()->add(History::Record{m_editor.getInputBase(),
                                                m_editor.getOutputBase(), value, output});

    return QString::fromStdString(output);
}

auto Controller::setInputBase(const int base) noexcept -> void
{
    try
    {
        m_editor.setInputBase(base);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

auto Controller::setOutputBase(const int base) noexcept -> void
{
    try
    {
        m_editor.setOutputBase(base);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

auto Controller::addSymbol(const QString& text) noexcept -> void
{
    try
    {
        m_editor.addSymbol(text.front().toLatin1());
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

auto Controller::clearEntry() noexcept -> void
{
    m_editor.clearEntry();
}

auto Controller::clearAll() noexcept -> void
{
    m_editor.clearAll();
}

}
