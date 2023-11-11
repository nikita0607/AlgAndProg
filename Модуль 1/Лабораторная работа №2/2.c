#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define bool int


#define lmax 20


bool isPalindrome(int num) {
    int nums = 0;
    int digitCount = ceil(log10(num));

    for (int i=0; i<=digitCount-1; i++) {
        nums += pow(10, digitCount-1-i)*((int)(num/pow(10, i))%10);
    }

    return nums == num;
}


int main() {
    printf("Task 2 \n\
            \r\r\rEnter n from 1 to %d\n", lmax);
    int n;

    do {
        scanf("%d", &n);
        while(getchar() != '\n');
    } while (n < 1 || n > lmax);

    int a[lmax+1], b[lmax+1];

    printf("Enter %d numbers:\n", n);


    for (int* i=a+1; i<=a+n; i++) {
        do {
            scanf("%d", i);
        } while(*i < 0);
    }
    
    int k = 0;
    for (int i=1; i<=n; i++) {
        if (isPalindrome(a[i])) {
            k++;
            b[k] = a[i];
        }
    }

    if (k == 0) {
        printf("Failed to create array");
        return 0;
    }

    printf("B = [");
    for (int i=1; i<=k; i++) {
        printf("%d ", b[i]);
    }
    printf("]");

    return 0;
}
