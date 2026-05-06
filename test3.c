#include "types.h"
#include "stat.h"
#include "user.h"

lock_t lock;
int counter = 0;

void
worker(void *arg1, void *arg2)
{
  int i;

  for(i = 0; i < 1000; i++){
    lock_acquire(&lock);
    counter++;
    lock_release(&lock);
  }

  exit();
}

int
main()
{
  lock_init(&lock);

  thread_create(worker, 0, 0);
  thread_create(worker, 0, 0);

  thread_join();
  thread_join();

  printf(1, "counter=%d\n", counter);

  if(counter == 2000)
    printf(1, "test3 passed\n");
  else
    printf(1, "test3 failed\n");

  exit();
}