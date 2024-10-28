#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000
#define TAM_INDEX1 1000
#define TAM_INDEX2 10

void gerarCrescente(int valor_inicial, int v[]);
void imprimirVetor(int v[], int tamanho);
void dividirVetor(int v[], int vIndex[], int vValues[], int intervalo, int tamanho);