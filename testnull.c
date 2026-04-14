#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    int *p = 0;  // not reference memory
    printf(1, "Attempting to read from NULL (0x0)\n");
    int val = *p;  // reference memory
    printf(1, "Read value %d from NULL (unexpected)\n", val);
    printf(1, "Attempting to write to NULL (0x0)\n");
    *p = 42;
    printf(1, "ERROR: write to NULL succeeded, p[0] = %d\n", *p);
    exit();
}
