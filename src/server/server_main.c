#include <stdio.h>
#include <stdlib.h>

int main() {

#if mps_en
 printf("hello,the mps is on.\n");
#else 
 printf("hello,the mps is off.\n");
#endif

#if daemon_en
 printf("hello,the daemon is on.\n");
#else
 printf("hello,the daemon is off.\n");
#endif

#if loglevel==0
 printf("hello,the loglevel = 0.\n");
#elif loglevel==1
 printf("hello,the loglevel = 1.\n");
#elif loglevel==2
 printf("hello,the loglevel = 2.\n");
#elif loglevel==3
 printf("hello,the loglevel = 3.\n");
#elif loglevel==4
 printf("hello,the loglevel = 4.\n");
#elif loglevel==5
 printf("hello,the loglevel = 5.\n");
#else
 printf("hello,the loglevel is setted %d.\n",(int)loglevel);
#endif

 return 0;
}   
