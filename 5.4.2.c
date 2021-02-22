#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int fd, res;

  size_t  sz;
  char resstring[14];
  char nm[] = "aaa.fifo";

  (void)umask(0);

  if ((fd = open(nm, O_RDONLY)) < 0) {
    printf("Can\'t open FIFO for reading\n");
    exit(-1);
  }

  sz = read(fd, resstring, 14);
  if (sz < 0) {
    printf("Can\'t read from FIFO\n");
    exit(-1);
  }
  printf("app 2 exit, resstring:%s\n", resstring);
  if (close(fd) < 0) {
    printf("child: Can\'t close FIFO\n"); exit(-1);
  }
  return 0;
}
