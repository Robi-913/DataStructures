#include <stdio.h>
#include <stdlib.h>

typedef struct nodep {
    int key;
    struct nodep *next;
} Nod;

void creare(Nod **curent, int key) {
    Nod *head = (Nod *) malloc(sizeof(Nod));
    head->key = key;
    head->next = *curent;
    *curent = head;

}

void printare(Nod *curent) {
    if (curent == NULL)
        printf("Lista este goala");
    while (curent != NULL) {
        printf("%d ", curent->key);
        curent = curent->next;
    }
}

void inversare(Nod **curent) {
    Nod *urmatorul = NULL;
    Nod *prezent = *curent;
    Nod *anteriorul = NULL;

    while (prezent != NULL) {
        urmatorul = prezent->next;
        prezent->next = anteriorul;
        anteriorul = prezent;
        prezent = urmatorul;

    }
  *curent=anteriorul;

}

int main() {
    Nod *curent = NULL;
    creare(&curent, 35);
    creare(&curent, 13);
    creare(&curent, 67);
    creare(&curent, 31);
    creare(&curent, 29);
    creare(&curent, 60);
    printf("Lista initiala:");
    printare(curent);

    inversare(&curent);
    printf("\nLista inversa:");
    printare(curent);


    return 0;
}
