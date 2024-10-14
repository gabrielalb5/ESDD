#include "lib.h"

int main(){
    printf("MELHOR CASO - VETORES ORDENADOS\n\n");
    melhor(1000);
    /*melhor(100000);
    melhor(1000000);*/

    printf("PIOR CASO - VETORES INVERTIDOS\n\n");
    pior(1000);/*
    pior(100000);
    pior(1000000);*/

    printf("CASO MÉDIO - VETORES ALEATÓRIOS\n\n");
    medio(1000);/*
    medio(100000);
    medio(1000000);*/

    return 0;
}