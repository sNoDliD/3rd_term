#include <stdio.h>
#include <string.h>
#include "scripts/classes.h"

//#include <sys/stat.h>
//mkdir("/some/directory", 0700);

void printHelp();
void processCommands();
void doCommand(char* command, char* table);

TABLE enumTable(char* table);
void update(char* table);
void get(char* table);
void insert(char* table);
void delete(char* table);

int main() {
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
        int count = scanf("%s%s", command, table);

        if (strcasecmp(command, "end") == 0) {
            break;
        }

        if (count != 2){
            printf("Please, enter command and table again\n");
        }
        else{
            doCommand(command, table);
        }
    }
}


void doCommand(char* command, char* table) {
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
    printf("%s", "Invalid command\n");
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


void update(char *table) {

}


void get(char *table) {

}


void insert(char *table) {
    switch (enumTable(table)) {
        case LAB:
            break;
        case TEACHER:
            break;
        case CLASS:
            break;
        case USER_STATUS:
            break;
        case USER:
            break;
        case CHOICE:
            break;
        case KEY_ERROR:
            break;
    }
}


void delete(char *table) {

}
