#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id, at, bt, et, tat, wt, rt, used;
} Process;

int proc_cmp(const void *a, const void *b) {
    return ((Process*)a)->at - ((Process*)b)->at;
}

int proc_cmp_id(const void *a, const void *b) {
    return ((Process*)a)->id - ((Process*)b)->id;
}

int deq(int q[], int *sz) {
    int res = q[0];
    for (int i = 0; i < *sz-1; ++i) {
        q[i] = q[i+1];
    }
    (*sz)--;
    return res;
}

int main() {
    int n, mn = INT_MAX, q, qsz = 0;
    printf("Quantum: ");
    scanf("%d", &q);
    printf("Number of processes: ");
    scanf("%d", &n);
    Process p[n];
    int ready[n];

    printf("Arrival time and Burst time:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i;
        p[i].et = -1;
        p[i].used = 0;
        p[i].rt = p[i].bt;
        ready[i] = 0;
    }

    qsort(p, n, sizeof(Process), proc_cmp);

    printf("ID\tAT\tBT\tET\tTAT\tWT\n");

    double avg_tat = 0, avg_wt = 0;
    int curt = 0, jd = 0;
    ready[qsz++] = 0;
    p[0].used = 1;
    while (qsz > 0) {
        int id = deq(ready, &qsz);
        if (p[id].rt != 0) {
            int ex = (p[id].rt < q ? p[id].rt : q);
            p[id].rt -= ex;
            p[id].et = curt + ex;
            curt = p[id].et;
            p[id].tat = p[id].et - p[id].at;
            p[id].wt = p[id].tat - p[id].bt;
            if (p[id].rt == 0) {
                avg_tat += p[id].tat;
                avg_wt += p[id].wt;
                jd++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (curt >= p[i].at && p[i].used == 0) {
                ready[qsz++] = i;
                p[i].used = 1;
            }
        }

        if (p[id].rt != 0) {
            ready[qsz++] = id;
        }

        if (qsz == 0) {
            for (int i = 0; i < n; ++i) {
                if (p[i].used == 0) {
                    ready[qsz++] = i;
                    p[i].used = 1;
                    curt = p[i].at;
                    break;
                }
            }
        }
    }

    qsort(p, n, sizeof(Process), proc_cmp_id);
    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].et, p[i].tat, p[i].wt);
    }

    avg_tat /= n;
    avg_wt /= n;
    printf("avg:\t\t\t\t%lg\t%lg\n", avg_tat, avg_wt);
}
