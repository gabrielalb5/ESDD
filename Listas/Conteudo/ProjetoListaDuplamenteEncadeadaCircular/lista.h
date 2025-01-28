#include "node.h"
#include <stdbool.h>

typedef struct linked_list* List;

List create();

void destroy(List list);

bool insert(List list, Info element);

bool insertAtBeggining(List list, Info element);

Info getInfoAt(List list, int position);

bool isEmpty(List list);

int size(List list);