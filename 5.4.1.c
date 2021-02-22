#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int fd, res;
  size_t sz;
  char nm[] = "name.fifo";
  (void)umask(0);

  if (mknod(nm, S_IFIFO | 0666, 0) < 0) {
    printf("Can\'t create FIFO\n");
    exit(-1);
  }

  if ((fd = open(nm, O_WRONLY)) < 0) {
    printf("Can\'t open FIFO for writting\n");
    exit(-1);
  }
  // Write
  sz = write(fd, "Fifo!", 14);
  if (sz != 14) {
    printf("Can\'t write all string to FIFO\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("app 1: Can\'t close FIFO\n"); exit(-1);
  }
  printf("app 1 exit.\n");
  return 0;
}
