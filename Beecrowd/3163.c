//BEECROWD 3163 - CONTROLADOR DE VOO
#define MAX_AVIOES 1000

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* T_Info;

struct queue {
    T_Info* elements;
    int size;
    int last;
};

typedef struct queue* T_Queue;

T_Queue init(int max_size);
void destroy(T_Queue queue);
bool is_full(T_Queue queue);
bool is_empty(T_Queue queue);
bool enqueue(T_Queue queue, T_Info element);
bool dequeue(T_Queue queue, T_Info* element);

int main() {

    T_Queue leste, oeste, sul, norte, avioes;
    T_Info aviao;
    
    leste = init(MAX_AVIOES);
    oeste = init(MAX_AVIOES);
    sul = init(MAX_AVIOES);
    norte = init(MAX_AVIOES);
    
    avioes = init(MAX_AVIOES*4);
    
    int posicao;
    char aviao_id[100];
    
    while (scanf("%d", &posicao) != EOF) {
        if (posicao == 0) {
            break;
        }
        
        scanf("%s", aviao_id);
        aviao = aviao_id;
        
        switch (posicao) {
            case -4:  // Leste
                enqueue(leste, aviao);
                break;
            case -3:  // Norte
                enqueue(norte, aviao);
                break;
            case -2:  // Sul
                enqueue(sul, aviao);
                break;
            case -1:  // Oeste
                enqueue(oeste, aviao);
                break;
            default:
                break;
        }
    }
    
    while(!is_empty(leste) || !is_empty(norte) || !is_empty(sul) || !is_empty(oeste)) {
        if (!is_empty(oeste)){
            dequeue(oeste, &aviao);
            enqueue(avioes, aviao);
        }
        if(!is_empty(norte)){
            dequeue(norte, &aviao);
            enqueue(avioes, aviao);
        }
        if(!is_empty(sul)){
            dequeue(sul, &aviao);
            enqueue(avioes, aviao);
        }
        if(!is_empty(leste)){
            dequeue(leste, &aviao);
            enqueue(avioes, aviao);
        }
    }

    
    while(!is_empty(avioes)){
        dequeue(avioes, &aviao);
        printf("%s", aviao);
        if(!is_empty(avioes)){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    destroy(leste);
    destroy(oeste);
    destroy(sul);
    destroy(norte);
    destroy(avioes);
    
    return 0;
}

T_Queue init(int max_size) {
    if (max_size < 1) {
        return NULL;
    }

    T_Queue queue = malloc(sizeof(struct queue));
    if (queue != NULL) {
        queue->last = -1;
        queue->size = max_size;
        queue->elements = malloc(sizeof(T_Info) * queue->size);
        if (queue->elements == NULL) {
            free(queue);
            queue = NULL;
        }
    }

    return queue;
}

void destroy(T_Queue queue) {
    for (int i = 0; i <= queue->last; i++) {
        free(queue->elements[i]);
    }
    free(queue->elements);
    free(queue);
}

bool is_full(T_Queue queue) {
    if (queue != NULL)
        return queue->last == queue->size - 1;
    else
        return false;
}

bool is_empty(T_Queue queue) {
    if (queue != NULL)
        return queue->last == -1;
    else
        return false;
}

bool enqueue(T_Queue queue, T_Info element) {
    if (queue == NULL) {
        return false;
    }
    if (is_full(queue)) {
        return false;
    }

    queue->last += 1;
    queue->elements[queue->last] = malloc(strlen(element) + 1);
    if (queue->elements[queue->last] == NULL) {
        return false;
    }
    strcpy(queue->elements[queue->last], element);
    return true;
}

bool dequeue(T_Queue queue, T_Info* element) {
    if (queue == NULL) {
        return false;
    }
    if (is_empty(queue)) {
        return false;
    }

    *element = queue->elements[0];

    for (int i = 0; i < queue->last; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }
    queue->last -= 1;

    return true;
}