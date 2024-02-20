#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <string>
#include <vector>

#include <QAbstractListModel>
#include <QList>

namespace dvt {

class History : public QAbstractListModel
{
    Q_OBJECT

public:
    struct Record
    {
        Record()  = default;
        ~Record() = default;

        Record(int input_base, int output_base,
               const std::string& input, const std::string& output);

        int         input_base  {};
        int         output_base {};
        std::string input       {};
        std::string output      {};
    };

    enum RoleNames
    {
        InputBaseRole = Qt::UserRole + 1,
        OutputBaseRole,
        InputRole,
        OutputRole
    };

public:
    explicit History(QObject* parent = nullptr);

public:
    auto rowCount(const QModelIndex& index) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;
    auto roleNames() const -> QHash<int, QByteArray> override;

public:
    auto add(const Record& record) noexcept -> void;

private:
    QList<Record> m_data {};
};

} // dvt

#endif // HISTORY_HPP
