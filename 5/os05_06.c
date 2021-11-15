#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    for (int i = 0; i < 100000000000000; i++)
    {
        printf("%ld\n", (long)getpid());
        sleep(1);
    }
}
