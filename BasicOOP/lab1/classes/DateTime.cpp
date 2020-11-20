#include <tuple>
#include "DateTime.h"

std::size_t TimeClass::TotalDays() const {
    static int daysSpendForMonth[] = {0, 31, 59, 90, 120, 151, 181, 211, 242, 272, 303, 303, 334};
    int year_ = year - 1;
    bool extra = (month > 2) && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    return day + year_ * 365 + daysSpendForMonth[month - 1] + (int(year_ / 4) - int(year_ / 100) + int(year_ / 400)) +
           extra;
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
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

std::size_t DateTime::week_in_month() const {
    static int daysSpendForMonth[] = {0, 31, 59, 90, 120, 151, 181, 211, 242, 272, 303, 303, 334};
    return (daysSpendForMonth[month] - day) / 7;
}

std::size_t DateTime::week_in_year() const {
    static int daysSpendForMonth[] = {0, 31, 59, 90, 120, 151, 181, 211, 242, 272, 303, 303, 334};
    return daysSpendForMonth[month] / 7;
}

TimeDelta DateTime::operator-(TimeClass &other) const {
    return {year - other.year, month - other.month, day - other.day,
            hours - other.hours, month - other.month, seconds - other.seconds};
}

DateTime DateTime::operator+(TimeDelta &other) const {
    DateTime result{year + other.year, month + other.month, day + other.day, hours + other.hours,
                    minutes + other.minutes, seconds + other.seconds};
    result.Correct();
    return result;
}

#define correct_param(a, b, c) while(a<0){ \
                                b--;\
                                a+=c;\
                                }\
                                b+=a/c;    \
                                a%=c;

void DateTime::Correct() {
    if (IsCorrect()) {
        return;
    }
    correct_param(seconds, minutes, 60)
    correct_param(minutes, hours, 60)
    correct_param(hours, day, 24)
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (day < 0) {
        month--;
        correct_param(month, year, 12)
        day += daysInMonth[month];
    }
    while (day > daysInMonth[month]) {
        day -= daysInMonth[month];
        month++;
        correct_param(month, year, 12)
    }
    correct_param(month, year, 12)
}

DateTime DateTime::operator-(TimeDelta &other) const {
    DateTime result{year - other.year, month - other.month, day - other.day, hours - other.hours,
                    minutes - other.minutes, seconds - other.seconds};
    result.Correct();
    return result;
}

std::string DateTime::Pretty() const {
    static std::string num[] = {"1st", "2nd", "3th", "4th"};
    static std::string week_day[] = {"MO", "TU", "WE", "TH", "FR", "SA", "SU"};
    static std::string month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                                        "September", "October", "November", "December"};
    return num[week_in_month()] + " " + week_day[(TotalDays() - 1) % 7] + " " + month_names[month];
}

std::string TimeClass::ToString() const {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year) +
           " " + std::to_string(hours) + ":" + std::to_string(minutes);
}

TimeClass::TimeClass(int year, int month, int day, int hours, int minutes, int seconds)
        : year(year), month(month), day(day), hours(hours), minutes(minutes), seconds(seconds) {
}


TimeClass::TimeClass(int year, int month, int day)
        : year(year), month(month), day(day) {}

bool TimeClass::operator<(TimeClass &other) const {
    return std::tie(this->year, this->month, this->day, this->hours, this->minutes, this->seconds)
           < std::tie(other.year, other.month, other.day, other.hours, other.minutes, other.seconds);

}

bool TimeClass::operator==(TimeClass &other) const {
    return std::tie(this->year, this->month, this->day, this->hours, this->minutes, this->seconds)
           == std::tie(other.year, other.month, other.day, other.hours, other.minutes, other.seconds);

}
