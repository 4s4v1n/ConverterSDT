#ifndef CONVERTER_P_TO_DECIMAL_HPP
#define CONVERTER_P_TO_DECIMAL_HPP

#include <string>

namespace dvt
{

class ConverterP2Decimal final
{
public:
    ConverterP2Decimal() = delete;
    ~ConverterP2Decimal() = delete;

public:
    static auto p_to_float(const std::string& value, int p) -> double;
    static auto p_to_int(const std::string& value, int p) -> int;

private:
    static auto char_to_int(char symbol) -> int;
};

} // dvt

#endif // CONVERTER_P_TO_DECIMAL_HPP
