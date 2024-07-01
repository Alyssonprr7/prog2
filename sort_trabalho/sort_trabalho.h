#ifndef SORT_TRABALHO_H
#define SORT_TRABALHO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"

// ARRAYS
/////////////////////////////////
void selection_sort_arr(int arr[], int size);
void bubble_sort_arr(int *v, unsigned int n);
void merge_sort_arr(int *v, unsigned int n);
/////////////////////////////////

/////////////////////////////////
void bubble_sort_lista(lista_t *l);
void selection_sort_lista(lista_t* l);
void merge_sort_lista(lista_t* l);
/////////////////////////////////

#endif //SORT_TRABALHO_H