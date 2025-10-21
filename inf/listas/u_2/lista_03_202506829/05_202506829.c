#include <stdio.h>
#include <string.h>

// usando técnica two pointers
void reverseStr(char *name) {
    int len = strlen(name);

    int right = len - 1;
    int left = 0;

    while(left < right) {
        int temp = name[left];
        name[left] = name[right];
        name[right] = temp;

        left++;
        right--;
    }
}

int main() {

    char name[] = "milena";
    printf("%s\n", name);

    reverseStr(name);
    printf("%s\n", name);

    return 0;
}