# Найти учеников, которые не выбирали вариант [Х] в лабораторноых преподователя [Y]

select user_id
from choice
         inner join labs l on choice.lab_id = l.id
         inner join classes c on l.class_id = c.id
         inner join teachers t on c.teacher_id = t.id
where choice.variant <> ${variant}
  and t.name = ${teacher};