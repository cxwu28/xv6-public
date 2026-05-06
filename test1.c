#include "types.h"
#include "stat.h"
#include "user.h"

void
worker(void *arg1, void *arg2)
{
  printf(1, "thread running\n");
  exit();
}

int
main()
{
  int pid;

  pid = thread_create(worker, 0, 0);
  if(pid < 0){
    printf(1, "thread_create failed\n");
    exit();
  }

  thread_join();

  printf(1, "test1 passed\n");
  exit();
}