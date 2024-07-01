#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"

void selection_sort_arr(int arr[], int size) {
    int min_index, i, j, aux;

    //Até o penúltimo, pois o último já estará ordenado
    for (i = 0; i < size - 1; ++i) {
        min_index = i;
        for (j = (i + 1); j < size; ++j) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        //Evitar ficar trocando caso já esteja ordenado
        if (i != min_index) {
            aux = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = aux;
        }
    }
}

void bubble_sort_arr(int *v, unsigned int n){
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
        if (flag == 0) return; // Como explicado acima, "flag == 0" sinaliza um "falso", isto é, os elemtentos da listanão foram trocados, pois já estão ordenados
    }
}


void merge(int* left, unsigned int left_length, int* right, unsigned int right_length) {
    unsigned int left_index = 0;
    unsigned int right_index = 0;
    int *newList = (int*) malloc(sizeof(int) * (left_length + right_length));
    int while_index = 0;

    while(left_index < left_length && right_index < right_length) {
        if(left[left_index] < right[right_index]) {
            newList[while_index] = left[left_index];
            left_index++;
        } else {
            newList[while_index] = right[right_index];
            right_index++;
        }

        while_index++;
    }

    //Apos alguma das listas ja ter terminado, vamos percorrer ate o final
    for(;left_index < left_length; left_index++) {
        newList[while_index] = left[left_index];
        while_index++;
    }

    for(;right_index < right_length; right_index++) {
        newList[while_index] = right[right_index];
        while_index++;
    }

    for(int j =0; j < left_index + right_index; j++) left[j] = newList[j];
    free(newList);
}

void merge_sort_arr(int *v, unsigned int n) {
    if(n<2) return; //Condição de parada

    //Separa em dois arrays, da esquerda e da direita
    int* left = &v[0];
    unsigned int middle = n/2;
    merge_sort_arr(v, middle);

    int* right = &v[middle];
    merge_sort_arr(right, n - middle); // (n-middle) Para os casos onde n é ímpar
    merge(left,middle, right, n-middle);
}


void bubble_sort_lista(lista_t *l ){
    if (l == NULL) return;
    unsigned int n = lista_tamanho(l);
    lista_t* atual;
    lista_t* proximo;
    // Por que aux é uma variável do tipo inteiro apenas e não lista_t (definido pela struct) ? -> Aux, nesse caso, é apenas uma variável auxiliar que guardará valores para que os inteiros dos nós subsequentes sejam trocados em caso do primeiro nó ser maior que o segundo
    int aux;
    // Este primeiro for serve como um garantidor de que todos os elementos da lista sejam analisados, ou melhor, percorrer todos os elementos da lista para que, em caso de ser neceeária a comparação, ele seja jogado para o final
    for (int i = 0; i < n - 1; i++) {
        atual = l;
        proximo = l->prox;
        // Este segundo for troca elementos de acordo com a condição de maioridade definida no if, isto é, seguindo a premissa do bubble sort, compara elementos subsequentes
        // O "n - i - 1" serve como parâmetro para evitar que sejam feitas comparações sem necessidade, uma vez que a cada pasagem do for acima, o maior número da lista será colocado na posição final, o que evita a necessidade de que seja analisado maisuma vez os valores do loop interno.
        for (int j = 0; j < n - i - 1; j++) {
            if (atual->x > proximo->x) {
                aux = atual->x;
                atual->x= proximo->x;
                proximo->x = aux;
            }
            atual = proximo;
            proximo = proximo->prox;
        }
    }
}

void selection_sort_lista(lista_t* l) {
    if (l == NULL) return;
    lista_t * min, * aux_i, * aux_j;
    int aux;
    aux_i = l;

    //Até o penultimo
    while(aux_i->prox != NULL) {
        min = aux_i;
        aux_j = aux_i->prox;
        while (aux_j != NULL) {
            if (aux_j->x < min->x) {
                min = aux_j;
            }
            aux_j = aux_j->prox;
        }

        //Evitar trabalho caso já esteja ordenado
        if(aux_i->x != min->x) {
            aux = aux_i->x;
            aux_i->x = min->x;
            min->x = aux;
        }

        aux_i = aux_i->prox;
    }

}

lista_t *divide(lista_t *l) {
    lista_t *aux1 = l;
    lista_t *aux2 = l;
    lista_t *right;

    if (l==NULL || l->prox==NULL) {
        return NULL;
    }

    while (aux1->prox != NULL && aux1->prox->prox != NULL) {
        aux1 = aux1->prox->prox;
        aux2 = aux2->prox;
    }
    right = aux2->prox;
    aux2->prox = NULL;
    return right;
}


lista_t *merge_lista(lista_t *left, lista_t *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    lista_t *resultado = NULL;

    if (left->x <= right->x) {
        resultado = left;
        resultado->prox = merge_lista(left->prox, right);
    } else {
        resultado = right;
        resultado->prox = merge_lista(left, right->prox);
    }

    return resultado;
}

void merge_sort_lista(lista_t **l) {
    lista_t *left = *l;
    if (left == NULL || left->prox == NULL) {
        return;
    }

    lista_t *right = divide(left);

    merge_sort_lista(&left);
    merge_sort_lista(&right);
    *l = merge_lista(left,right);
}