#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int op = -1, opCalc = -1;

    float a = 0.00f, b = 0.00f;

    float res = 1;

    int count = 0, sum = 0, sub = 0, mult = 0, div = 0, pot = 0, sqt = 0, abs = 0;

    do {
        printf("== Calculadora ==\n");
        printf("1 - Realizar operações\n");
        printf("2 - Gerar relatório\n");
        printf("0 - Encerrar");

        scanf("%d", &op);

        switch (op) {
            case 1:
                do {
                    printf("== Operações binárias básicas == \n");
                    printf("1 - Adicionar dois números\n");
                    printf("2 - Subtrair dois números\n");
                    printf("3 - Multiplicar dois números\n");
                    printf("4 - Dividir dois números\n");
            
                    printf("== Operações avançadas == \n");
                    printf("5 - Potenciação\n");
                    printf("6 - Raiz quadrada\n");
                    printf("7 - Valor absoluto\n");
            
                    printf("=====\n");
                    printf("0 - Encerrar\n");
            
                    scanf("%d", &opCalc);
            
                    switch (opCalc) {
                        case 1:
                            printf("Digite dois números para a + b: \n");
                            scanf("%f %f", &a, &b);
                            res = a + b;
                            printf("= %.3f\n", res);
            
                            count++;
                            sum++;
                            break;
            
                        case 2:
                            printf("Digite dois números para a - b: \n");
                            scanf("%f %f", &a, &b);
                            res = a - b;
                            printf("= %.3f\n", res);
            
                            count++;
                            sub++;
                            break;
            
                        case 3:
                            printf("Digite dois números para a * b: \n");
                            scanf("%f %f", &a, &b);
                            res = a * b;
                            printf("= %.3f\n", res);
            
                            count++;
                            mult++;
                            break;
            
                        case 4:
                            printf("Digite dois números para a / b\n");
                            scanf("%f %f", &a, &b);
                            if (b == 0) {
                                res = 0.00f;
                                printf("Divisão por zero!");
                                break;
                            }
                            printf("= %.3f\n", a / b);
            
                            count++;
                            div++;
                            break;
                        
                        case 5:
                            printf("Digite dois números para a ^ b: \n");
                            scanf("%f %f", &a, &b);
                            res = 1;
                            for (int i = 0; i < b; i++) {
                                res *= a;
                            }
                            printf("= %.3f\n", res);
            
                            count++;
                            pot++;
                            break;
            
                        case 6:
                            printf("Digite um número para √a: \n");
                            scanf("%f", &a);
                            res = sqrtf(a);
                            printf("= %.3f\n", res);
            
                            count++;
                            sqt++;
                            break;
            
                        case 7:
                            printf("Digite um número para |a|: \n");
                            scanf("%f", &a);
                            res = fabs(a);
                            printf("= %.3f\n", res);
            
                            count++;
                            abs++;
                            break;
                    }
                } while(opCalc != 0);
                break;
            
            case 2:
                printf("===== Relatório =====\n");
                printf("Último resultado da calculadora: \n");
                printf("%.3f\n", res);
                
                printf("=====\n");

                printf("Total de operações realizadas: \n");
                printf("%d\n", count);

                printf("=====\n");
                
                // sum, sub, mult, div, pot, sqt, abs
                printf("Operação mais usada: \n");
                if (sum >= sub && sum >= mult && sum >= div && sum >= pot && sum >= sqt && sum >= abs) {
                    printf("SOMA = %d\n", sum);
                } else if (sub >= sum && sub >= mult && sub >= div && sub >= pot && sub >= sqt && sub >= abs) {
                    printf("SUBTRAÇÃO = %d\n", sub);
                } else if (mult >= sum && mult >= sub && mult >= div && mult >= pot && mult >= sqt && mult >= abs) {
                    printf("MULTIPLICAÇÃO = %d\n", mult);
                } else if (div >= sum && div >= sub && div >= mult && div >= pot && div >= sqt && div >= abs) {
                    printf("DIVISÃO = %d\n", div);
                } else if (pot >= sum && pot >= sub && pot >= mult && pot >= div && pot >= sqt && pot >= abs) {
                    printf("POTENCIAÇÃO = %d\n", pot);
                } else if (sqt >= sum && sqt >= sub && sqt >= mult && sqt >= div && sqt >= pot && sqt >= abs) {
                    printf("RAIZ QUADRADA = %d\n", sqt);
                } else {
                    printf("VALOR ABSOLUTO = %d\n", abs);
                }

                printf("Operação menos usada: \n");
                if (sum <= sub && sum <= mult && sum <= div && sum <= pot && sum <= sqt && sum <= abs) {
                    printf("SOMA = %d\n", sum);
                } else if (sub <= sum && sub <= mult && sub <= div && sub <= pot && sub <= sqt && sub <= abs) {
                    printf("SUBTRAÇÃO = %d\n", sub);
                } else if (mult <= sum && mult <= sub && mult <= div && mult <= pot && mult <= sqt && mult <= abs) {
                    printf("MULTIPLICAÇÃO = %d\n", mult);
                } else if (div <= sum && div <= sub && div <= mult && div <= pot && div <= sqt && div <= abs) {
                    printf("DIVISÃO = %d\n", div);
                } else if (pot <= sum && pot <= sub && pot <= mult && pot <= div && pot <= sqt && pot <= abs) {
                    printf("POTENCIAÇÃO = %d\n", pot);
                } else if (sqt <= sum && sqt <= sub && sqt <= mult && sqt <= div && sqt <= pot && sqt <= abs) {
                    printf("RAIZ QUADRADA = %d\n", sqt);
                } else {
                    printf("VALOR ABSOLUTO = %d\n", abs);
                }

                break;
        }
    } while(op != 0);
    return 0;
}