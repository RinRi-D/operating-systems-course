#include <math.h>
#include <stdio.h>

typedef struct Point {
    float x, y;
} Point;

float distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float area(Point A, Point B, Point C) {
    return 0.5 * fabsf(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y +
                      C.x * A.y - A.x * C.y);
}

int main() {
    Point A = {2.5, 6};
    Point B = {1, 2.2};
    Point C = {10, 6};

    float f = distance(A, B);
	printf("A -- B distance is %f\n", f);


	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);
}