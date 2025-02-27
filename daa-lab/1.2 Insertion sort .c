//Insertion Sort
#include <stdio.h>
int count=0;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        while(j>=0 && temp<arr[j]){	
			count++; // Counting the comparison	
        	arr[j+1]=arr[j];
        	count++; // Counting the shift
        	j--;
		}

		arr[j+1]=temp;
		count++;
    }
}

int main()
{
    int arr[] = { 14,12,10,8,6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    
    printf("No of operations is %d\n", count);

    return 0;
}