#include <stdio.h>
#include "../../safeIO.h"

#define STRING_SIZE 50
#define MAX_STRING_COUNT 10 // less then 255


int isLatinSymbol(char s) {
    return (s >= 65 && s <= 90) || (97 <= s && s <= 122);
}

int isNumericSymbol(char s) {
    return (s >= 48 && s <= 57);
}


void copy(char *start, char *end, char *dest_start, int dest_len) {
    while(start <= end) {
        *dest_start = *start;
        dest_start++;
        start++;
        dest_len--;
    }
    for (;dest_len;dest_len--) {
        *dest_start = ' ';
        dest_start++;
    }
}


int find_substrI(int k, char str[MAX_STRING_COUNT][STRING_SIZE], char r_str[][STRING_SIZE+1]) {
    int j = 0;
    char cur_s_num = 0;
    int find;
    char *cur_s, *f_sym, *s_sym;

    for (cur_s = *str; cur_s<str[k-1]+STRING_SIZE; cur_s += STRING_SIZE) {
        for (f_sym = cur_s; *f_sym != '\0'; f_sym++) {
            for (s_sym = f_sym+1; *s_sym != '\0'; s_sym++) {
                if (isLatinSymbol(*f_sym) && isLatinSymbol(*s_sym)) {
                    *r_str[j] = cur_s_num;
                    copy(f_sym, s_sym, r_str[j]+1, STRING_SIZE);
                    j++;
                }
            }
        }
        cur_s_num++;
    }

    return j;
}


char *findSubstrII(int sub_c, char r_str[MAX_STRING_COUNT][STRING_SIZE+1]) {
    int max = 0, count;
    char *s = NULL;

    for (int i=0; i<sub_c; i++) {
        count = 0;
        for (int j=1; j<STRING_SIZE+1; j++) {
            if (isNumericSymbol(r_str[i][j]))
                count++;
        }
        if (count > max) {
            max=count;
            s = r_str[i];
        }
    }

    return s;
}


int delIII(char *str) {
    int dest=0;
    for (int i=0; i==0 || str[i-1] != '\0'; i++)
        if (!isLatinSymbol(str[i])) {
            str[dest] = str[i];
            dest++;
        }
}


int main() {
    int k;
    char *a = "ab";
    char str[MAX_STRING_COUNT][STRING_SIZE], r_str[MAX_STRING_COUNT*2][STRING_SIZE+1];

    printf("Enter k from 1 to %d: \n", MAX_STRING_COUNT);
    enterIntRanged(&k, 1, MAX_STRING_COUNT);
    
    printf("Enter %d strings:\n", k);
    clearBuffer();
    for (char *i=*str; i<str[k-1]+STRING_SIZE; i += STRING_SIZE)
        enterString(i, STRING_SIZE);

    int sub_c = find_substrI(k, str, r_str);

    if (sub_c == 0) {
        printf("I. Substrings not found!\n");
        return 0;
    }
    else {
        printf("Answer I:\n");
        for (int i=0; i<sub_c; i++) {
            printf("\t%d. ", i+1);
            printString(r_str[i]+1, STRING_SIZE);
            printf("\n");
        }
    }
    

    char *sub_s = findSubstrII(sub_c, r_str);

    if (sub_s == NULL) {
        printf("II. Substring not found!\n");
        return 0;
    }
    else {
        printf("Answer II: ");
        printString(sub_s+1, STRING_SIZE);
        printf("\n");
    }

    delIII(str[(int)sub_s[0]]);
    
    printf("Answer III: ");
    printString(str[(int)sub_s[0]], STRING_SIZE);

    return 0;
}
