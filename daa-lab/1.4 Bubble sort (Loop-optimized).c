#include <stdio.h>
#include<stdlib.h>
//int count=0;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
		  
        for (int j = 0; j < n - 1 - i; j++) {
        	//count++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];		//swap
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0) { 	// If no elements were swapped
            break;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    //printf("No of comparisons is %d\n", count);

    return 0;
}