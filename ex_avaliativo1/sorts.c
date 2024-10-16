#include "lib.h"

void bubble(int v[], int tamanho){
    int  continua, aux;
    int comparacoes = 0, trocas = 0;
    
    do{
        continua = 0;
        for(int i=0;i<tamanho-1;i++){
            comparacoes++;
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua=1;
                trocas++; 
            }
        }
    }while(continua!=0);
    printf("Comparações: %d | Trocas: %d", comparacoes, trocas);
}
void selection(int v[], int tamanho){
    int i, j, pos_menor, aux;

    for(i=0; i<tamanho; i++){
        pos_menor = i;
        for(j=i+1; j<tamanho; j++){
            if(v[j] < v[pos_menor]){
                pos_menor = j;
            }
        }
        aux = v[i];
        v[i] = v[pos_menor];
        v[pos_menor] = aux;
    }
}
void insertion(int v[], int tamanho){
   int i, j, aux;

    for(i=1; i<tamanho; i++){
        aux = v[i];
        for(j = i-1; j >= 0 && v[j] > aux; j--){
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}
void merge(int v[], int inicio, int fim, int tamanho){
    int meio;
	if(inicio < fim){
		meio = (inicio + fim) / 2;
		merge(v, inicio, meio, tamanho);
		merge(v, meio+1, fim, tamanho);
		intercala(v, inicio, fim, meio, tamanho);
	}
}

void intercala(int v[], int inicio, int fim, int meio, int tamanho){
	int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
	int arquivo_aux[tamanho];
	inicio_arquivo1 = inicio;
	inicio_arquivo2 = meio + 1;
	pos_livre = inicio;

	while(inicio_arquivo1 <= meio && inicio_arquivo2 <= fim){
		if(v[inicio_arquivo1] <= v[inicio_arquivo2]){
			arquivo_aux[pos_livre] = v[inicio_arquivo1];
			inicio_arquivo1 += 1;
		} 
		else
		{
			arquivo_aux[pos_livre] = v[inicio_arquivo2];
			inicio_arquivo2 += 1;
		}
		pos_livre += 1;
	}
	for(i=inicio_arquivo1; i<= meio; i++, pos_livre++){
		arquivo_aux[pos_livre] = v[i];
	}
	for(i=inicio_arquivo2; i<= fim; i++, pos_livre++){
		arquivo_aux[pos_livre] = v[i];
	}
	for(i=inicio; i <= fim; i++){
		v[i] = arquivo_aux[i];
	}
}

void quick(int v[], int lb, int ub){

    int j = -1;

    if(lb >= ub)
        return;                     /* Vetor está classificado */

    partition(v, lb, ub, &j);       /* Particiona os elementos do subvetor
                                     * de modo que um dos elementos seja alocado
                                     * em sua posição correta. A variável j é a
                                     * posição onde este elemento foi alocada
                                     */

    quick(v, lb, j-1);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição lb e j-1
                                     */

    quick(v, j+1, ub);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição j+1 e ub
                                     */

}


void partition(int v[], int lb, int ub, int *j){

    int a, down, up, temp;
    
    /*
     * a é o elemento cuja posição 
     * final é procurada (pivô)
     */
    a = v[lb];

    /*
     * Inicialização dos ponteiros
     */
    up = ub;
    down = lb;

    while(down < up){
        while(v[down] <= a && down < ub){
            /*
             * Sobe no vetor
             */
            down++;
        }
        while(v[up] > a){
            /*
             * Desce no vetor
             */
            up--;
        }
        if(down < up){
            temp = v[down];
            v[down] = v[up];
            v[up] = temp;
        }
    }
    v[lb] = v[up];
    v[up] = a;
    *j = up;
}