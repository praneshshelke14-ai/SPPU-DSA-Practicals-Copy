/* Practical 1(b): Binary Search on sorted student roll numbers */
#include <stdio.h>

int binarySearch(const int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int n, arr[100], key;

    printf("Enter number of students (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter roll numbers in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i > 0 && arr[i] < arr[i - 1]) {
            printf("Input must be sorted in ascending order.\n");
            return 1;
        }
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    int position = binarySearch(arr, n, key);
    if (position != -1) {
        printf("Student with roll number %d attended the training program.\n", key);
        printf("Position in array (1-based): %d\n", position + 1);
    } else {
        printf("Student with roll number %d did NOT attend the training program.\n", key);
    }
    return 0;
}
