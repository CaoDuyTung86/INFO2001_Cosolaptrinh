#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 12;

    int linearSearchIndex = linearSearch(arr, n, x);
    if (linearSearchIndex != -1) {
        printf("Tim thay %d tai chi so %d (tim kiem tuyen tinh)\n", x, linearSearchIndex);
    } else {
        printf("Khong tim thay %d (tim kiem tuyen tinh)\n", x);
    }
    int binarySearchIndex = binarySearch(arr, n, x);
    if (binarySearchIndex != -1) {
        printf("Tim thay %d tai chi so %d (tim kiem nhi phan)\n", x, binarySearchIndex);
    } else {
        printf("Khong tim thay %d (tim kiem nhi phan)\n", x);
    }
    return 0;
}
