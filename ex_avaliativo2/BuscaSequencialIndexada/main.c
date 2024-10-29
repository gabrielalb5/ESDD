#include "lib.h"

int main() {
    int procurado;
    bool achou;
    int original[ELEMENTOS][2];
    int tabela1[1000][2];
    int tabela2[100][2];
    int inicioFim[2][2];

    clock_t start, end;
    double cpu_time_used;
    
    printf("Digite o número procurado: ");
    scanf("%d",&procurado);
    
    gerarCrescente(1, original, ELEMENTOS);
    
    dividirTabela(original, tabela1, ELEMENTOS, 1000);
    dividirTabela(tabela1, tabela2, 1000, 100);

    start = clock();
    primeiraBusca(tabela2,10,procurado,inicioFim);
    segundaBusca(tabela1,procurado,inicioFim); 
    achou = buscaSequencial(procurado,original,inicioFim);
    end = clock();
    
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("\nDuração da busca: %f segundos", cpu_time_used);

    if(achou){
        printf("\nO número %d foi encontrado na posição %d ", inicioFim[0][1],inicioFim[0][0]);
    }else{
        printf("\nO número %d não foi encontrado", procurado);
    }
    
    return 0;
}