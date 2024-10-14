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
    //imprimir_vetor(v,tamanho);

    bubble(v,tamanho);
    //imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    selection(v,tamanho);
    //imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    insertion(v,tamanho);
    //imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);
    
    printf("\nMERGE: ");
    merge(v,0,tamanho-1,tamanho);
    //imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    printf("\nQUICK: ");
    quick(v,0,tamanho-1);
    //imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    printf("\n\n");
}