#include <stdio.h>

#define lmax 50


void printMatrix(int mat[lmax+1][lmax+1], int rows, int columns) {
    for (int i=1; i<=rows; i++) {
        printf("[");
        for (int j=1; j<=columns; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("]\n");
    }
}


void sort(int* arr, int size) {
    int v;
    for (int i=1; i<size; i++) {
        for (int j=i+1; j>= 1 && j<=size; j++) {
            if (arr[i] < arr[j]) {
                v = arr[i];
                arr[i] = arr[j];
                arr[j] = v;
            }
        }
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}


int main() {
    int q[lmax+1][lmax+1], z[lmax+1];
    
    printf("Пырлицану Никита Евгеньевич \n\
    \rGroup: БИВ239 \n\
    \rVariant: 473 (15) \n\
    \rЛабораторная работа №2 \n\
    \rTask I \n\
    \rEnter n, m, k from 1 to %d\n", lmax);

    int n = 0;
    int k=1;
    int m = 0;
    do {
        scanf("%d %d %d", &n, &m, &k);
        clearBuffer();
    } while ((m<1 || m>lmax) || (n<1 || n>lmax) || (k<1 || k>lmax));

 
    printf("Input of matrix \nEnter %dx%d numbers:\n", n, m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) 
            scanf("%d", &q[i][j]);
    }

    printf("Enter %d numbers:\n", k);
    for (int i=1; i<=k; i++) 
        scanf("%d", &z[i]);

    int maxs = 0;
    for (int i=1; i<=k; i++) {
        if (z[i] > maxs)
            maxs = z[i];

    }

    int sortFlag = 0;

    for (int i=1; i<=n; i++) {
        int sum=0;
        int j=1;
        int flag=0;

        while (sum<=maxs && j<=m) {
            sum += q[i][j];
            j++;
        }
        if (sum > maxs)
            flag=1;
        j = 1;

        while (j<=k && flag==0) {
            if (sum == z[j])
                flag=2;
            j++;
        }

        if (flag == 2) {
            sort(q[i], m);
            sortFlag = 1;
        }
    }

    if (sortFlag) {
        printf("Q = \n");
        printMatrix(q, n, m);
    }
    else {
        printf("Nothing was sort");
    }

    return 0;
}
