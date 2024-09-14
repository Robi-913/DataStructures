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

noduri* adaugare(noduri *p, int key, int poz){
    noduri *newnod=(noduri*) malloc(sizeof (noduri));
    noduri *itr=p;
    newnod->key=key;
    newnod->next=NULL;
    newnod->prev=NULL;
    int counter=0;
    poz--;

    while (itr->next!= NULL){
        counter++;
        itr=itr->next;
        if(counter == poz){
            newnod->next=itr->next;
            newnod->prev=itr;
            itr->next->prev=newnod;
            itr->next=newnod;
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

    int val=10;
    int poz=3;

    p=adaugare(p,val,poz);
    afisare(p);

    return 0;
}
