#include <stdio.h>
#include <string.h>
 
int main ()
{
  char str1[]="Sample string";
  char str2[40];
  char str3[256];
  strcpy (str2,str1+1);
  strcpy (str3,"copy successful");
  strcpy (str3, str1);
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  return 0;
}
