/*
Exercicio 11

Proposta: Implemente 5 funcoes que fazem tarefas basicas com strings:

        TAREFA                                   COMPORTAMENTO ESPERADO
  1) Imprimir uma string                     --> printf("%s", uma_string)
  2) Ler uma string                          --> scanf(" %s", uma_string)
  3) Determina a quantidade de chars em uma string --> strlen(uma_string)
  4) Copia os chars de uma string para outra       --> strcpy(s1,s2)
  5) Concatena os chars de uma string em outra     --> strcat(s1,s2)

IMPORTANTE: A ideia nao é apenas usar as funcionalidades prontas.
            Tente replicar o comportamento destas funcoes.

Na solucao, NAO vale usar:
* "%s" -- especificador de formato de string para printf() e scanf()
* strlen()
* strcpy()
* strcat()

Obs.: Podem ser usados apenas para comparar resultados. Ou seja,
      pra ver se a sua implementacao bate com a que ja esta pronta.

Obs.2: PODE USAR printf("%c", ...) e scanf(" %c", ...).
*/

#include <stdio.h>
#include <string.h>

void string_imprime(char str[]){
    int index = 0;
    while(1) {
        if (str[index] == '\0') {
            break;
        }
        printf("%c", str[index]);
        index++;
    }
    printf("\n");
}

size_t string_comprimento(char str[]){ // deve ser parecido com strlen()
    size_t len=0;
    while(1) {
        if (str[len] == '\0') {
            break;
        }
        len++;
    }
    return len;
}

void string_le(char str[], size_t n){ // "n" deve receber o tamanho do ARRAY. nao podemos tentar ler alem do que foi alocado
    size_t i=0;
    char c;
    scanf("%c", &c);
    while (c != ' ' && c != '\n' && i < (n-1)) { // o simbolo && indica "e" logico. similar ao "and" em python.
        str[i] = c;
        scanf("%c", &c);
        i++;
    }
    str[i] = '\0'; // finaliza str_1 com byte nulo -- FIM DA STRING
}

void string_copia(char str_1[], char str_2[]){ // deve ser parecido com strcpy()
    int index = 0;
    while(1) {
        str_1[index] = str_2[index];
        if (str_2[index] == '\0') {
            break;
        }
        index++;
    }
}

void string_concatena(char str_1[], char str_2[]){ // deve ser parecido com strcat()
    printf("max %lu", sizeof(str_1));
//    size_t max_len = sizeof(*str_1)/sizeof(int);
    size_t current_s1_len = string_comprimento(str_1);
    size_t current_s2_len = string_comprimento(str_2);

//    if(max_len < current_s1_len + current_s2_len) {
//        printf("Tamanho das strings incompatíveis\n");
//        return;
//    }

    int index = 0;
    while (1) {
        str_1[current_s1_len + index] = str_2[index];//Posso começar do index porque o último caracter de s1 é o /0
        if(str_2[index] == '\0') {
            break;
        }
        index++;
    }
    printf("\n");
}

int main(void){

    char s1[256] = "ola";
    char s2[256] = "mundo";
    size_t len_s1 = string_comprimento(s1);
    size_t len_s2 = string_comprimento(s2);

    string_imprime(s1);
    string_imprime(s2);
    printf("O tamanho de s1 é %zu\n", len_s1);
    printf("O tamanho de s2 é %zu\n", len_s2);

//    string_copia(s1,s2);
//    string_imprime(s1);
//    string_imprime(s2);

    string_concatena(s1,s2);
    string_imprime(s1);
    string_imprime(s2);

    char test[256];
    string_le(test, 256);
    string_imprime(test);

    return 0;
}
