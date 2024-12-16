#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T_Info;

struct queue{
    T_Info* elements;
    int maxsize;
    int size;
    int last;
    int first;
};

typedef struct queue* T_Queue;

T_Queue init(int max_size);
void destroy(T_Queue queue);
bool is_full(T_Queue queue);
bool is_empty(T_Queue queue);
bool enqueue(T_Queue queue, T_Info element);
bool dequeue(T_Queue queue, T_Info* element);

int main() {

    T_Queue fila;
    T_Info saiu;

    fila = init(40);

    for (int i = 1; i <= 40; i++){
        printf("%s\n", enqueue(fila, i) ? "Entrou" : "Não entrou");
    }

    int contador = 1;
    T_Info pessoa;
    
    printf("\nOrdem do suicídio\n");
    while(!is_empty(fila)){
        dequeue(fila, &pessoa);

        if (contador == 3) {
            printf("%d ", pessoa);
            contador = 1;
        } else {
            enqueue(fila, pessoa);
            contador++;
        }
    }
    
    printf("\nPortanto, o %d entregou-se aos romanos", pessoa);

    destroy(fila);
    return 0;
}

T_Queue init(int max_size){
    if(max_size<1){
        return NULL;
    }

    T_Queue queue = malloc(sizeof(struct queue));
    if(queue != NULL){
        queue->maxsize = max_size;

        queue->elements = malloc(sizeof(T_Info)*queue->maxsize);
        if(queue->elements == NULL){
            free(queue);
            queue = NULL;
        }else{
            queue->first = 0;
            queue->last = -1;
            queue->size = 0;
        }
    }
    return queue;
}

void destroy(T_Queue queue){
    free(queue->elements);
    free(queue);
}

bool is_full(T_Queue queue){
    return queue->size == queue->maxsize;
}

bool is_empty(T_Queue queue){
    return queue->size == 0;
}

bool enqueue(T_Queue queue, T_Info element){
    if(queue==NULL){
        return false;
    }
    if(!is_full(queue)){
        queue->last += 1;
        if(queue->last==queue->maxsize){
            queue->last = 0;
        }
        queue->elements[queue->last] = element;
        queue->size += 1;
        return true;
    }

    return false;
}

bool dequeue(T_Queue queue, T_Info* element){
    if(queue!=NULL){
        if(!is_empty(queue)){
            *element = queue->elements[queue->first];
            queue->first += 1;
            if(queue->first == queue->maxsize){
                queue->first = 0;
            }
            queue->size -= 1;
            return true;
        }
    }

    return false;
}