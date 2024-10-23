#include "lib.h"

int main(){
    printf("MELHOR CASO - VETORES ORDENADOS\n\n");
    melhor(1000);

    printf("PIOR CASO - VETORES INVERTIDOS\n\n");
    pior(1000);

    printf("CASO MÉDIO - VETORES ALEATÓRIOS\n\n");
    medio(1000);

    return 0;
}