#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
} Book;
int main() {
    int size;
    printf("Nhap so luong cuon sach: ");
    scanf("%d", &size);
    if (size > 0) {
        Book* books = (Book*)malloc(size * sizeof(Book));
        if (books == NULL) {
            printf("Khong the cap phat bo nho.\n");
            return 0;
        }
        printf("Nhap thong tin ve cac cuon sach:\n");
        int i; 
        for (i = 0; i < size; i++) {
            printf("Nhap thong tin cuon sach thu %d:\n", i + 1);
            printf("Ten sach: ");
            scanf(" %[^\n]s", books[i].title);
            printf("Tac gia: ");
            scanf(" %[^\n]s", books[i].author);
            printf("Gia: ");
            scanf("%f", &books[i].price);
        }
        printf("Thong tin ve cac cuon sach:\n");
        for (i = 0; i < size; i++) {
            printf("Cuon sach thu %d:\n", i + 1);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia: %.2f\n", books[i].price);
            printf("\n");
    }
        free(books);
    } else {
        printf("So luong cuon sach khong hop le.\n");
    }
    return 0;
}
