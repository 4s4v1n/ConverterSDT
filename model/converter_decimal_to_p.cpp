#include "converter_decimal_to_p.hpp"

#include <format>
#include <stdexcept>
#include <list>

namespace dvt
{
auto ConverterDecimal2P::float_to_p(double value, const int notation, const int accuracy) -> std::string
{
    if (notation < 2 || notation > 16)
    {
        throw std::invalid_argument{std::format("got invalid number notation {}", notation)};
    }

    // TODO

    return "";
}

auto ConverterDecimal2P::int_to_p(int value, const int notation) -> std::string
{
    if (notation < 2 || notation > 16)
    {
        throw std::invalid_argument{std::format("got invalid number notation {}", notation)};
    }

    auto is_negative {false};
    if (value < 0)
    {
        is_negative = true;
        value *= -1;
    }

    std::list<int> remainder_list {};
    while (value != 0)
    {
        remainder_list.push_front(value % notation);
        value /= notation;
    }

    std::string result {is_negative ? "-" : ""};
    for (const auto& reminder : remainder_list)
    {
        result.push_back(int_to_char(reminder));
    }

    return result;
}

auto ConverterDecimal2P::int_to_char(const int value) -> char
{
    if (value < 0 || value > 16)
    {
        throw std::invalid_argument{std::format("got invalid value {}", value)};
    }

    if (value <= 9)
    {
        return static_cast<char>(value + 48);
    }
    return static_cast<char>(value + 55);
}

} // dvt