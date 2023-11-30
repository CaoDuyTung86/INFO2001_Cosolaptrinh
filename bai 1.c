#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float score;
};
void inputStudent(struct Student *student) {
    printf("Nhap ten sinh vien: ");
    scanf("%s", student->name);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &student->age);
    
    printf("Nhap diem sinh vien: ");
    scanf("%f", &student->score);
}
void displayStudent(struct Student student) {
    printf("Ten: %s\n", student.name);
    printf("Tuoi: %d\n", student.age);
    printf("Diem: %.2f\n", student.score);
}
int main() {
    int numStudents;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);
    struct Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        inputStudent(&students[i]);
    }
    printf("\nThong tin cac sinh vien:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nThong tin cho sinh vien thu %d:\n", i + 1);
        displayStudent(students[i]);
    }
    return 0;
}
