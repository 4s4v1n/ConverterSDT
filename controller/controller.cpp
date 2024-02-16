#include "controller.hpp"

#include "../model/converter_p_to_decimal.hpp"
#include "../model/converter_decimal_to_p.hpp"

namespace dvt
{

auto Controller::convert(const std::string& value, const int input_degree, const int output_degree) -> std::string
{
    auto input {ConverterP2Decimal::p_to_int(value, input_degree)};
    return ConverterDecimal2P::int_to_p(input, output_degree);
}

}

