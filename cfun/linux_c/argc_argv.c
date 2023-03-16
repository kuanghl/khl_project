#include <stdio.h>
#include <string.h>

int main(int argc , int *argv[])
{
    printf("argc = %d\n", argc);

    argv++;
    while (*argv){
        if (strcmp(*argv, "Aa") == 0){
            argv++;
            printf("A for apple\n");

        }else if (strcmp(*argv, "Bb") == 0){
            argv++;
            printf("B for ball\n");

        }else if (strcmp(*argv, "Cc") == 0){
            argv++;
            printf("C for cat\n");

        }else if (strcmp(*argv, "Dd") == 0){
            argv++;
            printf("D for dog\n");
        }
    }
}
