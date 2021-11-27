#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int foo1(void) {
    printf("in foo1(%p) \n", foo1);
    exit(0);
}

int foo2(char * str) {
    char buf[20];
    strcpy(buf,str);
    printf("in foo2 (%p) \n", foo2);
    return 1;
}

int main(int argc, char **argv) {
    foo2(argv[1]);
    printf("in main\n");
    return 1;
}

/*
cat /proc/sys/kernel/randomize_va_space
sudo sysctl -w kernel.randomize_va_space=0

*/