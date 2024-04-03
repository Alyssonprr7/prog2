/*
Exercicio 8

Proposta: Complete a funcao main() para escrever um programa que le
          dados de um imovel e seu proprietario. Em seguida, deve
          ler dados de outra pessoa, e atribui-la como a nova
          proprietaria do imovel.

          O programa deve reportar as informacoes do imovel antes
          e apos a troca de proprietario.

Requisito: Use os tipos pessoa_t e imovel_t declarados abaixo.

Obs.: Pode implementar funcoes extras para auxiliar.
     Sugestao: funcao para imprimir informacoes do imovel.
*/

#include <stdio.h>

////////////////////////////////
struct _pessoa_{
    int idade;
    unsigned int cpf;
};
typedef struct _pessoa_ pessoa_t;
////////////////////////////////
struct _imovel_{
    float area;
    float preco;
    int num_comodos;
    pessoa_t proprietario;
};

typedef struct _imovel_ imovel_t;
////////////////////////////////

void printOwner(pessoa_t pessoa) {
    printf("\t CPF %u\n", pessoa.cpf);
    printf("\t Idade %d\n", pessoa.idade);
}

void printPlace(imovel_t imovel) {
    printf("\n");
    printf("Imóvel com %2.f m²\n", imovel.area);
    printf("com %d cômodos\n", imovel.num_comodos);
    printf("com único dono\n");
    printOwner(imovel.proprietario);
    printf("Por apenas R$/%2.f\n", imovel.preco);
    printf("\n");

}

void createPerson(pessoa_t *pt) {
    printf("Digite a idade da pessoa \n");
    scanf(" %d", &pt->idade);
    printf("Digite o CPF da pessoa \n");
    scanf(" %u", &pt->cpf);

}

int main(void){
    imovel_t place;
    pessoa_t oldOwner;
    pessoa_t newOwner;

    printf("\n");
    printf("Digite a área do imóvel\n");
    scanf(" %f", &place.area);
    printf("Digite o número de cômodos do imóvel\n");
    scanf(" %d", &place.num_comodos);
    printf("Digite o preço do imóvel\n");
    scanf(" %f", &place.preco);


    printf("Sobre o antigo dono...\n");
    createPerson(&oldOwner);
    place.proprietario = oldOwner;
    printPlace(place);

    printf("Sobre o novo dono...\n");
    createPerson(&newOwner);
    place.proprietario = newOwner;
    printPlace(place);

    return 0;
}