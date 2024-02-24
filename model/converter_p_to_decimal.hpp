#ifndef CONVERTER_P_TO_DECIMAL_HPP
#define CONVERTER_P_TO_DECIMAL_HPP

#include <regex>
#include <string>

namespace dvt
{

class ConverterP2Decimal final
{
public:
    ConverterP2Decimal() = delete;
    ~ConverterP2Decimal() = delete;

public:
    static auto pToFloat(const std::string& value, int p) -> double;
    static auto pToInt(const std::string& value, int p) -> int;
    static auto evaluatePrecision(const std::string& value) -> int;
    // static auto isValidExpression(const std::string& value, int base) -> bool;

private:
    static auto charToInt(char symbol) -> int;
    // static auto evaluateFloatRegex(int base) -> std::regex;
    // static auto evaluateIntRegex(int base) -> std::regex;
    static auto evaluateLetters(int base) -> std::pair<char, char>;
};

} // dvt

#endif // CONVERTER_P_TO_DECIMAL_HPP
