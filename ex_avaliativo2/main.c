#include "lib.h"

int main() {
    int v[TAM];
    int v1Index[TAM_INDEX1];
    int v1Values[TAM_INDEX1];
    int v2Index[TAM_INDEX2];
    int v2Values[TAM_INDEX2];
    srand((unsigned) time(NULL));
    gerarCrescente(1, v);
    dividirVetor(v, v1Index, v1Values, TAM, TAM_INDEX1);
    imprimirVetor(v1Index, TAM_INDEX1);
    
    return 0;
}