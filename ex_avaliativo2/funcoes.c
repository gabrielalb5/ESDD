#include "lib.h"

void gerarCrescente(int valor_inicial, int v[]){
    v[0] = valor_inicial;
    for (int i = 1; i < TAM; i++) {
        v[i] = v[i - 1] + (rand() % 10);
    }
}

void imprimirVetor(int v[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void dividirVetor(int v[], int vIndex[], int vValues[], int intervalo, int tamanho){
    int vCount = 0;
    for (int i = 0; i < intervalo; i++) {
        if (i % tamanho == 999) {
            if (vCount < tamanho) {
                vIndex[vCount] = i;
                vValues[vCount] = v[i];
                vCount++;
            }
        }
    }
}