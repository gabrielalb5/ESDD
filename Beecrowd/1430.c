//BEECROWD 1430 - COMPOSIÇÃO DE JINGLES
#include <stdio.h>
#include <string.h>

struct nota {
    char identificador;
    float duracao;
};

void criarNota(struct nota notas[], int *totalNotas, char identificador, float duracao);
int contarCompassos(const char *linha, struct nota notas[], int totalNotas);

int main() {
    char linha[200];
    struct nota notas[7];
    int totalNotas = 0;
    
    criarNota(notas, &totalNotas, 'W', 1.0);
    criarNota(notas, &totalNotas, 'H', 1.0/2);
    criarNota(notas, &totalNotas, 'Q', 1.0/4);
    criarNota(notas, &totalNotas, 'E', 1.0/8);
    criarNota(notas, &totalNotas, 'S', 1.0/16);
    criarNota(notas, &totalNotas, 'T', 1.0/32);
    criarNota(notas, &totalNotas, 'X', 1.0/64);
    
    while(scanf("%s",linha) && strcmp(linha, "*") != 0){
        int contador = contarCompassos(linha, notas, totalNotas);      
        printf("%d\n", contador);
    }

    return 0;
}

void criarNota(struct nota notas[], int *totalNotas, char identificador, float duracao) {
    notas[*totalNotas].identificador = identificador;
    notas[*totalNotas].duracao = duracao;
    (*totalNotas)++;
}

int contarCompassos(const char *linha, struct nota notas[], int totalNotas){
    int contador = 0;
    float duracaoCompasso = 0;
    
    for(int i=0;i<strlen(linha);i++) {
        if(linha[i] == '/'){
            if(duracaoCompasso == 1.0){
                contador++;
            }
            duracaoCompasso = 0;
        }else{
            for(int j=0;j<totalNotas;j++) {
                if(linha[i] == notas[j].identificador){
                    duracaoCompasso += notas[j].duracao;
                }
            }
        }
    }
    
    if(duracaoCompasso == 1.0) {
        contador++;
    }
    
    return contador;
}