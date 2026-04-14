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
    p[0] = 'X';
    printf(1, "Before mprotect: write succeeded, p[0]=%c\n", p[0]);
    if (mprotect(p, PGSIZE) < 0) {
        printf(1, "mprotect failed\n");
        exit();
    }
    printf(1, "Page protected.\n");
    if (munprotect(p, PGSIZE) < 0) {
        printf(1, "munprotect failed\n");
        exit();
    }
    printf(1, "Page unprotected (writable again).\n");
    p[0] = 'Y';
    printf(1, "After munprotect: write succeeded, p[0]=%c\n", p[0]);
    exit();
}
