#include "converter_decimal_to_p.hpp"

#include <cmath>
#include <format>
#include <limits>
#include <list>
#include <stdexcept>

namespace dvt
{
auto ConverterDecimal2P::float_to_p(double value, const int notation, const int accuracy) -> std::string
{
    if (notation < 2 || notation > 16)
    {
        throw std::invalid_argument{std::format("got invalid number notation {}", notation)};
    }

    auto integer_part{0.};
    auto fractional_part    {std::modf(value, &integer_part)};

    std::string integer_str    {int_to_p(static_cast<int>(integer_part), notation)};
    std::string fractional_str {};

    if (fractional_part < 0)
    {
        fractional_part *= -1;
    }

    auto current_accuracy {0};
    while (fractional_part > std::numeric_limits<double>::epsilon() && current_accuracy < accuracy)
    {
        fractional_part *= notation;
        fractional_part = std::modf(fractional_part, &integer_part);

        fractional_str.push_back(int_to_char(static_cast<int>(integer_part)));

        ++current_accuracy;
    }

    while (fractional_str.back() == '0')
    {
        fractional_str.pop_back();
    }

    return integer_str + "." + fractional_str;
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