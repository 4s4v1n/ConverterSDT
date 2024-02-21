#ifndef CONVERTER_DECIMAL_TO_P_HPP
#define CONVERTER_DECIMAL_TO_P_HPP

#include <string>
#include <type_traits>

namespace dvt
{

class ConverterDecimal2P final
{
    // TODO internal exception class
public:
    ConverterDecimal2P() = delete;
    ~ConverterDecimal2P() = delete;

public:
    static auto floatToP(double value, int notation, int accuracy) -> std::string;
    static auto intToP(int value, int notation) -> std::string;

private:
    static auto intToChar(int value) -> char;
};

} // dvt

#endif // CONVERTER_DECIMAL_TO_P_HPP
