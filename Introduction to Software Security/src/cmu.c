#include <stdio.h>

typedef int zip_dig[5];

int main() {
    zip_dig cmu = {1,5,2,1,3};
    zip_dig mit = {0,2,1,3,9};
    zip_dig ucb = {9,4,7,2,0};

    printf("%p \n", cmu);
    printf("%p \n", mit);
    printf("%p \n", ucb);
    
    printf("%d, %d, %d, %d\n", mit[-5], mit[-4], mit[8], mit[9]);
}