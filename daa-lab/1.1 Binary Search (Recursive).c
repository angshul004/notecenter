#include <stdio.h>
#include <stdlib.h>
//int count = 0;

int binarySearch(int arr[], int lo, int hi, int key) {
    if (lo > hi) {
        //count++;
        return -1;
    }

    int mid = (lo + hi) / 2;
    
    //count++;
    if (key==arr[mid]) {
        return mid;
    } else if (key<arr[mid]) {
        return binarySearch(arr, lo, mid - 1, key); 
    } else {
        return binarySearch(arr, mid + 1, hi, key); 
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements(sorted): \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int lo =0, hi = n-1;
    int index = binarySearch(arr, lo, hi, key);

    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key %d found at index %d\n", key, index);
    }
    //printf("No. of comparisons is %d\n", count);

    free(arr);
    return 0;
}
