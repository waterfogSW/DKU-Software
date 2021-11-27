#include <stdio.h>
#include <pthread.h>

#define BUCKETS (101)

typedef struct __node_t {
    int             key;
    struct __node_t *next;
}node_t;

typedef struct __list_t {
    node_t          *head;
    pthread_mutex_t lock;
}list_t;

typedef struct __hash_t {
    list_t lists[BUCKETS];

} hash_t;

void List_Init(list_t *L) {
    L->head = NULL;
    pthread_mutex_init(&L->lock,NULL);
}

int List_Insert(list_t *L, int key) {
    node_t *new = malloc(sizeof(node_t));
    if(new==NULL) {
        perror("malloc");
        pthread_mutex_unlock(&L->lock);
        return -1;
    }
    new->key = key;

    //Just Lock critical sections
    pthread_mutex_lock(&L->lock);
    new->next = L->head;
    L->head = new;
    pthread_mutex_unlock(&L->lock);
    return 0;
}

int List_Loockup(list_t *L, int key) {
    pthread_mutex_lock(&L->lock);
    node_t *curr = L->head;
    while(curr) {
        if(curr->key == key) {
            pthread_mutex_unlock(&L->lock);
            return 0;
        }
        curr = curr->next;
    }
    pthread_mutex_unlock(&L->lock);
    return -1;
}

void Hash_Init(hash_t *H) {
    for (int i = 0; i < BUCKETS; i++) {
        List_Init(&H->lists[i]);
    }
}

int Hash_Insert(hash_t *H, int key) {
    return List_Insert(&H->lists[key % BUCKETS], key);
}

int Hash_Lookup(hash_t *H, int key) {
    return List_Lookup(&H->lists[key % BUCKETS], key);
}