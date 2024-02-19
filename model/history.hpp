#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <string>
#include <vector>

namespace dvt {

class History
{
public:
    struct Record
    {
        Record()  = default;
        ~Record() = default;

        int         output_base {};
        int         input_base  {};
        std::string input       {};
        std::string output      {};
    };

public:
    [[nodiscard]] auto operator[](int index) const -> Record;

public:
    [[nodiscard]] auto count() const noexcept -> int;
    auto add(const Record& record) noexcept -> void;
    auto clear() noexcept -> void;

private:
    std::vector<Record> m_data {};
};

} // dvt

#endif // HISTORY_HPP
