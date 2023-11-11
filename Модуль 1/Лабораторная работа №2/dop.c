#include <stdio.h>
#include "safeInput.h"
#include <math.h>

#define lmax 200

int sum(int num) {
    int s = 0;
    for (int i=1; i<ceil(log10(num)); i += 2) {
        s += (num/(int)pow(10, i))%10;
    }

    return s;
}


int main() {
    int n, z;
    int arr[lmax], m[lmax];

    printf("Enter n:\n");
    int *nums = enterNumbers(1, 1, lmax);
    n = nums[0];
    free(nums);
    
    printf("Enter z:\n");
    nums = enterNumbersCount(1);
    z = nums[0];
    free(nums);
    
    printf("Enter %d numbers\n", n);
    for (int i=0; i<n; i++) {
        nums = enterNumbersCount(1);
        arr[i] = nums[0];
        free(nums);
    }

    int k=-1;
    for (int i=0; i < n; i++) {
        if (sum(arr[i]) > z) {
            k++;
            m[k] = arr[i];
        }
    }

    for (int i=0; i<=k; i++) {
        printf("%d; ", m[i]);
    }

}
