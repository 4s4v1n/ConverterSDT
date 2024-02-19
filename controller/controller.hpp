#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>

namespace dvt
{

class Controller final
{
public:
    Controller() = default;
    ~Controller() = default;

public:
    auto convert(const std::string& value, int input_base, int output_base) -> std::string;
    auto validate(const std::string& value, int base) -> bool;
};

} // namespace dvt

#endif // CONTROLLER_HPP
