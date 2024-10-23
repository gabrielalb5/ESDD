#include "lib.h"

int main(){
    printf("MELHOR CASO - VETORES ORDENADOS\n\n");
    melhor(100000);

    printf("PIOR CASO - VETORES INVERTIDOS\n\n");
    pior(100000);

    printf("CASO MÉDIO - VETORES ALEATÓRIOS\n\n");
    medio(100000);

    return 0;
}