#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#define TENMB 10*1024*1024

int main() {
    char *p[10];
    for (int i = 0; i < 10; i++) {
        p[i] = malloc(TENMB);
        memset(p[i], 0, TENMB);
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            printf("Usage: %ldKB\n", usage.ru_maxrss);
        } else {
            perror("getrusage");
            exit(1);
        }
        sleep(1);
    }
    for (int i = 0; i < 10; i++) {
        free(p[i]);
    }
}
