#include "types.h"
#include "user.h"
#include "fcntl.h"

// #include "param.h"
// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"
int
main(int argc, char *argv[])
{
  // 1. get the initial count
  int count1 = getclosecount();
  printf(1, "--- Variant C Test ---\n");
  printf(1, "Initial total close count: %d\n", count1);

  // 2. test
  // case A: valid close
  int fd = open("testfile", O_CREATE | O_RDWR); // it should be better or equal 3
  printf(1, "The new FD is: %d\n", fd); //
  if(fd >= 0) {
      close(fd); // first time
  } else {
      printf(1, "Error: Could not open file\n");
  }

  // case B: invalid close
  close(-1);   // second time
  close(100);  // third time

  // 3. get the final count, it should be 3 more than the initial count
  int count2 = getclosecount();
  printf(1, "Final total close count: %d\n", count2);

  // 4. check
  if (count2 == count1 + 3) {
    printf(1, "RESULT: SUCCESS! Count increased by exactly 3.\n");
  } else {
    printf(1, "RESULT: FAILED! Expected increase of 3, but got %d.\n", count2 - count1);
  }

  exit();
}