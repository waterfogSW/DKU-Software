/*
*   DKU Operating System Lab
*           Lab2 (Vehicle production Problem)
*           Student id : 32170578
*           Student name : 김산
*
*   lab2_sync.c :
*       - lab2 main file.
*       - must contains Vehicle production Problem function's declations.
*
*/

#ifndef _LAB2_SYNC_H
#define _LAB2_SYNC_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LINE_SIZE 10                // Production Line Size
#define TYPE_NUM 5                  // Car type num
#define FILE_NAME "./workload.txt"  // Workload file (path)

typedef struct {
    char    c_name;         // Car name
    int     star_t;         // Start time
    int     time_q;         // Time quantum
    int     volume;         // Production volume
    int     qaunty;         // Production qauntity
} Prod_Info;

typedef struct{
    Prod_Info **array;      // Queue buffer
    int         size;       // Queue size
    int         count;      // Number of processes in the queue
    int         front;      // Front index of queue
	int         rear;       // Rear index of queue
} ReadyQueue;

typedef struct car_queue {
    char    *buffer;        // Car queue buffer
	int     balance;        // Car queue balance count
    int     front;          // Car queue front index
    int     rear;           // Car queue rear index
} CarQueue;

Prod_Info   *info;          // Production info
ReadyQueue  rq;             // Ready queue
CarQueue    cq;             // Car queue
char        *order;         // Production order
int         p_num;          // Production count
int         c_num;          // Cosumtion count
int         total;          // Total production count
long int    es_time;        // Execution time (sec)
long int    eu_time;        // Execution time (usec)

pthread_cond_t  empty;      // When queue is empty
pthread_cond_t  fill;       // When queue is filled 
pthread_mutex_t mutex;      // Coarse-grained lock
pthread_mutex_t head;       // Fine-grained lock head
pthread_mutex_t tail;       // Fine-grained lock tail

/*lab2_init.c*/
void init(int);             // Initialize process
void init_line();           // Initialize production line
void parseInput();          // Parse from workload.txt file
void genVolume(int*);       // Generate Vehicle production volume by random
void printInfo();           // Print production information
void enqueue(Prod_Info *);  // Push item to ready queue
Prod_Info *dequeue();       // Pop item from ready queue
void rr(int);               // Round robin
void end();                 // Free the memory

/* lab2_uprod.c */
void put(char);
char get();

void *u_prod(void *);       // Unlocked producer
void *u_consA(void *);      // Unlocked Consumer A
void *u_consB(void *);      // Unlocked Consumer B
void *u_consC(void *);      // Unlocked Consumer C
void *u_consD(void *);      // Unlocked Consumer D
void *u_consE(void *);      // Unlocked Consumer E
void u_process();

/* lab2_cprod.c */
void *c_prod(void *);       // Coarse-grained lock Producer
void *c_consA(void *);      // Coarse-grained lock Consumer A
void *c_consB(void *);      // Coarse-grained lock Consumer B
void *c_consC(void *);      // Coarse-grained lock Consumer C
void *c_consD(void *);      // Coarse-grained lock Consumer D
void *c_consE(void *);      // Coarse-grained lock Consumer E
void c_process();

/* lab2_fprod.c */
void *f_prod(void *);       // Fine-grained lock Producer
void *f_consA(void *);      // Fine-grained lock Consumer A
void *f_consB(void *);      // Fine-grained lock Consumer B
void *f_consC(void *);      // Fine-grained lock Consumer C
void *f_consD(void *);      // Fine-grained lock Consumer D
void *f_consE(void *);      // Fine-grained lock Consumer E
void f_process();

void printLine();

#endif