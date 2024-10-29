#include "lib.h"

int main(){
    int procurado;
    int posicao = -1;

    clock_t start, end;
    double cpu_time_used;
    
    printf("Digite o número procurado: ");
    scanf("%d",&procurado);

    int v[TAM];
    srand(1);
    gerarCrescente(1, v);
    
    start = clock();
    posicao = buscaSequencial(v,procurado,posicao);
    end = clock();
    
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("\nDuração da busca: %f segundos", cpu_time_used);
    
    if(posicao<0){
        printf("\nO número %d não foi encontrado", procurado);
    }else{
        printf("\nO número %d foi encontrado na posição %d ", procurado,posicao);
    }
    
    return 0;
}