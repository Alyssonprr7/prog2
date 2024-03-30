/*
Exercicio 03

Proposta: Escreva um programa que encontra o minimo entre
          'n' numeros informados pelo usuario.

Requisito: Crie uma funcao que acha o minimo entre dois inteiros
           e use-a na sua solucao.
*/

/*
Para rodar (terminal):
1) Compilar: gcc -o exec ex3.c
2) Rodar: ./exec

Alternativas com botao de 'run':
- replit (online)
- code blocks (IDE)
*/

#include <stdio.h>

// Declaracao da funcao 'acha_minimo'
//
// Lembrando:
//  [tipo do retorno] [nome da fução] ( tipo param1, tipo param2, ...  ){
//    [código]
//  }
//
// tipo  nome     (tipo param1, tipo param2)
//  |     |         |   |        |   |
// int acha_minimo(int  a,      int  b)

int acha_minimo(int a, int b){
    int min;
    if(a > b) {
        min = b;
    } else {
        min = a;
    }
    return min;
}
int main(void){
    int numbers;
    printf("Digite quantos números serão inseridos\n");
    scanf("%d", &numbers);

    int actualUserInput = 0;
    int min;
    for(int i=0; i< numbers; i++) {
        printf("Digite um número\n");
        scanf("%d", &actualUserInput);
        min = acha_minimo(actualUserInput, min);
    }

    printf("O menor número é %d\n", min);
    return 0;
}