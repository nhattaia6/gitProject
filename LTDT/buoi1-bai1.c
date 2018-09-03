#include<stdio.h>
#define maxVertices 100
#define maxEdge 500
typedef struct{
	int n;
	int m;
	int a[maxVertices][maxEdge];
}Graph;

void initGraph(Graph *G, int n, int m){
	G->n=n;
	G->m=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			G->a[i][j]=0;
	}
}
void addEdge(Graph *G,int e,int x,int y){
	G->a[x][e]=1;
	G->a[y][e]=1;
}
int adjacent(Graph *G,int x,int y){
	
		for(int j=1;j<=G->m;j++){
			if((G->a[x][j]==1) && (G->a[y][j]==1))
				return 1;
		}
		return 0;
}
int degree(Graph *G,int x){
	int count=0;
	for(int i=1;i<=G->m;i++)
		if(G->a[x][i]==1)
			count++;
	return count;
}
int main(){
	Graph G;
	initGraph(&G,4,5);
	addEdge(&G,1,1,2);
	addEdge(&G,2,1,3);
	addEdge(&G,3,1,3);
	addEdge(&G,4,3,4);
	addEdge(&G,5,1,4);
	for(int i=1;i<=4;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	return 0;
}
