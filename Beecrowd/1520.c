//BEECROWD 1520 - PARAFUSOS E PORCAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int x[], int lb, int ub);
void partition(int x[], int lb, int ub, int *j);
int busca(int v[], int tamanho, int procurado);

int main(){
    
    int qtdCaixas;
    
    while (scanf("%d", &qtdCaixas) != EOF) {
        
        int inicio, fim, procurado, pos = 0;
        int *string = malloc(sizeof(int)*10000);
        
        for(int i=0;i<qtdCaixas;i++){
            scanf("%d %d",&inicio,&fim);
            for(int j=inicio;j<=fim;j++){
                string[pos] = j;
                pos++;
            }
        }
        
        scanf("%d",&procurado);
        
        quicksort(string,0,pos-1);
        busca(string,pos,procurado);
    }
    
    return 0;
}

int busca(int v[], int tamanho, int procurado){
    int primeira = -1, ultima = -1;
    for(int i=0;i<tamanho;i++){
        if(procurado == v[i]){
            if(primeira == -1){
                primeira = i;
            }
            ultima = i;
        }
    }
    if(primeira!=-1){
        printf("%d found from %d to %d\n",procurado, primeira, ultima);
    }else{
        printf("%d not found\n",procurado);
    }
}

void quicksort(int x[], int lb, int ub){
    int j = -1;
    if(lb >= ub)
        return;
    partition(x, lb, ub, &j);   
    quicksort(x, lb, j-1);          
    quicksort(x, j+1, ub);          
}

void partition(int x[], int lb, int ub, int *j){
    int a, down, up, temp;
    a = x[lb];
    up = ub;
    down = lb;

    while(down < up){
        while(x[down] <= a && down < ub){
            down++;
        }
        while(x[up] > a){
            up--;
        }
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}