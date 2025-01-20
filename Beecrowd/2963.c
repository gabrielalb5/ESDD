//BEECROWD 2963 - CHURRAS NO YURI
#include <stdio.h>

struct Carne{
    char nome[20];
    int validade;
};

void insertSort(struct Carne v[], int tamanho);

int main() {
    
    int qtdCarnes;
    
    while (scanf("%d", &qtdCarnes) != EOF) {
        
        while(qtdCarnes>10 || qtdCarnes<0){
            scanf("%d", &qtdCarnes);
        }
        
        struct Carne carnes[10];
        
        for (int i = 0; i < qtdCarnes; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
            while(carnes[i].validade > 50 || carnes[i].validade < 0){
                scanf("%s %d", carnes[i].nome, &carnes[i].validade);
            }
        }
    
        insertSort(carnes,qtdCarnes);
        
        for (int i = 0; i < qtdCarnes; i++) {
            if (i > 0) printf(" ");
            printf("%s", carnes[i].nome);
        }
        printf("\n");
    }
    
    return 0;
}

void insertSort(struct Carne v[], int tamanho){
   int i, j;
   struct Carne aux;

    for(i=1; i<tamanho; i++){
        aux = v[i];
        for(j = i-1; j >= 0 && v[j].validade > aux.validade; j--){
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}