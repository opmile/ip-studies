#include <stdio.h>

void identifyRisk(int age, float weight) {
    printf("Grupo de risco: ");

    if (weight < 60) {
        if (age < 20) {
            printf("9\n");
        } else if (age < 50) {
            printf("6\n");
        } else {
            printf("3\n");
        }

    } else if (weight >= 60.0 && weight < 90.0) {
        if (age < 20) {
            printf("8\n");
        } else if (age < 50) {
            printf("5\n");
        } else {
            printf("2\n");
        }
    
    } else {
        if (age < 20) {
            printf("7\n");
        } else if (age < 50) {
            printf("4\n");
        } else {
            printf("1\n");
        }
    } 
}