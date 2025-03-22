#include<stdio.h>
#include<stdlib.h>
#define high 9999

void prims(int graph[][20],int v){
	int *selected = (int *)malloc(v * sizeof(int));
	int *key = (int *)malloc(v * sizeof(int));
	int *parent =(int *)malloc(v * sizeof(int));
	//The selected array is used to keep track of which vertices have already been included in MST
	//key[i] stores the minimum edge weight needed to connect vertex i to the MST
	//For each vertex in the MST (except the starting vertex), the parent array stores the index of its "parent" vertex
	for(int i=0;i<v;i++){
		selected[i]=0;
		key[i]=high;
		parent[i] = -1;
	}
	key[0] = 0; // starting vertex 0
	
	int ec; //edge count
	for(ec=0; ec<v-1; ec++){
		int min=high, u=-1;
		
		//Finds the vertex u that is not yet selected in the MST and with the minimum key value.
		for(int j=0;j<v;j++){
			if(selected[j]==0 && key[j]<min){
				min=key[j];
				u=j;
			}
		}
		selected[u]=1;
		
		//Updates key[] and parent[] for all unselected neighbors of u.
		for(int k=0;k<v;k++){
			if(selected[k]==0 && graph[u][k]<key[k]){
				key[k]=graph[u][k]; //store the new minimum weight to reach k
				parent[k]=u;		// Set parent of k to u
			}
		}
	}

	printf("\nMinimum Spanning Tree Edges:\n");
	int tot_w=0;
    for (int i = 1; i < v; i++) {
        printf("%d - %d  Weight: %d\n", parent[i], i, graph[parent[i]][i]);
        tot_w+=graph[parent[i]][i];
    }
    printf("Total cost: %d",tot_w);

    free(selected);
    free(key);
    free(parent);
}

void display(int graph[][20],int vertex){
	printf("The graph adjacency matrix:\n");
	for (int i=0;i<vertex;i++){
		for (int j=0;j<vertex;j++)
			printf("%d\t",graph[i][j]);
		printf("\n");
	}
}

int main(){
	int graph[20][20];	// Adjacency matrix
	int vertex,edge,v1,v2,i,j,weight;
	
	printf("Enter number of vertices: ");
	scanf("%d",&vertex);
	printf("Enter number of edges: ");
	scanf("%d",&edge);
	
	// Initialize graph with all 9999
    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
                graph[i][j] = high;
        }
    }
	
	//input graph
	for(i=0;i<edge;i++){
		printf("Enter vertices v1 & v2 of edge %d: ",i);
		scanf("%d %d",&v1,&v2);
		printf("Enter weight of edge (%d,%d): ",v1,v2);
		scanf("%d",&weight);
		graph[v2][v1]=graph[v1][v2]=weight;
	}
	
	display(graph,vertex);
	prims(graph,vertex);
	
	return 0;
}