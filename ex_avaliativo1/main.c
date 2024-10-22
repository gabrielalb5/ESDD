#include "lib.h"

int main(){
    printf("MELHOR CASO - VETORES ORDENADOS\n\n");
    melhor(300000);

    printf("PIOR CASO - VETORES INVERTIDOS\n\n");
    pior(300000);

    printf("CASO MÉDIO - VETORES ALEATÓRIOS\n\n");
    medio(300000);

    return 0;
}