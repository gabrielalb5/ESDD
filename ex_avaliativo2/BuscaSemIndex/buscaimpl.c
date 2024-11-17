#include "lib.h"

void gerarCrescente(int valor_inicial, int v[]){
    v[0] = valor_inicial;
    for (int i = 1; i < TAM; i++) {
        v[i] = v[i - 1] + (rand() % 10);
    }
}

int buscaSequencial(int v[], int procurado){
    int posicao = -1;
    for(int i=0; i<TAM; i++){
        if(v[i] == procurado){
            posicao = i;
        }
    }
    return posicao;
}