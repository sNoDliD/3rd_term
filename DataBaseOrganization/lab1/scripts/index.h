#ifndef LAB1_INDEX_H
#define LAB1_INDEX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>


typedef struct {
    int id;
    int row;
} Index;


long int file_size(char* file_name){
    FILE* fp = fopen(file_name, "r");

    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    long int res = ftell(fp);
    fclose(fp);
    return res;
}


/*
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
return place.id + 1;*/


//int find_id(char* table, int id, size_t struct_size){
//    int size = 5;
//    int borders[2] = {0, size - 1};
//    int middle;
//    while (borders[0] <= borders[1]){
//        middle = (borders[0] + borders[1]) / 2;
//
//        if (id == arr[middle]){
//            return middle;
//        }
//        borders[id < arr[middle]] = middle + 1 - 2 * (x < arr[middle]);
//    }
//
//    return -1 - (middle + 1 * (arr[middle] < x));
//}
#endif //LAB1_INDEX_H
