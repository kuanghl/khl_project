#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
 
void main()
{
	int fd;
	struct timespec ts;
	
	fd = open("/dev/khello",O_RDWR);
	if(fd<0)
	{
		perror("open fail \n");
		return ;
	}
    printf("ok, khello driver opened.\n");
	clock_gettime(CLOCK_REALTIME, &ts);
	printf("ts uhello time: %llds, %ldns\n", ts.tv_sec, ts.tv_nsec);
	close(fd);
}