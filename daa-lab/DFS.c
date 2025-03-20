#include<stdio.h>
#include<stdlib.h>
struct stack{
	int top, size, *arr;
};

int isFull(struct stack *s){
	return (s->top==s->size-1);
}
int isEmpty(struct stack *s){
	return (s->top==-1);
}

void push(struct stack *s,int data){
	if(isFull(s))
		printf("stack full.");
	else{
		s->top++;
		s->arr[s->top]=data;
	}
}
int pop(struct stack *s){
	int data=-1;
	if(isEmpty(s))
		printf("stack empty.");
	else{
		data=s->arr[s->top];
		s->top--;
	}
	return data;
}

int main(){
	struct stack s;
	s.size=100;
	s.top=-1;
	s.arr=(int *)malloc(s.size*sizeof(int));
	
	//DFS
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
	push(&s,i);
	visited[i]=1;
	
	while(!isEmpty(&s)){
		int node=pop(&s);
		printf("%d ",node);
		
		for(int j=6; j>=0; j--){
			if(a[node][j]==1 && visited[j]==0){
				push(&s,j);
				visited[j]=1;
			}
		}
	}
	
	free(s.arr);
	return 0;
}









