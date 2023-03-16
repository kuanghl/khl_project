#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct info_s
{
    unsigned int info1;
    unsigned char info2;
    unsigned short int info3;
};

int main(){
    struct info_s info[4];
    struct info_s *info_addr = &info;

    unsigned char i;
    srand((unsigned)time(NULL));
    for(i =  0; i < 4; i++){
        info[i].info1 = rand();
        info[i].info2 = rand();
        info[i].info3 = rand();
        printf("SN%3d:info1 = %11d, info2 = %11d, info3 = %11d.\n", i, info[i].info1, info[i].info2, info[i].info3);
    }
    printf("**************************out\n");
    for(i =  0; i < 4; i++){
        printf("SN%3d:info1 = %11d, info2 = %11d, info3 = %11d.\n", i, (info_addr+i)->info1, (info_addr+i)->info2, (info_addr+i)->info3);
    }
    
    return 0;
}
