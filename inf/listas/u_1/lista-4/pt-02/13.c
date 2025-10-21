#include <stdio.h>

int main() {
    double h = 0;
    int num = 1;

    for (int den = 1; den <= 50; den++) {
        h += (double)num / den;
        num += 2;
    }

    printf("H = %.5lf\n", h);
    return 0;
}
