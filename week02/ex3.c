#include <stdio.h>
#include <string.h>

/* DISCLAIMER: As far as I understand, I need to create a function,
   which takes a long long number (not a string), convert it to a
   string, use that string as it was a number in the source
   number system, and then print out in the target number system.

   I think it is way better to use string for the number itself and
   read it as a string from the beginning. But I will follow the
   assignment instructions since I don't want to get a lower grade.
   Please, make it more clear next time.
   */

void convert(long long n, int s, int t) {
    if (!(s >= 2 && s <= 10 && t >= 2 && t <= 10)) {
        printf("cannot convert!\n");
        return;
    }

    // convert n from source number system to normal long long integer
    long long n_actual = 0, cur = 1;
    while (n) {
        if (n % 10 >= s) {
            printf("cannot convert!\n");
            return;
        }
        n_actual += cur * (n % 10);
        cur *= s;
        n /= 10;
    }

    // convert the actual n to target number system
    char buf[65];
    int i = 0;
    while (n_actual) {
        buf[i++] = (n_actual % t) + '0';
        n_actual /= t;
    }
    buf[i] = '\0';

    for (--i; i >= 0; --i) {
        putc(buf[i], stdout);
    }

    putc('\n', stdout);
}

int main() {
    long long number;
    int source, target;
    scanf("%lld%d%d", &number, &source, &target);
    convert(number, source, target);
}