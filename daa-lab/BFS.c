#include<stdio.h>
#include<stdlib.h>

struct queue{
	int size, f, r, *arr;
};

int isEmpty(struct queue *q){
	if(q->f==-1&&q->r==-1)
		return 1;
	return 0;
}
int isFull(struct queue *q){
	if(q->r==q->size-1)
		return 1;
	return 0;
}

void enqueue(struct queue *q, int data){
	if(isFull(q))
		printf("Queue full");
	else{
		if(q->f==-1)
			q->f=0;
		q->r++;
		q->arr[q->r]=data;
	}
}
int dequeue(struct queue *q){
	int data=-1;
	if(isEmpty(q))
		printf("Queue empty");
	else{
		data=q->arr[q->f];
		if(q->f==q->r)
			q->f=q->r=-1;
		else
			q->f++;
	}
	return data;
}

int main(){
	//initialize queue
	struct queue q;
	q.size=100;
	q.f=q.r=-1;
	q.arr=(int*)malloc(q.size*sizeof(int));
	
	//BFS
	int i=0; 			//starting value
	int visited[] = {0,0,0,0,0,0,0};	//for 7 nodes
	int a[7][7]={
	   //0,1,2,3,4,5,6
		{0,1,1,1,0,0,0},
		{1,0,1,0,0,0,0},
		{1,1,0,1,0,0,0},
		{1,0,1,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	
	//search traversal
	
	enqueue(&q,i);
	visited[i]=1;
	
	while(!isEmpty(&q)){
		int node= dequeue(&q);
		printf("%d ",node);
		
		for(int j=0;j<7;j++){
			if(a[node][j]==1 && visited[j]==0){
				enqueue(&q,j);
				visited[j]=1;
			}
		}
	}
	
	free(q.arr);
	return 0;
}







