//BEECROWD 1025 - ONDE ESTÁ O MÁRMORE
#include <stdio.h>
#include <stdbool.h>

void insertSort(int v[], int tamanho);
int buscaSequencial(int N[], int tamanho, int palpite);
 
int main() {
    
    int N, Q, palpite, pos, caso = 1;
    
    do{
        printf("CASE# %d:\n",caso);
        scanf("%d %d",&N,&Q);
        while(N>10000 || Q>10000 || N<0 || Q<0){
            printf("Os números não podem ser negativos ou maiores que 10 mil\n");
            printf("CASE# %d: ",caso);
            scanf("%d %d",&N,&Q);
        }
        int marmores[N];
        
        for(int i=0;i<N;i++){
            scanf("%d",&marmores[i]);
        }
        
        insertSort(marmores,N);
        
        for(int i=0;i<Q;i++){
            scanf("%d",&palpite);
            pos = buscaSequencial(marmores, N, palpite);
            if(pos == -1){
                printf("%d not found\n",palpite);
            }else{
                printf("%d found at %d\n",palpite,pos+1);
            }
        }
        caso++;
    }while((N != 0 && Q != 0) && caso<=60);
    
    return 0;
}

void insertSort(int v[], int tamanho){
   int i, j, aux;

    for(i=1; i<tamanho; i++){
        aux = v[i];
        for(j = i-1; j >= 0 && v[j] > aux; j--){
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}

int buscaSequencial(int marmores[], int N, int palpite){
    int pos = -1;
    for(int i=0;i<N;i++){
        if(marmores[i]==palpite){
            pos = i;
            return pos;
        }
    }
    return pos;
}