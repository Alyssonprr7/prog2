/*
Exercicio 02

Proposta: Escreva um programa que calcula a média entre
          'n' numeros informados pelo usuario.
*/

/*
Para rodar (terminal):
1) Compilar: gcc -o exec ex2.c
2) Rodar: ./exec

Alternativas com botao de 'run':
- replit (online)
- code blocks (IDE)
*/

#include <stdio.h>
const float STOP_NUMBER = 0;

int main(void){
    float userInput = -1;
    float numbersInputedCount = 0;
    float sum = 0;
    while(userInput != STOP_NUMBER) {
        printf("Digite um número\n");
        scanf("%f", &userInput);
        if(userInput != 0) {
            sum += userInput;
            numbersInputedCount++;
        }
    }

    float average = sum / numbersInputedCount;
    printf("A média desses números é %.2f\n", average);

    return 0;
}