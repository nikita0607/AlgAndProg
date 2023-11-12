#include <stdio.h>
#include "../../safeIO.h"
#define lmax 10

int findRep(int n, int *arr, int* reps, int* repc) {
    int *bn=reps;
    int *j;
    for (int *i=arr; i<arr+n; i++) {
        for (j=reps; j<bn && *j != *i; j++);

        if (j == bn) {
            *bn = *i;
            *(repc-reps+bn) = 1;
            bn++;
        }
        else {
            (*(repc-reps+j))++;
        }
    }

    return (int)(bn-reps);
}

int delNonRep(int n, int *a, int cl_arr_len, int *reps, int *repc) {
    int *j=a;
    for (int *i=reps; i<reps+cl_arr_len; i++) {
        if (*(repc-reps+i) == 1) {
            while(*j != *i) j++;
            for (int *l=j+1; l<a+n; l++) {
                *(l-1) = *l;
            }
            n--;
        }
    }
    
    return n;
}


int main() {
    printf("Task III.\n");
    int a[lmax], reps[lmax], repc[lmax];
    int n;

    printf("Enter n greater than 0 and less then %d:\n", lmax);
    enterIntRanged(&n, 1, lmax);

    printf("Enter array with %d elements:\n", n);
    enterIntArray(a, n);

    int cl_arr_len = findRep(n, a, reps, repc);
    int k = delNonRep(n, a, cl_arr_len, reps, repc);

    if (k == n) {
        printf("Nothing to change!");
        return 0;
    }
  
    
    printf("A = ");
    printIntArray(k, a);

    return 0;
}
