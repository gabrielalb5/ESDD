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