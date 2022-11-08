#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int page;
    unsigned char count;
} PageFrame;

int findFrame(PageFrame *pframes, int n, int page) {
    for (int i = 0; i < n; ++i)
        if (pframes[i].page == page)
            return i;

    return -1;
}

int oldestFrame(PageFrame *pframes, int n) {
    int mn = INT_MAX, mnpos = -1;
    for (int i = 0; i < n; ++i)
        if (pframes[i].page < mn)
            mn = pframes[i].page, mnpos = i;

    return mnpos;
}

/*
 * My program doesn't simulate the "timer".
 * Instead, it shifts everything every iteration.
 * That's why I haven't implemented r-bits.
 */

int main(int argc, char **argv) {
    FILE *f = fopen("input.txt", "r");

    PageFrame pframes[100];
    for (int i = 0; i < 100; ++i)
        pframes[i].page = -1, pframes[i].count = 0;

    int testFrames = atoi(argv[1]);

    float miss = 0, hit = 0;
    unsigned long page;

    while (fscanf(f, "%lu", &page) != EOF) {
        int frame = findFrame(pframes, testFrames, page);
        
        if (frame == -1) {
            miss++;
            int oldest = oldestFrame(pframes, testFrames);
            pframes[oldest].page = page;
            pframes[oldest].count = (1 << 7);
        } else {
            hit++;
            pframes[frame].count |= (1 << 7);
        }

        // do refresh after every access
        for (int i = 0; i < testFrames; ++i)
            pframes[i].count >>= 1;
    }

    printf ("hits: %f\nmisses: %f\nratio: %f\n", hit, miss, hit / miss);

    fclose(f);
}
