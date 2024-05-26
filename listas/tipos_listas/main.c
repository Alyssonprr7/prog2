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

#include <stdio.h>
#include <stdlib.h>

/*
Obs: Descomentar apenas um dos includes abaixo.

Para compilar: gcc -o exec main.c lista.c
           ou: gcc -o exec main.c lista2.c
           ou: gcc -o exec main.c lista_circular.c

A depender da biblioteca que você incluiu.
*/
//#include "lista.h"
//#include "lista_duplamente_encadeada.h"
#include "lista_circular.h"

int main( void ){

    lista_t *l1 = lista_inicia();
    lista_t *l2 = lista_inicia();

    l1 = lista_append( l1, 3 );
    l1 = lista_append( l1, 5 );
    l1 = lista_append( l1, 7 );


//    lista_imprime(l1);

    printf("l1 = ");
    //lista_imprime(l1);
//    lista_imprime_recursivo(l1);
    lista_imprime_recursivo_circular(l1, l1);
    printf("\n");

    printf("l1 inversa = ");
    lista_imprime_inverso_recursivo_circular(l1, l1);
    printf("\n");

    l1 = lista_insere_ordenado_circ( l1, 6 );
    l1 = lista_insere_ordenado_circ( l1, 4 );
    l1 = lista_insere_ordenado_circ( l1, 1 );
    l1 = lista_insere_ordenado_circ( l1, 100 );


    printf("l1 = ");
    lista_imprime(l1);
    printf("\n");

    l1 = lista_remove(l1, 5);
    printf("l1 = ");
    lista_imprime(l1);
    printf("\n");

    l2 = lista_append( l2, 8 );
    l2 = lista_append( l2, 22 );
    l2 = lista_append( l2, 77 );
//
//    printf("l2 = ");
//    //lista_imprime(l2);
//    lista_imprime_recursivo(l2);
//    printf("\n");
//
    lista_t *l3 = lista_junta( l1, l2 );

    printf("l3 = ");
    lista_imprime(l3);
    printf("\n");

    lista_termina(l1);
    lista_termina(l2);
    lista_termina(l3);

    return 0;
}