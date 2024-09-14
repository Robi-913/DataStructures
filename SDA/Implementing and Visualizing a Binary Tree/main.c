#include <stdio.h>
#include <stdlib.h>

typedef struct binary {
    int key;
    struct binary *left;
    struct binary *right;
} tree;

tree *creareroot(int key) {
    tree *p = malloc(sizeof(tree));
    if (p != NULL) {
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}


tree *crearetree(tree *p, int data) {
    if (p == NULL) {
        return creareroot(data);
    } else if (data == p->key) {
        return p;
    } else if (data < p->key) {
        p->left = crearetree(p->left, data);
    } else {
        p->right = crearetree(p->right, data);
    }
    return p;
}

tree *cautareel(tree *p, int data) {
    if (p == NULL) return NULL;
    else if (p->key == data) return p;
    else if (data <= p->key)return cautareel(p->left, data);
    else return cautareel(p->right, data);
}

void afisare(tree *p) {
    if (p == NULL) {
        printf("Copacul este gol ");
        return;
    }
    printf("%d ", p->key);
    printf("l:");
    afisare(p->left);
    printf("r:");
    afisare(p->right);

}

int main() {
    tree *p = NULL;

     p= creareroot(12);

    p = crearetree(p, 9);
    p = crearetree(p, 7);
    p = crearetree(p, 5);
    p = crearetree(p, 3);
    p = crearetree(p, 8);

    afisare(p);

    return 0;
}
