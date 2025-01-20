//BEECROWD 1215 - PRIMEIRO DICIONÁRIO DE ANDY
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PALAVRAS 5050
#define MAX_TAMANHO 201

typedef struct {
    char palavra[MAX_TAMANHO];
} string;

bool buscaPalavra(const char *palavra, string *dicionario, unsigned tam);
void ordenarDicionario(string *dicionario, int tam);
void quickSort(string *dicionario, int inicio, int fim);

int main() {
    char entrada[MAX_TAMANHO], temp[MAX_TAMANHO];
    string dicionario[MAX_PALAVRAS];
    unsigned k = 0;

    memset(dicionario, 0, sizeof(dicionario));

    while (scanf(" %[^\n]", entrada) != EOF) {
        int i = 0, j = 0;

        while (entrada[i]) {
            while (isalpha(entrada[i])) {
                temp[j++] = tolower(entrada[i++]);
            }

            if (j > 0) {
                temp[j] = '\0';
                if (!buscaPalavra(temp, dicionario, k)) {
                    strcpy(dicionario[k++].palavra, temp);
                }
                j = 0;
            }

            while (entrada[i] && !isalpha(entrada[i])) {
                i++;
            }
        }
    }

    ordenarDicionario(dicionario, k);

    for (int i = 0; i < k; i++) {
        printf("%s\n", dicionario[i].palavra);
    }

    return 0;
}

bool buscaPalavra(const char *palavra, string *dicionario, unsigned tam) {
    for (unsigned i = 0; i < tam; i++) {
        if (strcmp(dicionario[i].palavra, palavra) == 0) {
            return true;
        }
    }
    return false;
}

void ordenarDicionario(string *dicionario, int tam) {
    quickSort(dicionario, 0, tam - 1);
}

void quickSort(string *dicionario, int inicio, int fim) {
    if (inicio < fim) {
        int i = inicio, j = fim;
        string pivo = dicionario[(inicio + fim) / 2];

        while (i <= j) {
            while (strcmp(dicionario[i].palavra, pivo.palavra) < 0) i++;
            while (strcmp(dicionario[j].palavra, pivo.palavra) > 0) j--;

            if (i <= j) {
                string temp = dicionario[i];
                dicionario[i] = dicionario[j];
                dicionario[j] = temp;
                i++;
                j--;
            }
        }

        quickSort(dicionario, inicio, j);
        quickSort(dicionario, i, fim);
    }
}