# Найти классы, в которых ни один студент не выбрал лабораторную с названием [X].

SELECT classes.name
FROM classes
WHERE classes.id NOT IN (SELECT DISTINCT l.class_id
                         FROM labs l
                                  INNER JOIN choice c on l.id = c.lab_id
                         WHERE l.name = ${lab_name});