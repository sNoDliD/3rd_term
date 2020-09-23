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


int file_size(char* file_name){
    FILE* fp = fopen(file_name, "rb");

    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    int res = (int) ftell(fp);
    fclose(fp);
    return res;
}


int count_rows(char* file_name){
    return file_size(file_name) / (int) sizeof(Index);
}


Index get_index_by_row(char* file_name, int row){
    Index index;
    FILE* fp = fopen(file_name, "rb");

    fseek(fp, 0L, SEEK_END);

    int res = (int) ftell(fp);
    fclose(fp);
    return index;
}


int b_search(char* file_name, int id){
    int size = count_rows(file_name);
    int borders[2] = {0, size - 1};
    int middle = 0;
    Index index;
    index.id = -1;

    while (borders[0] <= borders[1]){
        middle = (borders[0] + borders[1]) / 2;

        index = get_index_by_row(file_name, middle);
        if (id == index.id){
            return middle;
        }
        borders[id < index.id] = middle + 1 - 2 * (id < index.id);
    }

    return -1 - (middle + 1 * (index.id < id));
}


Index get_index_by_id(char* file_name, int id){
    Index index;

    int offset = b_search(file_name, id);
    if (offset < 0){
        index.id = -1;
        return index;
    }

    FILE* fp = fopen(file_name, "rb");
    fseek(fp, (long) sizeof(Index) * offset, SEEK_SET);
    fread(&index, sizeof(Index), 1, fp);
    fclose(fp);

    return index;
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
