#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>

typedef struct __lock_t{
    int flag;
}lock_t;

static volatile int counter = 0;
lock_t mutex;

void init(lock_t *mutex) {
    mutex->flag = 0;
}

void lock(lock_t *mutex) {
    while(mutex->flag == 1);
    mutex->flag = 1;
}

void unlock(lock_t *mutex) {
    mutex->flag = 0;
}

void *mythread(void *arg) {
    printf("%s : begin\n", (char *) arg);
    for (int i = 0; i < 1e7; i++) {
        lock(&mutex);
        counter = counter + 1;
        unlock(&mutex);
    }
    printf("%s : done\n",(char*) arg);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t p1, p2;
    int rc;
    init(&mutex);
    printf("main: begin (counter = %d)\n", counter);
    rc = pthread_create(&p1, NULL, mythread, "A"); assert(rc==0);
    rc = pthread_create(&p2, NULL, mythread, "B"); assert(rc==0);

    rc = pthread_join(p1, NULL); assert(rc==0);
    rc = pthread_join(p2, NULL); assert(rc==0);

    printf("main: end (counter = %d)\n", counter);
    return 0;
}
