#include <stdio.h>

int main() {
    int k = 100;
    int a[4] = {0, 1, 2, 3};
    int b[4] = {4, 5, 6, 7};
    int c[4] = {8, 9, 10, 11};
    a[-1] = 0xAA;
    a[7] = 0xBB, a[10] = 0xCC;
    c[-2] = 0xDD, c[-6] = 0xEE;
    printf("  k = %d  (0x%x)\n", k, k);
    for(int i=0;i<12; i++) {
        printf("%3d (0x%x) ", a[i], a[i]);
        if ((i+1) % 4 == 0) 
            printf("\n");
    }
}