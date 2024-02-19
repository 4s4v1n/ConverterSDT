#include "history.hpp"

namespace dvt
{

auto History::operator[](int index) const -> Record
{
    return m_data[index];
}

auto History::count() const noexcept -> int
{
    return static_cast<int>(m_data.size());
}

auto History::add(const Record& record) noexcept -> void
{
    m_data.push_back(record);
}

auto History::clear() noexcept -> void
{
    m_data.clear();
}

} // dvt