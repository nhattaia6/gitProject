#include<stdio.h>
#define maxN 100
#define maxM 500
typedef struct{
	int n;
	int m;
	int A[maxN][maxM];
}Graph;
void initGraph(Graph *G,int n,int m){
	G->n=n;
	G->m=m;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			G->A[i][j]=0;
}
void addEdge(Graph *G,int e,int x,int y){
	G->A[x][e]=1;
	G->A[y][e]=1;
}
int degree(Graph *G, int x){
	int i;
	int count=0;
	for(i=1;i<=G->m;i++){
		if(G->A[x][i]==1)
			count++;
	}
	return count;
}
int adjacent(Graph *G,int x,int y){
	int e;
	for(e=1;e<=G->m;e++)
		if((G->A[x][e]==1) && (G->A[y][e]==1))
			return 1;
	return 0;
}
void neighbours(Graph *G,int x){
	int i;
	for(i=1;i<=G->n;i++)
		if((adjacent(G,x,i))&&(x!=i))
			printf("%d ",i);
}
int main(){
	Graph G;
	int n,m;
	int u,v;
	FILE* file=fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	initGraph(&G,n,m);
	for(int i=1;i<=m;i++){
		fscanf(file,"%d%d",&u,&v);
		addEdge(&G,i,u,v);
	}
	fclose(file);
	for(int i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	for(int i=1;i<=G.n;i++){
		for(int j=1;j<=G.m;j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
	for(int i=1;i<=G.n;i++){
		printf("%d = ",i);
		neighbours(&G,i);
		printf("\n");
	}
	return 0;
}
/*
List neighbors(Graph *G,int x){
	int i,e;
	List L;
	make_null(&L);
	for(i=1;i<=G->n;i++)
		for(e=G->m;e>=1;e--)
		    if((G->A[x][e]==1) && (G->A[i][e]==1) &&(x!=i)){
		        int j=1;
		        while(j<=count_list(&L)){
		            if(element_at(&L,j)==i)
		                break;
		            else
		                j++;
		        }
		        if(j>count_list(&L))
		            push_back(&L,i);
		    }
	return L;
}*/
