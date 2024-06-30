# include <stdio.h>
# include <stdlib.h>
// bubble sort por vetor
void bubble_sort (int *v, unsigned int n){
    int aux;
    int flag; // o objetivo da flag é inviabilizar percorrer a lista novamente para verificar sua ordenação, pois se não realizar troca no segundo for, pode-se inferir ordenação
    for (unsigned int i = 0; i < n-1; i++){
        // este for indo até n-1 se dá pelo fato de ocorrer a pior hipótese possível, no qual haverá apenas uma troca por rodada. O n-1 (e não n) é por causa do último elemento não ter com quem ele ser comparado, o que vai d encontro com o algoritmo que faz comparação por blocos subsequentes.
        flag = 0;
        for (unsigned int j = 0; j < n-1; j++){
            if (v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                flag = 1; // sinaliza que houve troca na primeira passagem, portanto há uma desordem nos elementos da lista
            }
        }
        if (flag == 0) return; // Como explicado acima, "flag ==0" sinaliza um "falso", isto é, os elemtentos da listanão foram trocados, pois já estão ordenados
    }
}
void lista_imprime (int * vetor, unsigned int n){
    for (int i = 0; i < n; i++){
        printf("%d ",vetor[i]);
    }
}
int main (void){
    int lista[] = {5,9,1,3,4,8,-6,6};
    unsigned int tamanho = (sizeof(lista)/sizeof(int)); // número de elementos da lista
    printf("lista normal: ");
    lista_imprime(lista,tamanho);
    bubble_sort(lista,tamanho);
    printf("\nlista ordenada: ");
    lista_imprime(lista,tamanho);
}