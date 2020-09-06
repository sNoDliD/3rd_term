#include <stdio.h>
#include <stdlib.h>

struct NodeStruct{
    struct NodeStruct* next;
    int data;
};

typedef struct NodeStruct* List;
typedef struct NodeStruct Node;


/// It is my function
/// \param a ashka
/// \param b beshka
/// \param c tseshka
/// \return abetseshka
int fooo(int a, int b, int c){
    return a*b*c;
}

int main() {
    printf("%d", fooo(3,5,7));
//    List l = malloc(sizeof(Node));
//    l->data = 55;
//    l->next = malloc(sizeof(Node));
//    l->next->data = 66;
//    l->next->next = NULL;
//    for(Node* it = l; it; it=it->next){
//        printf("%d\n", it->data);
//    }
//    free(l);
//    l = NULL;

    return 0;
}
