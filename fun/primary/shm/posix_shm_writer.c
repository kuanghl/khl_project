#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
 
#define MMAP_DATA_SIZE 1024
 
#define USE_MMAP 1
 
//int main(int argc,char * argv[])
int main(void)
{
        char * data;


        /*判断文件或文件夹是否存在*/
        if(access("/tmp/rpp", 0) != 0){
                if ( mkdir("/tmp/rpp", S_IRWXU|S_IRWXG) != 0) {
                        printf("%s, create %s failed\n", __func__, "/tmp/rpp");
                        return -1;
                }       
        }
        if(access("/tmp/rpp/pti", 0) != 0){
                if ( mkdir("/tmp/rpp/pti", S_IRWXU|S_IRWXG) != 0) {
                        printf("%s, create %s failed\n", __func__, "/tmp/rpp/pti");
                        return -1;
                }       
        }
        // int fd = shm_open("shm-file0001", O_CREAT|O_RDWR, 0777);
        int fd = open("/tmp/rpp/pti/shm-file0001", O_CREAT | O_RDWR, 0777);
        if (fd < 0) {
                printf("shm_open failed!\n");
                return -1;
        }
 
        ftruncate(fd, MMAP_DATA_SIZE);
        if (USE_MMAP) {
                data = (char*)mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
                if (!data) {
                        printf("mmap failed\n");
                        close(fd);
                }
 
 
                sprintf(data, "This is a share memory! %d\n", fd);
 
                munmap(data, MMAP_DATA_SIZE);
        }
        else {
            char buf[1024];
            int len = sprintf(buf,"This is a share memory by write! ! %d\n",fd);
            if (write(fd, buf, len) <= 0) {
                printf("write file %d failed!%d\n",len,errno);
             }  
        }
 
        close(fd);
        getchar();
 
        // shm_unlink("shm-file0001");
        //remove("/tmp/rpp/pti/shm-file0001");
 
        return 0;
}