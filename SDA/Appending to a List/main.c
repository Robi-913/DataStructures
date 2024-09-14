#include <stdio.h>
#include <stdlib.h>

typedef struct nodp{
    int el;
    struct nodp *next;
}noduri;

void creare(noduri **curent, int key){
    noduri *temp=(noduri*) malloc(sizeof(noduri));
    temp->el=key;
    temp->next=*curent;
    *curent=temp;
}

void inserarenod(noduri *curent, int nod){
    noduri *p= malloc(sizeof (noduri));
    p->el=nod;
    p->next=NULL;
    while (curent->next != NULL){
        curent=curent->next;
    }
    curent->next=p;


}

void printare(noduri *curent){
    if(curent == NULL)
        printf("Lista este goala");
    while (curent != NULL){
        printf("%d ",curent->el);
        curent=curent->next;
    }
}

int main() {

    noduri *curent=NULL;
    creare(&curent,7);
    creare(&curent,6);
    creare(&curent,8);
    creare(&curent,0);
    creare(&curent,1);

    printare(curent);
    printf("\n");

    inserarenod(curent,12);
    printare(curent);


    return 0;
}
