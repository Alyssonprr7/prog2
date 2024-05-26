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

#include "lista_duplamente_encadeada.h"

/////////////////////////////////
lista_t *lista_remove( lista_t *l, int d ){
    if(l == NULL) {
        printf("Lista vazia");
        return NULL;
    }

    lista_t * aux = l;
    if (aux->x == d) {
        l = l->prox;
        l->ante = NULL;
        free(aux);
        return l;
    }

    while (aux != NULL) {
        if(aux->x == d) {
            if (aux->prox != NULL) {
                aux->ante->prox = aux->prox;
                aux->prox->ante = aux->ante;
            } else {
                aux->ante->prox = NULL;
            }
            free(aux);
            break;
        }
        aux = aux->prox;
    }

    return l;
}
/////////////////////////////////
lista_t *lista_junta( lista_t *l1, lista_t *l2 ){
    if(l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }

    lista_t *l = lista_inicia();
    while (l1 != NULL) {
        l = lista_append(l, l1->x);
        l1 = l1->prox;
    }

    while (l2 != NULL) {
        l = lista_append(l, l2->x);
        l2 = l2->prox;
    }
    return l;
}
/////////////////////////////////
lista_t *lista_insere_ordenado( lista_t *l, int d ){
    lista_t *aux = l;
    while (aux != NULL) {
        if(aux->x > d && aux->ante == NULL) {
            lista_t * new_node = (lista_t *) malloc(sizeof(lista_t));
            new_node->x = d;
            new_node->prox = aux;
            new_node->ante = NULL;
            aux->ante = new_node;
            l = new_node;
            break;
        } else if(aux->x < d && (aux->prox == NULL || d < aux->prox->x )) {
            lista_t * new_node = (lista_t *) malloc(sizeof(lista_t));
            new_node->x = d;
            new_node->prox = aux->prox;
            new_node->ante = aux;
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
/////////////////////////////////
void lista_imprime_inverso_recursivo( lista_t *l ){
    if(l == NULL) {
        return;
    }

    lista_imprime_inverso_recursivo(l->prox);
    printf("%d ", l->x);
}
/////////////////////////////////


/////////////////////////////////
lista_t *lista_inicia(void){
    return NULL;
}
/////////////////////////////////
void lista_termina( lista_t *l ){
    lista_t *aux;
    while ( l != NULL ){
        aux = l;
        l = l->prox;
        free(aux);
    }
}
/////////////////////////////////
void lista_imprime( lista_t *l ){
    lista_t *aux = l;
    while ( aux != NULL ){
        printf("%d ", aux->x);
        aux = aux->prox;
    }
}
/////////////////////////////////
void lista_imprime_inverso( lista_t *l ){
    lista_t *aux = l;
    while ( aux->prox != NULL ){
        aux = aux->prox;
    }
    while ( aux != NULL ){
        printf("%d ", aux->x);
        aux = aux->ante;
    }
}
/////////////////////////////////
lista_t *lista_append( lista_t *l, int d ){

    lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
    novo->x = d;
    novo->ante = NULL;
    novo->prox = NULL;

    if ( l == NULL ) return novo;

    lista_t *aux = l;
    while ( aux->prox != NULL ){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ante = aux;

    return l;
}
/////////////////////////////////
// adiciona no inicio
lista_t *lista_push( lista_t *l, int d ){
    lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
    novo->x = d;
    novo->ante = NULL;
    novo->prox = l;

    l->ante = novo;

    return novo;
}
/////////////////////////////////
// remove do inicio
lista_t *lista_pop( lista_t *l ){

    lista_t *aux = l;
    l = l->prox;
    l->ante = NULL;
    free(aux);

    return l;
}
/////////////////////////////////