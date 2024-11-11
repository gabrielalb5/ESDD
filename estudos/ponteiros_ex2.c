#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[50];
    float media;
    int faltas;
};

void bubble(struct aluno *v, int q);
void relatorio(struct aluno *v, int q);

int main(){
    int q;
    printf("Quantidade de alunos: ");
    scanf("%d",&q);

    struct aluno *v = (struct aluno *)malloc(q * sizeof(struct aluno));
    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for(int i=0;i<q;i++){
        printf("Nome: ");
        scanf(" %s",v[i].nome);
        printf("Média: ");
        scanf("%f",&v[i].media);
        printf("Faltas: ");
        scanf("%d",&v[i].faltas);
    }
    
    bubble(v,q);
    relatorio(v,q);
    
    free(v);
    
    return 0;
}

void bubble(struct aluno *v, int q){
    int continua;
    struct aluno aux;
    
    do{
        continua = 0;
        for(int i=0;i<q-1;i++){
            if(v[i].media>v[i+1].media){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua=1;
            }
        }
    }while(continua!=0);
}

void relatorio(struct aluno *v, int q){
    printf("\n----- RELATÓRIO -----\n");
    for(int i=0;i<q;i++){
        printf("Nome: %s\n",v[i].nome);
        printf("Média: %.2f\n",v[i].media);
        printf("Faltas: %d\n\n",v[i].faltas);
    }
}