//BEECROWD 1507 - SUBSEQUÊNCIAS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contem(char subString[], char string[]);

void main (){

	int i, j;
	char string[100000];
	char subString[1100];
	int qtsCasos, qtsStrings;

	scanf("%d", &qtsCasos);
	scanf("%s", string);

	for (i = 0; i < qtsCasos; ++i){
        scanf("%d", &qtsStrings);
        
        for (j = 0; j < qtsStrings; ++j){
			scanf("%s", subString);
			if (contem(subString, string))
				printf("Yes\n");
			else
				printf("No\n");
		}
		scanf("%s", string);
	}
}

bool contem(char subString[], char string[]){

	int i, j;
	int tamSubString, tamString;

	tamSubString = strlen(subString);
	tamString = strlen(string);

	for (i = 0, j = 0; i < tamString && j < tamSubString; i++)
		if (subString[j] == string[i])
			j++;

	if (j == tamSubString)
		return true;
	else
		return false;

}