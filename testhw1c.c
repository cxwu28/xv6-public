#include "types.h"
#include "user.h"
#include "fcntl.h"


void
test_basic() 
{
  int c1 = getclosecount();
  printf(1, "--- Variant C basic test (1 valid and 2 invalid close) ---\n");

  // case A: valid close
  int fd = open("testfile", O_CREATE | O_RDWR);
  if(fd >= 0) {
      close(fd); // first time
  } else {
      printf(1, "Error: Could not open file\n");
  }
  // case B: invalid close
  close(-1);   // second time
  close(100);  // third time

  // check
  int c2 = getclosecount();
  if (c2 == c1 + 3) {
    printf(1, "RESULT: SUCCESS! Count increased by exactly 3.\n");
  } else {
    printf(1, "RESULT: FAILED! Expected increase of 3, but got %d.\n", c2 - c1);
  }
}

void
test_stress() 
{
  int procnum = 10;
  int callnum = 100;
  int c1 = getclosecount();
  printf(1, "--- Variant C stress test (%d processes * %d calls) ---\n", procnum, callnum);

  for (int i = 0; i < procnum; i++) {
    if (fork() == 0) {
      for (int j = 0; j < callnum; j++) {
        close(-1);
      }
      exit();
    }
  } // parent exit loop until all children created

  for (int i = 0; i < procnum; i++) {
    wait();
  } // parent exit loop until all children finished

  int c2 = getclosecount();
  if (c2 == c1 + procnum * callnum) {
    printf(1, "RESULT: SUCCESS! Count increased by exactly %d.\n", procnum * callnum);
  } else {
    printf(1, "RESULT: FAILED! Expected increase of %d, but got %d.\n", procnum * callnum, c2 - c1);
  }
}

int
main(int argc, char *argv[])
{
  test_basic();
  test_stress();
  printf(1, "--- Global check: the close calls count is: %d ---\n");
  exit();
}