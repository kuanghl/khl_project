/** Compilation: gcc -o memwriter memwriter.c -lrt -lpthread **/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>       
#include <fcntl.h>          
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

#define ByteSize 512
#define BackingFile "/shMemEx"
#define AccessPerms 0777
#define SemaphoreName "mysemaphore"
#define MemContents "This is the way the world ends...\n"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1);
}

int main(void) {
  int fd = shm_open(BackingFile,      /* name from smem.h */
		    O_RDWR | O_CREAT, /* read/write, create if needed */
		    AccessPerms);     /* access permissions (0644) */
  if (fd < 0) report_and_exit("Can't open shared mem segment...");

  chmod("/dev/shm/shMemEx", AccessPerms);

  ftruncate(fd, ByteSize); /* get the bytes */

  caddr_t memptr = mmap(NULL,       /* let system pick where to put segment */
			ByteSize,   /* how many bytes */
			PROT_READ | PROT_WRITE, /* access protections */
			MAP_SHARED, /* mapping visible to other processes */
			fd,         /* file descriptor */
			0);         /* offset: start at 1st byte */
  if ((caddr_t) -1  == memptr) report_and_exit("Can't get segment...");
  
  fprintf(stderr, "shared mem address: %p [0..%d]\n", memptr, ByteSize - 1);
  fprintf(stderr, "backing file:       /dev/shm%s\n", BackingFile );

  /* semahore code to lock the shared mem */
  sem_t* semptr = sem_open(SemaphoreName, /* name */
			   O_CREAT,       /* create the semaphore */
			   AccessPerms,   /* protection perms */
			   0);            /* initial value */
  if (semptr == (void*) -1) report_and_exit("sem_open");

  chmod("/dev/shm/sem.mysemaphore", AccessPerms);
  
  strcpy(memptr, MemContents); /* copy some ASCII bytes to the segment */

  /* increment the semaphore so that memreader can read */
  if (sem_post(semptr) < 0) report_and_exit("sem_post");

  sleep(12); /* give reader a chance */
  
  /* clean up */
  munmap(memptr, ByteSize); /* unmap the storage */
  close(fd);
  sem_close(semptr);
  // shm_unlink(BackingFile); /* unlink from the backing file */
  return 0;
}


