//Explanation: https://youtu.be/jlHkDBEumP0
#include<stdio.h>

int B[50];  


void merge(int A[],int lb,int mid,int ub){
	int i=lb, j=mid+1, k=lb;
	
	while(i<=mid && j<=ub){		//find smaller bw i,j & put into k
		if(A[i]<=A[j]){
			B[k]=A[i];
			i++;
		}
		else{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	
	if(i>mid){			//remainings
		while(j<=ub){
			B[k]=A[j];
			j++; k++;
		}
	}
	else{
		while(i<=mid){
			B[k]=A[i];
			i++; k++;
		}
	}
	
	for (k = lb; k <= ub; k++) {  // Copy B back to A
        A[k] = B[k];
    }
		
}

void mergeSort(int A[],int lb,int ub){
	if(lb<ub){
		int mid=(lb+ub)/2;
		
		mergeSort(A,lb,mid);
		mergeSort(A,mid+1,ub);
		
		merge(A,lb,mid,ub);
	}
}

int main() 
{
    int A[] = {15,5,24,8,1,3,16,10,20};
    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);
    
    printf("sorted array:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", A[i]);
    }
    return 0;
}