#include <stdio.h>

long long tribonacci(int n) {
    long long a = 0, b = 1, c = 1;
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;

    for (int i = 3; i <= n; ++i) {
        long long d = a + b + c;
        a = b, b = c, c = d;
    }
    return c;
}

int main() {
    printf("%lld\n%lld\n", tribonacci(4), tribonacci(36));
}