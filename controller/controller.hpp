#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>

#include "../model/editor.hpp"
#include "../model/history.hpp"

namespace dvt
{

class Controller final : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(Controller);

public:
    Q_INVOKABLE void setInputBase(int base) noexcept;
    Q_INVOKABLE void setOutputBase(int base) noexcept;
    Q_INVOKABLE void addSymbol(const QString& text) noexcept;
    Q_INVOKABLE void clearEntry() noexcept;
    Q_INVOKABLE void clearAll() noexcept;

public:
    Controller() = default;
    ~Controller() override = default;

public:
    static auto getInstance() -> Controller*;

public:
    auto convert(const std::string& value, int input_base, int output_base) -> std::string;
    auto history() const noexcept -> const History&;

private:
    Editor  m_editor  {};
    History m_history {};
};

} // namespace dvt

#endif // CONTROLLER_HPP
