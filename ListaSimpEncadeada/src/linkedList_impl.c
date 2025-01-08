#include "linkedList.h"

struct simple_linked_list{
    NodePtr head;
};

List createList(){
    List list = malloc(sizeof(struct simple_linked_list));
    list->head = NULL;
    return list;
}

void destroyList(List list);

bool insertList(List list, Info element){
    NodePtr node, walker;
    bool result = false;

    if(list != NULL){
        node = createNode();
        setInfo(node, element);
        setNext(node, NULL);

        if(list->head == NULL){
            list->head = node;
            return true;
        }else{
            walker = list->head;
            while(getNext(walker) != NULL){
                walker = getNext(walker);
            }
            setNext(walker, node);
            return true;
        }
    }

    return result;
}

Info getInfoAt(List list, int position);

bool isEmpty(List list);

int size(List list);