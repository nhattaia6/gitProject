#include<stdio.h>
#define maxM 500
typedef struct{
	int u;
	int v;
}Edge;
typedef struct{
	int n;
	int m;
	Edge edges[maxM];
}Graph;
void initGraph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
}
void addEdge(Graph *pG,int x,int y){
	pG->edges[pG->m].u=x;
	pG->edges[pG->m].v=y;
	pG->m++;
}
int degree(Graph *pG, int x){
	int i;
	int count=0;
	for(i=0;i<pG->m;i++){
		if((pG->edges[i].u==x) || (pG->edges[i].v==x))
			count++;
	}
	return count;
}
int adjacent(Graph *pG,int x,int y){
	int i;
	for(i=0;i<pG->m;i++){
		if(((pG->edges[i].u==x) && (pG->edges[i].v==y))
		|| ((pG->edges[i].u==y) && (pG->edges[i].v==x)))
			return 1;
	}
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
		printf("e%d :(%d,%d)\n",i,G.edges[i].u,G.edges[i].v);
	}
	for(int i=1;i<=G.n;i++){
		printf("%d = ",i);
		neighbours(&G,i);
	}
	return 0;
}
