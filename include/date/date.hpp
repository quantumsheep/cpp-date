#include <chrono>
#include <string>

class Date
{
public:
    size_t day = 0;
    size_t month = 0;
    size_t year = 0;

    constexpr Date(const size_t &day_, const size_t &month_, const size_t &year_) : day(day_), month(month_), year(year_) {}

    Date(const std::chrono::system_clock::time_point &time)
    {
        const auto tt = std::chrono::system_clock::to_time_t(time);
        const auto local_tm = *localtime(&tt);

        this->day = local_tm.tm_mday;
        this->month = local_tm.tm_mon + 1;
        this->year = local_tm.tm_year + 1900;
    }

    std::chrono::seconds epoch() const
    {
        const auto day = this->day - 1;
        const auto month = this->month - 1;
        const auto year = this->year;

        std::tm t = {0};
        t.tm_year = year - 1900;
        t.tm_mon = month;
        t.tm_mday = day;

        const auto timeSinceEpoch = mktime(&t);
        return std::chrono::seconds(timeSinceEpoch);
    }

    static Date now()
    {
        const auto time = std::chrono::system_clock::now();
        return Date(time);
    }

    constexpr bool operator>(const Date &right) const
    {
        return this->epoch() > right.epoch();
    }

    constexpr inline bool operator<(const Date &right) const
    {
        return this->epoch() < right.epoch();
    }
};
