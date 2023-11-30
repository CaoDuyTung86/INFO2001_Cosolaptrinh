#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    float score;
} SinhVien;
void sortByName(SinhVien arr[], int n) {
    int i, j;
    SinhVien temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sortByScore(SinhVien arr[], int n) {
    int i, j;
    SinhVien temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].score > arr[j + 1].score) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int searchByName(SinhVien arr[], int n, char *name) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
int searchById(SinhVien arr[], int n, int id) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].id == id) {
            return i;
        }
    }
    return -1;
}
int main() {
    int i, n, choice;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SinhVien students[n];
    for (i = 0; i < n; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Ten: ");
        scanf("%s", students[i].name);
        printf("Diem: ");
        scanf("%f", &students[i].score);
    }
    printf("\nDanh sach sinh vien ban dau:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Diem: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    printf("\nChon lua cach sap xep:\n");
    printf("1. Sap xep theo ten\n");
    printf("2. Sap xep theo diem\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            sortByName(students, n);
            printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
            break;
        case 2:
            sortByScore(students, n);
            printf("\nDanh sach sinh vien sau khi sap xep theo diem:\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            return 0;
    }
    for (i = 0; i < n; i++) {
        printf("ID: %d,Tên: %s, Ði?m: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    char searchName[50];
    int searchId;
    printf("\nNhap ten hoac id cua sinh vien can tim kiem: ");
    scanf("%s", searchName);
    int searchResult = searchByName(students, n, searchName);
    if (searchResult != -1) {
        printf("Sinh vien co ten %s duoc tim thay tai vi tri %d trong danh sach.\n", searchName, searchResult + 1);
    } else {
        printf("Khong tim thay sinh vien co ten %s trong danh sach.\n", searchName);
    }
    printf("\nNhap id cua sinh vien can tim kiem: ");
    scanf("%d", &searchId);
    searchResult = searchById(students, n, searchId);
    if (searchResult != -1) {
        printf("Sinh vien co id %d duoc tim thay tai vi tri %d trong danh sach.\n", searchId, searchResult + 1);
    } else {
        printf("Khong tim thay sinh vien co id %d trong danh sach.\n", searchId);
    }
    return 0;
}
