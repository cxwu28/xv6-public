#include "types.h"
#include "stat.h"
#include "user.h"

void
worker(void *arg1, void *arg2)
{
  int a = *(int*)arg1;
  int b = *(int*)arg2;

  printf(1, "args: %d %d\n", a, b);
  exit();
}

int
main()
{
  int x = 10;
  int y = 20;

  thread_create(worker, &x, &y);
  thread_join();

  printf(1, "test2 passed\n");
  exit();
}