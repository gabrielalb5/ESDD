//BEECROWD 2065 - FILA DO SUPERMERCADO
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T_Info;

struct queue {
    T_Info* elements;
    int size;
    int last;
    int front;
};

typedef struct queue* T_Queue;

T_Queue init(int max_size);
void destroy(T_Queue queue);
bool is_full(T_Queue queue);
bool is_empty(T_Queue queue);
bool enqueue(T_Queue queue, T_Info element);
bool dequeue(T_Queue queue, T_Info* element);

int main(){
    int i, qtd_caixas, qtd_clientes;
    
    scanf("%d", &qtd_caixas);
    int a[qtd_caixas];
    scanf("%d", &qtd_clientes);
    int b[qtd_clientes];

    T_Queue caixas = init(qtd_caixas);
    T_Queue clientes = init(qtd_clientes);

    for(i = 0; i < qtd_caixas; i++) {
        scanf("%d", &a[i]);
        enqueue(caixas, a[i]);
    }

    for(i = 0; i < qtd_clientes; i++) {
        scanf("%d", &b[i]);
        enqueue(clientes, b[i]);
    }

    int aux[qtd_caixas];
    int t = 0;
    while(t < qtd_clientes) {
        if(t < qtd_caixas) {
            int elem_b;
            dequeue(clientes, &elem_b);
            aux[t] = elem_b * a[t];
            t++;
        }
        else {
            int elem_b;
            dequeue(clientes, &elem_b);

            int index = aux[0];
            int z = 0;
            for(i = 0; i < qtd_caixas; i++)
                if(index > aux[i]) {
                    index = aux[i];
                    z = i;
                }
            aux[z] += elem_b * a[z];

            t++;
        }
    }

    int index = aux[0];
    for(i = 0; i < qtd_caixas; i++) {
        if(index < aux[i])
            index = aux[i];
    }

    printf("%d\n", index);

    destroy(caixas);
    destroy(clientes);

    return 0;
}

T_Queue init(int max_size) {
    if(max_size < 1) {
        return NULL;
    }

    T_Queue queue = malloc(sizeof(struct queue));
    if(queue != NULL) {
        queue->last = -1;
        queue->front = 0;
        queue->size = max_size;
        queue->elements = malloc(sizeof(T_Info) * queue->size);
        if(queue->elements == NULL) {
            free(queue);
            queue = NULL;
        }
    }

    return queue;
}

void destroy(T_Queue queue) {
    free(queue->elements);
    free(queue);
}

bool is_full(T_Queue queue) {
    if(queue != NULL)
        return queue->last == queue->size - 1;
    else
        return false;
}

bool is_empty(T_Queue queue) {
    if(queue != NULL)
        return queue->last < queue->front;
    else
        return false;
}

bool enqueue(T_Queue queue, T_Info element) {
    if(queue == NULL)
        return false;
    if(is_full(queue))
        return false;

    queue->last += 1;
    queue->elements[queue->last] = element;
    return true;
}

bool dequeue(T_Queue queue, T_Info* element) {
    if(queue == NULL)
        return false;
    if(is_empty(queue))
        return false;

    *element = queue->elements[queue->front];
    queue->front += 1;
    return true;
}