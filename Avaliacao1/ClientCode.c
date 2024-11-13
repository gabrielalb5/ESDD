#include <stdio.h>
#include "MyString.h"

int main(){
    
    T_String string1 = create("Nunca quebre o TAD!");
    T_String string2 = create("Estrutura de Dados. ");
    T_String string3 = NULL;
    T_String string4 = NULL;

    printf("%s\n", toCString(string1));
    printf("Tamanho da String: %d\n", length(string1));
    printf("Tamanho da String: %d\n", length(string3));
    printf("Caractere em 15: %c\n", charAt(string1, 15));
    printf("Caractere em 25: %c\n", charAt(string2, 25));
    printf("D na posição: %d\n", indexOf(string2, 'D'));
    printf("q na posição: %d\n", indexOf(string3, 'q'));
    

    /*string3 = concat(string2, string1);
    if (string3 != NULL)
        printf("%s\n", toCString(string3));
    else
        printf("Erro ao concatenar.\n");

    string3 = concat(string1, string4);
    if (string3 != NULL)
        printf("%s\n", toCString(string3));
    else
        printf("Erro ao concatenar.\n");


    string3 = substring(string1, 15, 17);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar substring.\n");
    }

    string3 = substring(string2, 15, 0);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar substring.\n");
    }

    string3 = substring(string1, 15, 50);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar substring.\n");
    }

    string3 = substring(string4, 15, 17);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar substring.\n");
    }

    string3 = replace(string2, 'a', '@');
    if (string3 != NULL){
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao alterar caracteres.\n");
    }

    string3 = replace(string1, 'f', 'X');
    if (string3 != NULL){
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao alterar caracteres.\n");
    }

    string3 = replace(string4, 'a', 'X');
    if (string3 != NULL){
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao alterar caracteres.\n");
    }



    string3 = toUpper(string1);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar string maiúscula.\n");
    }

    string3 = toUpper(string4);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar string maiúscula.\n");
    }


    string3 = toLower(string4);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar string minúscula.\n");
    }

    string3 = toLower(string2);
    if (string3 != NULL) {
        printf("%s\n", toCString(string3));
    } else {
        printf("Erro ao gerar string minúscula.\n");
    }*/

    return 0;
}

/*
    A função main() acima gera a seguinte saída no terminal: 
    
Nunca quebre o TAD!
Tamanho da String: 19
Tamanho da String: -1
Caractere em 15: T
Caractere em 25: �
D na posição: 13
q na posição: -1
Estrutura de Dados. Nunca quebre o TAD!
Erro ao concatenar.
TAD
Erro ao gerar substring.
Erro ao gerar substring.
Erro ao gerar substring.
Estrutur@ de D@dos. 
Nunca quebre o TAD!
Erro ao alterar caracteres.
NUNCA QUEBRE O TAD!
Erro ao gerar string maiúscula.
Erro ao gerar string minúscula.
estrutura de dados.

 */