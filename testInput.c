#include "safeInput.h"

#define lmax 200
#define lmaxs "200"


int main() {
    int a, b;
    printf("Enter a from 1 to "lmaxs" and b from 100 to 200:\n");
    enterNumberRanged(&a, 1, lmax);
    enterNumberRanged(&b, 100, 200);
    printf("You entered: %d, %d\n", a, b);
    int nums[10];

    enterArrayRanged(nums, 10, 20);

    return 0;
}
