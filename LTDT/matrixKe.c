#include<stdio.h>
#define maxN 100
typedef struct{
	int n;
	int m;
	int A[maxN][maxN];
}Graph;
void initGraph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			pG->A[i][j]=0;
}
void addEdge(Graph *pG,int x,int y){
	pG->A[x][y]=1;
	pG->A[y][x]=1;
}
int degree(Graph *pG, int x){
	int i;
	int count=0;
	for(i=1;i<=pG->n;i++){
		if(pG->A[x][i]==1)
			count++;
	}
	return count;
}
int adjacent(Graph *pG,int x,int y){
	if(pG->A[x][y]==1)
		return 1;
	else
		return 0;
}
void neighbours(Graph *pG,int x){
	int i;
	for(i=1;i<=pG->n;i++)
		if(adjacent(pG,x,i))
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
	}
	return 0;
}
