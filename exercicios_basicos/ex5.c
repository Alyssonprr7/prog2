/*
Exercicio 05

Proposta: Escreva um programa que encontra o produto de maior preço
          entre produtos informados pelo usuario

Requisitos:
     - Use o tipo abstrato de dado definido para armazenar produtos
     - Crie uma funcao que acha o produto de maior preço entre dois produtos
       e use-a na sua solucao.
*/

/*
Para rodar (terminal):
1) Compilar: gcc -o exec ex5.c
2) Rodar: ./exec

Alternativas com botao de 'run':
- replit (online)
- code blocks (IDE)
*/

#include <stdio.h>

///////////////////////////////////////
// Definindo o tipo produto

struct meu_produto{
    float preco;
    int codigo;
};

typedef struct meu_produto produto_t;
///////////////////////////////////////

// Declaracao da funcao 'acha_produto_mais_caro'
//
// Lembrando:
//  [tipo do retorno] [nome da fução] ( tipo param1, tipo param2, ...  ){
//    [código]
//  }
//
//  tipo          nome             (tipo param1, tipo param2)
//   |              |                 |       |    |       |
// produto_t acha_produto_mais_caro(produto_t a, produto_t b)

produto_t acha_produto_mais_caro(produto_t a, produto_t b){
    produto_t caro;
    if (a.preco > b.preco) {
        caro = a;
    } else {
        caro = b;
    }


    return caro;
}

produto_t* acha_produto_mais_caro_pointer(produto_t* a, produto_t* b){
    produto_t* caro;
    if (a->preco > b->preco) {
        caro = a;
    } else {
        caro = b;
    }

    return caro;
}

int main(void){

    // COMPLETAR

    // Dica 1: usar as funções printf() e scanf() para pedir e ler dados sobre os produtos.
    //  - printf("algo") imprime 'algo' na tela
    //  - printf("algo %d",i) imprime 'algo [valor de i]' na tela
    //  - scanf(" %d", &i) lê o que o usuário escreveu e atribui à variável 'i'
    //
    // Lembrando de python:
    //  - printf() é parecido com print()
    //  - scanf()  é parecido com input()
    //
    // Dica 2: Use um for ou while para ler todos os números
    //
    //  for ( inicializa contador; condicao; incrementa contador ){
    //    [código]
    //  }
    //
    //  while ( condicao ){
    //    [código]
    //  }
    //
    // Dica 3: Chame a funcao 'acha_produto_mais_caro' declarada acima.
    // Exemplo:
    //  produto_t x;
    //  x.preco = 0.99;
    //  x.codigo = 100;
    //  produto_t y;
    //  y.preco = 9.99;
    //  y.codigo = 35;
    //  produto_t caro;
    //  caro = acha_produto_mais_caro(x,y);

    float price = 100;
    int code = 0;
    produto_t actualProduct;
    produto_t moreExpensive = {0, 0};
    produto_t* moreExpensivePointer;
    while (code != 0 || price != 0.0) {
        printf("Cadastrando novo produto...\n");
        printf("Insira o código do produto\n");
        scanf("%d", &code);
        printf("Insira o valor do produto\n");
        scanf("%f", &price);
        printf("\n");

        if (code!= 0 && price != 0) {
            actualProduct.preco = price;
            actualProduct.codigo = code;
            moreExpensive = acha_produto_mais_caro(moreExpensive, actualProduct);
            moreExpensivePointer = acha_produto_mais_caro_pointer(&moreExpensive, &actualProduct);
        }
    }

    printf("O produto mais caro é o %d com R$%.2f\n", moreExpensive.codigo, moreExpensive.preco);
    printf("O produto mais caro (pointer) é o %d com R$%.2f\n", moreExpensivePointer->codigo, moreExpensivePointer->preco);
    return 0;
}