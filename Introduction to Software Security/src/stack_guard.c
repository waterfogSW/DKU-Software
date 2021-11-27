#include <string.h>
#include <stdio.h>
#define goodPass "GOODPASS"

int main() {
    char passIsGood = 0;
    short canary = 20;
    char buf[28];

    printf("%08x, %08x, %08x\n", buf, &canary, &passIsGood);
    printf("Enter password: \n");
    gets(buf);
    printf("%d (0x%x)\n", canary,canary);
    if(canary != 20) {
        printf("buffer overflow attack!\n");
        return -1;
    }

    if(strcmp(buf,goodPass)==0) passIsGood = 1;
    if(passIsGood == 1) printf("you win!\n");
}
