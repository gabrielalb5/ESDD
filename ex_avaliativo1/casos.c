#include "lib.h"

void melhor(){
    printf("MELHOR CASO - VETORES ORDENADOS\n\n");

    //1000 ordenados
    int tamanho = 1000;
    int a[tamanho];
    int a_aux[tamanho];
    crescente(a,tamanho);
    copia_vetor(a_aux,a,tamanho);

    printf("Mil elementos\n");

    casos(a,a_aux,tamanho);
}

void medio(){
    printf("CASO MÉDDIO - VETORES ALEATÓRIOS\n\n");

    //1000 aleatorios
    int tamanho = 1000;
    int a[tamanho];
    int a_aux[tamanho];
    aleatorio(a,tamanho,5);
    copia_vetor(a_aux,a,tamanho);
    
    printf("Mil elementos\n");

    casos(a,a_aux,tamanho);
}

void pior(){
    printf("PIOR CASO - VETORES INVERTIDOS\n\n");

    //1000 invertidos
    int tamanho = 1000;
    int a[tamanho];
    int a_aux[tamanho];
    decrescente(a,tamanho);
    copia_vetor(a_aux,a,tamanho);
    
    printf("Mil elementos\n");

    casos(a,a_aux,tamanho);
}

void casos(int v[], int v_aux[], int tamanho){
    imprimir_vetor(v,tamanho);

    bubble(v,tamanho);
    imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    selection(v,tamanho);
    imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    insert(v,tamanho);
    imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);
    
    printf("\n\nMERGE: ");
    merge(v,0,tamanho-1,tamanho);
    imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    printf("\n\nQUICK: ");
    quick(v,0,tamanho-1);
    imprimir_vetor(v,tamanho);
    copia_vetor(v,v_aux,tamanho);

    printf("\n\n");
}