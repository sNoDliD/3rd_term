#ifndef LAB1_MASTER_H
#define LAB1_MASTER_H

typedef struct
{
    int id;
    char name[32];
    char curator[64];
} Group;


Group get_m(int id){

}

void print_m(){

}


void insert_m() {
    Group group;
    int id;
    char curator[64];
    char name[32];

    while (1){
        scanf("%i", &id);
        if (get_index_by_id("groups.ind", id).id < 0){
            break;
        }
        printf("group id must be unique!\nTry again: ");
    }
    scanf("%s%s", curator, name);
    strncpy(group.name, name, sizeof(name));
    strncpy(group.curator, curator, sizeof(name));
    group.id = id;
}


void delete_m(Group group){

}


void update_m(Group group){

}


int count_m(){
    return count_rows("groups.ind");
}

#endif //LAB1_MASTER_H
