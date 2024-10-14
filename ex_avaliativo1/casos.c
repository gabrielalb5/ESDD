#include "lib.h"

void melhor(tamanho){
    int v[tamanho];
    int v_aux[tamanho];
    crescente(v,tamanho);
    copia_vetor(v_aux,v,tamanho);
    printf("%d elementos",tamanho);
    casos(v,v_aux,tamanho);
}

void medio(tamanho){
    int v[tamanho];
    int v_aux[tamanho];
    aleatorio(v,tamanho,5);
    copia_vetor(v_aux,v,tamanho);
    printf("%d elementos",tamanho);
    casos(v,v_aux,tamanho);
}

void pior(tamanho){
    int v[tamanho];
    int v_aux[tamanho];
    decrescente(v,tamanho);
    copia_vetor(v_aux,v,tamanho);
    printf("%d elementos",tamanho);
    casos(v,v_aux,tamanho);
}

void casos(int v[], int v_aux[], int tamanho){
    clock_t start, end;
    double cpu_time_used;
    //imprimir_vetor(v,tamanho);

    printf("\nBUBBLE - ");
    start = clock();
    bubble(v,tamanho);
    //imprimir_vetor(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("(%f segundos)", cpu_time_used);
    copia_vetor(v,v_aux,tamanho);

    printf("\nSELECTION - ");
    start = clock();
    selection(v,tamanho);
    //imprimir_vetor(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("(%f segundos)", cpu_time_used);
    copia_vetor(v,v_aux,tamanho);

    printf("\nINSERT - ");
    start = clock();
    insertion(v,tamanho);
    //imprimir_vetor(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("(%f segundos)", cpu_time_used);
    copia_vetor(v,v_aux,tamanho);
    
    printf("\nMERGE - ");
    start = clock();
    merge(v,0,tamanho-1,tamanho);
    //imprimir_vetor(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("(%f segundos)", cpu_time_used);
    copia_vetor(v,v_aux,tamanho);

    printf("\nQUICK - ");
    start = clock();
    quick(v,0,tamanho-1);
    //imprimir_vetor(v,tamanho);
    end = clock();
    cpu_time_used = (  (double)(end - start) / CLOCKS_PER_SEC );
    printf("(%f segundos)", cpu_time_used);
    copia_vetor(v,v_aux,tamanho);

    printf("\n\n");
}