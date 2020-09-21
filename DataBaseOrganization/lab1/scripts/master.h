#ifndef LAB1_MASTER_H
#define LAB1_MASTER_H

typedef struct
{
    int id;
    char name[32];
    char curator[64];
} Group;

//int index_m(int id){
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

Group get_m(){

}

void print_m(){

}


void insert_m(Group group) {

}


void delete_m(Group group){

}


void update_m(Group group){

}


int count_m(){
    FILE* file = fopen("run/tables/groups.ind", "a+");
    if (file){
        fclose(file);
    }
    return 0;
}

#endif //LAB1_MASTER_H
