#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// C?u trúc Employee
typedef struct {
    int employeeId;
    char name[50];
    char position[50];
    float salary;
} Employee;

// M?ng ch?a danh sách nhân viên
Employee employeeList[MAX_EMPLOYEES];
int numEmployees = 0;

// Ch?c nang thêm nhân viên
void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("Danh sach nhan vien da day. Khong the them nua.\n");
        return;
    }

    Employee newEmployee;
    printf("Nhap ma nhan vien: ");
    scanf("%d", &newEmployee.employeeId);
    printf("Nhap ten nhan vien: ");
    scanf(" %[^\n]", newEmployee.name);
    printf("Nhap chuc vu: ");
    scanf(" %[^\n]", newEmployee.position);
    printf("Nhap luong: ");
    scanf("%f", &newEmployee.salary);

    employeeList[numEmployees] = newEmployee;
    numEmployees++;

    printf("Them nhan vien thanh cong.\n");
}

// Ch?c nang xóa nhân viên
void removeEmployee() {
    int employeeId;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &employeeId);

    int foundIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        if (employeeList[i].employeeId == employeeId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Khong tim thay nhan vien co ma nhan vien %d.\n", employeeId);
        return;
    }

    for (int i = foundIndex; i < numEmployees - 1; i++) {
        employeeList[i] = employeeList[i + 1];
    }

    numEmployees--;

    printf("Xoa nhan vien thanh cong.\n");
}

// Ch?c nang hi?n th? danh sách nhân viên
void displayEmployees() {
    if (numEmployees == 0) {
        printf("Danh sach nhan vien rong.\n");
        return;
    }

    printf("Danh sach nhan vien:\n");
    printf("Ma NV\tTen\tChuc vu\tLuong\n");
    for (int i = 0; i < numEmployees; i++) {
        Employee currentEmployee = employeeList[i];
        printf("%d\t%s\t%s\t%.2f\n", currentEmployee.employeeId, currentEmployee.name, currentEmployee.position, currentEmployee.salary);
    }
}

// Hàm so sánh d? s?p x?p nhân viên theo mã nhân viên
int compareEmployee(const void* a, const void* b) {
    Employee* employeeA = (Employee*)a;
    Employee* employeeB = (Employee*)b;

    return employeeA->employeeId - employeeB->employeeId;
}

// Ch?c nang s?p x?p nhân viên theo mã nhân viên
void sortEmployees() {
    if (numEmployees == 0) {
        printf("Danh sach nhan vien rong.\n");
        return;
    }

    qsort(employeeList, numEmployees, sizeof(Employee), compareEmployee);

    printf("Sap xep nhan vien theo ma nhan vien thanh cong.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nQUAN LY NHAN SU\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep nhan vien theo ma nhan vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                removeEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                sortEmployees();
                break;
            case 0:
                printf("Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}
