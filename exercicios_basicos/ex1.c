/*
Exercicio 01

Proposta: Escreva um programa que pergunta ao usuario sua idade
          e a partir deste dado, avisa-o se pode dirigir.

Regra: Se tiver 18 anos ou mais, pode dirigir.

Obs: Se tiver menos de 18 anos, reporte quantos anos
     faltam para que possa dirigir.
*/

/*
Para rodar (terminal):
1) Compilar: gcc -o exec ex1.c
2) Rodar: ./exec

Alternativas com botao de 'run':
- replit (online)
- code blocks (IDE)
*/


#include <stdio.h>
const int ADULTHOOD_MINIMUM_AGE = 18;

int main(void){
    printf("Digite sua idade\n");
    int age;
    scanf("%d", &age);
    if(age < ADULTHOOD_MINIMUM_AGE) {
        printf("Com %d anos, você NÃO pode dirigir\n", age);
    } else {
        printf("Com %d anos, você PODE dirigir\n", age);
    }

    return 0;
}