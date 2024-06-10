#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"

void insert_sort_arr(int arr[], int size) {
    int min_index, i, j, aux;

    for (i = 0; i < size - 1; ++i) { //Até o penúltimo, pois o último já estará ordenado
        min_index = i;
        for (j = (i + 1); j < size; ++j) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (i != min_index) { //Evitar ficar trocando caso já esteja ordenado
            aux = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = aux;
        }
    }
}

void print_arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf(" %d", arr[i]);
    }
}

int main(void){
    int arr[] = {7,10, -22, 0, 251, 7, 1000, 55};
    int arr_size = sizeof(arr) / sizeof(int);

    printf("array original = ");
    print_arr(arr, arr_size);
    printf("\n");

    insert_sort_arr(arr, arr_size);
    printf("array depois do sort = ");
    print_arr(arr, arr_size);
    printf("\n");


    lista_t * l = lista_inicia();
    l = lista_append(l,7);
    l = lista_append(l,10);
    l = lista_append(l, -22);
    l = lista_append(l, 0);
    l = lista_append(l, 251);
    l = lista_append(l, 7);
    l = lista_append(l, 1000);
    l = lista_append(l,55);

    printf("lista original = ");
    lista_imprime(l);
    printf("\n");

    lista_selection_sort(l);
    printf("lista apos sort = ");
    lista_imprime(l);
    printf("\n");

    lista_termina(l);

    return 0;
}