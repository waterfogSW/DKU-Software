/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32170578
*	    Student name : 김산
*
*   lab1_init.c :
*       - Lab1 initialize function implementations
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

int proc_num = 0;
int total_time = 0;

/* Initialize array of Process structure and output */
void init () {
    parseInput();
    sortInput(task);
    setTotalTime();
    initReadyQueue(10);
    srand(time(NULL));
}

/* Parse process information from input.txt file */
void parseInput () {
    FILE *fp;           // file pointer
    int line_num = 0;   // count number of line

    char pid_p;         // parsed process id
    int ariv_p;         // parsed arrival time
    int serv_p;         // parsed service time

    /* input.txt file open */
    if((fp = fopen(FILE_NAME,"r")) == NULL) {
        fprintf(stderr, "Fail to open file: \"%s\", errno:%d\n", FILE_NAME, errno);
        perror("open\n");
        return;
    }

    /* Read file, parse pid, arrival time and service time */
    while(!feof(fp)) {
        /* Parse element of each line */
        fscanf(fp, "%c %d %d\n", &pid_p, &ariv_p, &serv_p);

        /* Initialize process struct */
        task[line_num].p_name = pid_p;
        task[line_num].ariv_t = ariv_p;
        task[line_num].rema_t = serv_p;
        task[line_num].serv_t = serv_p;
        task[line_num].turn_t = -1;
        task[line_num].resp_t = -1;
        task[line_num].qlevel = 0;
        task[line_num].ticket = 100;

        line_num += 1;

        /* Show error when exceed the maximum number of lines */
        if(line_num > MAX_PROC_NUM) {
            perror("Too many processes has been executed : You can only execute below 10 processes!");
            return;
        }
    }
    fclose(fp);
    proc_num = line_num;
}

/* sort Input */
void sortInput(Process *p){
    Process temp;
    for (int i = proc_num - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if(p[j].ariv_t > p[j+1].ariv_t){
                temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;
            } else if(p[j].ariv_t == p[j+1].ariv_t && p[j].p_name > p[j+1].p_name) {
                temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;
            }
        }
    }
}

/* set total time global variable */
void setTotalTime() {
    int sum = 0;
    for (int i = 0; i < proc_num; i++) {
        sum += task[i].serv_t;
    }
    total_time = sum;
}

/* set time quantum of all tasks */
void setTimeQ(int q){
    for (int i = 0; i < proc_num; i++) {
        task[i].time_q = q;
    }
}