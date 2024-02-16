#include "converter_p_to_decimal.hpp"

#include <cmath>
#include <format>
#include <stdexcept>

namespace dvt
{

auto ConverterP2Decimal::p_to_float(const std::string& value, const int p) -> double
{
    // TODO
    return 0.;
}

auto ConverterP2Decimal::p_to_int(const std::string& value, const int p) -> int
{
    auto result {0};
    auto degree {0};

    for (auto it {value.rbegin()}; it != value.rend(); ++it, ++degree)
    {
        result += char_to_int(*it) * static_cast<int>(std::pow(p, degree));
    }
    return result;
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