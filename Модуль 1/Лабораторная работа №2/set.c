#include <stdio.h>


void put(unsigned short *s, int val) {
    s[val/16] |= 1 << (val%16-1);
}


int has(unsigned short *s, int val) {
    return (s[val/16]>>(val%16-1)) & 1;
}


int main() {
    unsigned short s[2 << 16];
    unsigned int num = 4294967295;
    printf("%d\n", has(s, num));
    put(s, num);

    printf("%d\n", has(s, num));
    

    
}
