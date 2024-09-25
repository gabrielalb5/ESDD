#include <stdio.h>

int conta_digitos(int n, int d);

int main(){

    int a, b, iguais;
    int vetor_a[10], vetor_b[10];

    printf("Digite o número a: ");
    scanf("%d",&a);
    printf("Digite o número b: ");
    scanf("%d",&b);

    for(int i=1;i<10;i++){
        int cont = 0;
        cont = conta_digitos(a,i);
        vetor_a[i] = cont;
        cont = conta_digitos(b,i);
        vetor_b[i] = cont;
        if(vetor_a[i]==vetor_b[i])
            iguais++;
    }
    /*for(int i=1;i<10;i++){
        printf(" %d",vetor_a[i]);
    }
    printf("\n");
    for(int i=1;i<10;i++){
        printf(" %d",vetor_b[i]);
    }*/
    
    if(iguais<9){
        printf("\nOs números não são uma permutação :(");
    }else{
        printf("\nOs números são uma permutação!");
    }

    return 0;
}

int conta_digitos(int n, int d){
    int resto = 0, cont = 0;;
    while(n>=1){
        resto = n%10;
        n = n/10;
        if(resto==d){
            cont++;
        };
    };

    return cont;
}