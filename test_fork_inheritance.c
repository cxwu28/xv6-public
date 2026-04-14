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
    p[0] = 'P';
    printf(1, "Parent: initial write succeeded, p[0]=%c\n", p[0]);
    if (mprotect(p, PGSIZE) < 0) {
        printf(1, "mprotect failed\n");
        exit();
    }
    printf(1, "Parent: page protected (read-only).\n");
    int pid = fork();
    if (pid < 0) {
        printf(1, "fork failed\n");
        exit();
    }
    if (pid == 0) {
        printf(1, "Child: attempting to write to protected page...\n");
        p[0] = 'C';
        printf(1, "ERROR: Child wrote to protected page, p[0]=%c\n", p[0]);
        exit();
    } else {
        wait();
        printf(1, "Parent: child returned\n");
        exit();
    }
}
