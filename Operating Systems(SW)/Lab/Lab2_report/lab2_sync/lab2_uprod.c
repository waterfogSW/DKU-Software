#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#include "lab2_sync.h"

void put(char value) {
    cq.buffer[cq.rear] = value;
    cq.rear = (cq.rear + 1) % LINE_SIZE;
    cq.balance++;
    p_num++;
}

char get() {
    char tmp = cq.buffer[cq.front];
    cq.front = (cq.front + 1) % LINE_SIZE;
    cq.balance--;
    return tmp;
}

void *u_prod(void *arg) {
    while(p_num < total) {
        if(cq.balance < LINE_SIZE)
            put(order[p_num]);
    }
    return NULL;
}

void *u_consA(void *arg) {
    char tmp;
    while(p_num < total || cq.balance > 0) {
        if(cq.buffer[cq.front] == 'A')
            tmp = get();
    }
}

void *u_consB(void *arg) {
    char tmp;
    while(p_num < total || cq.balance > 0) {
        if(cq.buffer[cq.front] == 'B')
            tmp = get();
    }
}

void *u_consC(void *arg) {
    char tmp;
    while(p_num < total || cq.balance > 0) {
        if(cq.buffer[cq.front] == 'C')
            tmp = get();
    }
}

void *u_consD(void *arg) {
    char tmp;
    while(p_num < total || cq.balance > 0) {
        if(cq.buffer[cq.front] == 'D')
            tmp = get();
    }
}

void *u_consE(void *arg) {
    char tmp;
    while(p_num < total || cq.balance > 0) {
        if(cq.buffer[cq.front] == 'E')
            tmp = get();
    }
}

void u_process() {
    pthread_t p,c_a,c_b,c_c,c_d,c_e;
    struct timeval stime,etime,gap;

    gettimeofday(&stime,NULL);

    pthread_create(&p,NULL,u_prod,NULL);
    pthread_create(&c_a,NULL,u_consA,NULL);
    pthread_create(&c_b,NULL,u_consB,NULL);
    pthread_create(&c_c,NULL,u_consC,NULL);
    pthread_create(&c_d,NULL,u_consD,NULL);
    pthread_create(&c_e,NULL,u_consE,NULL);

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
}

