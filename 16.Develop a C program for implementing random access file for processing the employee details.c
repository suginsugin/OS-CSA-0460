#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;

void writeEmployee(FILE *file, Employee emp, int index) {
    fseek(file, index * sizeof(Employee), SEEK_SET);
    fwrite(&emp, sizeof(Employee), 1, file);
}

void readEmployee(FILE *file, Employee *emp, int index) {
    fseek(file, index * sizeof(Employee), SEEK_SET);
    fread(emp, sizeof(Employee), 1, file);
}

int main() {
    FILE *file = fopen("employees.dat", "wb+");
    Employee emp1 = {1, "John Doe", 50000.0};
    writeEmployee(file, emp1, 0);
    
    Employee emp2;
    readEmployee(file, &emp2, 0);
    printf("ID: %d, Name: %s, Salary: %.2f\n", emp2.id, emp2.name, emp2.salary);
    
    fclose(file);
    return 0;
}
