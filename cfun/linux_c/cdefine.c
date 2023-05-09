#include <stdio.h>
#include <string.h>

/*宏定义验证及累计*/

#define roundup_pow_of_two(a)  ({int _a = a,_b = 1,_ret;\
                                    while(a >>= 1) _b <<= 1; \
                                    _ret = _b < _a ? _b << 1 : _b; \
                                    _ret;})

int main(void)
{
    int i = 270;
    int tmp;
    tmp = roundup_pow_of_two(i);
    printf("i = %d, tmp = %d.\n", i, tmp);
    return 0;
}