/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32170578
*	    Student name : 김산
*
*   lab1_io.c :
*       - Lab1 io function file.
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

void printQueue() {
    printf("Queue : ");
    for (int i = 1; i <= rq.count; i++) {
		int index = (rq.front + i) % rq.size;
        printf("%c ", rq.array[index]->p_name);
    }
    printf("\n");
}

void printProcInfo(){
    for (int i = 0; i < proc_num; i++) {
        printf("%c : %d, %d \n",task[i].p_name, task[i].ariv_t,task[i].serv_t);
    }
    printf("Process num : %d\n", proc_num);
    printf("Total  time : %d\n", total_time);
}

void printOutput(char* output){
    for (int i = 0; i < total_time; i++){
        printf("%c ", output[i]);
    }
    printf("\n");
}