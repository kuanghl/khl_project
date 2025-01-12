/** Compilation: gcc -o memreader memreader.c -lrt -lpthread **/
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
  int fd = shm_open(BackingFile, O_RDWR, AccessPerms);  /* empty to begin */
  if (fd < 0) report_and_exit("Can't get file descriptor...");

  /* get a pointer to memory */
  caddr_t memptr = mmap(NULL,       /* let system pick where to put segment */
			ByteSize,   /* how many bytes */
			PROT_READ | PROT_WRITE, /* access protections */
			MAP_SHARED, /* mapping visible to other processes */
			fd,         /* file descriptor */
			0);         /* offset: start at 1st byte */
  if ((caddr_t) -1 == memptr) report_and_exit("Can't access segment...");

  /* create a semaphore for mutual exclusion */
  sem_t* semptr = sem_open(SemaphoreName, /* name */
			    O_RDWR | O_CREAT,       /* create the semaphore */
			   AccessPerms,   /* protection perms */
			   0);            /* initial value */
  if (semptr == (void*) -1) report_and_exit("sem_open");

  /* use semaphore as a mutex (lock) by waiting for writer to increment it */
  sem_wait(semptr);
  if (1) { /* wait until semaphore != 0 */
    int i;
    for (i = 0; i < strlen(MemContents); i++)
      write(STDOUT_FILENO, memptr + i, 1); /* one byte at a time */
    // sem_post(semptr);   /*repeat read*/
  }

  /* cleanup */
  munmap(memptr, ByteSize);
  close(fd);
  sem_close(semptr);
  // unlink(BackingFile);
  return 0;
}
