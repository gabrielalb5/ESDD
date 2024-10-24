#include "lib.h"

int main(){
    for(int i=0;i<3;i++){
    printf("-----TESTE NUMERO %d-----\n\n",i+1);

    printf("MELHOR CASO - VETORES ORDENADOS\n\n");
    melhor(1000);

    printf("PIOR CASO - VETORES INVERTIDOS\n\n");
    pior(1000);

    printf("CASO MÉDIO - VETORES ALEATÓRIOS\n\n");
    medio(1000);
    }

    return 0;
}