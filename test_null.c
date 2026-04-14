#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    int *p = 0;  // not reference memory
    printf(1, "Attempting to read from NULL (0x0)\n");
    int val = *p;  // reference memory
    printf(1, "Read value %d from NULL (unexpected)\n", val);
    exit();
}
