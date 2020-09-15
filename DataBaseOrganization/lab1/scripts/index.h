#ifndef LAB1_INDEX_H
#define LAB1_INDEX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>


struct IndexStruct{
    int id;
    int row;
};
typedef struct IndexStruct Index;


size_t nextId(char* table){
    char path[64] = "run/tables/";
    mkdir("run", 0700);
    mkdir("run/tables", 0700);

    strncat(path, table, 16);
    strcat(path, ".ind");

    FILE* index_file = fopen(path, "a+");

    Index place;
    fseek(index_file, (long) -sizeof(Index), SEEK_END);
    fread(&place, sizeof(Index), 1, index_file);

    if (feof(index_file)){
        fclose(index_file);
        return 1;
    }
    fclose(index_file);
    return place.id + 1;
}

#endif //LAB1_INDEX_H
