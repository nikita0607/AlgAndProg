#include <stdio.h>
#include <stdlib.h>
#include "../../safeIO.h"
#include <limits.h>

#define lmax 10

int H(int n, int m, int b[][lmax]) {
    int max, min = INT_MAX;

    for (int *uj=*b; uj<(*b)+m; uj++) {
        max = *uj;
        for (int *ui=uj+lmax; ui<b[n-1]+m; ui+=lmax)
            if (abs(*ui) > max)
                max = abs(*ui);

        if (max < min)
            min = max;
    }

    return min;
}

int main() {
    printf("Task II.\n");
    int b[lmax][lmax];
    int n, m;

    printf("Enter n, m such that 1 <= n, m <= %d:\n", lmax);
    enterIntsRanged(1, lmax, 2, &n, &m);

    printf("Enter matrix %dx%d:\n", n, m);
    for (int i=0; i<n; i++) {
        printf("String %d:\n", i+1);
        enterIntArray(b[i], m);
    }

    printf("H = %d", H(n, m, b));
}
