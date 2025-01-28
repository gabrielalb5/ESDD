#include <stdio.h>
#include "lista.h"

int main(){
    List lista = create();

    insert(lista, "Caio");
    insert(lista, "Luke");
    insert(lista, "Gabriel");

    int max = size(lista);
    for(int i=0;i<max;i++){
        printf("%s\n",getInfoAt(lista, i));
    }
    return 0;
}