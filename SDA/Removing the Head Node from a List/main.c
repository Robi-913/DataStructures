#include <stdio.h>
#include <stdlib.h>

typedef struct nodep{
    int key;
    struct nodep *next;
}noduri;

void creare(noduri **p, int val){
    noduri *temp = (noduri*) malloc(sizeof (noduri));
    temp->key=val;
    temp->next=*p;
    *p=temp;
}

struct nodep* stergerenodprim(noduri *p){
    if(p == NULL)
        printf("Lista este goala");
    else{
        noduri *t=p;
        p=p->next;
        free(t);
    }
    return p;
}

void afisare(noduri *p){
    if(p == NULL)
        printf("Lista este goala");
    while (p != NULL){
        printf("%d ",p->key);
        p=p->next;
    }
}

int main() {

    noduri *p;
    creare(&p,9);
    creare(&p,9);
    creare(&p,9);
    creare(&p,9);
    creare(&p,9);
    creare(&p,4);
    afisare(p);


    printf("\n");

    p=stergerenodprim(p);
    afisare(p);


    return 0;
}
