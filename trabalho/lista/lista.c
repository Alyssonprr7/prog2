#include "lista.h"

/////////////////////////////////
lista_t *lista_remove( lista_t *l, int d ){
    if(l == NULL) {
        printf("Lista vazia");
        return NULL;
    }

    lista_t * aux;
    lista_t * first = l;
    if (first->x == d) {
        first = l->prox;
        free(l);
        return first;
    }

    while (l != NULL) {
        if(l->x == d) {
            aux->prox = l->prox;
            free(l);
            break;
        }
        aux = l;
        l = l->prox;
    }

    return first;
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
        if(aux == l && aux->x > d) {
            lista_t * new_node = (lista_t *) malloc(sizeof(lista_t));
            new_node->x = d;
            new_node->prox = l->prox;
            l = new_node;
            break;
        } else if(aux->x < d && (aux->prox == NULL || d < aux->prox->x )) {
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
    printf("\n");
}
/////////////////////////////////
lista_t *lista_append( lista_t *l, int d ){

    lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
    novo->x = d;
    novo->prox = NULL;

    if ( l == NULL ) return novo;

    lista_t *aux = l;
    while ( aux->prox != NULL ){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}
/////////////////////////////////
// adiciona no inicio
lista_t *lista_push( lista_t *l, int d ){
    lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
    novo->x = d;
    novo->prox = l;
    return novo;
}
/////////////////////////////////
// remove do inicio
lista_t *lista_pop( lista_t *l ){

    lista_t *aux = l;
    l = l->prox;
    free(aux);

    return l;
}
/////////////////////////////////

void lista_selection_sort(lista_t* l) {
    if (l == NULL) return;
    lista_t * min, * aux_i, * aux_j;
    int aux;
    aux_i = l;

    while(aux_i->prox != NULL) { //Até o penultimo
        min = aux_i;
        aux_j = aux_i->prox;
        while (aux_j != NULL) {
            if (aux_j->x < min->x) {
                min = aux_j;
            }
            aux_j = aux_j->prox;
        }

        if(aux_i->x != min->x) {
            aux = aux_i->x;
            aux_i->x = min->x;
            min->x = aux;
        }

        aux_i = aux_i->prox;
    }
}