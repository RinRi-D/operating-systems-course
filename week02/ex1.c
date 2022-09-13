#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    int i = INT_MAX;
    unsigned short us = USHRT_MAX;
    long l = LONG_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("int: %lu, %d\n"
           "unsigned short: %lu, %hu\n"
           "long: %lu, %ld\n"
           "float: %lu, %f\n"
           "double: %lu, %lf\n",
           sizeof(i), i, sizeof(us), us, sizeof(l), l, sizeof(f), f, sizeof(d),
           d);
}