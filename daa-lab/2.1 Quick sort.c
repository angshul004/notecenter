//Explanation: https://www.youtube.com/watch?v=QN9hnmAgmOc

#include<stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int lb, int ub) 
{ 
    int pivot=arr[lb];
    int start=lb;
    int end = ub;
    
    while(start<end){
    	while(arr[start]<=pivot)
    		start++;
    	while(arr[end]>pivot)
    		end--;
    	if(start<end)
    		swap(&arr[start],&arr[end]);
	}
	swap(&arr[lb],&arr[end]);
	return end;
}

void quickSort(int arr[], int lb, int ub) 
{
    if(lb<ub){
    	int pos=partition(arr,lb,ub);
    	quickSort(arr,lb,pos-1);
    	quickSort(arr,pos+1,ub);
	}
}

int main() 
{
    int arr[] = {15,5,24,8,1,3,16,10,20};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    
    printf("sorted array:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    return 0;
}