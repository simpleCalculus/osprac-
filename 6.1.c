#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
  int     fileToWrite;
  int     readResult;
  int     i;
  int     *array;    // Pointer to shared memory
  int     shmid;     // IPC descriptor for the shared memory
  char    pathname[] = "6.1.c"; // The file name used to generate the key.
  
  key_t   key;       // IPC key
  
  if ((key = ftok(pathname,0)) < 0) {
    printf("Can\'t generate key\n");
    exit(-1);
  }
  
  if ((shmid = shmget(key, 4096*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0) {
    if (errno != EEXIST) {
      printf("Can\'t create shared memory\n");
      exit(-1);
    } else {
      if ((shmid = shmget(key, 4096*sizeof(int), 0)) < 0) {
        printf("Can\'t find shared memory\n");
        exit(-1);
      }
    }
  }
  
  if ((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
    printf("Can't attach shared memory\n");
    exit(-1);
  }

  fileToWrite = open("./6.1.c", O_RDONLY);
  i = 0;
  while ((readResult = read(fileToWrite, &array[i], 1)) > 0) {
    i++;
  }
  array[i+1]=EOF;

  if (readResult < 0) {
    printf("Can't read file\n");
    exit(-1);
  }

  printf("File was successfully writen!\n");

  if (shmdt(array) < 0) {
    printf("Can't detach shared memory\n");
    exit(-1);
  }

  return 0;
}
