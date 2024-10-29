#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ELEMENTOS 1000000

void gerarCrescente(int valor_inicial, int tabela[][2], int tamanho);
void imprimirTabela(int tabela[][2], int tamanho);
void dividirTabela(int original[][2], int tabela[][2], int intervalo, int qtdIndices);
void primeiraBusca(int tabela[][2], int tamanho, int procurado, int inicioFim[][2]);
void segundaBusca(int tabela[][2], int procurado, int inicioFim[][2]);
bool buscaSequencial(int procurado,int tabela[][2],int inicioFim[][2]);