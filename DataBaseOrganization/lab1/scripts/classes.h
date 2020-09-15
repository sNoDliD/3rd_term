#ifndef LAB1_CLASSES_H
#define LAB1_CLASSES_H

#include "teacher.h"
#include "lab.h"

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
