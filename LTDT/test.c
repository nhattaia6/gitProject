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
	G->A[x][y]=1;
	G->A[y][x]=1;
}
int main(){
	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int i,n, m, u, v, e;
	scanf("%d%d", &n, &m);
	initGraph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		addEdge(&G, u, v);
	}
	for(i=1;i<=n;i++){
		for(e=1;e<=n;e++)
			printf("%d ",G.A[i][e]);
		printf("\n");
	}
}
