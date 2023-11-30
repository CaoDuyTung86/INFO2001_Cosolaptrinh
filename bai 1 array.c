#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t start_bubble = clock();
    bubbleSort(arr, n);
    clock_t end_bubble = clock();
    clock_t start_selection = clock();
    selectionSort(arr, n);
    clock_t end_selection = clock();
    double time_taken_bubble = ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    double time_taken_selection = ((double)(end_selection - start_selection)) / CLOCKS_PER_SEC;
    printf("Mang sau khi sap xep:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Thoi gian thuc thi Bubble Sort: %f giay\n", time_taken_bubble);
    printf("Thoi gian thuc thi Selection Sort: %f giay\n", time_taken_selection);
    return 0;
}
