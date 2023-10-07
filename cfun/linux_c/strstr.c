#include <stdio.h>
#include <string.h>
 
 
int main()
{
   const char haystack[20] = "RUNOOB";
   const char needle[10] = "NOOB";
   char *ret;
 
   ret = strstr(haystack, needle);
 
   printf("子字符串是： %s\n", ret);
   
   return(0);
}