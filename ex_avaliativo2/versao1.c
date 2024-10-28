#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000000
#define TAM_INDEX1 1000
#define TAM_INDEX2 10

void gerarCrescente(int valor_inicial, int v[]);
void imprimirVetor(int v[], int tamanho);
void dividirVetor(int v[], int posicoes[], int vIndex[], int vValues[], int intervalo, int tamanho);

int main() {
    int v[TAM];
    int v1Index[TAM_INDEX1];
    int v1Values[TAM_INDEX1];
    int v2Index[TAM_INDEX2];
    int v2Values[TAM_INDEX2];
    // VETOR ALEATÓRIO
    //srand((unsigned) time(NULL));
    // VETOR COM SEED
    srand(1);
    gerarCrescente(1, v);
    dividirVetor(v, v, v1Index, v1Values, TAM, TAM_INDEX1);
    imprimirVetor(v1Index, TAM_INDEX1);
    dividirVetor(v1Index, v1Values, v2Index, v2Values, TAM_INDEX1, 100);
    imprimirVetor(v2Index, TAM_INDEX2);
    return 0;
}

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

void dividirVetor(int v[], int valores[], int vIndex[], int vValues[], int intervalo, int tamanho){
    int vCount = 0;
    for (int i = 0; i < intervalo; i++) {
        if(tamanho == 1000){
            if (i % tamanho == 999) {
                if (vCount < tamanho) {
                    vIndex[vCount] = i;
                    vValues[vCount] = v[i];
                    vCount++;
                }
            }
        }else{
            if (i % tamanho == 99) {
                if (vCount < tamanho) {
                    vIndex[vCount] = v[i];
                    vValues[vCount] = valores[i];
                    vCount++;
                }
            }
        }
        
    }
}