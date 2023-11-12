#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>


void clearBuffer() {
    while(getchar() != '\n');
}

int* _enterInts(int count, int min_limit, int max_limit) {
    int *nums = malloc(sizeof(int)*count);
    float input;
    int inputCode;

    for (int i=0; i<count; i++) {
        inputCode = scanf("%f", &input);

        if (!inputCode || input < min_limit || input > max_limit || ((int)input) != input) {
            clearBuffer();
            printf("Wrong input! Enter %d more numbers!\n", count-i);
            i--;
        }
        else
            nums[i] = (int)input;
    }

    return nums;
}

void enterIntRanged(int *dir, int minLimit, int maxLimit) {
    int *nums = _enterInts(1, minLimit, maxLimit);
    *dir = nums[0];
    free(nums);
}

void enterInt(int *dir) {
    int *nums = _enterInts(1, INT_MIN, INT_MAX);
    *dir = nums[0];
    free(nums);
}

void enterInts(int count, ...) {
    va_list arg;
    va_start(arg, count);
    
    int *nums = _enterInts(count, INT_MIN, INT_MAX);
    for (int i=0; i<count; i++)
        *va_arg(arg, int*) = nums[i];
    free(nums);
    va_end(arg);
}

void enterIntsRanged(int minLimit, int maxLimit, int count, ...) {
    va_list arg;
    va_start(arg, count);
    int *nums = _enterInts(count, minLimit, maxLimit);
    for (int i=0; i<count; i++) 
        *va_arg(arg, int*) = nums[i];
    free(nums);
    va_end(arg);
}

void enterIntArrayRanged(int *ptr, int minLimit, int maxLimit, int len) {
    int *nums = _enterInts(len, minLimit, maxLimit);
    for (int i=0; i<len; i++)
        ptr[i] = nums[i];
    free(nums);
    
}

void enterIntArray(int *ptr, int len) {
    enterIntArrayRanged(ptr, INT_MIN, INT_MAX, len);
}



float *_enterFloats(int count, float min_limit, float max_limit) {
    float *nums = malloc(sizeof(float)*count);
    double input;
    int inputCode;

    for (int i=0; i<count; i++) {
                inputCode = scanf("%lf", &input);

        if (!inputCode || input < min_limit || input > max_limit) {
            clearBuffer();
            printf("Wrong input! Enter %d more numbers:\n", count-i);
            ;
            i--;
        }
        else
            nums[i] = (float)input;
    }

    return nums;
}


void enterFloatRanged(float *ptr, float min_val, float max_val) {
    float *nums = _enterFloats(1, min_val, max_val);
    *ptr = nums[0];
    free(nums);
}

void enterFloat(float *ptr) {
    float *nums = _enterFloats(1, FLT_MIN, FLT_MAX);
    *ptr = nums[0];
    free(nums);
}

void enterFloatsRanged(float min_val, float max_val, int count, ...) {
    va_list arg;
    va_start(arg, count);
    float *nums = _enterFloats(count, min_val, max_val);

    for (int i=0; i<count; i++) {
        float *ptr = va_arg(arg, float*);
        *ptr = nums[i];
    }

    free(nums);
    va_end(arg);
}

void enterFloats(int count, ...) {
    va_list arg;
    va_start(arg, count);
    float *nums = _enterFloats(count, FLT_MIN, FLT_MAX);

    for (int i=0; i<count; i++) {
        float *ptr = va_arg(arg, float*);
        *ptr = nums[i];
    }

    free(nums);
    va_end(arg);
}


void printIntArray(int len, int *arr) {
    printf("{");
    if (len < 1) {
        printf("}");
        return;
    }
    for (int i=0; i<len-1; i++)
        printf("%d, ", arr[i]);
    printf("%d}", arr[len-1]);
}

void enterString(char *ptr, int len) {
    clearBuffer();

    char sym;
    for (int i=0; i<len-1; i++) {
        scanf("%c", &sym);
        if (sym == '\n') {
            ptr[i] = '\0';
            return;
        }
        ptr[i] = sym;
    }
    ptr[len-1] = '\0';
}

void printString(char *ptr, int len) {
    for (int i=0; i<len; i++) 
        printf("%c", ptr[i]);
    
}


// void enterNumbersFRanged(const char *str, ...) {
//     int len = strlen(str);
//
//     va_list arg;
//     va_start(arg, str);
//
//     int left = 0, right = 0;
//
//     int curRange = 0;
//     
//     for (int i=0; i<len; i++) {
//         char sym = str[i];
//         if (sym == ' ') {
//
//         }
//         else if (sym == ',') {
//             curRange++;
//         } 
//         else if (sym == ';') {
// #ifdef DEBUG
//             if (left > right) printf("Error: Left range greater then right!");
// #endif
//             int* ptr = va_arg(arg, int*);
//             enterNumberRanged(ptr, left, right);
//             curRange = 0;
//             left = right = 0;
//         }
//         else {
//             if (!curRange) {
//                 left = left*10 + (int)(sym-'0');
//             }
//             else {
//                 right = right*10 + (int)(sym-'0');
//             }
//         }
//     }
//
// }
