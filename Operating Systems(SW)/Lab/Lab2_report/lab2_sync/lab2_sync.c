#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#include "lab2_sync.h"

void printLine() {
    for (int i = 0; i < cq.balance; i++) {
        int index = cq.front + i;
        printf("%c ", cq.buffer[index]);
    }
}

void lab2_sync_usage(char *cmd) {
	printf("\n Usage for %s : \n",cmd);
    printf("    -c: Total number of vehicles produced, must be bigger than 0 ( e.g. 100 )\n");
    printf("    -q: RoundRobin Time Quantum, must be bigger than 0 ( e.g. 1, 4 ) \n");
}

void lab2_sync_example(char *cmd) {
	printf("\n Example : \n");
    printf("    #sudo %s -c=100 -q=1 \n", cmd);
    printf("    #sudo %s -c=10000 -q=4 \n", cmd);
}

int main(int argc, char* argv[]) {
	char op;
	int n; char junk;
	int time_quantum = 0;
	int total_car = 0;

	if (argc <= 1) {
		lab2_sync_usage(argv[0]);
		lab2_sync_example(argv[0]);
		exit(0);
	}

	for (int i = 1; i < argc; i++) {
		if (sscanf(argv[i], "-c=%d%c", &n, &junk) == 1) {
			total_car = n;
		}
		else if (sscanf(argv[i], "-q=%d%c", &n, &junk) == 1) {
			time_quantum = n;
		}
		else {
			lab2_sync_usage(argv[0]);
			lab2_sync_example(argv[0]);
			exit(0);
		}
	}

    printf("====== Vehicle Production Problem ======\n");

    init(total_car);
    printInfo();
    rr(time_quantum);

    u_process();
    printf("(1) No Lock Exeperiment\n");
    printf("Exeperiment Info\n");
    printf("        Total Produce Number    = %d\n", p_num);
    printf("        Final Balance Value     = %d\n", cq.balance);
    printf("        Execution time          = %ld.%06ld\n", es_time,eu_time);

    init_line();
    c_process();
    printf("(2) Coarse-grained Lock Exeperiment\n");
    printf("Exeperiment Info\n");
    printf("        Total Produce Number    = %d\n", p_num);
    printf("        Final Balance Value     = %d\n", cq.balance);
    printf("        Execution time          = %ld.%06ld\n", es_time,eu_time);

    init_line();
    f_process();
    printf("(3) Fine-grained Lock Exeperiment\n");
    printf("Exeperiment Info\n");
    printf("        Total Produce Number    = %d\n", p_num);
    printf("        Final Balance Value     = %d\n", cq.balance);
    printf("        Execution time          = %ld.%06ld\n", es_time,eu_time);

    printf("========================================\n");
    end();
}