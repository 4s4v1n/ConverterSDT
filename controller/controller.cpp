#include "controller.hpp"

#include "../model/converter_p_to_decimal.hpp"
#include "../model/converter_decimal_to_p.hpp"

namespace dvt
{

auto Controller::convert(const std::string& value, const int input_base, const int output_base) -> std::string
{
    if (value.find('.') != std::string::npos)
    {
        auto input {ConverterP2Decimal::pToFloat(value, input_base)};
        return ConverterDecimal2P::floatToP(input, output_base,
                                             ConverterP2Decimal::evaluatePrecision(value));
    }
    auto input {ConverterP2Decimal::pToInt(value, input_base)};
    return ConverterDecimal2P::intToP(input, output_base);
}

auto Controller::validate(const std::string& value, int base) -> bool
{
    return ConverterP2Decimal::isValidExpression(value, base);
}

}
