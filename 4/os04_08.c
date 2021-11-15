#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
//gcc -D_REENTRANT -std=c99 os04_07.c -o os04_07 -lpthread
// /ps -eLf
void *thread1(void *arg)
{
    pid_t pid = getpid();
    for (int i = 0; i < 75; i++)
    {
        if (i == 50)
        {
            printf("os04_07_T1 SLEEP!!!");
            sleep(10);
        }
        sleep(1);
        printf("os04_07_T1 %d\n", pid);
    }
    pthread_exit("Child thread");
}

int main()
{
    pthread_t a_thread;
    void *thread_result;
    pid_t pid = getpid();
    int res = pthread_create(&a_thread, NULL, thread1, NULL);

    for (int i = 0; i < 100; i++)
    {
        if (i == 30)
        {
            printf("Main Thread SLEEP!!!");
            sleep(15);
        }
        sleep(1);
        printf("os04_07: pid = %d \n", pid);
    }

    int status = pthread_join(a_thread, (void **)&thread_result);
    exit(0);
}
