#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int age) {
    int result;

    time_t t = time(NULL);
    result = localtime(&t)->tm_year + 1900 - age;

    return result;
}

int main() {
    const int x = 10;
    const int *q = &x;
    const int *const p = malloc(sizeof(int) * 5);
    for (int *i = (int *)p; i < p + 5; ++i) {
        *i = x;
        printf("%p%c", i, (i < p + 4 ? ' ' : '\n'));
    }

    for (int *i = (int *)p; i < p + 5; ++i) {
        scanf("%d", i);
    }

    for (int *i = (int *)p; i < p + 5; ++i) {
        *i = foo(*i);
        printf("%d%c", *i, (i < p + 4 ? ' ' : '\n'));
    }

    free((int *)p);
}