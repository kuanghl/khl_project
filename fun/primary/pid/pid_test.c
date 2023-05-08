#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
    pid_t pid = getpid();
    printf("this PID = %d.\n", pid);
    while(1);
}