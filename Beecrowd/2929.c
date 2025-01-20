//BEECROED 2929 - MENOR DA PILHA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack* T_Stack;
typedef int T_Info;

T_Stack init(int maxsize);

void destroy(T_Stack stack);

bool isFull(T_Stack stack);

bool isEmpty(T_Stack stack);

bool push(T_Stack stack, T_Info element);

bool pop(T_Stack stack);

struct stack{
    int top;
    int maxsize;
    T_Info* elements;
};

int main(){

    T_Stack pilha;
    
    int operacoes;
    scanf("%d",&operacoes);
    
    pilha = init(operacoes);
    char comando[10];
    int novo;
    
    for(int i=0;i<operacoes;i++){
        scanf("%s",comando);
        if(strcmp(comando,"PUSH") == 0){
            scanf("%d",&novo);
            push(pilha,novo);
        }else if(strcmp(comando,"MIN") == 0){
            if(isEmpty(pilha)){
                printf("EMPTY\n");
            }else{
                T_Info min = pilha->elements[0];
                for (int j = 1; j <= pilha->top; j++) {
                    if (pilha->elements[j] < min) {
                        min = pilha->elements[j];
                    }
                }
                printf("%d\n", min);
            }
        }else if(strcmp(comando,"POP") == 0){
            if(isEmpty(pilha)){
                printf("EMPTY\n");
            }else{
                pop(pilha);
            }
        }else{
            printf("Comando não reconhecido\n");
        }
    }
    
    destroy(pilha);

    return 0;
}

T_Stack init(int maxsize){
    T_Stack stack = NULL;
    if(maxsize>0){
        stack = malloc(sizeof(struct stack));
        if(stack != NULL){
            stack->top = -1;
            stack->maxsize = maxsize;
            stack->elements = malloc(sizeof(T_Info) * maxsize);
            if(stack->elements == NULL){
                free(stack);
                stack = NULL;
            }
        }
    }
    return stack;
}

void destroy(T_Stack stack){
    if(stack != NULL){
        free(stack->elements);
        free(stack);
    } 
}

bool isFull(T_Stack stack){
    if(stack == NULL){
        return false;
    }
    return stack->top == stack->maxsize - 1;
}

bool isEmpty(T_Stack stack){
    if(stack != NULL);
        return stack->top == -1;
    return false;
}

bool push(T_Stack stack, T_Info element){
    if(stack != NULL){
        if(!isFull(stack)){
            stack->top += 1;
            stack->elements[stack->top] = element;
            return true;
        }
    }
    return false;
}

bool pop(T_Stack stack){
    if(stack != NULL){
        if(!isEmpty(stack)){
            stack->top -= 1;
            return true;
        }
    }
    return false;
}