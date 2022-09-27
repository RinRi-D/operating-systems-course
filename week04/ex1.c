#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    clock_t pt = clock(), t1, t2;
    int status;

    printf("Main. PID: %d\nParent PID: %d\n\n", getpid(), getppid());

    pid_t child1 = fork(), child2;
    t1 = clock();

    if (child1 != 0) {
        child2 = fork();
        t2 = clock();
    }

    if (child1 == 0) {
        printf("Child1. PID: %d\nParent PID: %d\n", getpid(), getppid());
        t1 = clock() - t1;
        printf("Child1. Time took: %fms\n\n", ((double)t1)/CLOCKS_PER_SEC*1000);
    } else if (child2 == 0) {
        printf("Child2. PID: %d\nParent PID: %d\n", getpid(), getppid());
        t2 = clock() - t2;
        printf("Child2. Time took: %fms\n\n", ((double)t2)/CLOCKS_PER_SEC*1000);
    } else {
        pt = clock() - pt;
        printf("Main. Time took: %fms\n\n", ((double)pt)/CLOCKS_PER_SEC*1000);
    }
}
