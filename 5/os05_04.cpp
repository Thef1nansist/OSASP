#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/resource.h>
#include <sched.h>
#include <sys/syscall.h>
#define gettid() syscall(SYS_gettid)

int main(int argc, char **argv)
{

    printf("%ld\n", (long)getpid());
    printf("%ld\n", (long)gettid());
    printf("current nice = %d\n", getpriority(PRIO_PROCESS, 0));

    cpu_set_t set;
    CPU_ZERO(&set);
    if (sched_getaffinity(0, sizeof(cpu_set_t), &set) == 0)
    {
        int is = 0;
        for (int i = 0; i < CPU_SETSIZE; i++)
        {
            is = CPU_ISSET(i, &set);
            printf("cpu = %i is %s\n", i, is ? "set" : "unset");
        }
    }
    else
        printf("sched_getaaffinity = ERROR");
}