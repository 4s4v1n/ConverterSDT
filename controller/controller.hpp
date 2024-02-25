#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <memory>

#include "../model/editor.hpp"
#include "../model/history.hpp"

namespace dvt
{

class Controller final : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(Controller);

public:
    Q_INVOKABLE void    setInputBase(int base) noexcept;
    Q_INVOKABLE void    setOutputBase(int base) noexcept;
    Q_INVOKABLE void    addSymbol(const QString& text) noexcept;
    Q_INVOKABLE void    clearEntry() noexcept;
    Q_INVOKABLE void    clearAll() noexcept;
    Q_INVOKABLE QString convert() noexcept;

public:
    static auto getInstance() -> Controller*;

private:
    Controller() = default;
    ~Controller() override = default;

private:
    Editor m_editor {};
};

} // namespace dvt

#endif // CONTROLLER_HPP
