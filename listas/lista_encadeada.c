/*
Exercicio de Listas Encadeadas

Proposta: Implementar funções que aumentem a utilidade da nossa lista.

Obs.: Teste TODAS suas funções na main.

1) Função que determina e retorna o tamanho (quantidade de nós) de uma lista:
unsigned int lista_tamanho( lista_t *l );

2) Função que encontra e retorna o dado máximo armazenado numa lista:
int lista_max( lista_t *l );

3) Função para encontrar um dado na lista e retornar um ponteiro para o nó em questão:
lista_t *lista_encontra_no( lista_t *l, int d );

4) Função para encontrar um dado na lista e retornar o índice de sua posição na lista:
unsigned int lista_encontra_indice( lista_t *l, int d );

5) Função para inverter uma lista (fim -> inicio):
lista_t *lista_inverte( lista_t *l );

*/

#include <stdio.h>
#include <stdlib.h>

struct _no_ {
    int x; // dado armazenado no nó de uma lista
    struct _no_ *prox;
};
typedef struct _no_ lista_t;

lista_t *lista_inicia(void){
    lista_t *p = NULL;
    return p;
}

void lista_termina( lista_t *l ){
    lista_t *aux;
    while ( l != NULL ){
        aux = l;
        l = l->prox;
        free(aux);
    }
}

lista_t *lista_append( lista_t *l, int d ){

    lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
    novo->x = d;
    novo->prox = NULL;

    if ( l == NULL ){
        l = novo;
        return l;
    }

    lista_t *aux = l;
    while ( aux->prox != NULL ){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}

void lista_imprime( lista_t *l ){
    lista_t *aux = l;
    while ( aux != NULL ){
        printf("%d ", aux->x);
        aux = aux->prox;
    }
}

// remove do inicio
lista_t *lista_pop( lista_t *l ){

    lista_t *aux = l;
    l = l->prox;
    free(aux);

    return l;
}

//1) Função que determina e retorna o tamanho (quantidade de nós) de uma lista:
unsigned int lista_tamanho( lista_t *l ){
    unsigned int tam = 0;
    while(l != NULL) {
        l = l->prox;
        tam++;
    }
    return tam;
}

//2) Função que encontra e retorna o dado máximo armazenado numa lista:
int lista_max( lista_t *l ){
    int max = 0;
    while(l != NULL) {
        if(l->x > max) {
            max = l->x;
        }
        l = l->prox;
    }
    return max;
}

//3) Função para encontrar um dado na lista e retornar um ponteiro para o nó em questão:
lista_t *lista_encontra_no( lista_t *l, int d ){
    lista_t *no = NULL;
    while(l != NULL) {
        if(l->x == d) {
            no = l;
            break;
        }
        l = l->prox;
    }
    return no;
}

//4) Função para encontrar um dado na lista e retornar o índice de sua posição na lista:
int lista_encontra_indice( lista_t *l, int d ){
    int id = -1;
    int index = 0;
    while(l != NULL) {
        if(l->x == d) {
            id = index;
            break;
        }
        l = l->prox;
        index++;
    }
    return id >= 0 ? id : -1;
}

//5) Função para inverter uma lista (fim -> inicio):
lista_t *lista_inverte( lista_t *l ){
    if ( l == NULL ) return NULL;
    if ( l->prox == NULL ) return l;
    lista_t * aux = l->prox;
    lista_t * anterior = l;
    lista_t * atual;
    anterior->prox = NULL;

    while(aux != NULL) {
        atual = aux;
        aux = aux->prox;
        atual->prox = anterior;
        anterior = atual;
    }

    return atual;
}

int main( void ){

    lista_t *l = lista_inicia();

    l = lista_append( l, 3 );
    l = lista_append( l, 5 );
    l = lista_append( l, 8 );
    l = lista_append( l, 1 );
    l = lista_append( l, 7 );

    lista_imprime(l);
    printf("\n");

    unsigned int tamanho = lista_tamanho(l);
    printf("Tamanho da lista: %u\n", tamanho);
    printf("Valor máximo da lista: %d\n", lista_max(l));

//    lista_t * no_encontrado = lista_encontra_no(l, 128);
//    if(no_encontrado != NULL) {
//        printf("Encontrar nó: %d\n", no_encontrado->x);
//    } else {
//        printf("Nenhum nó com esse valor foi encontrado\n");
//    }

    int indice_no_encontrado = lista_encontra_indice(l, 18);
    if(indice_no_encontrado != -1) {
        printf("Encontrar nó indice: %d\n", indice_no_encontrado);
    } else {
        printf("Nenhum nó com esse valor foi encontrado\n");
    }

    l = lista_pop(l);
    l = lista_pop(l);

//    lista_imprime(l);
//    printf("\n");

    tamanho = lista_tamanho(l);
    printf("Tamanho da lista: %u\n", tamanho);

    lista_t* invertida = lista_inverte(l);
    lista_imprime(invertida);

    lista_termina(l);

    return 0;
}

