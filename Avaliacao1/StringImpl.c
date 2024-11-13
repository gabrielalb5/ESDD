#include "MyString.h"
#include <stdio.h>

struct myString{
    char* string;
};

T_String create(char* text){

    T_String minha_string;

    minha_string = malloc(sizeof(struct myString));

    minha_string->string = text;
    return minha_string;
}

void destory(T_String str){
    free(str);
}

char* toCString(T_String str){
    return str->string;
}

int length(T_String str){
    int tam = 0;

    if(str == NULL){
        return -1;
    }else{
        while(str->string[tam]!='\0'){
            tam++;
        }
        return tam;
    }
}

char charAt(T_String str, int index){
    if(index>length(str))
        return '\0';
    else
        return str->string[index];
}

int indexOf(T_String str, char c){
    int tamanho = length(str);
    int posicao = -1;

    for(int i=0;i<tamanho;i++){
        if(str->string[i] == c){
            posicao = i;
            break;
        }
    }

    return posicao;
}