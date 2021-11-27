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

/* FCFS : first come first serve */
void fcfs() {
    init();
    char output[total_time];
    int next_idx = 0;
    int cpu_time = 0;

    Process *cur= &task[next_idx++];
    while (cpu_time < total_time) {
        /* enqueue arrived task to ready queue */
        while (next_idx < proc_num && task[next_idx].ariv_t == cpu_time) {
            enqueue(&task[next_idx++]);
        }
        /* set output */
        output[cpu_time++] = cur->p_name;
        run(cur);
        /* complet porcess & schedule new process from ready queue */
        if(cur->rema_t == 0) {
            cur = dequeue();
        }
    }

    printf("fcfs        : ");
    printOutput(output);
}

/* SPN  : shortest process next */
void spn() {
    init();
    char output[total_time];
    int next_idx = 0;
    int cpu_time = 0;

    Process *cur= &task[next_idx++];
    while (cpu_time < total_time) {
        while (next_idx < proc_num && task[next_idx].ariv_t == cpu_time) {
            enqueue(&task[next_idx++]);
        }
        /* sort ready queue by service time, to get shortest process next */
        sortbyServ();
        output[cpu_time++] = cur->p_name;
        run(cur);
        if(cur->rema_t == 0) {
            cur = dequeue();
        }
    }
    printf("spn         : ");
    printOutput(output);
}

/* RR   : round robin */
void rr(int q) {
    init();
    char output[total_time];
    int next_idx = 0;
    int cpu_time = 0;
    int flag = 0;   //to notify that time quantum has expired
    Process *cur= &task[next_idx++];
    Process *tmp;
    setTimeQ(q);

    while (cpu_time < total_time) {
        while (next_idx < proc_num && task[next_idx].ariv_t == cpu_time) {
            enqueue(&task[next_idx++]);
        }
        /*The flag at this location ensures that the currently
            running process follows the newly arrived process. */
        if(flag == 1) {
            enqueue(tmp);
            cur = dequeue();
            flag = 0;
        }
        output[cpu_time++] = cur->p_name;
        run(cur);
        if(cur->rema_t <= 0) {
            cur = dequeue();
        } else if(cur->time_q <= 0) {
            tmp = cur;
            tmp->time_q = q;
            flag = 1;
        }
    }
    printf("rr(q=%d)     : ", q);
    printOutput(output);
}

void mlfq_1() {
    init();
    char output[total_time];
    int next_idx = 0;
    int cpu_time = 0;
    int flag = 0;   // 1: process complete, 2: time quantum expired
    Process *cur= &task[next_idx++];
    setTimeQ(1);

    while (cpu_time < total_time) {
        while (next_idx < proc_num && task[next_idx].ariv_t == cpu_time) {
            enqueue(&task[next_idx++]);
        }
        if(flag == 1) {
            if (rq.count > 0) {
                promote(cur,1);
                enqueue(cur);
                sortbylevel();
                cur = dequeue();
            } else {
                cur->time_q = 1;
            }
            flag = 0;
        }
        if(flag == 2) {
            sortbylevel();
            cur = dequeue();
            flag = 0;
        }
        output[cpu_time] = cur->p_name;
        run(cur);
        if(cur->rema_t <= 0) {
            flag = 2;
        } else if (cur->time_q <= 0) {
            flag = 1;
        }
        cpu_time++;
    }
    printf("mlfq(q=1)   : ");
    printOutput(output);
}

void mlfq_2() {
    init();
    char output[total_time];
    int next_idx = 0;
    int cpu_time = 0;
    int flag = 0;
    Process *cur= &task[next_idx++];
    setTimeQ(1);

    while (cpu_time < total_time) {
        while (next_idx < proc_num && task[next_idx].ariv_t == cpu_time) {
            enqueue(&task[next_idx++]);
        }
        if(flag == 1) {
            if (rq.count > 0) {
                promote(cur,2);
                enqueue(cur);
                sortbylevel();
                cur = dequeue();
            } else {
                cur->time_q = pow_2(cur->qlevel);
            }
            flag = 0;
        }
        if(flag == 2) {
            sortbylevel();
            cur = dequeue();
            flag = 0;
        }
        output[cpu_time] = cur->p_name;
        run(cur);
        if(cur->rema_t <= 0) {
            flag = 2;
        } else if (cur->time_q <= 0) {
            flag = 1;
        }
        cpu_time++;
    }
    printf("mlfq(q=2)   : ");
    printOutput(output);
}

void lott() {
    init();
    char output[total_time];
    int next_idx = 0;
    int cpu_time = 0;
    int complete = 0;

    Process *cur;
    enqueue(&task[0]);
    while(cpu_time < total_time) {
        while (next_idx < proc_num && task[next_idx].ariv_t == cpu_time) {
            enqueue(&task[next_idx++]);
        }
        cur = get_winner();
        run(cur);
        output[cpu_time++] = cur->p_name;
        if(cur->rema_t <= 0) del_data(cur);
    }
    printf("lottery     : ");
    printOutput(output);
}
