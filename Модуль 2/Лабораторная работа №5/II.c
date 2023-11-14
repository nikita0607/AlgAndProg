#include <stdio.h>
#include <stdlib.h>
#include "../../safeIO.h"
#include <string.h>
#include <locale.h>

#define STRING_SIZE 50
#define FILE_NAME_SIZE 10
// Variant(6, 6) 

int isrus(char sym) {
    return sym<0;
}

void delstrind(char *str, int ind) {
    for (int i=ind; i<STRING_SIZE-1; i++)
        str[i] = str[i+1];
}

void delrus(char str[STRING_SIZE]) {
    for (int i=0; i<STRING_SIZE && str[i] != '\0'; i++) {
        if (isrus(str[i])) {
            delstrind(str, i);
            if (i+1 != STRING_SIZE) i--;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    char name[FILE_NAME_SIZE];
    printf("Enter input file name:\n");
    enterString(name, FILE_NAME_SIZE);
    printf("%s", name);

    FILE *f = fopen(name, "r");
    printf("Enter output file name\n");
    enterString(name, FILE_NAME_SIZE);

    FILE *fo = fopen(name, "w");
    if (fo == NULL || f == NULL) {
        printf("ERROR!\n");
        return 0;
    }

    char str[STRING_SIZE];
    int k;
    do {
        k = fscanf(f, "%s", str);
        if (k != -1) {
            delrus(str);
            printf("%s\n", str);
            fprintf(fo, "%s\n", str);
        }
    } while (k != -1);

    fclose(f);


    
    
}
