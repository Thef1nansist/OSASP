#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
// #include <unistd.h>
void cycle(int k, char *s)
{
    for (int i = 0; i < k; i++)
    {
        printf("This %s ID of this program is %d\n", s, getpid());
        sleep(1);
    }
};
//ps -A|grep ./1
int main()
{
    pid_t pid;
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("This process ID of this program is %d\n", getpid());
    //     sleep(1);
    // }

    switch (pid == fork())
    {
    case -1:
        perror("fork error");
        exit(-1);
    case 0:
        cycle(50, "os_03_05_1");
        exit(0);
    default:
        cycle(100, "os_03_05");
        wait(NULL);
    }
}