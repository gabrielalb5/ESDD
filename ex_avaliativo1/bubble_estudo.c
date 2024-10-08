#define TAM 10
#include <stdio.h>


int main (){

    int  continua, aux, v[TAM] = {10,9,8,7,6,5,4,3,2,1}, troca=0, comp=0;

    do{
        continua = 0;
        for(int i=0;i<TAM-1;i++){
            comp++;
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua=1;
                troca++;
            }
        }
    }while(continua!=0);
    
    for(int i=0;i<TAM;i++){
        printf("%d ",v[i]);
    }
    printf("\nTrocas: %d\n",troca);
    printf("Comparação: %d",comp);
    
    return 0;
}