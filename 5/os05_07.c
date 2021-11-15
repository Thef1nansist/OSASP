#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/resource.h>
#include <sched.h>
#include <sys/wait.h>

void mainFun()
{
    for (int i = 0; i < 100000000000000; i++)
    {
        printf("%ld\n", (long)getpid());
        sleep(1);
    }
}

void threadFun()
{
    setpriority(PRIO_PROCESS, 0, -10);
    mainFun();
}

int main(int argc, char **argv)
{
    pid_t pid;
    switch (pid = fork())
    {
    case -1:
        perror("fork error");
        exit(-1);
    case 0:
        threadFun();
        exit(0);
    default:
        mainFun();
        wait(NULL);
    }
}
