//BEECROWD 1022 - TDA Racional
#include <stdio.h>

struct Fracao{
    int num;
    int den;
};

struct Fracao soma(struct Fracao f1, struct Fracao f2);
struct Fracao subtracao(struct Fracao f1, struct Fracao f2);
struct Fracao divisao(struct Fracao f1, struct Fracao f2);
struct Fracao multiplicacao(struct Fracao f1, struct Fracao f2);
struct Fracao simplificacao(struct Fracao fracao);


int main(){
    int leituras;
    char sinal;
    struct Fracao f1, f2, resultado, simplificado;
    
    scanf("%d",&leituras);
    
    for (int i=0;i<leituras;++i){
        scanf("%d / %d %c %d / %d", &f1.num, &f1.den, &sinal, &f2.num, &f2.den);
        
        switch(sinal){
            case '+': resultado = soma(f1,f2); break;
            case '-': resultado = subtracao(f1,f2); break;
            case '/': resultado = divisao(f1,f2); break;
            case '*': resultado = multiplicacao(f1,f2); break;
        }
        
        simplificado = simplificacao(resultado);
        
        printf("%d/%d = %d/%d\n", resultado.num, resultado.den, simplificado.num, simplificado.den);
    }

    return 0;
}

struct Fracao soma(struct Fracao f1, struct Fracao f2){
    struct Fracao resultado;
    resultado.num = f1.num*f2.den + f2.num*f1.den;
    resultado.den = (f1.den*f2.den);
    return resultado;
}

struct Fracao subtracao(struct Fracao f1, struct Fracao f2){
    struct Fracao resultado;
    resultado.num = f1.num*f2.den - f2.num*f1.den;
    resultado.den = f1.den*f2.den;
    return resultado;
}

struct Fracao divisao(struct Fracao f1, struct Fracao f2){
    struct Fracao resultado;
    resultado.num = f1.num*f2.den;
    resultado.den = f2.num*f1.den;
    return resultado;
}

struct Fracao multiplicacao(struct Fracao f1, struct Fracao f2){
    struct Fracao resultado;
    resultado.num = f1.num*f2.num;
    resultado.den = f1.den*f2.den;
    return resultado;
}

struct Fracao simplificacao(struct Fracao fracao){
    int a;
    int b = fracao.den;
    
    if(fracao.num<0){
        a = -fracao.num;
    }else{
        a = fracao.num;
    }

    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
    }

    fracao.num /= a;
    fracao.den /= a;

    return fracao;
}