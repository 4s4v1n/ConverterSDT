#include "editor.hpp"

namespace dvt
{

auto Editor::getNumber() const noexcept -> std::string
{
    return m_number;
}

auto Editor::addDigit(const char value) -> void
{
    m_number += value;
}

auto Editor::addZero() -> void
{
    m_number += zero;
}

auto Editor::addDelimiter() -> void
{
    m_number += delimiter;
}

auto Editor::clear() -> void
{
    m_number.clear();
}

auto Editor::bs() -> void
{
    m_number.pop_back();
}

auto Editor::accuracy(unsigned int n) -> void
{
    auto position {m_number.find(delimiter)};
    if ((m_number.size() - position - 1) <= n || n < 1)
    {
        return;
    }

    char symbol {'\n'}; // TODO change to 0
    while ((m_number.size() - position - 1) > n)
    {
        symbol = m_number[m_number.size() - 1];
        bs();
    }

    int digit {0};
    if (symbol >= '0' && symbol <= '9')
    {
        digit = symbol - '0';
    }
    else
    {
        digit = symbol - 'A' + 10;
    }

    auto last_number {0};
    if (symbol >= '0' && symbol <= '9')
    {
        last_number = m_number[m_number.size() - 1] - '0';
    }
    else
    {
        last_number = m_number[m_number.size() - 1] - 'A' + 10;
    }

    if (last_number < digit && digit >= 5 && last_number < 15)
    {
        last_number++;
        if (last_number < 10)
        {
            m_number[m_number.size() - 1] = static_cast<char>(last_number + '0');
        }
        else
        {
            m_number[m_number.size() - 1] = static_cast<char>(last_number + 'A' - 10);
        }
    }
}

} // dvt