#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int
main(int argc, char *argv[])
{
    int x = 100;
    int status;
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        x = 98;
        int re;
        re = wait(&status);
        printf("%d\n", re);
    } else {
        // parent goes down this path (original process)
        int re;
        re = wait(&status);
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        printf("%d\n", re);
    }
    return 0;
}