#include <stdio.h>

void triangle(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j)
            printf(" ");

        for (int j = 1; j <= i * 2 - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void triangle2(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void arrow(int n) {
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n / 2; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void rectangle(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Specify number of rows: ");
    scanf("%d", &n);
    // triangle(n);
    triangle2(n);
    printf("\n");
    arrow(n);
    printf("\n");
    rectangle(n, n);
}