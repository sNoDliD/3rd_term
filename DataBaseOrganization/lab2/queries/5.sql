# имена преподователей у котрых есть студент который выполняют больше чем [Х] лаб

select distinct t.name
from choice
         inner join labs l on choice.lab_id = l.id
         inner join classes c on l.class_id = c.id
         inner join teachers t on c.teacher_id = t.id
group by choice.user_id, c.id
having count(*) > ${more_then};
