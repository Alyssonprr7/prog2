/*
Exercicio 12

Proposta: Escreva uma função que troca valores apontados por dois ponteiros


*/

#include <stdio.h>

void troca(int *pa, int *pb){
    int aux = *pa;
    *pa = *pb;
    *pb = aux;
}

int main(void){

    int a = 2;
    int b = 3;

    troca( &a, &b );

    // Deve imprimir: a = 3, b = 2
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    return 0;
}