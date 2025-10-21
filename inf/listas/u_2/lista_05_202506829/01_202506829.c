#include <stdio.h>

#define CHAR_NUM 50

typedef struct {
    int registrationCode;
    char name[CHAR_NUM];
    float n1;
    float n2;
    float n3;
} Student;

int main() {

    Student s1 = {
        202506829,
        "milena",
        9.8,
        9.7,
        10.0
    };

    printf("TAMANHO EM BYTES DA STRUCT = %zu\n", sizeof(s1));

    return 0;
}