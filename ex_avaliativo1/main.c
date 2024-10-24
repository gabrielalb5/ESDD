#include "lib.h"

int main(){
    for(int i=0;i<3;i++){
    printf("-----TESTE NUMERO %d-----\n\n",i+1);

    printf("MELHOR CASO - VETORES ORDENADOS\n\n");
    melhor(100000);
    melhor(1000000);

    printf("PIOR CASO - VETORES INVERTIDOS\n\n");
    pior(100000);
    pior(1000000);
    }

    return 0;
}