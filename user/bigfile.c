#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

#define BSIZE 1024

int
main(void)
{
  int fd, i, n;
  char buf[BSIZE];

  fd = open("big.file", O_CREATE | O_RDWR);
  if(fd < 0){
    fprintf(2, "bigfile: cannot open big.file for writing\n");
    exit(1);
  }

  memset(buf, 'a', sizeof(buf));

  n = 0;
  while(1){
    i = write(fd, buf, sizeof(buf));
    if(i != sizeof(buf))
      break;
    n++;

    if(n % 100 == 0)
      printf(".");
  }

  printf("\nwrote %d blocks\n", n);

  if(n != 65803){
    printf("bigfile: file is too small\n");
    close(fd);
    exit(1);
  }

  printf("done; ok\n");
  close(fd);
  exit(0);
}