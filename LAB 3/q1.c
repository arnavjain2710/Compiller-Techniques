#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  
    }
}


int LIS(int arr[], int size) {

    int lis[size];  
    for (int i = 0; i < size; i++) {
        lis[i] = 1;
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maxLIS = 0;
    for (int i = 0; i < size; i++) {
        if (lis[i] > maxLIS) {
            maxLIS = lis[i];
        }
    }

    return maxLIS;
}

int main() {

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generateRandomArray(arr, size);

    printf("Generated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = LIS(arr, size);
    printf("Length of Longest Increasing Subsequence (LIS): %d\n", result);

    return 0;
}
