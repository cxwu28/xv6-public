#include "types.h"
#include "stat.h"
#include "user.h"

int global = 0;

void
worker(void *a, void *b)
{
  global = 1;
  exit();
}

int
main()
{
  thread_create(worker, 0, 0);
  thread_join();

  printf(1, "global=%d\n", global);
  exit();
}