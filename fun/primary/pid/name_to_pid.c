#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
	char cmd[256];
	memset(cmd, 0, 256);
	
	pid_t pid = getpid();
	
	if(argc < 2)
	{
		printf("Usage: ./a.exe <pid name>\n");
		return -1;
	}
	
	sprintf(cmd, "ps -e | grep %s | awk '{print $1}'", argv[1]);
	
	system(cmd);
	
	return 0;
}