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
	int n,m,i;
	int u,v;
	char temp[50];
	gets(temp);
	FILE* file=fopen(temp,"r");
	fscanf(file,"%d%d",&n,&m);
	initGraph(&G,n,m);
	for( i=1;i<=G.m;i++){
		fscanf(file,"%d%d",&u,&v);
		addEdge(&G,i,u,v);
	}
	fclose(file);
	for( i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	return 0;
}
