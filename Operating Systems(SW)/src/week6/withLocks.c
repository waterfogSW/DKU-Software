#include <stdio.h>
#include <pthread.h>

typedef struct __counter_t {
    int value;
    pthread_mutex_t lock;
} counter_t;

typedef struct MultipleArg {
	counter_t *c;
}MA;

void init(counter_t *c) {
    c->value = 0;
    pthread_mutex_init(&c->lock, NULL);
}

void increment(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return rc;
}


int main() {
    pthread_t t1, t2, t3;
    counter_t c;

    MA *multiple_arg;
    
    init(&c);
    
    pthread_create(&t1, NULL, increment, &c);
	pthread_create(&t2, NULL, increment, &c);
    pthread_create(&t3, NULL, increment, &c);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("%d \n", get(&c));
}