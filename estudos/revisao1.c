#include <stdio.h>

int main(){

    int tamanho, flag = 1;

    printf("Quantos número tem no vetor? ");
    scanf("%d",&tamanho);

    int vetor[tamanho];

    for(int i=0;i<tamanho;i++){
        scanf("%d",&vetor[i]);
    }

    for(int i=0;i<tamanho;i++){
        if(vetor[i]>vetor[i+1] && i+1<tamanho){
            flag = 0;
        }
    }

    if(flag)
        printf("ORDENADO");
    else
        printf("NÂO ORDENADO");

    return 0;
}