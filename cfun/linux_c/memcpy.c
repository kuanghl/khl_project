#include<stdio.h>
#include<string.h>
 
int main(void)
{
  char src[] = "***";
  char dest[] = "abcdefg";
  printf("使用 memcpy 前: %s\n", dest);
  memcpy(dest, src, strlen(src));
  printf("使用 memcpy 后: %s\n", dest);
  return 0;
}