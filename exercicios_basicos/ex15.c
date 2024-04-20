/*
Exercicio 15

Proposta: Escreva uma função que retorna um ponteiro para array alocado em memória Heap contendo todos os
          números inteiros dentre um limite inferior e um limite superior.

          Na função main, deve imprimir o array a partir do ponteiro recebido.

Exemplo:

int *v = numeros_inteiros_entre(2,5);

v --> { 2, 3, 4, 5 }

*/

#include <stdio.h>
#include <stdlib.h>

int *numeros_inteiros_entre(int a, int b){
    int len = b-a + 1;
    int *arr = malloc(len*sizeof(int));
    int array_index = 0;
    for (int i = a; i <= b; ++i) {
        arr[array_index] = i;
        array_index++;
    }
    return arr;
}

int main(void){

    int min = 100;
    int max = 250;

    int *v = numeros_inteiros_entre( min, max );

    int len = max-min +1;
    for (int i = 0; i < len; ++i) {
        printf("%d \t", v[i]);
    }
    printf("\n");

    return 0;
}