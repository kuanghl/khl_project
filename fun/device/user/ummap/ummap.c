#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <linux/fb.h> 
#include <sys/mman.h> 
#include <sys/ioctl.h> 
 
#define ummap_level 0

#if (ummap_level == 0)
#define PAGE_SIZE 4096 
int main(int argc , char *argv[]) 
{ 
	int fd; 
	int i; 
	unsigned char *p_map; 
	
	//打开设备 
	fd = open("/dev/kmmap",O_RDWR); 
	if(fd < 0) 
	{ 
		printf("open fail\n"); 
		exit(1); 
	} 
	
	//内存映射 
	p_map = (unsigned char *)mmap(0, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0); 
	if(p_map == MAP_FAILED) 
	{ 
		printf("mmap fail\n"); 
		goto here; 
	} 
	
	//打印映射后的内存中的前10个字节内容 
	for(i=0;i<10;i++) 
		printf("%d\n",p_map[i]); 
	
	
here: 
	munmap(p_map, PAGE_SIZE); 
	return 0; 
}

#elif (ummap_level == 1)
#define PAGE_SIZE (4*1024)
#define BUF_SIZE (16*PAGE_SIZE)
#define OFFSET (0)
// #define OFFSET (16*PAGE_SIZE)
// #define OFFSET (16*PAGE_SIZE)

int main(int argc, const char *argv[])
{
	int fd;
	char *addr = NULL;

	fd = open("/dev/kmmap", O_RDWR);
	if (fd < 0) {
		perror("open failed\n");
		exit(-1);
	}

	addr = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd, OFFSET);
	if (!addr) {
		perror("mmap failed\n");
		exit(-1);
	}

	sprintf(addr, "I am %s\n", argv[0]);

	return 0;
}

#elif (ummap_level == 2)
#define PAGE_SIZE (4*1024)
#define BUF_SIZE (32*PAGE_SIZE)
#define OFFSET (0)

int main(int argc, const char *argv[])
{
	int fd;
	char *addr = NULL;
	int *brk;

	fd = open("/dev/kmmap", O_RDWR);
	if (fd < 0) {
		perror("open failed\n");
		exit(-1);
	}

	addr = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd, 0);
	if (!addr) {
		perror("mmap failed\n");
		exit(-1);
	}
	memset(addr, 0x0, BUF_SIZE);

	printf("Clear Finished\n");

	return 0;
}

#endif