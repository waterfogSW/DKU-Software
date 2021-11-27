/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32170578
*	    Student name : 김산
*
*   lab1_io.c :
*       - Lab1 Ready queue function implementations
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

#include <limits.h>
#include "lab1_sched_types.h"

ReadyQueue rq;

void initReadyQueue(unsigned size){
	rq.rear = size-1;
	rq.front = size-1;
    rq.count = 0;
	rq.size = size;
	rq.array = (Process **)malloc(size * sizeof(Process *));
}

void del_data(Process *p) {
	int count = rq.count;
	Process *tmp;
	for (int i = 0; i < count; i++){
		tmp = dequeue();
		if(tmp != p){
			enqueue(tmp);
		}
	}
}

void enqueue(Process *item){
	rq.rear = (rq.rear + 1) % rq.size;
	if(rq.rear == rq.front){
		rq.rear--;
	}else{
		rq.array[rq.rear] = item;	
	}
    rq.count++;
}

Process *dequeue(){
	if(rq.front == rq.rear){
		return NULL;
	}
	rq.front = (rq.front + 1) % rq.size;
    rq.count--;
	return rq.array[rq.front];
}

Process *getFront() {
    int i = (rq.front + 1) % rq.size;
    return rq.array[i];
}
