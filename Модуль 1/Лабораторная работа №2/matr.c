#include <stdio.h>


void printMatrix(int *mat, int row, int col) {
    for (int i=0; i<row; i++) {
        int *v = (mat+i);

        for (int j=0; j<col; j++) {
            printf("%d ", *(v+j));
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    n = m = 5;

    int mat[n][m];


    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            mat[i][j] = i+j;

    printMatrix((int *)mat, n, m);

}
