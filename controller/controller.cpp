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

auto Controller::convert(const std::string& value, const int input_base, const int output_base) -> std::string
{
    std::string output {};

    if (value.find('.') != std::string::npos)
    {
        auto input {ConverterP2Decimal::pToFloat(value, input_base)};
        output = ConverterDecimal2P::floatToP(input, output_base,
                                              ConverterP2Decimal::evaluatePrecision(value));
    }
    else
    {
        auto input {ConverterP2Decimal::pToInt(value, input_base)};
        output = ConverterDecimal2P::intToP(input, output_base);
    }
    m_history.add(History::Record{input_base, output_base, value, output});

    return output;
}

auto Controller::history() const noexcept -> const History&
{
    return m_history;
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
