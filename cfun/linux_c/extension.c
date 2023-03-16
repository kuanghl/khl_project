#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define do_div(n,base) (__extension__({                    \
    unsigned int __base = (base);                \
    unsigned int __rem;                        \
    __rem = ((unsigned long long)(n)) % __base;            \
    (n) = ((unsigned long long)(n)) / __base;                \
    __rem;                            \
 }))



int main()
{
int do_n = 19,do_base = 3,do_ret;	
int result = __extension__({
int i, sum = 0,ret = 8;
for (i = 1; i <= 100; i++)
        sum+= i;
      sum;
      //ret;
});
do_ret=do_div(do_n,do_base);
printf("ret = %d, do_n = %d, do_base = %d\n", do_ret, do_n, do_base);
printf("result=%d\n", result);
return 0;
}
