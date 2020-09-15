#ifndef LAB1_TEACHER_H
#define LAB1_TEACHER_H
#include "common.h"


struct TeacherStruct{
    int id;
    char name[32];
};
typedef struct TeacherStruct Teacher;


void printTeachers(){

}


void insertTeacher(Teacher teacher) {

}


Teacher getTeacher(int id){
    Teacher teacher;
    teacher.id = 0;

    return teacher;
}


void deleteTeacher(Teacher teacher){

}


void updateTeacher(Teacher teacher){

}


#endif //LAB1_TEACHER_H
