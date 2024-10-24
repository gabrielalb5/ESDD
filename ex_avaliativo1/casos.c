#include "lib.h"

void melhor(int tamanho){
    int *v = (int *)malloc(tamanho * sizeof(int));
    int *v_aux = (int *)malloc(tamanho * sizeof(int));
    crescente(v,tamanho);
    copia_vetor(v_aux,v,tamanho);
    printf("%d elementos",tamanho);
    casos(v,v_aux,tamanho);
    free(v);
    free(v_aux);
}

void medio(int tamanho){
    int *v = (int *)malloc(tamanho * sizeof(int));
    int *v_aux = (int *)malloc(tamanho * sizeof(int));
    aleatorio(v,tamanho,5);
    copia_vetor(v_aux,v,tamanho);
    printf("%d elementos",tamanho);
    casos(v,v_aux,tamanho);
    free(v);
    free(v_aux);
}

void pior(int tamanho){
    int *v = (int *)malloc(tamanho * sizeof(int));
    int *v_aux = (int *)malloc(tamanho * sizeof(int));
    decrescente(v,tamanho);
    copia_vetor(v_aux,v,tamanho);
    printf("%d elementos",tamanho);
    casos(v,v_aux,tamanho);
    free(v);
    free(v_aux);
}

void casos(int v[], int v_aux[], int tamanho){
    clock_t start, end;
    double cpu_time_used;
    long long int merge_comp = 0, merge_troca = 0, quick_comp = 0, quick_troca = 0;
    long long int *ptr_merge_comp = &merge_comp, *ptr_merge_troca = &merge_troca;
    long long int *ptr_quick_comp = &quick_comp, *ptr_quick_troca = &quick_troca;

    printf("\nBUBBLE - ");
    start = clock();
    bubble(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf(" (%f segundos)", cpu_time_used);
    
    copia_vetor(v,v_aux,tamanho);

    printf("\nINSERTION - ");
    start = clock();
    insertion(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf(" (%f segundos)", cpu_time_used);
    
    copia_vetor(v,v_aux,tamanho);

    printf("\nSELECTION - ");
    start = clock();
    selection(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf(" (%f segundos)", cpu_time_used);
    
    copia_vetor(v,v_aux,tamanho);
    
    printf("\nMERGE - ");
    start = clock();
    merge(v,0,tamanho-1,tamanho,ptr_merge_comp,ptr_merge_troca);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("COMP: %lld | TROCAS: %lld", merge_comp, merge_troca);
    printf(" (%f segundos)", cpu_time_used);
    
    copia_vetor(v,v_aux,tamanho);

    printf("\nQUICK - ");
    start = clock();
    quick(v,0,tamanho-1,ptr_quick_comp,ptr_quick_troca);
    //imprimir_vetor(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("COMP: %lld | TROCAS: %lld", quick_comp, quick_troca);
    printf(" (%f segundos)", cpu_time_used);

    printf("\n\n");
}