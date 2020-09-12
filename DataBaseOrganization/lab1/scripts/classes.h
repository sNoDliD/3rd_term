#ifndef LAB1_CLASSES_H
#define LAB1_CLASSES_H

struct IndexStruct{
    int id;
    int address;
};
typedef struct IndexStruct Index;


struct TeacherStruct{
    int id;
    char name[32];
};
typedef struct TeacherStruct Teacher;


struct ClassStruct{
    int id;
    char name[32];
    int teacher_id;
};
typedef struct ClassStruct Class;


struct UserStatusStruct{
    int id;
    char name[32];
};
typedef struct UserStatusStruct UserStatus;


struct UserStruct{
    int id;
    int class_id;
    int status_id;
};
typedef struct UserStruct User;


struct LabStruct{
    int id;
    char name[32];
    char params[32];
    int class_id;
};
typedef struct LabStruct Lab;


struct ChoiceStruct{
    int lab_id;
    int user_id;
    char variant[32];
};
typedef struct ChoiceStruct Choice;

#endif //LAB1_CLASSES_H
