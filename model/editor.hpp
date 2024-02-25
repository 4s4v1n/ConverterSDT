#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <QObject>

#include <set>
#include <string>

namespace dvt
{

class Editor final
{
public:
    Editor();
    ~Editor() = default;

public:
    auto setInputBase(int base) -> void;
    auto setOutputBase(int base) -> void;
    auto getInputBase() const noexcept -> int;
    auto getOutputBase() const noexcept -> int;
    auto getValue() const noexcept -> std::string;
    auto addSymbol(char symbol) -> void;
    auto clearEntry() noexcept -> void;
    auto clearAll() noexcept -> void;

private:
    const std::set<char> m_valid_symbols;

private:
    std::string m_value       {};
    int         m_input_base  {};
    int         m_output_base {};
};

} // dvt

#endif // EDITOR_HPP
