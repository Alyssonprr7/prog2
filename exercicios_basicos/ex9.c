/*
Exercicio 9

Proposta: Complete as funções declaradas abaixo para escrever um programa
          que determina média, produtório, máximo e mínimo de um
          array de inteiros.

          O programa deve imprimir o array inteiro e reportar os resultados
          de sua média, produtório, max e min.

Requisito: Usar as funções declaradas, após completá-las.
*/

#include <stdio.h>

int isEmpty(size_t n) {
    return n <= 0;
}

float calcula_media_de_array(int arr[], size_t n){ // "n" é a quantidade de itens em "arr"
    float somatorio=0.0;
    for (int i = 0; i < n; ++i) {
        somatorio += (float) arr[i];
    }
    return somatorio/n;
}

float calcula_produtorio_de_array(int arr[], size_t n){ // "n" é a quantidade de itens em "arr"
    float prod=1.0;
    for (int i = 0; i < n; ++i) {
        prod *= (float) arr[i];
    }
    return prod;
}

int encontra_max_de_array(int arr[], size_t n){ // "n" é a quantidade de itens em "arr"
    int max;
    for (int i = 0; i < n; ++i) {
        max = max && max >= arr[i] ? max : arr[i];
    }
    return max;
}

int encontra_min_de_array(int arr[], size_t n){ // "n" é a quantidade de itens em "arr"
    int min;
    for (int i = 0; i < n; ++i) {
        min = min && min <= arr[i] ? min : arr[i];
    }
    return min;
}



int main(void){

    int arr[] = { 6, 3, 2, 1, 12, 5, 23 };
    size_t length = sizeof(arr)/sizeof(int);
    if (isEmpty(length) == 1) {
        return 0;
    }

    float media = calcula_media_de_array(arr, length);
    printf("média: %.2f\n", media);

    float produtorio = calcula_produtorio_de_array(arr, length);
    printf("produtório: %.2f\n", produtorio);

    int max = encontra_max_de_array(arr, length);
    printf("max: %d\n", max);

    int min = encontra_min_de_array(arr, length);
    printf("min: %d\n", min);
    return 0;
}