#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>

#include "lab2_sync.h"

void init(int _total) {
    init_line();
    
    total       = _total;
    info        = malloc(TYPE_NUM * sizeof(Prod_Info));
    rq.array    = (Prod_Info **)malloc(total * sizeof(Prod_Info *));
    rq.size     = total;
    rq.count    = 0;
    rq.front    = total-1;
    rq.rear     = total-1;

    parseInput(_total);
}

void init_line() {
    free(cq.buffer);
    p_num       = 0;
    es_time      = 0;
    eu_time      = 0;

    cq.buffer   = (char*)malloc(sizeof(char) * (LINE_SIZE + 10));
    cq.balance  = 0;
    cq.front    = 0;
    cq.rear     = 0;
}

/* Parse process information from input.txt file */
void parseInput () {
    FILE *fp;           // file pointer
    int line_num = 0;   // count number of line

    char    car_name;       // Parsed car_name
    int     start_time;     // Parsed starting time
    int     *volumes = (int*)malloc(sizeof(int)*TYPE_NUM);
    genVolume(volumes);

    /* input.txt file open */
    if((fp = fopen(FILE_NAME,"r")) == NULL) {
        fprintf(stderr, "Fail to open file: \"%s\", errno:%d\n", FILE_NAME, errno);
        perror("open\n");
        return;
    }

    /* Read file, parse pid, arrival time and service time */
    while(!feof(fp)) {
        /* Parse element of each line */
        fscanf(fp, "%c %d\n", &car_name, &start_time);

        /* Initialize process struct */
        info[line_num].c_name = car_name;
        info[line_num].star_t = start_time;
        info[line_num].volume = volumes[line_num];
        info[line_num].qaunty = volumes[line_num];

        line_num += 1;

        /* Show error when exceed the maximum number of lines */
        if(line_num > TYPE_NUM) {
            printf("Too many vehicle type inputted");
            return;
        }
    }
    free(volumes);
    fclose(fp);
}

/* Generate vehicle production volume by random */
void genVolume(int *a) {
    srand(time(NULL));
    int sum;
    do {
        sum = 0;
        for (int i = 0; i < TYPE_NUM; i++) {
            a[i] = rand() % ( total + 1 ) + 1;
            sum += a[i];
        }      
    } while ( sum != total );
}

void printInfo() {
    printf("┌──────Workload──────┐\n");
    printf("│Type  Time  Quantity│\n");
    printf("├────────────────────┤\n");
	for (int i = 0; i < TYPE_NUM; i++) {
		printf("│%3c  ", info[i].c_name);
		printf("%4d  ", info[i].star_t);
		printf("%7d  │\n", info[i].qaunty);
	}
    printf("└────────────────────┘\n");
}

void enqueue(Prod_Info *item){
	rq.rear = (rq.rear + 1) % rq.size;
	if(rq.rear == rq.front){
		rq.rear--;
	}else{
		rq.array[rq.rear] = item;	
	}
    rq.count++;
}

Prod_Info *dequeue(){
	if(rq.front == rq.rear){
		return NULL;
	}
	rq.front = (rq.front + 1) % rq.size;
    rq.count--;
	return rq.array[rq.front];
}

void rr(int q) {
    order = malloc(sizeof(int)*total);
    int next_idx = 0;
    int cpu_time = 0;
    int flag = 0;   //to notify that time quantum has expired
    Prod_Info *cur= &info[next_idx++];
    Prod_Info *tmp;
    
    for (int i = 0; i < TYPE_NUM; i++) {
        info[i].time_q = q;
    }

    while (cpu_time < total) {
        while (next_idx < TYPE_NUM && info[next_idx].star_t == cpu_time && info[next_idx].volume != 0) {
            enqueue(&info[next_idx++]);
        }
        /*The flag at this location ensures that the currently
            running process follows the newly arrived process. */
        if(flag == 1) {
            enqueue(tmp);
            cur = dequeue();
            flag = 0;
        }
        order[cpu_time++] = cur->c_name;
        cur->volume--;
        cur->time_q--;
        if(cur->volume <= 0) {
            cur = dequeue();
        } else if(cur->time_q <= 0) {
            tmp = cur;
            tmp->time_q = q;
            flag = 1;
        }
    }
}

void end() {
    free(rq.array);
    free(order);
    free(info);
}