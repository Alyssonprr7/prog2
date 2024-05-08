#include <stdio.h>
#include <stdlib.h>

struct _pilha_ {
    unsigned int dim;
    unsigned int len;
    int *dados;
};

typedef struct _pilha_ pilha_t;

pilha_t * inicia_pilha(int dim) {
    pilha_t* pilha_p = (pilha_t *) malloc(dim * sizeof(pilha_t));
    int* dados = (int*) malloc(dim*sizeof(int));

    pilha_p->dim = dim;
    pilha_p->dados = dados;
    pilha_p->len = 0;

    return pilha_p;
}

void deleta_pilha(pilha_t* pilha) {
    free(pilha->dados);
    free(pilha);
}

void push(pilha_t* pilha, int value) {
    if(pilha->len == pilha->dim) {
        printf("Pilha lotada");
        return;
    }

    pilha->dados[pilha->len] = value;
    pilha->len++;
}

int pop(pilha_t * pilha) {
    if (pilha->len == 0) {
        return 0;
    }

    int popped = pilha->dados[pilha->len -1];
    pilha->len --;
    return popped;


}

void print(pilha_t* pilha) {
    printf("PILHA\n");
    for (int i = pilha->len - 1; i >= 0; --i) {
        printf("%d\n", pilha->dados[i]);
    }

}

int main() {
    pilha_t * pilha = inicia_pilha(1000);
    print(pilha);
    push(pilha, 10);
    push(pilha, 2);
    push(pilha, 15);

    print(pilha);
    pop(pilha);
    pop(pilha);
    print(pilha);


    deleta_pilha(pilha);
    return 0;

}