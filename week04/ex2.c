#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    srand(time(NULL));
    FILE *out = fopen("temp.txt", "w");
    int u[120], v[120];
    for (int i = 0; i < 120; ++i)
        u[i] = rand() % 100, v[i] = rand() % 100;

    int n;
    scanf("%d", &n);
    pid_t id[10];
    int start = -1, sz = 120 / n;
    for (int i = 0; i < n; ++i) {
        id[i] = fork();
        if (id[i] == 0) {
            start = i * sz;
            break;
        }
    }

    if (start != -1) {
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            res += u[start + i] * v[start + i];
        }
        fprintf(out, "%d\n", res);
    } else {
        int status;
        wait(&status);
        fclose(out);
        int res = 0;
        FILE *in = fopen("temp.txt", "r");
        for (int i = 0; i < n; ++i) {
            int a;
            fscanf(in, "%d", &a);
            res += a;
        }
        fclose(in);
        printf("Result: %d\n", res);
    }
}
