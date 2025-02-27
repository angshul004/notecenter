#include<stdio.h>
#include<stdlib.h>
int max, min;

void max_min(int arr[],int i,int j){
	if(i==j){			//1 element
		max=arr[i];
		min=arr[j];
	}
	else{
		if(i==j-1){		//2 elements
			if(arr[i]<arr[j]){
				max=arr[j];
				min=arr[i];
			}
			else{
				max=arr[i];
				min=arr[j];
			}
		}
		else{
			int mid=(i+j)/2;
			
			max_min(arr,i,mid);
			int max1 = max; 
			int min1 = min;
			
			max_min(arr,mid+1,j);
			if(max <max1)
   				max = max1;
   			if(min > min1)
    			min = min1;
				
				
		}
	}
}

int main(){
	int n,*arr;
	printf("Enter number of element: ");
	scanf("%d",&n);
	
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter numbers:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int i=0,j=n-1;
	
	max_min(arr,i,j);
	printf ("Minimum element in array : %d\n", min);
 	printf ("Maximum element in array : %d\n", max);
	
	free(arr);
	return 0; 
}