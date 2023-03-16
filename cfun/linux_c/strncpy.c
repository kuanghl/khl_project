#include <stdio.h>
#include <string.h>
 
int main()
{
   char src[40];
   char dest[12];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is runoob.com");
   strncpy(dest, src, 10);
 
   printf("最终的目标字符串： %s\n", dest);
   
   return(0);
}
