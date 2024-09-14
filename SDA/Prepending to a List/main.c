#include <stdio.h>
#include <stdlib.h>

typedef struct nodep{
    int val;
    struct nodep *next;
}node;

void creare(node **curent, int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->val=val;
    temp->next=*curent;
    *curent=temp;
}

void inserareinceput(node **curent, int val){
    node *p=(node*)malloc(sizeof(node));
    p->val=val;
    p->next=*curent;
    *curent=p;
}

void printare(node *curent){
    if(curent == NULL)
        printf("Lista este goala");
    while (curent != NULL){
        printf("%d ",curent->val);
        curent=curent->next;
    }
}

int main() {
    node *curent=NULL;
    creare(&curent,9);
    creare(&curent,3);
    creare(&curent,42);
    creare(&curent,5);
    creare(&curent,78);
    creare(&curent,1);
    creare(&curent,8);
    creare(&curent,1);

    printare(curent);
    inserareinceput(&curent,1);
    printf("\n");
    printare(curent);

    return 0;
}
