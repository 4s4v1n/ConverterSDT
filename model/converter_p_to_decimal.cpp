#include "converter_p_to_decimal.hpp"

#include <cmath>
#include <stdexcept>

namespace dvt
{

auto ConverterP2Decimal::pToFloat(const std::string& value, int p) -> double
{
    auto dot_position{static_cast<int>(value.find('.'))};
    auto integer_part {pToInt(value.substr(0, dot_position), p)};
    auto fractional_part{0.};

    auto degree {-1};
    for (auto it {value.begin() + dot_position + 1}; it != value.end(); ++it, --degree)
    {
        fractional_part += charToInt(*it) * std::pow(p, degree);
    }
    return value.front() == '-' ? integer_part - fractional_part : integer_part + fractional_part;
}

auto ConverterP2Decimal::pToInt(const std::string& value, int p) -> int
{
    auto result {0};
    auto degree {0};

    for (auto it {value.rbegin()}; it != value.rend() && *it != '-'; ++it, ++degree)
    {
        result += charToInt(*it) * static_cast<int>(std::pow(p, degree));
    }
    return value.starts_with('-') ? result * -1 : result;
}

auto ConverterP2Decimal::charToInt(const char symbol) -> int
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

    throw std::invalid_argument{"got invalid symbol " + std::to_string(symbol)};
}

auto ConverterP2Decimal::evaluatePrecision(const std::string &value) -> int
{
    auto dot_position {value.find('.')};
    return static_cast<int>(value.size() - dot_position);
}

auto ConverterP2Decimal::evaluateLetters(const int base) -> std::pair<char, char>
{
    if (base < 11 || base > 16)
    {
        throw std::invalid_argument{"got invalid base " + std::to_string(base)};
    }
    return std::make_pair(static_cast<char>(base + 54), static_cast<char>(base + 86));
}

// auto ConverterP2Decimal::evaluateFloatRegex(const int base) -> std::regex
// {
//     if (base < 2 || base > 16)
//     {
//         throw std::invalid_argument{std::format("got invalid base {}", base)};
//     }

//     if (base <= 10)
//     {
//         return std::regex{std::format(R"(^\-?[0-{}]+\.[0-{}]+$)", base - 1, base - 1)};
//     }

//     auto [upper, lower] {evaluateLetters(base)};
//     return std::regex{std::format(R"(^\-?([0-9]|[A-{}]|[a-{}])+\.([0-9]|[A-{}]|[a-{}])+$)",
//                                   upper, lower, upper, lower)};
// }

// auto ConverterP2Decimal::evaluateIntRegex(const int base) -> std::regex
// {
//     if (base < 2 || base > 16)
//     {
//         throw std::invalid_argument{std::format("got invalid base {}", base)};
//     }

//     if (base <= 10)
//     {
//         return std::regex{std::format(R"(^\-?[0-{}]+$)", base - 1, base - 1)};
//     }

//     auto [upper, lower] {evaluateLetters(base)};
//     return std::regex{std::format(R"(^\-?([0-9]|[A-{}]|[a-{}]))", upper, lower)};
// }

// auto ConverterP2Decimal::isValidExpression(const std::string &value, const int base) -> bool
// {
//     if (value.find('.') != std::string::npos)
//     {
//         return std::regex_match(value, evaluateFloatRegex(base));
//     }
//     return std::regex_match(value, evaluateIntRegex(base));
// }

} // dvt
