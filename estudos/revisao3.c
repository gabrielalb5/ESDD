#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool buscaBinaria(int v[], int, int, int*);

int main(){

    int tamanho, buscado;
    int *position;
    bool achou;
    
    position = malloc(sizeof(int));
    
    scanf("%d",&tamanho);
    scanf("%d",&buscado);
    
    int vetor[tamanho];

    for(int i=0;i<tamanho;i++){
        vetor[i] = i*2;
        printf("%d ",vetor[i]);
    }
    
    achou = buscaBinaria(vetor,tamanho,buscado,position);
    
    if(achou)
        printf("\nNúmero %d na posição %d",buscado,*position+1);
    else
        printf("\nO número %d não foi encontrado no conjunto",buscado);

    return 0;
}

bool buscaBinaria(int v[], int tamanho, int buscado, int* position){
    int inicio, fim, meio;
    bool achou = false;
    
    inicio = 0;
    fim = tamanho-1;
    meio = (inicio+fim)/2;
    
    while(inicio <= fim && !achou){
        if(v[meio] == buscado){
            achou = true;
            *position = meio;
        }else{
            if(buscado<v[meio]){
                fim = meio-1;
            }else{
                inicio = meio+1;
            }
            meio = (inicio+fim)/2;
        }
        
    }
    
    return achou;
}