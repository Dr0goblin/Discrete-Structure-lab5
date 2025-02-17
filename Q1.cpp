#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

bool nextPermutation(int arr[], int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i < 0)
        return false;

    int j = n - 1;
    while (arr[j] <= arr[i])
        j--;

    swap(&arr[i], &arr[j]);
    reverse(arr, i + 1, n - 1);
    return true;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (nextPermutation(arr, n)) {
        printf("Next permutation: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No next permutation available.\n");
    }

    return 0;
}

