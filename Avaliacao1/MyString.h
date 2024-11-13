#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct myString* T_String;

T_String create(char* text);

void destroy(T_String str);

char* toCString(T_String str);

int length(T_String str);

char charAt(T_String str, int index);

T_String concat(T_String str1, T_String str2);

T_String substring(T_String str, int start, int end);

T_String replace(T_String str, char oldChar, char newChar);

int indexOf(T_String str, char c);

T_String toUpper(T_String str);

T_String toLower(T_String str);
