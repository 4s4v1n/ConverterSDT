#include "editor.hpp"

#include <stdexcept>

#include <QDebug>

namespace dvt
{

Editor::Editor():
        m_value{},
        m_input_base{2},
        m_output_base{2},
        m_valid_symbols{'0', '1', '2', '3',
                        '4', '5', '6', '7',
                        '8', '9', 'A', 'B',
                        'C', 'D', 'E', 'F',
                        'a', 'b', 'c', 'd',
                        'e', 'f', '.', '-'}
{}

auto Editor::setInputBase(const int base) -> void
{
    if (base < 2 || base > 16)
    {
        throw std::invalid_argument{"base is out of range"};
    }
    if (m_input_base != base)
    {
        m_input_base = base;
    }
}

auto Editor::setOutputBase(int base) -> void
{
    if (base < 2 || base > 16)
    {
        throw std::invalid_argument{"base is out of range"};
    }
    if (m_output_base != base)
    {
        m_output_base = base;
    }
}


auto Editor::getInputBase() const noexcept -> int
{
    return m_input_base;
}

auto Editor::getOutputBase() const noexcept -> int
{
    return m_output_base;
}

auto Editor::getValue() const noexcept -> std::string
{
    return m_value;
}

auto Editor::addSymbol(const char symbol) -> void
{
    if (!m_valid_symbols.contains(symbol))
    {
        throw std::invalid_argument{"symbol is out of range"};
    }
    m_value += symbol;
}

auto Editor::clearEntry() noexcept -> void
{
    m_value.pop_back();
}

auto Editor::clearAll() noexcept -> void
{
    m_value.clear();
}

} // namespace dvt
