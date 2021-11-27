#include<stdio.h>

int main() {
    char dum[4];
    int cookie;
    char buf[20];

    printf("buf: %p, &cookie: %p\n", buf, &cookie);
    gets(buf);
    if(cookie == 0x41424344)
        printf("you win!\n");
}