#include <stdio.h>

int eh_primo(int n){
    for (int i=2; i<n; i++){
        if ( n%i == 0 ) return 0;
    }
    return 1;
}

int main(void){

    int num;
    while (1){
        printf("Digite um numero (0 para sair): ");
        scanf(" %d", &num);
        if ( num <= 0 ) break;
        if ( eh_primo(num) ){
            printf("%d eh primo\n",num);
        } else {
            printf("%d nao eh primo\n",num);
        }
    }

    return 0;
}