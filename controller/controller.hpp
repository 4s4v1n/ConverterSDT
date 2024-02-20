#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>

#include "../model/editor.hpp"

namespace dvt
{

class Controller final
{
public:
    enum class State : unsigned char
    {
        Edit    = 0,
        Convert = 1
    };

public:
    Controller() = default;
    ~Controller() = default;

public:
    auto getNumber() const noexcept -> std::string;
    auto convert(const std::string& value, int input_base, int output_base) -> std::string;
    auto validate(const std::string& value, int base) -> bool;
    auto addZero() -> void;
    auto addDelimiter() -> void;
    auto addDigit(char value) -> void;
    auto clear() -> void;
    auto bs() -> void;
    auto accuracy(unsigned int accuracy) -> void;

public:
    inline auto inputBase() -> int&
    {
        return m_input_base;
    }
    inline auto outputBase() -> int&
    {
        return m_output_base;
    }

private:
    int    m_input_base  {};
    int    m_output_base {};
    Editor m_editor      {};
};

} // namespace dvt

#endif // CONTROLLER_HPP
