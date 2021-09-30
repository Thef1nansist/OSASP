
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
    system("./os03_05_1");
    for (int i = 0; i < 100; i++)
    {
        printf("This 03-06 main ID of this program is %d\n", getpid());
        sleep(1);
    }
}