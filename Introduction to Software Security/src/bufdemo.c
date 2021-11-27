#include<stdio.h>

int main() {
    printf("Type a string: ");
    echo();
    return 0;
}

void echo() {
    char buf[4];
    gets(buf);
    puts(buf);
}