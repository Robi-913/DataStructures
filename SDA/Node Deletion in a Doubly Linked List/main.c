#include <stdio.h>
#include <stdlib.h>

typedef struct nodep{
    int key;
    struct nodep * next, *prev;
}noduri;

noduri* inserare(noduri *p, int key){
    noduri *t=(noduri*) malloc(sizeof (noduri));
    t->key=key;
    t->next=NULL;
    t->prev=NULL;
    if(p != NULL){
        t->next=p;
        p->prev=t;
    }
    p=t;
    return p;
}

noduri* stergere(noduri *p, int poz){
    noduri *t=p;
    int counter=0;
    poz--;
    while (t != NULL){
        counter++;
        t=t->next;
        if(poz==counter){
            noduri *aux=t;
            t->next->prev=t;
            t->prev->next=t->next;
            free(aux);
            break;
        }
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

    noduri *p=NULL;
    p=inserare(p,1);
    p=inserare(p,2);
    p=inserare(p,3);
    p=inserare(p,4);
    p=inserare(p,5);
    p=inserare(p,6);
    afisare(p);

    printf("\n");

    int poz=2;

    p=stergere(p,poz);
    afisare(p);

    return 0;
}
