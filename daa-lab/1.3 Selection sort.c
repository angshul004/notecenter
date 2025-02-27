#include <stdio.h>
#include <stdlib.h>

int count = 0; // Counter to track the number of comparisons

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; // Index of the minimum element

        for (int j = i + 1; j < n; j++) {
            count++; // Counting each comparison
            if (arr[j] < arr[min])
                min = j;
        }
        
        // Swap the found minimum element with the first element
        int min_number = arr[min];
        arr[min] = arr[i];
        arr[i] = min_number;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Number of comparisons in worst case: %d\n", count);

    free(arr); 
    return 0;
}
