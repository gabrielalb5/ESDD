#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void segundoGrau(float*,float*,int,int,int,bool*);

int main(){
    
    int a, b, c;
    float *ptr1, *ptr2;
    bool *real;
    
    ptr1 = malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    real = malloc(sizeof(bool));
    
    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("c: ");
    scanf("%d",&c);
    
    segundoGrau(ptr1,ptr2,a,b,c,real);
    
    if(*real){
        printf("Resultado 1: %.2f\n",*ptr1);
        printf("Resultado 2: %.2f",*ptr2);
    }
    
    return 0;
}

void segundoGrau(float *ptr1,float *ptr2,int a,int b,int c,bool *real){
    int delta;
    int res1, res2;

    delta = pow(2,b)-4*a*c;
    if(delta<0)
        printf("Delta negativo. Sem solução real.\n");
    else{
        *ptr1 = (-b+(sqrt(delta)))/(2*a);
        *ptr2 = (-b-(sqrt(delta)))/(2*a);
        *real = true;
    }
}
