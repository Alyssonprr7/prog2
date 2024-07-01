#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"
#include "sort_trabalho.h"

void print_arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf(" %d", arr[i]);
    }
}

void testa_array() {
    int arr[] = {7,10, -22, 0, 251, 7, 1000, 55};
    int arr_size = sizeof(arr) / sizeof(int);

    printf("Array original = ");
    print_arr(arr, arr_size);
    printf("\n");

    selection_sort_arr(arr, arr_size);
    printf("Array depois do Selection Sort = ");
    print_arr(arr, arr_size);
    printf("\n");

    int arr2[]  = {7,10, -22, 0, 251, 7, 1000, 55}; //Desordenando novamente
    bubble_sort_arr(arr2, arr_size);
    printf("Array depois do Bubble Sort = ");
    print_arr(arr2, arr_size);
    printf("\n");

    int arr3[]  = {7,10, -22, 0, 251, 7, 1000, 55}; //Desordenando novamente
    merge_sort_arr(arr3, arr_size);
    printf("Array depois do Merge Sort = ");
    print_arr(arr3, arr_size);
    printf("\n");
}

lista_t * obtem_lista() {
    lista_t *l = lista_inicia();
    l = lista_append(l,7);
    l = lista_append(l,10);
    l = lista_append(l, -22);
    l = lista_append(l, 0);
    l = lista_append(l, 251);
    l = lista_append(l, 7);
    l = lista_append(l, 1000);
    l = lista_append(l,55);

    return l;
}

void testa_lista(){
    lista_t * l1 = obtem_lista();

    printf("Lista original = ");
    lista_imprime(l1);
    printf("\n");

    selection_sort_lista(l1);
    printf("Lista apos selection sort = ");
    lista_imprime(l1);
    printf("\n");

    lista_termina(l1);

    lista_t * l2 = obtem_lista();
    bubble_sort_lista(l2);
    printf("Lista apos bubble sort = ");
    lista_imprime(l2);
    printf("\n");

    lista_termina(l2);

    lista_t * l3 = obtem_lista();
    merge_sort_lista(&l3);
    printf("Lista apos merge sort = ");
    lista_imprime(l3);
    printf("\n");

    lista_termina(l3);
}

int main(void){
    testa_array();
    printf("\n");
    testa_lista();
    return 0;
}