#ifndef CONVERTER_DECIMAL_TO_P_HPP
#define CONVERTER_DECIMAL_TO_P_HPP

#include <string>
#include <type_traits>

namespace dvt
{

class ConverterDecimal2P final
{
public:
    ConverterDecimal2P() = delete;
    ~ConverterDecimal2P() = delete;

public:
    static auto float_to_p(double value, int notation, int accuracy) -> std::string;
    static auto int_to_p(int value, int notation) -> std::string;

private:
    static auto int_to_char(int value) -> char;
};

} // dvt

#endif // CONVERTER_DECIMAL_TO_P_HPP
