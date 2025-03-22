#include<stdio.h>
#include<stdlib.h>

struct item{
	int profit,weight;
	double ratio;
};

void bubbleSort(struct item *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int flag = 0;
		  
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j].ratio < arr[j + 1].ratio){
                struct item temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main(){
	int n,capacity;
	printf("Enter no. of items: ");
	scanf("%d",&n);
	
	struct item *itemArr=(struct item*)malloc(n*sizeof(struct item));
	for(int i=0;i<n;i++){
		printf("Enter profit and weight of item %d: ",i);
		scanf("%d %d",&itemArr[i].profit,&itemArr[i].weight);
		itemArr[i].ratio= (double)itemArr[i].profit/itemArr[i].weight;
	}
	
	printf("Enter knapsack capacity: ");
	scanf("%d",&capacity);
	
	bubbleSort(itemArr,n);
	
	double totalProfit=0; int remainingWeight=capacity;
	printf("\nKnapsack caclculation:\n");
	for(int i=0;i<n;i++){
		if(itemArr[i].weight<=remainingWeight){
			totalProfit+=itemArr[i].profit;
			remainingWeight-=itemArr[i].weight;
			printf("Item %d: Profit=%d Weight=%d taken\n",i,itemArr[i].profit,itemArr[i].weight);
		}
		else{
			double f=((double)remainingWeight/itemArr[i].weight);
			totalProfit+=itemArr[i].profit*f;
			printf("Item %d: Profit=%.2f Weight=%d taken\n",i,itemArr[i].profit*f,remainingWeight);
			break;// Knapsack full
		}
	}
	printf("Total profit: %.2f",totalProfit);
	
	free(itemArr);
}

//This algorithm runs in O(n log n) due to sorting and O(n) for selection, total complexity O(n log n).
