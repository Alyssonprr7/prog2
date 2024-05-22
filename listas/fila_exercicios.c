/*
Exercicio de Filas com array

Proposta: Completar o código abaixo para implementar funções que lidam com filas

Obs.: Teste TODAS suas funções na main.

Obs.2: Similar à implementação das pilhas com array (ver arquivo pilha.c)

Lembrando:

-> PILHA é uma estrutura de dados linear que segue a regra LIFO (Last In, First Out == último a entrar, primeiro a sair). Temos as operações de PUSH (inserção) e POP (remoção).
Exemplo:

minha_pilha = |  2  |
              |  1  |
              |  5  |
              -------

PUSH( minha_pilha, 4 );

minha_pilha = |  4  |
              |  2  |
              |  1  |
              |  5  |
              -------

POP( minha_pilha );  // 2x POP
POP( minha_pilha );

minha_pilha = |  1  |
              |  5  |
              -------

-> FILA é uma estrutura de dados linear que segue a regra FIFO (First In, First Out == primeiro a entrar, primeiro a sair). Também podemos chamar as operações de PUSH (inserção) e POP (remoção), mas elas não tem o mesmo comportamento da pilha. Na FILA, dados entram no fim e saem do início.
Exemplo:

minha_fila = |  2  |  (fim)
             |  1  |
             |  5  |
             -------  (inicio)

PUSH( minha_fila, 4 );

minha_fila = |  4  | (fim)
             |  2  |
             |  1  |
             |  5  |
             ------- (inicio)

POP( minha_fila );  // 2x POP
POP( minha_fila );

minha_fila = |  4  | (fim)
             |  2  |
             ------- (inicio)

*/

#include <stdio.h>
#include <stdlib.h>

struct _fila_ {
    unsigned int dim;
    unsigned int len;
    int *dados;
};

typedef struct _fila_ fila_t;

fila_t * fila_inicia(unsigned int dim){
    fila_t *nova_fila = (fila_t *) malloc(sizeof(fila_t));
    nova_fila->dim = dim;
    nova_fila->len = 0;
    nova_fila->dados = (int *) malloc(sizeof(int)*dim);
    return nova_fila;
}

void fila_termina( fila_t *f ){
    free(f->dados);
    free(f);
}

void fila_push(fila_t *f, int d){
    if(f->len == f->dim) {
        printf("A lista está cheia\n");
        return;
    }
    f->dados[f->len] = d;
    f->len++;
}

int fila_pop(fila_t *f){
    if(f->len <= 0) {
        printf("A lista está vazia\n");
        return -1;
    }
    int valor_removido =  f->dados[0];
    for (int i = 1; i < f->len; ++i) {
        f->dados[i-1] = f->dados[i]; //Shiftando os dados para a esquerda
    }
    f->len--;
    return valor_removido;
 }

void fila_imprime(fila_t *f){
    if (f->len > 0) {
        for (int i = 0; i < f->len; ++i) {
            printf("%d\t", f->dados[i]);
        }
        printf("\n");
        return;
    }

    scanf("A lista está vazia");
}


int main(void){

    fila_t *minha_fila = fila_inicia(1000);

    fila_push( minha_fila, 2 );
    fila_push( minha_fila, 4 );
    fila_push( minha_fila, 6 );
    fila_push( minha_fila, 3 );

    fila_imprime( minha_fila );
    printf("\n");

    int x;
    x = fila_pop( minha_fila );
    printf("Valor removido %d\n", x);
    x = fila_pop( minha_fila );
    printf("Valor removido %d\n", x);

    fila_imprime( minha_fila );
    printf("\n");

    fila_termina( minha_fila );

    return 0;
}