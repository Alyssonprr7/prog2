/*
Exercicio 7

Proposta: Complete as funcoes main() e aluno_com_maior_nota()
          para escrever um programa que le matricula e nota de
          alunos em loop ate que o usuario sinalize para finalizar.

          O programa deve reportar a media das notas dos alunos,
          bem como as informacoes do aluno de maior nota.

Requisito: Use o tipo aluno_t declarado abaixo.

Obs.: Pode implementar funcoes extras para auxiliar.
*/

#include <stdio.h>

////////////////////////////////
struct _aluno_{
    int matricula;
    float nota;
};
typedef struct _aluno_ aluno_t;
////////////////////////////////

aluno_t aluno_com_maior_nota(aluno_t a, aluno_t b){
    if (a.nota > b.nota) {
        return a;
    }

    return b;
}

int main(void){

    float grade = -1;
    int code = 0;
    aluno_t actualStudent;
    aluno_t greaterGrade = {0, 0};
    float sum = 0;
    float amount = 0;
    while (code != 0 || grade != 0.0) {
        printf("Cadastrando novo aluno...\n");
        printf("Insira a matrícula do aluno \n");
        scanf("%d", &code);
        printf("Insira o valor da nota\n");
        scanf("%f", &grade);
        printf("\n");

        if (code!= 0 && grade != 0) {
            actualStudent.matricula = code;
            actualStudent.nota = grade;
            sum += grade;
            amount++;
            greaterGrade = aluno_com_maior_nota(greaterGrade, actualStudent);
        }
    }

    printf("O aluno com maior nota é o %d com a nota %.2f\n", greaterGrade.matricula, greaterGrade.nota);
    printf("A média das notas é %.2f\n", amount ? sum/amount : 0);

    return 0;
}