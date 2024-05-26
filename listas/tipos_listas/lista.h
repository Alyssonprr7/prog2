#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct _no_ {
    int x; // dado armazenado no nó de uma lista
    struct _no_ *prox;
};
typedef struct _no_ lista_t;

// EXERCICIOS
/////////////////////////////////
lista_t *lista_remove( lista_t *l, int d );
lista_t *lista_junta( lista_t *l1, lista_t *l2 );
lista_t *lista_insere_ordenado( lista_t *l, int d );
void lista_imprime_recursivo( lista_t *l );
void lista_imprime_inverso_recursivo( lista_t *l );
/////////////////////////////////

/////////////////////////////////
lista_t *lista_inicia(void);
void lista_termina( lista_t *l );
/////////////////////////////////

/////////////////////////////////
void lista_imprime( lista_t *l );
/////////////////////////////////

/////////////////////////////////
lista_t *lista_append( lista_t *l, int d );
lista_t *lista_push( lista_t *l, int d );
lista_t *lista_pop( lista_t *l );
/////////////////////////////////

#endif // LISTA_H