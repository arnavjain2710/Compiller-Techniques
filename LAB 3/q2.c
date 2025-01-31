#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) ;
    }
}


int findSmallestMissingPositive(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        while (arr[i] > 0 && arr[i] <= size && arr[arr[i] - 1] != arr[i]) {
            int temp = arr[i];
            arr[i] = arr[arr[i] - 1];
            arr[temp - 1] = temp;
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    return size + 1;
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

    int result = findSmallestMissingPositive(arr, size);
    printf("Smallest missing positive integer (MEX): %d\n", result);

    return 0;
}
