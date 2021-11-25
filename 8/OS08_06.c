#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int main() {
	int count = 0;
	struct timespec start, end, proc;
	clock_gettime(CLOCK_REALTIME, &start);
	for(;;) {
		count++;
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &proc);
		if(proc.tv_sec == 2) break;
	}
	clock_gettime(CLOCK_REALTIME, &end);	
	printf("2 c: %d\n", count);
	printf("time: %lds %ldns\n", end.tv_sec - start.tv_sec, end.tv_nsec - 		start.tv_nsec);
	
	exit(0);
}