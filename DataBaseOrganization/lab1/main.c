#include <stdio.h>
#include <string.h>
#include "scripts/classes.h"
#include "scripts/common.h"

void printHelp();
void processCommands();
int doCommand(char* command, char* table);

TABLE enumTable(char* table);
int update(char* table);
int get(char* table);
int insert(char* table);
int delete(char* table);


int insertTeacher();
int getTeacher();
int deleteTeacher();
int updateTeacher();

int insertLab();
int getLab();
int deleteLab();
int updateLab();

int insertUserStatus();
int getUserStatus();
int deleteUserStatus();
int updateUserStatus();

int insertClass();
int getClass();
int deleteClass();
int updateClass();

int insertUser();
int getUser();
int deleteUser();
int updateUser();

int insertChoice();
int getChoice();
int deleteChoice();
int updateChoice();

int main() {
//    int id = nextId("user");
    printHelp();
    processCommands();

    return 0;
}


void printHelp() {
    FILE* help_file = NULL;
    help_file = fopen("run/help.txt", "r");

    if (help_file){
        char buff[255];
        while (1){
            fgets(buff, sizeof(buff), (FILE*)help_file);
            if (feof(help_file)){
                break;
            }
            printf("%s", buff );
        }
        fclose(help_file);
    } else{
        printf("%s", "can't find help file\n");
    }
}


void processCommands(){
    char command[32];
    char table[32];

    while (1){
        printf("Your query: ");
        int count = scanf("%s%s", command, table);

        if (strcasecmp(command, "end") == 0) {
            break;
        }

        if (count != 2){
            printf("Please, enter command and table again\n");
        }
        else{
            if (doCommand(command, table) != 0){
                printf("Invalid input\n");
            }
        }
    }
}


int doCommand(char* command, char* table) {
    if (strcasecmp(command, "update")==0){
        return update(table);
    }
    if (strcasecmp(command, "get")==0){
        return get(table);
    }
    if (strcasecmp(command, "delete")==0){
        return delete(table);
    }
    if (strcasecmp(command, "insert")==0){
        return insert(table);
    }

    return -1;
}


TABLE enumTable(char *table) {
    if (strcasecmp(table, "lab")==0){
        return LAB;
    }
    if (strcasecmp(table, "teacher")==0){
        return TEACHER;
    }
    if (strcasecmp(table, "class")==0){
        return CLASS;
    }
    if (strcasecmp(table, "choice")==0){
        return CHOICE;
    }
    if (strcasecmp(table, "userStatus")==0){
        return USER_STATUS;
    }
    if (strcasecmp(table, "user")==0){
        return USER;
    }

    return KEY_ERROR;
}


int update(char *table) {
    switch (enumTable(table)) {
        case LAB:
            return updateLab();
        case TEACHER:
            return updateTeacher();
        case CLASS:
            return updateClass();
        case USER_STATUS:
            return updateUserStatus();
        case USER:
            return updateUser();
        case CHOICE:
            return updateChoice();
        case KEY_ERROR:
            return -1;
    }
}


int get(char *table) {
    switch (enumTable(table)) {
        case LAB:
            return getLab();
        case TEACHER:
            return getTeacher();
        case CLASS:
            return getClass();
        case USER_STATUS:
            return getUserStatus();
        case USER:
            return getUser();
        case CHOICE:
            return getChoice();
        case KEY_ERROR:
            return -1;
    }
}


int insert(char *table) {
    switch (enumTable(table)) {
        case LAB:
            return insertLab();
        case TEACHER:
            return insertTeacher();
        case CLASS:
            return insertClass();
        case USER_STATUS:
            return insertUserStatus();
        case USER:
            return insertUser();
        case CHOICE:
            return insertChoice();
        case KEY_ERROR:
            return -1;
    }
}



int delete(char *table) {
    switch (enumTable(table)) {
        case LAB:
            return deleteLab();
        case TEACHER:
            return deleteTeacher();
        case CLASS:
            return deleteClass();
        case USER_STATUS:
            return deleteUserStatus();
        case USER:
            return deleteUser();
        case CHOICE:
            return deleteChoice();
        case KEY_ERROR:
            return -1;
    }
}
