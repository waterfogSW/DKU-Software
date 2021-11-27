#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#include "lab2_sync.h"

void *f_prod(void *input) {
    for (int i = 0; i < total; i++) {
        pthread_mutex_lock(&tail);
        while (cq.balance == LINE_SIZE)
            pthread_cond_wait(&empty, &tail);
        put(order[i]);
        pthread_cond_broadcast(&fill);
        pthread_mutex_unlock(&tail);
    }
    while(cq.balance > 0) {
        pthread_cond_broadcast(&fill);
    }
    return NULL;
}

void *f_consA(void *multi_arg) {
    for (int i = 0; i < info[0].qaunty; i++) {
        pthread_mutex_lock(&head);
        while (cq.balance == 0 || cq.buffer[cq.front] != 'A')
            pthread_cond_wait(&fill, &head);
        get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&head);
    }
    return NULL;
}

void *f_consB(void *multi_arg) {
    for (int i = 0; i < info[1].qaunty; i++) {
        pthread_mutex_lock(&head);
        while (cq.balance == 0 || cq.buffer[cq.front] != 'B')
            pthread_cond_wait(&fill, &head);
        get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&head);
    }
    return NULL;
}

void *f_consC(void *multi_arg) {
    for (int i = 0; i < info[2].qaunty; i++) {
        pthread_mutex_lock(&head);
        while (cq.balance == 0 || cq.buffer[cq.front] != 'C')
            pthread_cond_wait(&fill, &head);
        get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&head);
    }
    return NULL;
}

void *f_consD(void *multi_arg) {
    for (int i = 0; i < info[3].qaunty; i++) {
        pthread_mutex_lock(&head);
        while (cq.balance == 0 || cq.buffer[cq.front] != 'D')
            pthread_cond_wait(&fill, &head);
        get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&head);
    }
    return NULL;
}

void *f_consE(void *multi_arg) {
    for (int i = 0; i < info[4].qaunty; i++) {
        pthread_mutex_lock(&head);
        while (cq.balance == 0 || cq.buffer[cq.front] != 'E')
            pthread_cond_wait(&fill, &head);
        get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&head);
    }
    return NULL;
}

void f_process() {
    pthread_t p,c_a,c_b,c_c,c_d,c_e;
    struct timeval stime,etime,gap;

    pthread_cond_init(&fill,NULL);
    pthread_cond_init(&empty,NULL);
    pthread_mutex_init(&head,NULL);
    pthread_mutex_init(&tail,NULL);

    gettimeofday(&stime,NULL);
    
    pthread_create(&p, NULL, f_prod,NULL);
    pthread_create(&c_a, NULL, f_consA,NULL);
    pthread_create(&c_b, NULL, f_consB,NULL);
    pthread_create(&c_c, NULL, f_consC,NULL);
    pthread_create(&c_d, NULL, f_consD,NULL);
    pthread_create(&c_e, NULL, f_consE,NULL);

    pthread_join(p,NULL);
    pthread_join(c_a,NULL);
    pthread_join(c_b,NULL);
    pthread_join(c_c,NULL);
    pthread_join(c_d,NULL);
    pthread_join(c_e,NULL);

    gettimeofday(&etime,NULL);

    gap.tv_sec = etime.tv_sec - stime.tv_sec;
	gap.tv_usec = etime.tv_usec - stime.tv_usec;

    if(gap.tv_usec < 0){
        gap.tv_sec = gap.tv_sec-1; 
        gap.tv_usec = gap.tv_usec + 1000000;
    }
    es_time = gap.tv_sec;
    eu_time = gap.tv_usec;
    free(cq.buffer);
}

