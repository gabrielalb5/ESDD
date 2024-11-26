#include <stdio.h>
#include "queue.h"

int main() {

    T_Queue fila;
    T_Info saiu;

    fila = init(5);

    printf("%s\n", enqueue(fila, 'A') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'B') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'C') ? "Entrou" : "Não entrou");
    printf("%s\n", fura_fila(fila, 'D') ? "Furou a fila" : "Não furou a fila");
    printf("%s\n", fura_fila(fila, 'E') ? "Furou a fila" : "Não furou a fila");
    printf("%s\n", fura_fila(fila, 'F') ? "Furou a fila" : "Não furou a fila");

    while(!is_empty(fila)) {
        dequeue(fila, &saiu);
        printf("Saiu: %c\n", saiu);
    }

    printf("%s\n", enqueue(fila, 'A') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'B') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'C') ? "Entrou" : "Não entrou");
    if (dequeue(fila, &saiu))       
        printf("Saiu: %c\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %c\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %c\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %c\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %c\n", saiu);

    printf("%s\n", enqueue(fila, 'D') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'E') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'F') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'G') ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 'H') ? "Entrou" : "Não entrou");

    destroy(fila);
    return 0;
}
