# Найти студентов выбранные варианты которых выбрал студент [X]

select u.id
from users u
where not exists(select lab_id, user_id
                 from choice c
                 where c.user_id = u.id
                   and (c.lab_id, c.variant) not in (select c2.lab_id, c2.variant
                                                     from choice c2
                                                     where c2.user_id = ${user_id})
    )
  and exists(select * from choice where user_id = u.id)
  and u.id != ${user_id};
