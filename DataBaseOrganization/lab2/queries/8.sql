# Найти учеников которые выполняют все те лабы что задал преподователь [X]

select u.id
from users u
         left join classes c on c.id = u.class_id
         left join teachers t on t.id = c.teacher_id
where t.name = ${teacher}
  and not exists(select *
                 from labs l
                          left join classes c on l.class_id = c.id
                 where c.teacher_id = t.id
                   and l.class_id = u.class_id
                   and l.id not in (select lab_id from choice where user_id = u.id))

  and exists(select *
             from choice
             where user_id = u.id);
