# Найти все лабораторые с параметром [Х] и преподователем [Y]

select labs.id, labs.name
from labs
         inner join classes c on labs.class_id = c.id
         inner join teachers t on c.teacher_id = t.id
where t.name = ${teacher_name}
  and labs.params = ${param};