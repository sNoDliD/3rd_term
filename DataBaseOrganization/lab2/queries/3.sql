# найти все группы и количество студентов в которых преподователь [имя]

select classes.name, count(*) students_in_group
from classes
         inner join users u on classes.id = u.class_id
         inner join teachers t on classes.teacher_id = t.id
where t.name = ${teacher_name}
group by classes.id;