#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap diem cua sinh vien %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float diemTrungBinh = sum / n;
    printf("Diem trung binh cua lop: %.2f\n", diemTrungBinh);
    return 0;
}
