#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &size);
    if (size > 0) {
        int* arr = (int*)malloc(size * sizeof(int));
        if (arr == NULL) {
            printf("Khong the cap phat bo nho.\n");
            return 0;
        }
        int i;
        printf("Nhap cac phan tu cua mang:\n");
        for (i = 0; i < size; i++) {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
        }
        printf("Cac phan tu cua mang la:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    } else {
        printf("So luong phan tu khong hop le.\n");
    }
    return 0;
}
