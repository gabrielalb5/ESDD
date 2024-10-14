#include <time.h>
#include <stdio.h>

void bubble(int v[], int tamanho);
void selection(int v[], int tamanho);
void insertion(int v[], int tamanho);
void merge(int v[], int inicio, int fim, int tamanho);
void intercala(int v[], int inicio, int fim, int meio, int tamanho);
void quick(int v[], int lb, int ub);
void partition(int v[], int lb, int ub, int *j);

void imprimir_vetor(int v[], int tamanho);
void crescente(int v[], int tamanho);
void aleatorio(int v[], int tamanho, int qtd_digitos);
void decrescente(int v[], int tamanho);

void melhor(int tamanho);
void medio(int tamanho);
void pior(int tamanho);

void casos(int v[], int v_aux[], int tamanho);