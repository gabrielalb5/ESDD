#include <stdio.h>
#include <stdbool.h>

int main(){

    int tamanho, novo;
    bool naoEntrou = true;

    printf("Quantos número tem no vetor? ");
    scanf("%d",&tamanho);

    int vetor[tamanho+1];

    printf("Qual valor será inserido? ");
    scanf("%d",&novo);

    printf("Digite os valores armazenados no vetor ordenado: ");
    for(int i=0;i<tamanho;i++){
        scanf("%d",&vetor[i]);
    }

    for(int i=tamanho-1;i>=0;i--){
        if(naoEntrou){
            if(vetor[i]>novo){
                vetor[i+1] = vetor[i]; 
            }else{
                vetor[i+1] = novo;
                naoEntrou = false;
            }
        }
    }
    if(naoEntrou){
        vetor[0] = novo;
    }

    for(int i=0;i<=tamanho;i++){
        printf("%d ",vetor[i]);
    }
    
    return 0;
}