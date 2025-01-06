#include <stdio.h>
#include "mecProject.h"
#include "setOfProjects.h"

int main(){

    Set projetos = init();

    insert(projetos, create(111, 1000.0));
    insert(projetos, create(151, 1500.0));
    insert(projetos, create(222, 2000.0));
    insert(projetos, create(252, 2500.0));
    insert(projetos, create(333, 3000.0));
    insert(projetos, create(353, 3500.0));
    insert(projetos, create(555, 5000.0));

    for(int i=0;i<size(projetos);i++){
        printf("%s",toString(getAt(projetos, i)));
    }

    return 0;
}