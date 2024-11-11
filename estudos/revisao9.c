#include <stdio.h>
#include <stdlib.h>

void troca(int*,int*);

int main(){

    int a, b;
    
    scanf("%d",&a);
    scanf("%d",&b);
    
    printf("Original - A: %d e B: %d\n",a,b);
    
    troca(&a,&b);
    
    printf("Trocado - A: %d e B: %d",a,b);

    return 0;
}

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}