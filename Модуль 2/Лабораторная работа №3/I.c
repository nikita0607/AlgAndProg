#include <stdio.h>
#include <safeIO.h>


float f(float x1, float x2, float x3, float y1, float y2, float y3, float x) {
    if (x1 <= x && x < x2) {
        return (float)y1 + ((float)(x-x1) / (x2-x1))*(y2-y1);
    }

    if (x2 <= x && x < x3) {
        return (float)y2 + ((float)(x-x2) / (x3-x1))*(y3-y2);
    }

    return (float)y3;
}


int main() {
    printf("Task I.\n");
    float x1, x2, x3, y1, y2, y3, x;


    do {
        printf("Enter x1, x2, x3, y1, y2, y3:\n");
        enterFloats(6, &x1, &x2, &x3, &y1, &y2, &y3);
    } while(!(x1 <= x2 && x2 <=  x3));
    
    for(;;) {
        printf("Enter x such that x1 <= x <= x3:\n");
        enterFloatRanged(&x, x1, x3);
        printf("f(%f) = %f\n", x, f(x1,x2,x3,y1,y2,y3, x));
    }
    

    return 0;
}
