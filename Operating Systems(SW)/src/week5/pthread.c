#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void *mythread(void *arg) {
    return NULL;
}

int main() {
    double sum, avg;
    struct timespec begin, end;
    pthread_t p;

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        if(fork() == 0) { exit(0);}
        // pthread_create(&p,NULL,mythread,"A");
        clock_gettime(CLOCK_MONOTONIC, &end);
        sum +=  (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    }
    avg = sum / 1000;
    printf("fork           : %lf\n", avg);

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        pthread_create(&p,NULL,mythread,"A");
        clock_gettime(CLOCK_MONOTONIC, &end);
        sum +=  (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    }
    avg = sum / 1000;
    printf("pthread_create : %lf\n", avg);
    return 0;
}