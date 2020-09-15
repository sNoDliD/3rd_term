#ifndef LAB1_CLASS_H
#define LAB1_CLASS_H

struct ClassStruct{
    int id;
    char name[32];
    int teacher_id;
};
typedef struct ClassStruct Class;


void printClasses(){

}


void insertClass(Class class){

}


Class getClass(int id) {
    Class result;
    result.id = 0;

    return result;
}


void deleteClass(Class class){

}


void updateClass(Class class){

}


#endif //LAB1_CLASS_H
