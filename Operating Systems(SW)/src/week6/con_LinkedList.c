#include <stdio.h>
#include <pthread.h>

typedef struct __node_t {
    int             key;
    struct __node_t *next;
}node_t;

typedef struct __list_t {
    node_t          *head;
    pthread_mutex_t lock;
}list_t;

void List_Init(list_t *L) {
    L->head = NULL;
    pthread_mutex_init(&L->lock,NULL);
}

int List_Insert(list_t *L, int key) {
    /* Unnecessarily large lock areas 
    increase the likelihood of bugs occurring */
    
    // pthread_mutex_lock(&L->lock);
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