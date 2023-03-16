#include <stdio.h>
#include <string.h>
 
int main ()
{
   int len;
   const char str[] = "https://www.runoob.com";
   const char ch = '.';
   char *ret;
 
   ret = strrchr(str, ch);
 
   printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);
   
   return(0);
}
