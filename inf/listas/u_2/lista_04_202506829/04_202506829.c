#include <stdio.h>
#include <string.h>

#define CHAR_NUM 50
#define CHAR_CPF 15
#define MAX 30

typedef struct {
    char name[CHAR_NUM];
    char role[CHAR_NUM];
    float baseSalary;
    float finalSalary;
    char department[CHAR_NUM];
    char cpf[CHAR_CPF];
} Employee;

void cleanBuffer();

float calculateFinalSalary(float baseSalary, char *role);

void report(const Employee *e, int len);

int main() {
    int len = 0;
    printf("Digite quantos funcionários deseja cadastrar: ");
    scanf("%d", &len);
    cleanBuffer();

    Employee employees[MAX];
    float sumSalaries = 0.00f;

    for (int i = 0; i < len; i++) {
        printf("\n-- Funcionário: %d --\n", i + 1);

        printf("Nome: ");
        fgets(employees[i].name, CHAR_NUM, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Cargo: ");
        fgets(employees[i].role, CHAR_NUM, stdin);
        employees[i].role[strcspn(employees[i].role, "\n")] = '\0';

        printf("Salário-base: ");
        scanf("%f", &employees[i].baseSalary);
        cleanBuffer();

        printf("CPF: ");
        fgets(employees[i].cpf, CHAR_CPF, stdin);
        employees[i].cpf[strcspn(employees[i].cpf, "\n")] = '\0';

        printf("Departamento: ");
        fgets(employees[i].department, CHAR_NUM, stdin);
        employees[i].department[strcspn(employees[i].department, "\n")] = '\0';

        employees[i].finalSalary = calculateFinalSalary(employees[i].baseSalary, employees[i].role);

        sumSalaries += employees[i].finalSalary;
    }

    float avgSalaries = sumSalaries / len;

    report(employees, len);
    printf("Salário médio: R$%.3f", avgSalaries);

    return 0;
}

float calculateFinalSalary(float baseSalary, char *role) {
    if (strcasecmp(role, "assistente") == 0) {
        return baseSalary * 1.05;
    } else if (strcasecmp(role, "supervisor") == 0) {
        return baseSalary * 1.10;
    } else if (strcasecmp(role, "gerente") == 0) {
        return baseSalary * 1.15;
    } else {
        return baseSalary * 1.02;
    }
}

void report(const Employee *e, int len) {
    printf("\n== Relatório de Funcionários ==\n");
    for (int i = 0; i < len; i++) {
        printf("NOME: %s\n", e[i].name);
        printf("CARGO: %s\n", e[i].role);
        printf("CPF: %s\n", e[i].cpf);
        printf("DPT: %s\n", e[i].department);
        printf("SALÁRIO FINAL: R$%.3f\n", e[i].finalSalary);
        printf("-----------------------\n");
    }
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
