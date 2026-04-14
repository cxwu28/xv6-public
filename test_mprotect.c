#include "types.h"
#include "stat.h"
#include "user.h"
#define PGSIZE 4096

int main() {
    char *p = sbrk(PGSIZE); 
    if (p < 0) {
        printf(1, "sbrk failed\n");
        exit();
    }
    p[0] = 'A';
    printf(1, "Before mprotect: write succeeded, p[0]=%c\n", p[0]);
    if (mprotect(p, PGSIZE) < 0) {
        printf(1, "mprotect failed\n");
        exit();
    }
    printf(1, "Page protected (read-only).\n");
    printf(1, "After mprotect: attempting write...\n");
    p[0] = 'B';
    printf(1, "ERROR: write to protected page succeeded, p[0]=%c\n", p[0]);
    exit();
}
