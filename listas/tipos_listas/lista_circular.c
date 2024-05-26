/*
Exercícios de listas encadeadas

Implemente funções para aumentar a utilidade das bibliotecas de listas
que estamos desenvolvendo. Faça para TODOS os tipos de lista que vimos:
- Lista Simplesmente Encadeada
- Lista Duplamente Encadeada
- Lista Simplesmente Encadeada Circular

Obs.: Já há um início das implementações nos arquivos lista.c, lista2.c e lista_circular.c.
      Preencha com código onde encontrar comentários "// COMPLETE AQUI"

----------------------------------------------------------------------------
1) Função que encontra dado na lista e remove (parecido com "remove" em python):
lista_t *lista_remove( lista_t *l, int d );

Exemplo:
l = 3->5->7  \
              -->  l = 3->7
d = 5        /

----------------------------------------------------------------------------
2) Função que junta duas listas "l1" e "l2" em outra lista "l": l = l1 -> l2
lista_t *lista_junta( lista_t *l1, lista_t *l2 );

Exemplo:
l1 = 3->5->7 \
              -->  l = 3->5->7->2->1->4
l2 = 2->1->4 /

----------------------------------------------------------------------------
3) Função que insere um novo dado "d" em uma lista "l" de forma ordenada (assuma que "l" já estava ordenada):
lista_t *lista_insere_ordenado( lista_t *l, int d );

Exemplo:
l = 3->5->7  \
              -->  l = 3->4->5->7
d = 4        /

----------------------------------------------------------------------------
4) Função RECURSIVA que imprime a lista do início ao fim:
void lista_imprime_recursivo( lista_t *l );

----------------------------------------------------------------------------
5) Função RECURSIVA que imprime a lista do fim ao início (ordem inversa):
void lista_imprime_inverso_recursivo( lista_t *l );

----------------------------------------------------------------------------

*/

#include "lista_circular.h"

/////////////////////////////////
lista_t *lista_remove( lista_t *l, int d ){
    if(l == NULL) {
        printf("Lista vazia");
        return NULL;
    }

    if (l->prox == l ){ // Um único nó
        if (l->x == d){
            free(l);
            l = NULL;
        }
        return l;
    }

    lista_t * aux = l;
    if (aux->x == d) {
        l = l->prox;
        free(aux);
        return l;
    }

    lista_t * anterior = l;
    aux = l->prox;
    while (aux != l) {
        if(aux->x == d) {
            anterior->prox = aux->prox;
            free(aux);
            break;
        }
        anterior = aux;
        aux = aux->prox;
    }

    return l;
}
/////////////////////////////////
lista_t *lista_junta( lista_t *l1, lista_t *l2 ){
    lista_t *l = lista_inicia();
    lista_t * aux;

    if (l1 != NULL) {
      l = lista_append(l, l1->x);
      aux = l1->prox;
      while(aux != l1) {
          l = lista_append(l, aux->x);
          aux = aux->prox;
      }
    }

    if (l1 != NULL) {
        l = lista_append(l, l2->x);
        aux = l2->prox;
        while(aux != l2) {
            l = lista_append(l, aux->x);
            aux = aux->prox;
        }
    }

    return l;
}
/////////////////////////////////
lista_t *lista_insere_ordenado_circ( lista_t *l, int d ){
    if( l == NULL) {
        l = lista_inicia();
        l = lista_append(l, d);
        return l;
    }

    if(l->x > d) {
        l = lista_push(l, d);
        return l;
    }

    lista_t *aux = l->prox;
    while (aux != l) {
        if(aux->x < d && (aux->prox == l || d < aux->prox->x )) {
            lista_t * new_node = (lista_t *) malloc(sizeof(lista_t));
            new_node->x = d;
            new_node->prox = aux->prox;
            aux->prox = new_node;
            break;
        }
        aux = aux->prox;
    }
    return l;
}
/////////////////////////////////
void lista_imprime_recursivo( lista_t *l ){
    if(l == NULL) {
        return;
    }

    printf("%d ", l->x);
    lista_imprime_recursivo(l->prox);
}

void lista_imprime_recursivo_circular(lista_t *l, lista_t *fim){
    printf("%d ", l->x);
    if(l->prox != fim) {
        lista_imprime_recursivo_circular(l->prox, fim);
    }
}
/////////////////////////////////
void lista_imprime_inverso_recursivo( lista_t *l ){
    if(l == NULL) {
        return;
    }

    lista_imprime_inverso_recursivo(l->prox);
    printf("%d ", l->x);

}

void lista_imprime_inverso_recursivo_circular( lista_t *l, lista_t * fim ){
    if(l->prox != fim) {
        lista_imprime_inverso_recursivo_circular(l->prox, fim);
    }
    printf("%d ", l->x);
}
/////////////////////////////////


/////////////////////////////////
lista_t *lista_inicia(void){
    return NULL;
}
/////////////////////////////////
void lista_termina( lista_t *l ){
    if ( l == NULL ) return;
    lista_t *aux = l;
    lista_t *para_liberar;
    do {
        para_liberar = aux;
        aux = aux->prox;
        free(para_liberar);
    } while (aux != l);
}
/////////////////////////////////
void lista_imprime( lista_t *l ){
    if ( l == NULL ) return;
    lista_t *aux = l;
    do {
        printf("%d ", aux->x);
        aux = aux->prox;
    } while ( aux != l );
}
/////////////////////////////////
lista_t *lista_append( lista_t *l, int d ){

    lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
    novo->x = d;
    novo->prox = l;

    if ( l == NULL ){
        novo->prox = novo;
        return novo;
    }

    lista_t *aux = l;
    while ( aux->prox != l ){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}
/////////////////////////////////
// adiciona no inicio
lista_t *lista_push( lista_t *l, int d ){
    l = lista_append(l,d);
    lista_t *aux = l;
    while ( aux->prox != l ){
        aux = aux->prox;
    }
    return aux;
}
/////////////////////////////////
// remove do inicio
lista_t *lista_pop( lista_t *l ){
    if ( l == NULL ) return NULL;
    if ( l->prox == l ){
        free(l);
        return NULL;
    }

    lista_t *aux = l;
    while ( aux->prox != l ){
        aux = aux->prox;
    }
    aux->prox = l->prox;
    free(l);
    return aux->prox;
}
/////////////////////////////////