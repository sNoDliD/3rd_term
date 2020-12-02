# Найти пары студентов с одной группы у которых совподают больше [количество] вариантов

select c1.user_id, c2.user_id
from choice c1
         inner join choice c2 on c1.variant = c2.variant and c1.lab_id = c2.lab_id
where c1.user_id < c2.user_id
group by c1.user_id, c2.user_id
having count(*) > ${repeat_more_then};