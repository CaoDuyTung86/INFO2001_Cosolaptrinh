#include <stdio.h>
#define MAX_SIZE 100

void nhapMang(int* arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }
}

void inMang(const int* arr, int size) {
    printf("Cac phan tu cua mang la:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int timKiem(const int* arr, int size, int x) {
    int i;
    for (i = 0; i < size; i++) {
        if (*(arr + i) == x) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int arr[MAX_SIZE];
    int size;
    
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &size);
    
    if (size > 0 && size <= MAX_SIZE) {
        nhapMang(arr, size);
        
        inMang(arr, size);
        
        int x;
        printf("Nhap phan tu can tim kiem: ");
        scanf("%d", &x);
        
        int index = timKiem(arr, size, x);
        if (index != -1) {
            printf("Phan tu %d xuat hien tai vi tri %d trong mang.\n", x, index);
        } else {
            printf("Khong tim thay phan tu %d trong mang.\n", x);
        }
    } else {
        printf("So luong phan tu khong hop le.\n");
    }
    
    return 0;
}
