#include "types.h"
#include "stat.h"
#include "user.h"

void
worker(void *a, void *b)
{
  printf(1, "thread running\n");
  exit();
}

int
main()
{
  thread_create(worker, 0, 0);
  thread_join();
  exit();
}