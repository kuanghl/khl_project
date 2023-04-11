#include <stdio.h>
#include <string.h>

/*宏定义验证及累计*/

#define NUM_TO_POW2(num_a)  ({int buf_num_a = num_a,num_b = 1,num_ret;\
                            while(num_a >>= 1) num_b <<= 1; \
                            num_ret = num_b < buf_num_a ? num_b << 1 : num_b; \
                            num_ret;})

int main(void)
{
    int i = 3;
    int tmp;
    tmp = NUM_TO_POW2(i);
    printf("i = %d, tmp = %d.\n", i, tmp);
    return 0;
}