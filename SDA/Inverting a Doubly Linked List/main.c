#include <stdio.h>
#include <stdlib.h>

typedef struct nodep{
    int val;
    struct nodep *next, *priv;
}nod;

nod* adaugare(nod* p, int val){
    nod *t=(nod*) malloc(sizeof (nod));
    t->val=val;
    t->next=NULL;
    t->priv=NULL;

    if(p != NULL){
        t->next=p;
        p->priv=t;
    }
    p=t;

    return p;
}

nod* inversare(nod *p){
    nod* prezent=p;
    nod* urmator=prezent->next;

    prezent->next=NULL;
    prezent->priv=urmator;

    while (urmator != NULL){
        urmator->priv=urmator->next;
        urmator->next=prezent;
        prezent=urmator;
        urmator=urmator->priv;
    }
    p=prezent;

    return p;
}

void afisare(nod *p){
    if(p == NULL)
        printf("Lista este goala");
    while (p != NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}

int main() {
    nod *p=NULL;
    p=adaugare(p,8);
    p=adaugare(p,7);
    p=adaugare(p,6);
    p=adaugare(p,5);
    p=adaugare(p,4);

    afisare(p);

    printf("\n");
    p=inversare(p);
    afisare(p);


    return 0;
}
