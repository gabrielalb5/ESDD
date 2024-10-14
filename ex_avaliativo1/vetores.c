#include "lib.h"

void imprimir_vetor(int v[], int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%d ",v[i]);
    }
}

void crescente(int v[], int tamanho){
    for(int i=0;i<tamanho;i++){
        v[i] = i+1;
    }
}

void aleatorio(int v[], int tamanho, int qtd_digitos){
    int i, digitos;
	
	for(i=1, digitos = 10; i < qtd_digitos; i++){
		digitos *= 10;
	}
	
	srand( (unsigned) time(NULL) );
	for(i=0; i < tamanho; i++){
		v[i] = rand() % digitos;
	}
}

void decrescente(int v[], int tamanho){
    int j=0;
    for(int i=tamanho;i>0;i--){
        v[j] = i;
        j++;
    }
}

void copia_vetor(int destino[], int origem[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}