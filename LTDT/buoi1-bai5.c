#include<stdio.h>
#define maxN 100
typedef struct{
	int n;
	int m;
	int A[maxN][maxN];
}Graph;
void initGraph(Graph *G,int n){
	G->n=n;
	G->m=0;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->A[i][j]=0;
}
void addEdge(Graph *G,int x,int y){
	G->A[x][y]+=1;
	G->A[y][x]+=1;
}
int degree(Graph *G, int x){
	int i;
	int count=0;
	for(i=1;i<=G->n;i++){
		count+=G->A[x][i];
	}
	return count;
}
int adjacent(Graph *G,int x,int y){
	if(G->A[x][y]==1)
		return 1;
	else
		return 0;
}
void neighbours(Graph *G,int x){
	int i;
	for(i=1;i<=G->n;i++)
		if(adjacent(G,x,i))
			printf("%d ",i);
}
int main(){
	Graph G;
	int n,m;
	int u,v;
	FILE* file=fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	initGraph(&G,n);
	for(int i=1;i<=m;i++){
		fscanf(file,"%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	fclose(file);
	for(int i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	
	for(int i=1;i<=G.n;i++){
		printf("%d = ",i);
		neighbours(&G,i);
		printf("\n");
	}
	return 0;
}
