//BEECROWD 2479 - ORDENANDO A LISTA DE CRIANÇAS DO PAPAI NOEL
#include <stdio.h>
#include <string.h>

void insertSort(char v[][21], int tamanho);

int main() {
    int tamanho;
    
    do{
        scanf("%d", &tamanho);
    }while(tamanho < 0 || tamanho > 100 || tamanho == 0);

    char criancas[tamanho][21];
    char comportamentos[tamanho];
    int comportado=0;
    int nao_comportado=0;

    for (int i = 0; i < tamanho; i++) {
        scanf(" %c %20s", &comportamentos[i], criancas[i]);
    }
    
    for (int i = 0; i < tamanho; i++) {
        if(comportamentos[i]=='+'){
            comportado++;
        }else{
            nao_comportado++;
        }
    }
    
    insertSort(criancas,tamanho);
    
    for(int i=0;i<tamanho;i++){
        printf("%s\n",criancas[i]);
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n",comportado,nao_comportado);

    return 0;
}

void insertSort(char v[][21], int tamanho){
    char aux[21];
    for (int i = 1; i < tamanho; i++) {
        strcpy(aux, v[i]);
        int j;
        for (j = i - 1; j >= 0 && strcmp(v[j], aux) > 0; j--) {
            strcpy(v[j + 1], v[j]);
        }
        strcpy(v[j + 1], aux);
    }
}