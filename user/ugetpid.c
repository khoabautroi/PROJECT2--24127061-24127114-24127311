#include "kernel/types.h"
#include "user/user.h"

#define USYSCALL 0x3ffff000

struct usyscall {
  int pid;
};

int
main()
{
  struct usyscall *u = (struct usyscall *)USYSCALL;
  printf("%d\n", u->pid);
  exit(0);
}