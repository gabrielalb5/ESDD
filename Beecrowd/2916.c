//BEECROWD 2916 - A NOTA
#include <stdio.h>
#define MOD 1000000007

void merge(int v[], int inicio, int fim, int tamanho);
void intercala(int v[], int inicio, int fim, int meio);

int main() {
    int qtdNotas, trecho, notas[1000000];

    while (scanf("%d %d", &qtdNotas, &trecho) != EOF) {
        if (qtdNotas > 1000000 || trecho <= 0 || trecho > qtdNotas) {
            printf("Entrada inválida\n");
            continue;
        }

        for (int i = 0; i < qtdNotas; i++) {
            scanf("%d", &notas[i]);
        }

        merge(notas, 0, qtdNotas - 1,qtdNotas);

        long long soma = 0;
        for (int i = 0; i < trecho; i++) {
            soma = (soma + notas[i]) % MOD;
        }

        printf("%lld\n", soma);
    }

    return 0;
}

void merge(int v[], int inicio, int fim, int tamanho){
    int meio;
	if(inicio < fim){
		meio = (inicio + fim) / 2;
		merge(v, inicio, meio, tamanho);
		merge(v, meio+1, fim, tamanho);
		intercala(v, inicio, fim, meio);
	}
}

void intercala(int v[], int inicio, int fim, int meio) {
    int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
    int arquivo_aux[fim - inicio + 1];
    inicio_arquivo1 = inicio;
    inicio_arquivo2 = meio + 1;
    pos_livre = 0;

    while (inicio_arquivo1 <= meio && inicio_arquivo2 <= fim) {
        if (v[inicio_arquivo1] >= v[inicio_arquivo2]) {
            arquivo_aux[pos_livre] = v[inicio_arquivo1];
            inicio_arquivo1 += 1;
        } else {
            arquivo_aux[pos_livre] = v[inicio_arquivo2];
            inicio_arquivo2 += 1;
        }
        pos_livre += 1;
    }

    while (inicio_arquivo1 <= meio) {
        arquivo_aux[pos_livre] = v[inicio_arquivo1];
        inicio_arquivo1++;
        pos_livre++;
    }

    while (inicio_arquivo2 <= fim) {
        arquivo_aux[pos_livre] = v[inicio_arquivo2];
        inicio_arquivo2++;
        pos_livre++;
    }

    for (i = 0; i < pos_livre; i++) {
        v[inicio + i] = arquivo_aux[i];
    }
}