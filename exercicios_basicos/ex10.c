/*
Exercicio 10

Proposta: Complete a funcao main() para escrever um programa que le
          dados de 3 pessoas e um imovel. Em seguida, deve perguntar
          qual pessoa ser atribuida como proprietaria do imovel.

          O programa deve reportar as informacoes do imovel ao final.

Requisito: Use os tipos pessoa_t e imovel_t e as funcoes declarados abaixo.

Obs.: Pode implementar funcoes extras para auxiliar.
     Sugestao: funcao para imprimir informacoes do imovel.
*/

#include <stdio.h>
#include <string.h>

////////////////////////////////
struct _pessoa_{
    unsigned int idade;
    char cpf[15];
};
typedef struct _pessoa_ pessoa_t;
////////////////////////////////
struct _imovel_{
    float area;
    float preco;
    pessoa_t proprietario;
};
typedef struct _imovel_ imovel_t;
////////////////////////////////

void le_imovel(imovel_t* x){
    printf("Por favor, informe os seguintes dados sobre o imóvel:\n");
    printf("--área: ");
    scanf(" %f", &x->area);
    printf("--preço: ");
    scanf(" %f", &x->preco);
}

void le_pessoa(pessoa_t* x){
    printf("Pessoa:\n");
    printf("--idade: ");
    scanf(" %u", &x->idade);
    printf("--cpf: ");
    scanf(" %14s", x->cpf); // %14s só deixa ler até 14 chars
}

void imprime_imovel(imovel_t x){
    printf("área: %.2f\n", x.area);
    printf("preço: %.2f\n", x.preco);
    printf("proprietário(a):\n");
    printf("--idade: %u\n", x.proprietario.idade);
    printf("--cpf: %s\n", x.proprietario.cpf);
}

pessoa_t procura_dono(pessoa_t pessoas[], size_t length, char cpf[]) {
    pessoa_t proprietario;
    for (int i = 0; i < length; ++i) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            proprietario = pessoas[i];
        }
    }
    return proprietario;
}

int main(void){

    imovel_t casa;
    pessoa_t pessoas[3];
    char cpf_proprietario[15];

    le_pessoa(&pessoas[0]);
    le_pessoa(&pessoas[1]);
    le_pessoa(&pessoas[2]);
    le_imovel(&casa);

    printf("Qual o cpf do proprietário?\n");
    scanf("%14s", cpf_proprietario);

    size_t pessoasLength = sizeof(pessoas)/sizeof(pessoa_t);
    pessoa_t proprietario = procura_dono(pessoas, pessoasLength, cpf_proprietario);
    casa.proprietario = proprietario;

    imprime_imovel(casa);
    return 0;
}