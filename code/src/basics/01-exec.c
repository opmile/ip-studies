#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void printInt(int *ptr) {
    printf("%d\n", *ptr * 2);
}

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

float average(int *arr, int len) {
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += *(arr + i);
    }

    return (float) sum / len;
}

int countLetters(char* str) {
    int count = 0;

    while (*str != '\0') {
        if (isalpha(*str)) {
            count++;
        }
        str++; // str = &str[0]
    }
    return count;
}

void inverter(char* str) {
    int len = strlen(str);
 
    int left = 0;
    int right = len - 1;

    while (left < right) {
        char temp = *(str + left);
        *(str + left) = *(str + right);
        *(str + right) = temp;

        left++;
        right--;
    }
}

int* sumVectors(int* v1, int *v2, int len) { // decai para ponteiro!
    int *result = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        *(result + i) = *(v1 + i) + *(v2 + i);
    }
    return result;
}

int* removeNegative(int *arr, int len, int* newLen) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] > 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    int* result = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        *(result + i) = *(arr + i);
    }

    *newLen = count;
    return result;
}

int* generateVector(int n) {
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        *(arr + i) = i + 1;
    }
    return arr;
}

int main() {
    
    // 01
    int x = 10;
    int *ptrX = &x;
    printf("%d\n", *ptrX);

    // 02
    printInt(ptrX);

    // 03
    int y = 30;
    swap(ptrX, &y);
    printf("x: %d, y: %d\n", x, y);

    // 04
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < len; i++) {
        printf("numero[%d]: %d\n", i, *(arr + i));
    }

    // 05
    int averageArr[] = {10, 10, 10, 10};
    int lenAvg = sizeof(averageArr) / sizeof(averageArr[0]);
    float result = average(averageArr, lenAvg);
    printf("média: %.2f\n", result);

    // 06
    char str[] = "nova string!";
    int count = countLetters(str);
    printf("%d\n", count);

    // 07
    char banana[] = "banana";
    inverter(banana);
    printf("%s\n", banana);

    // 08
    int v1[] = {1, 2, 3};
    int v2[] = {1, 2, 3};

    int lenSum = sizeof(v1) / sizeof(v1[0]);

    int *sum = sumVectors(v1, v2, lenSum); 

    for (int i = 0; i < lenSum; i++) {
        printf("numero[%d]: %d\n", i, *(sum + i));
    }
    free(sum);

    // 09
    int negatives[] = {-1, -2, 1, 2, 3, -3, -4, -7};
    int lenNeg = sizeof(negatives) / sizeof(negatives[0]);
    int newLen;

    int *noNegatives = removeNegative(negatives, lenNeg, &newLen);
    for (int i = 0; i < newLen; i++) {
        printf("numero[%d]: %d\n", i, *(noNegatives + i));
    }
    free(noNegatives);

    // 10
    int *genArr = generateVector(10);
    for(int i = 0; i < 10; i++) {
        printf("%d\n", *(genArr + i));
    }
    free(genArr);

    // 11

    return 0;
}