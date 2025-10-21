#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(const Point *a, const Point *b);

int main() {
    float xA = 0.00f, xB = 0.00f, yA = 0.00f, yB = 0.00f;

    printf("Ponto A:\n");
    printf("Xa = ");
    scanf("%f", &xA);
    printf("Ya = ");
    scanf("%f", &yA);

    printf("Ponto B:\n");
    printf("Xb = ");
    scanf("%f", &xB);
    printf("Yb = ");
    scanf("%f", &yB);

    Point a = {xA, yA};
    Point b = {xB, yB};

    float distance = calculateDistance(&a, &b);
    printf("Distância AB = %.2f\n", distance);

    return 0;
}

float calculateDistance(const Point *a, const Point *b) {
    return sqrtf(
        powf(b->x - a->x, 2) + powf(b->y - a->y, 2)
    );
}