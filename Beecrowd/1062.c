//BEECROWD 1062 - TRILHOS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack* T_Stack;
typedef int T_Info;

T_Stack init(int maxsize);
void destroy(T_Stack stack);
bool isFull(T_Stack stack);
bool isEmpty(T_Stack stack);
bool push(T_Stack stack, T_Info element);
bool pop(T_Stack stack, T_Info* element);
int getTopPosition(T_Stack stack);
int getTop(T_Stack stack);

struct stack {
    int top;
    int maxsize;
    T_Info* elements;
};

int main() {
    int qtdVagoes, vagao;
    
    // Leitura do número de vagões
    while (scanf("%d", &qtdVagoes) && qtdVagoes != 0) {
        // Processar cada permutação para este número de vagões
        while (scanf("%d", &vagao) && vagao != 0) { // O loop termina quando 'vagao' for zero
            // Inicializa a pilha para cada permutação
            T_Stack pilhaEntrada = init(qtdVagoes);
            T_Stack estacao = init(qtdVagoes);
            T_Stack pilhaSaida = init(qtdVagoes);
            bool possible = true;
            int currentVagao = 1; // O próximo vagão a ser colocado na pilha

            // A sequência de saída desejada começa com 'vagao' e continua até o fim
            T_Info* saidaDesejada = (T_Info*)malloc(qtdVagoes * sizeof(T_Info));
            saidaDesejada[0] = vagao;
            for (int i = 1; i < qtdVagoes; i++) {
                scanf("%d", &saidaDesejada[i]);
            }

            // Tenta criar a saída desejada com a pilha
            for (int i = 0; i < qtdVagoes; i++) {
                // Empilha os vagões até que o topo seja o desejado
                while (currentVagao <= qtdVagoes && (isEmpty(pilhaEntrada) || getTop(pilhaEntrada) != saidaDesejada[i])) {
                    push(pilhaEntrada, currentVagao++);
                }

                // Verifica se o topo da pilha é o que queremos
                if (!isEmpty(pilhaEntrada) && getTop(pilhaEntrada) == saidaDesejada[i]) {
                    pop(pilhaEntrada, &vagao);
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            destroy(pilhaEntrada);
            destroy(estacao);
            destroy(pilhaSaida);
            free(saidaDesejada);
        }
        printf("\n"); // Linha em branco após cada bloco
    }

    return 0;
}

T_Stack init(int maxsize) {
    T_Stack stack = NULL;
    if (maxsize > 0) {
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

void destroy(T_Stack stack) {
    if (stack != NULL) {
        free(stack->elements);
        free(stack);
    }
}

bool isFull(T_Stack stack) {
    if (stack == NULL) return false;
    return stack->top == stack->maxsize - 1;
}

bool isEmpty(T_Stack stack) {
    if (stack != NULL) return stack->top == -1;
    return false;
}

bool push(T_Stack stack, T_Info element) {
    if (stack != NULL) {
        if (!isFull(stack)) {
            stack->top += 1;
            stack->elements[stack->top] = element;
            return true;
        }
    }
    return false;
}

bool pop(T_Stack stack, T_Info* element) {
    if (stack != NULL) {
        if (!isEmpty(stack)) {
            *element = stack->elements[stack->top];
            stack->top -= 1;
            return true;
        }
    }
    return false;
}

int getTopPosition(T_Stack stack) {
    return stack->top;
}

int getTop(T_Stack stack) {
    return stack->elements[stack->top];
}