#include <stdio.h>
#include <stdlib.h>

typedef struct nodp{
    int element;
    struct nodp *next;
}noduri;

void inserare(noduri **nod, int key){
    noduri *temp=(noduri*) malloc(sizeof(noduri));
    temp->element=key;
    temp->next=*nod;
    *nod=temp;
}

void cautare(noduri *nod, int poz){
    noduri *p=nod;
    int counter=0;
    while (p != NULL){
        counter++;
        p=p->next;
        if(counter==poz-1){
            nod=p;
            printf("%d",nod->element);
            p=NULL;
        }
    }
}

void printare(noduri *nod){
    if(nod==NULL)
        printf("Lista este goala");
    while (nod != NULL){
        printf("%d ",nod->element);
        nod=nod->next;
    }
}

int main() {

    noduri *nod=NULL;
    inserare(&nod,7);
    inserare(&nod,6);
    inserare(&nod,4);
    inserare(&nod,3);
    inserare(&nod,2);

    printare(nod);
    int poz=0;
    printf("Intoduceti pozitia dorita:");
    scanf("%d",&poz);
    cautare(nod,poz);

    return 0;
}
