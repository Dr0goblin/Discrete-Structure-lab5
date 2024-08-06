#include <stdio.h>
#include <stdbool.h>

bool nextCombination(int arr[], int n, int r) {
    int i = r - 1;
    while (i >= 0 && arr[i] == n - r + i + 1)
        i--;

    if (i < 0)
        return false;

    arr[i]++;
    for (int j = i + 1; j < r; j++) {
        arr[j] = arr[i] + j - i;
    }

    return true;
}

int main() {
    int n = 5, r = 3;
    int arr[3] = {1, 2, 3};

    do {
        printf("Combination: ");
        for (int i = 0; i < r; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } while (nextCombination(arr, n, r));

    return 0;
}

