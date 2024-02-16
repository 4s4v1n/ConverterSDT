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
    auto convert(const std::string &value, int input_degree, int output_degree) -> std::string;
};

} // namespace dvt

#endif // CONTROLLER_HPP
