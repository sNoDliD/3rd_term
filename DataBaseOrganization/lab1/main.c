#include <stdio.h>
#include <stdlib.h>

struct NodeStruct{
    struct NodeStruct* next;
    int data;
};

typedef struct NodeStruct* List;
typedef struct NodeStruct Node;

int main() {
    List l = malloc(sizeof(Node));
    l->data = 55;
    l->next = malloc(sizeof(Node));
    l->next->data = 66;
    l->next->next = NULL;
    for(Node* it = l; it; it=it->next){
        printf("%d\n", it->data);
    }
    return 0;
}
