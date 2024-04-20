/*
Exercicio 14

Proposta: Escreva uma função que recebe um ponteiro para uma struct do tipo produto_t (declarado abaixo)
          e aplica um desconto de 10% no preço deste produto.

          Na main, faça loops (for ou while) para aplicar o desconto em cada produto
          em um array de produtos, e para imprimir as informações dos produtos ao fim.

*/

#include <stdio.h>

///////////////////////////////////////
struct _meu_produto_{
    float preco;
    int codigo;
};

typedef struct _meu_produto_ produto_t;
///////////////////////////////////////

void aplica_desconto( produto_t *p ){
    float actual_price = p->preco;
    p->preco = actual_price*0.90;
}

void imprime_produto(produto_t *p) {
    printf("COD: %d\t Preço: R$%.2f\n", p->codigo, p->preco);
}

int main(void){

    // inicializa array de produtos
    produto_t produtos[] = {  { 10.0, 1 },       // produtos[0]: { preco = 10.0 , codigo = 1 }
                              { 22.0, 2 },       // produtos[1]: { preco = 22.0 , codigo = 2 }
                              {  5.0, 3 }  };    // produtos[2]: { preco =  5.0 , codigo = 3 }

    // quantidade de produtos
    size_t n = sizeof(produtos) / sizeof(produto_t);
    for (int i = 0; i < n; ++i) {
        imprime_produto(&produtos[i]);
        aplica_desconto(&produtos[i]);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        imprime_produto(&produtos[i]);
    }

    return 0;
}
