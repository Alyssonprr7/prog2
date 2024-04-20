/*
Exercicio 13

Proposta: Escreva uma função que encontra a primeira ocorrência de um item em um array
          e retorna um ponteiro para este item.

*/

#include <stdio.h>

int * encontra_item( int *v, size_t n, int item ){
    int *p;
    for (int i = 0; i < n; ++i) {
        if (v[i] == item) {
            p = &v[i];
        }
    }

    return p;
}

int main(void){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    size_t n = sizeof(arr) / sizeof(int);
    printf("n = %zu", n);
    int item_a_ser_encontrado = 9;

    int *p = encontra_item( arr, n, item_a_ser_encontrado );

    // Deve imprimir: *p = 5
    printf("*p = %d\n", *p);

    return 0;
}