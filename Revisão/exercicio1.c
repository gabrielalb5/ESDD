#include <stdio.h>

int conta_digitos(int n, int d);

int main(){

    int n, d;

    printf("Digite o n: ");
    scanf("%d",&n);
    printf("Digite o dígito que deseja encontrar: ");
    scanf("%d",&d);

    int cont = conta_digitos(n,d);
    
    if(cont==1){
        printf("\nO número %d aparece %d vez",d,cont);  
    }else if(cont>1){
        printf("\nO número %d aparece %d vezes",d,cont);  
    }else{
        printf("\nO número %d não aparece em %d",d,n);
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
        //Verificação das comparações
        //printf("\nestou comparando %d com %d",resto,d);
        //printf("\nnovo numero: %d\n",n);
    };

    return cont;
}