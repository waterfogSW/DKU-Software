#include <stdio.h>

typedef struct __counter_t {
    int value;
} counter_t;

void init(counter_t *c) {
    c->value = 0;
}

void increment(counter_t *c) {
    c->value++;
}

void decrement(counter_t *c) {
    c->value--;
}

int get(counter_t *c) {
    return c->value;
}


int main() {
    counter_t c;
    init(&c);
    increment(&c);
    printf("%d ", get(&c));
    increment(&c);
    printf("%d ", get(&c));
    decrement(&c);
    printf("%d ", get(&c));
}