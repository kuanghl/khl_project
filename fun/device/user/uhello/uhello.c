#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
 
void main()
{
	int fd;
 
	fd = open("/dev/khello",O_RDWR);
	if(fd<0)
	{
		perror("open fail \n");
		return ;
	}
    printf("ok, khello driver opened.\n");
 
	close(fd);
}