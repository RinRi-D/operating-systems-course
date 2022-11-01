#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TENMB 10*1024*1024

/* vmstat 1
 * Inconsistently, probably because timings are not ideal,
 * but every second free memory decreases by approximately 10MB.
 * si and so are 0, because swap memory wasn't being used.
 */

/* top -d 1
 * By pressing M, top sorts processes by memory usage.
 * Compared to vmstat, top updates total memory usage
 * slower. Every second ex2 goes to the top of the 'top'.
 */


int main() {
    char *p[10];
    for (int i = 0; i < 10; i++) {
        p[i] = malloc(TENMB);
        memset(p[i], 0, TENMB);
        sleep(1);
    }
    for (int i = 0; i < 10; i++) {
        free(p[i]);
    }
}
