#ifndef LAB1_DATETIME_H
#define LAB1_DATETIME_H


#include <string>
/*
(**)Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди).
 Перевірка правильності дати та часу відповідно до григоріанського календаря.
 Арифметика моментів часу: різниця між двома моментами часу у заданих одиницях,
 додавання чи віднімання такої різниці до заданого моменту часу. Обчислення дня тижня для заданої дати.
+* за обчислення додаткових параметрів, наприклад, номер тижня в місяці та в році
+* за альтернативні варіанти побудови дати та часу (наприклад, «перший вівторок листопада»)
*/

class TimeClass{
public:
    int year = 0;
    int month = 0;
    int day = 0;

    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    TimeClass(int year, int month, int day, int hours, int minutes, int seconds);
    TimeClass(int year, int month, int day);
    TimeClass() = default;
    std::size_t TotalDays() const;
    std::string ToString() const;

    bool operator <(TimeClass& other) const;
    bool operator ==(TimeClass& other) const;
};

class TimeDelta: public TimeClass{
    using TimeClass::TimeClass;
};

class DateTime: public TimeClass{
    bool IsCorrect() const;
    bool IsLeap() const;
    void Correct();
public:
    using TimeClass::TimeClass;
    std::size_t week_in_month() const;
    std::size_t week_in_year() const;
    std::string Pretty() const;
    TimeDelta operator -(TimeClass& other) const;
    DateTime operator +(TimeDelta& other) const;
    DateTime operator -(TimeDelta& other) const;
};


#endif //LAB1_DATETIME_H
