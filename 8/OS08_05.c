#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int main() {
	time_t t = time(&t);
	struct tm * tmptr;
	tmptr = gmtime(&t);
	printf("%d.", tmptr->tm_mday);
	printf("%d.", tmptr->tm_mon + 1);
	printf("%d.", tmptr->tm_year);
	printf(" ");
	printf("%d.", tmptr->tm_hour);
	printf("%d.", tmptr->tm_min);
	printf("%d\n", tmptr->tm_sec);

	exit(0);
}