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

void inserare(noduri *p, int val, int poz){
    noduri *temp = (noduri*) malloc(sizeof (noduri));
    temp->key=val;
    temp->next=NULL;
    int counter=0;
    poz--;
    while (p != NULL){
        counter++;
        p=p->next;
        if(counter == poz){
            temp->next=p->next;
            p->next=temp;
        }
    }
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
    creare(&p,9);
    afisare(p);

    int val, poz;
    printf("Intoduceti valoarea si pozitia:");
    scanf("%d %d",&val, &poz);

    printf("\n");

    inserare(p,val,poz);
    afisare(p);


    return 0;
}
