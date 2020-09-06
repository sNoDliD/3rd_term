CREATE TABLE IF NOT EXISTS teachers(
    id INT,
    name VARCHAR(255),

    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS classes(
    id INT AUTO_INCREMENT,
    name VARCHAR(255),
    teacher_id INT,

    PRIMARY KEY(id),
    FOREIGN KEY(teacher_id) REFERENCES teachers(id)
);

CREATE TABLE IF NOT EXISTS users_statuses(
    id INT AUTO_INCREMENT,

    name VARCHAR(255),
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS users(
    id INT,
    class_id INT NOT NULL,
    status_id INT NOT NULL,

    PRIMARY KEY(id),
    Foreign Key(class_id) REFERENCES classes(id) ON DELETE CASCADE,
    Foreign Key(status_id) REFERENCES users_statuses(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS labs(
    id INT,
    name VARCHAR(255) NOT NULL,
    params VARCHAR(255) NOT NULL,
    class_id INT,

    PRIMARY KEY(id),
    FOREIGN KEY(class_id) REFERENCES classes(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS choice(
    lab_id INT NOT NULL ,
    user_id INT NOT NULL ,

    variant VARCHAR(255) DEFAULT NULL,

    FOREIGN KEY(lab_id) REFERENCES labs(id) ON DELETE CASCADE,
    FOREIGN KEY(user_id) REFERENCES users(id) ON DELETE CASCADE
);

