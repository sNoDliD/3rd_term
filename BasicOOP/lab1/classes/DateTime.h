//
// Created by dima on 27.09.20.
//

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
+* за підтримку часових зон
+* за обчислення статистики, наприклад, на який день тижня найчастіше припадає 13 число (за даним діапазоном дат чи взагалі в календарі).
*/
//year, month, day) and time (hours, minutes, seconds)
class TimeClass{
private:
    friend bool operator <(TimeClass& left, TimeClass& right);
    friend bool operator ==(TimeClass& left, TimeClass& right);
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
};

class TimeDelta: TimeClass{

};

class DateTime: TimeClass{
    bool IsCorrect() const;
    bool IsLeap() const;

public:
    DateTime(int i, int i1, int i2);
};


#endif //LAB1_DATETIME_H
