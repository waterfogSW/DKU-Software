/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32170578
*	    Student name : 김산
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H

#define Q_BUF 10                // Buffer size of ready queue
#define MAX_LEVEL 10            // MAX priority level
#define MAX_PROC_NUM 10         // MAX process number
#define FILE_NAME "./input.txt" // Input file name(path)

/* Process structure*/
typedef struct {
    char p_name;    // Process name 
    int ariv_t;     // Arrival time
    int rema_t;     // Remain time
    int serv_t;     // Service time
    int turn_t;     // Turnaround time
    int resp_t;     // Response time
    int time_q;     // time quatum
    int qlevel;     // Queue level(=priority)
    int ticket;     // Ticket num
} Process;

/* Ready queue structure*/
typedef struct{
    Process **array;    // Queue buffer
    int size;           // Queue size
    int count;          // Number of processes in the queue
    int front;          // Front index of queue
	int rear;           // Rear index of queue
} ReadyQueue;

/* Global variables */
int proc_num;               // number of process
int total_time;             // total execution time
char *output;               // record running process
Process task[MAX_PROC_NUM]; // task arrays
ReadyQueue rq;              // ready queue

/* lab1_ready_q.c : Ready Queue functions*/
void initReadyQueue(unsigned size);     // initialize ready queue
void del_data(Process *);               // delete data from queue
void enqueue(Process *);                // push item to ready queue
Process *dequeue();                     // pop item from ready queue
Process *getFront();                    // get first process of ready queue

/* lab1_init.c : Process initialize functions */
void init();            // initialize process
void parseInput();      // parse from input.txt file
void sortInput();       // sort task by arrival time
void setTotalTime();    // set Totaltime variable by sum of tasks service time
void setTimeQ(int);     // set time quantum

/* lab1_io.c : io functions */
void printQueue();
void printProcInfo();
void printOutput(char *);

/* lab1_sched.c : Scheduler functions */
void fcfs();            // FCFS : first come first serve
void spn();             // SPN  : shortest process next
void rr(int q);	        // RR   : round robin
void mlfq_1();		    // MLFQ : multi level feedback queue (q = 1)
void mlfq_2();		    // MLFQ : multi lesvel feedback queue (q = 2^i)
void lott();	        // implement at lottery.c

/* lab1_sch_in.c : Scheduler inner functions */
int pow_2(int);                 // Get power of first argument
int getTotaltickets();          // Get total tickets of current ready queue
int get_random();               // Get random number from a to b
void sortbyServ();              // Sort ready queue by service time
void sortbylevel();             // Sort ready queue by priority level
void promote(Process *,int);    // Promote priority level (1: q = 1, 2: q = 2^i)
void run(Process *);            // Run task 
void swap(Process *, Process *);// Swap Process
Process* get_winner();          // Get winner index at lottery scheduling

#endif /* LAB1_HEADER_H*/
