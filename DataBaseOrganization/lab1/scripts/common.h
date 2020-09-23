#ifndef LAB1_COMMON_H
#define LAB1_COMMON_H

#include <stdio.h>
#include <string.h>

#include "index.h"
//#include "master.h"
#include "slave.h"

void create(const char* path){
    FILE* file = fopen(path, "a+");
    if (file){
        fclose(file);
    }
}


void initTables(){
    create("students.ind");
    create("students.fl");
    create("groups.ind");
    create("groups.fl");
}


void printHelp() {
    FILE* help_file = fopen("help.txt", "r");

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


int doCommand(char*);
int processCommands(){
    char command[32];

    while (1){
        printf("Your query: ");
        scanf("%s", command);

        if (strcasecmp(command, "end") == 0) {
            return 0;
        }

        if (doCommand(command) != 0){
            printf("Invalid input\n");
        }

    }
}


int doCommand(char* command) {
//    if (strcasecmp(command, "update")==0){
//        return update(table);
//    }
//    if (strcasecmp(command, "get")==0){
//        return get(table);
//    }
//    if (strcasecmp(command, "delete")==0){
//        return delete(table);
//    }
//    if (strcasecmp(command, "insert")==0){
//        return insert(table);
//    }

    return -1;
}

#endif //LAB1_COMMON_H
