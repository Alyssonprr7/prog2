#include <stdio.h>
#include <stdlib.h>


void merge(int* left, unsigned int leftLength, int* right, unsigned int rightLength) {
    unsigned int leftIndex = 0;
    unsigned int rightIndex = 0;
    int *newList = (*int) malloc(sizeof(int) * (leftLength + rightLength));
    int whileIndex = 0;

    while(leftIndex < leftLength && rightIndex < rightLength) {
        if(left[leftIndex] < right[rightIndex]) {
            newList[whileIndex] = left[leftIndex];
            leftIndex++;
        } else {
            newList[whileIndex] = left[leftIndex];
            rightIndex++;
        }

        whileIndex++;
    }

    //Apos alguma das listas ja ter terminado, vamos percorrer ate o final
    for(;leftIndex < leftLength; leftIndex++) {
        newList[whileIndex] = left[leftIndex];
        whileIndex++;
    }

    for(;rightIndex < rightLength; rightIndex++) {
        newList[whileIndex] = right[rightIndex];
        whileIndex++;
    }

    //Nao posso fazer isso porque vamos dar free
    //left = newList;

    for(int j =0; j < leftIndex + rightIndex; j++) left[j] = newList[j];

    free(newList);
}

void mergeSort(int *v, unsigned int n) {
    if(n<2) return;

    int* left = &v[0];
    unsigned int middle = n/2;
    mergeSort(v, middle);

    int* right = &v[middle];
    mergeSort(right, n - middle); //Para os casos onde n é ímpar
    merge(left,middle, right, n-middle);
}





int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int length = sizeof(arr)/sizeof(int);

    printf("lista inicial");
//    printArray();
//    mergeSort();
}
