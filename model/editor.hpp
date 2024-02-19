#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <string>

namespace dvt
{

class Editor
{
public:
    [[nodiscard]] auto getNumber() const noexcept -> std::string ;
    auto addDigit(char value) -> void;
    auto addZero() -> void;
    auto addDelimiter() -> void;
    auto clear() -> void;
    auto bs() -> void;
    auto accuracy(unsigned int accuracy) -> void;

private:
    static constexpr char delimiter {'.'};
    static constexpr char zero      {'0'};

private:
    std::string m_number {};
};

} // dvt

#endif // EDITOR_HPP
