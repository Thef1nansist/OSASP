#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mx;

void *thread1(void *arg)
{
    for (int i = 1; i <= 90; i++)
    {
        if (i == 30)
        {
            pthread_mutex_lock(&mx);
        }
        if (i == 60)
        {
            pthread_mutex_unlock(&mx);
        }

        sleep(1);
        printf("child 1: %d\n", i);
        if (i == 60)
        {
            pthread_mutex_lock(&mx);
            pthread_mutex_unlock(&mx);
        }
    }
    pthread_exit("Child Thread");
}

void *thread2(void *arg)
{
    for (int i = 1; i <= 90; i++)
    {
        if (i == 30)
        {
            pthread_mutex_lock(&mx);
        }
        if (i == 60)
        {
            pthread_mutex_unlock(&mx);
        }

        sleep(1);
        printf("child 2: %d\n", i);
        if (i == 60)
        {
            pthread_mutex_lock(&mx);
            pthread_mutex_unlock(&mx);
        }
    }
    pthread_exit("Child Thread");
}

int main()
{
    pthread_mutex_init(&mx, NULL);
    pthread_t a_th1, a_th2;
    void *r_th1, *r_th2;
    pid_t pid = getpid();
    printf("main: pId = %d \n", getpid());

    int res1 = pthread_create(&a_th1, NULL, thread1, NULL);
    int res2 = pthread_create(&a_th2, NULL, thread2, NULL);

    for (int i = 1; i <= 90; i++)
    {
        if (i == 30)
        {
            pthread_mutex_lock(&mx);
        }
        if (i == 60)
        {
            pthread_mutex_unlock(&mx);
        }

        sleep(1);
        printf("main: %d \n", i);
        if (i == 60)
        {
            pthread_mutex_lock(&mx);
            pthread_mutex_unlock(&mx);
        }
    }

    int status1 = pthread_join(a_th1, (void **)&r_th1);
    int status2 = pthread_join(a_th2, (void **)&r_th2);

    pthread_mutex_destroy(&mx);
    exit(0);
}
