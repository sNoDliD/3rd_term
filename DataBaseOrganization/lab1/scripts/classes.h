#ifndef LAB1_CLASSES_H
#define LAB1_CLASSES_H

enum TABLE_ENUM{
    LAB,
    TEACHER,
    CLASS,
    USER_STATUS,
    USER,
    CHOICE,

    KEY_ERROR,
};
typedef enum TABLE_ENUM TABLE;


struct IndexStruct{
    int id;
    int row;
};
typedef struct IndexStruct Index;


struct TeacherStruct{
    int id;
    char name[32];
};
typedef struct TeacherStruct Teacher;
void printTeachers();
void insertTeacherStruct(Teacher);
Teacher getTeacherStruct(int id);
void deleteTeacherStruct(Teacher);
void updateTeacherStruct(Teacher);


struct ClassStruct{
    int id;
    char name[32];
    int teacher_id;
};
typedef struct ClassStruct Class;
void printClasses();
void insertClassStruct(Class);
Class getClassStruct(int id);
void deleteClassStruct(Class);
void updateClassStruct(Class);


struct UserStatusStruct{
    int id;
    char name[32];
};
typedef struct UserStatusStruct UserStatus;
void printUserStatuses();
void insertUserStatusStruct(UserStatus);
UserStatus getUserStatusStruct(int id);
void deleteUserStatusStruct(UserStatus);
void updateUserStatusStruct(UserStatus);


struct UserStruct{
    int id;
    int class_id;
    int status_id;
};
typedef struct UserStruct User;
void printUsers();
void insertUserStruct(User);
User getUserStruct(int id);
void deleteUserStruct(User);
void updateUserStruct(User);


struct LabStruct{
    int id;
    char name[32];
    char params[32];
    int class_id;
};
typedef struct LabStruct Lab;
void printLabs();
void insertLabStruct(UserStatus);
UserStatus getLabStruct(int id);
void deleteLabStruct(UserStatus);
void updateLabStruct(UserStatus);


struct ChoiceStruct{
    int lab_id;
    int user_id;
    char variant[32];
};
typedef struct ChoiceStruct Choice;
void printChoices();
void insertChoiceStruct(Choice);
Choice getChoiceStruct(int id);
void deleteChoiceStruct(Choice);
void updateChoiceStruct(Choice);

#endif //LAB1_CLASSES_H
