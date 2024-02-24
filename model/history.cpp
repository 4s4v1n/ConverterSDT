#include "history.hpp"

namespace dvt
{

History::History(QObject *parent):
    QAbstractListModel{parent}
{}

History::Record::Record(const int input_base, const int output_base,
                        const std::string& input, const std::string& output):
    input_base{input_base},
    output_base{output_base},
    input{input},
    output{output}
{}

auto History::add(const Record& record) noexcept -> void
{
    const int size {static_cast<int>(m_data.size())};

    beginInsertRows(QModelIndex{}, size, size + 1);
    m_data.push_back(record);
    endInsertRows();
}

auto History::rowCount(const QModelIndex& index) const -> int
{
    return static_cast<int>(m_data.size());
}

auto History::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid())
    {
        return QVariant{};
    }

    const auto row {index.row()};
    if (row < 0 || row >= m_data.size())
    {
        return QVariant{};
    }

    const auto& data {m_data.value(row)};
    switch (role)
    {
        case InputBaseRole:  return QVariant::fromValue(data.input_base);
        case OutputBaseRole: return QVariant::fromValue(data.output_base);
        case InputRole:      return QVariant::fromValue(data.input);
        case OutputRole:     return QVariant::fromValue(data.output);
        default:             return QVariant{};
    }
}

auto History::roleNames() const -> QHash<int, QByteArray>
{
    static QHash<int, QByteArray> roles {QAbstractListModel::roleNames()};

    roles[InputBaseRole]  = "m_input_base";
    roles[OutputBaseRole] = "m_output_base";
    roles[InputRole]      = "input_role";
    roles[OutputRole]     = "output_role";

    return roles;
}

} // dvt