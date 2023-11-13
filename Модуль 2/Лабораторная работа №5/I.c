#include <stdio.h>
#include <stdlib.h>
#include "../../safeIO.h"

// Variant(6, 6) 

int main() {
    int sr=0;
    int c=0;

    FILE *f = fopen("./I.txt", "w");
    int ptr;
    
    int num;
    int count = 0;
    printf("Enter 0-termined\n");

    do {
        enterInt(&num);
        if (num != 0 || count > 0) {
            count++;
            fprintf(f, "%d ", num);
        }
        else if (!count)
            printf("Enter numbers!\n");
    } while (num != 0 || !count);
    fclose(f);

    f = fopen("./I.txt", "r");
    
    int rnum;
    int k;
    
    do {
        fscanf(f, "%d", &rnum);
        printf("%d\n", rnum);
        if (rnum < 0) {
            sr += rnum;
            c++;
        }

    } while (rnum != 0);

    printf("sr = %f", c > 0 ? ((float)sr)/(float)c : 0);
}
