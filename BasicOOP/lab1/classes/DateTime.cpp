#include <tuple>
#include "DateTime.h"

std::size_t TimeClass::TotalDays() const {
    static int daysSpendForMonth[] = {0, 31, 59, 90, 120, 151, 181, 211, 242, 272, 303, 303, 334};
//                    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},

    return day + year * 365 + daysSpendForMonth[month - 1] + int(year / 4) - int(year / 100) + int(year / 400);
}

bool DateTime::IsCorrect() const {
    if (month > 12 || month < 1) return false;
    if (year < 0) return false;
    if (minutes > 59 || minutes < 0) return false;
    if (seconds > 59 || seconds < 0) return false;
    if (hours > 23 || hours < 0) return false;
    int daysInMonth[12] = {31, 28 + IsLeap(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonth[month - 1]) return false;

    return true;
}

bool DateTime::IsLeap() const {
    return (year % 400 == 0) or (year % 4 == 0 && year % 100 != 0);
}

std::size_t DateTime::week_in_month() const{
    return 0;
}

std::size_t DateTime::week_in_year() const{
    return 0;
}

std::string TimeClass::ToString() const {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year) +
           " " + std::to_string(hours) + ":" + std::to_string(minutes);
}

TimeClass::TimeClass(int year, int month, int day, int hours, int minutes, int seconds)
        : year(year), month(month), day(day), hours(hours), minutes(minutes), seconds(seconds) {}


TimeClass::TimeClass(int year, int month, int day)
        : year(year), month(month), day(day) {}

bool TimeClass::operator<(TimeClass &other) const{
    return std::tie(this->year, this->month, this->day, this->hours, this->minutes, this->seconds)
           < std::tie(other.year, other.month, other.day, other.hours, other.minutes, other.seconds);

}

bool TimeClass::operator==(TimeClass &other) const{
    return std::tie(this->year, this->month, this->day, this->hours, this->minutes, this->seconds)
           == std::tie(other.year, other.month, other.day, other.hours, other.minutes, other.seconds);

}
