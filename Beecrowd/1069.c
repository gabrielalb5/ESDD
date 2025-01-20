//BEECROWD - DIAMANTES E AREIA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack* T_Stack;
typedef char T_Info;

T_Stack init(int maxsize);
void destroy(T_Stack stack);
int isFull(T_Stack stack);
int isEmpty(T_Stack stack);
int push(T_Stack stack, T_Info element);
int pop(T_Stack stack, T_Info* element);

struct stack{
    int top;
    int maxsize;
    T_Info* elements;
};

int main(){
    T_Stack pilha;
    int entradas, tam, resposta;
    char sequencia[1001];

    scanf("%d", &entradas);

    for (int i=0;i<entradas;i++) {
        scanf("%s", sequencia);

        resposta = 0;
        pilha = init(strlen(sequencia));
        tam = strlen(sequencia);

        for (int i = 0; i < tam; ++i){
            if (sequencia[i] == '<'){
                push(pilha, '<');
            }else if (sequencia[i] == '>'){
                if(!isEmpty(pilha)){
                    ++resposta;
                    pop(pilha, &sequencia[i]);
                }
            }
        }
        printf("%d\n", resposta);

        destroy(pilha);
    }
    
    return 0;
}

T_Stack init(int maxsize){
    T_Stack stack = NULL;
    if (maxsize>0){
        stack = malloc(sizeof(struct stack));
        if (stack != NULL) {
            stack->top = -1;
            stack->maxsize = maxsize;
            stack->elements = malloc(sizeof(T_Info) * maxsize);
            if (stack->elements == NULL) {
                free(stack);
                stack = NULL;
            }
        }
    }
    return stack;
}

void destroy(T_Stack stack){
    if (stack != NULL) {
        free(stack->elements);
        free(stack);
    }
}

int isFull(T_Stack stack){
    if (stack == NULL) return 0;
    return stack->top == stack->maxsize - 1;
}

int isEmpty(T_Stack stack){
    if (stack != NULL) return stack->top == -1;
    return 0;
}

int push(T_Stack stack, T_Info element){
    if (stack != NULL){
        if (!isFull(stack)){
            stack->top += 1;
            stack->elements[stack->top] = element;
            return 1;
        }
    }
    return 0;
}

int pop(T_Stack stack, T_Info* element){
    if (stack != NULL){
        if (!isEmpty(stack)){
            *element = stack->elements[stack->top];
            stack->top -= 1;
            return 1;
        }
    }
    return 0;
}