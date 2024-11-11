#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    
    scanf("%d",&a);
    scanf("%d",&b);
    
    printf("endereço de A: %p\nendereço de B: %p",&a,&b);
    
    if(&a>&b)
        printf("\nO maior endereço guarda A");
    else
        printf("\nO maior endereço guarda B");

    return 0;
}