#include <stdio.h>
#include <stdlib.h>

int sumRecursive(int k) {
    if (k == 0) {
        return 0;
    } else {
        return k + sumRecursive(k - 1);
    }
}

int sumArrRecursive(int *arr, int len) {
    if (len == 0) {
        return 0;
    } else {
        return arr[0] + sumArrRecursive(arr + 1, len - 1);
    }
}

int main() {
    int sumRange = sumRecursive(10);
    printf("a soma é: %d\n", sumRange);

    int numbers[] = {1, 2, 3, 4, 5};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    int sum = sumArrRecursive(numbers, len);
    printf("a soma dos elementos é: %d\n", sum);

    return 0;
}