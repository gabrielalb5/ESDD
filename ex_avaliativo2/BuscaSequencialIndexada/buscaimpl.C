#include "lib.h"

void gerarCrescente(int valor_inicial, int tabela[][2], int tamanho) {
    tabela[0][0] = 0;
    tabela[0][1] = valor_inicial;
    for (int i = 1; i < tamanho; i++) {
        tabela[i][0] = i;
        tabela[i][1] = tabela[i - 1][1] + (rand() % 10);
    }
}

void imprimirTabela(int tabela[][2], int tamanho) {
    for(int i=0;i<tamanho;i++){
        printf("%d ",tabela[i][1]);
    }
}

void dividirTabela(int original[][2], int tabela[][2], int intervalo, int qtdIndices) {
    int cont = 0;
    for(int i=0;i<intervalo;i++){
        if(i%qtdIndices == qtdIndices-1 && cont<qtdIndices){
            tabela[cont][0] = original[i][0];
            tabela[cont][1] = original[i][1];
            cont++;
        }
    }
}

void busca(int tabela[][2], int tamanho, int procurado, int inicioFim[][2]){
    int inicio, fim;
    
    if(tamanho==10){
        inicio = 0;
        fim = tamanho;
    }else{
        inicio = inicioFim[0][0]/1000;
        fim = inicioFim[1][0]/1000;
    }
    
    for(int i=inicio;i<fim;i++){
        if(procurado>tabela[i][1]){
            inicioFim[0][0] = tabela[i][0]; //Indice Inicio
            inicioFim[0][1] = tabela[i][1]; //Valor Inicio
            inicioFim[1][0] = tabela[i+1][0]; //Indice Fim
            inicioFim[1][1] = tabela[i+1][1]; //Valor Fim
        }
    }
    if(procurado<=tabela[0][1]){
            inicioFim[0][0] = 0; //Indice Inicio
            inicioFim[0][1] = 0; //Valor Inicio
            inicioFim[1][0] = tabela[0][0]; //Indice Fim
            inicioFim[1][1] = tabela[0][1]; //Valor Fim
    }
}

bool buscaSequencial(int procurado,int tabela[][2],int inicioFim[][2]){
    int inicio = inicioFim[0][0];
    int fim = inicioFim[1][0];
    
    for(int i=inicio;i<=fim;i++){
        if(procurado == tabela[i][1]){
            inicioFim[0][0] = tabela[i][0];
            inicioFim[0][1] = tabela[i][1];
            return true;
        }
    }
    return false;
}