#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/shm.h>
#include <sys/types.h>

int main(){
    unsigned char i;
    srand((unsigned)time(NULL));
    for(i = 0; i < 100; i++){
        printf("rand number = %4d.\n", (key_t)rand());
    }
    return 0;
}