#include "converter_p_to_decimal.hpp"

#include <cmath>
#include <format>
#include <stdexcept>

namespace dvt
{

auto ConverterP2Decimal::p_to_float(const std::string& value, const int p) -> double
{
    auto dot_position{static_cast<int>(value.find('.'))};
    auto integer_part {p_to_int(value.substr(0, dot_position), p)};
    auto fractional_part{0.};

    auto degree {-1};
    for (auto it {value.begin() + dot_position + 1}; it != value.end(); ++it, --degree)
    {
        fractional_part += char_to_int(*it) * std::pow(p, degree);
    }
    return value.front() == '-' ? integer_part - fractional_part : integer_part + fractional_part;
}

auto ConverterP2Decimal::p_to_int(const std::string& value, const int p) -> int
{
    auto result {0};
    auto degree {0};

    for (auto it {value.rbegin()}; it != value.rend() && *it != '-'; ++it, ++degree)
    {
        result += char_to_int(*it) * static_cast<int>(std::pow(p, degree));
    }
    return value.starts_with('-') ? result * -1 : result;
}

auto ConverterP2Decimal::char_to_int(const char symbol) -> int
{
    if (symbol >= '0' && symbol <= '9')
    {
        return static_cast<int>(symbol) - 48;
    }
    if (symbol >= 'A' && symbol <= 'F')
    {
        return static_cast<int>(symbol) - 55;
    }
    if (symbol >= 'a' && symbol <= 'f')
    {
        return static_cast<int>(symbol) - 87;
    }

    throw std::invalid_argument{std::format("got invalid symbol {}", symbol)};
}

} // dvt