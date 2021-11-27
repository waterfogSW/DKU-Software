/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32170578
*	    Student name : 김산
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
*
*/

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>

#include "lab1_sched_types.h"

/* get power of first argument */
int pow_2(int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= 2;
    }
    return res;
}

/* Get total tickets of current ready queue*/
int getTotaltickets(){
    int total = 0;
    for (int i = 1; i <= rq.count; i++) {
		int index = (rq.front + i) % rq.size;
        total += rq.array[index]->ticket;
    }
    return total;
}

/* Get random number from a to b*/
int get_random() {
    int random;
    int total = getTotaltickets();
    if(total == 0) return 0;
    random = rand() % total;
    return random;
}

/* Get winner process at lottery scheduling */
Process* get_winner() {
    int counter = 0;
    int index = 0;
    int winner = get_random();
    for (int i = 1; i <= rq.count; i++) {
        index = (rq.front + i) % rq.size;
        counter += rq.array[index]->ticket;
        if(counter > winner) {
            return rq.array[index];
        }
    }
}

/* Sort ready queue by service time */
void sortbyServ() {
    Process *tmp;
    int serv_tmp1;
    int serv_tmp2;
    int *idx = (int*)malloc(sizeof(int)*rq.count);

    for (int i = 0; i < rq.count; i++) {
        idx[i] = (rq.front + i + 1) % rq.size;
    }

    for (int i = rq.count - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            serv_tmp1 = rq.array[idx[j]]->serv_t;
            serv_tmp2 = rq.array[idx[j+1]]->serv_t;
            if(serv_tmp1 > serv_tmp2) {
                swap(rq.array[idx[j]],rq.array[idx[j+1]]);
            }
        }    
    }
    free(idx);
}

void sortbylevel() {
    Process *tmp;
    Process *tmp_arr[rq.count+1];
    int next = 1;
    int index = 0;
    while (next <= rq.count){
        for (int i = 0; i < MAX_LEVEL; i++) {
            for (int j = 1; j <= rq.count; j++) {
		        index = (rq.front + j) % rq.size;
                if(i == rq.array[index]->qlevel) {
                    tmp_arr[next++] = rq.array[index];
                }
            }
        }
    }

    for (int i = 1; i <= rq.count; i++) {
        index = (rq.front + i) % rq.size;
        rq.array[index] = tmp_arr[i];
    }
    
}

/* promote current running task (1: q = 1, 2: q = 2^i)*/
void promote(Process *p, int i) {
    Process *tmp = p;
    p->qlevel++;
    switch (i) {
    case 1:
        p->time_q = 1;
        break;
    case 2:
        p->time_q = pow_2(p->qlevel);
        break;
    default:
        printf("promote option error");
        return;
    }
}

/* run process */
void run(Process *run) {
    run->rema_t--;
    run->time_q--;
}

void swap(Process *a, Process *b) {
    Process tmp = *a;
    *a = *b;
    *b = tmp;
}