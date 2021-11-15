
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("This 03-07 main ID of this program is %d\n", getpid());
        sleep(1);
    }

    char *const argv[] = {"./os03_05_1", NULL};
    execv("./os03_05_1", argv);
}