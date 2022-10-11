#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, at, bt, et, tat, wt;
} Process;

int proc_cmp(const void *a, const void *b) {
    return ((Process*)a)->at - ((Process*)b)->at;
}

int proc_cmp_id(const void *a, const void *b) {
    return ((Process*)a)->id - ((Process*)b)->id;
}

int main() {
    int n;
    printf("Number of processes: ");
    scanf("%d", &n);
    Process p[n];

    printf("Arrival time and Burst time:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i;
    }

    qsort(p, n, sizeof(Process), proc_cmp);

    int curt = 0;
    printf("ID\tAT\tBT\tET\tTAT\tWT\n");
    double avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; ++i) {
        p[i].et = (curt > p[i].at ? curt : p[i].at) + p[i].bt;
        curt = p[i].et;

        p[i].tat = p[i].et - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }

    qsort(p, n, sizeof(Process), proc_cmp_id);
    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].et, p[i].tat, p[i].wt);
    }

    avg_tat /= n;
    avg_wt /= n;
    printf("avg:\t\t\t\t%lg\t%lg\n", avg_tat, avg_wt);
}
