#include <stdio.h>
#include <stdlib.h>
#include <log.h>
#include <stdint.h>

uint64_t cacul_add(uint32_t max_num){
    uint64_t ret = 0;  
    for(uint32_t i = 0; i <= max_num; i++){
        ret += i;
    }
    return ret;
}

int factorial(int max_num) {
  int result = 1;
  for (int i = 1; i <= max_num; i++) {
    result *= i;
  }
  return result;
}

uint32_t transfer(void *indata, void *outdata, uint32_t size){
    *(uint32_t *)outdata = 0x10001111;
    return *(uint32_t *)indata;
}

int main(int argc, char *argv[])
{
    // #if mps_en
    // printf("hello,the mps is on.\n");
    // #else 
    // printf("hello,the mps is off.\n");
    // #endif

    // #if daemon_en
    // printf("hello,the daemon is on.\n");
    // #else
    // printf("hello,the daemon is off.\n");
    // #endif

    // #if loglevel==0
    // printf("hello,the loglevel = 0.\n");
    // #elif loglevel==1
    // printf("hello,the loglevel = 1.\n");
    // #elif loglevel==2
    // printf("hello,the loglevel = 2.\n");
    // #elif loglevel==3
    // printf("hello,the loglevel = 3.\n");
    // #elif loglevel==4
    // printf("hello,the loglevel = 4.\n");
    // #elif loglevel==5
    // printf("hello,the loglevel = 5.\n");
    // #else
    // printf("hello,the loglevel is setted %d.\n",(int)loglevel);
    // #endif

    // uint64_t sum = cacul_add(1000000);
    // printf("sum = %ld.\n", sum);
    // int ret = factorial(4000000);
    // printf("ret = %d.\n", ret);

    // log_trace("%s, this is server log, %s\n", __func__, "hello!");
    // log_debug("%s, this is server log, %s\n", __func__, "hello!");
    // log_info("%s, this is server log, %s\n", __func__, "hello!");
    // log_warn("%s, this is server log, %s\n", __func__, "hello!");
    // log_error("%s, this is server log, %s\n", __func__, "hello!");
    // log_fatal("%s, this is server log, %s\n", __func__, "hello!");

    for(uint32_t i = 0; i < 1000; i++){
      uint32_t indata32 = 0x10000031, outdata32;
      uint32_t result = 0x00;
      result = transfer((void *)&indata32, (void *)&outdata32, 4);
      log_debug("result 0x%x, in 0x%x, out 0x%x\n", result, indata32, outdata32);
    }

    return 0;
}   
