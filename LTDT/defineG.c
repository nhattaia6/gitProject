#include<stdio.h>
#define Max_edge 500
#define Max_vertex 100
typedef struct{
    int u;
    int v;
}Edge;
typedef struct{
    int n;
    int m;
    Edge edges[Max_edge];
    int A[Max_vertex][Max_vertex];
}Graph;
void init_graph(Graph *G,int n,int m){
    G->n=n;
    G->m=m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            G->A[i][j]=0;
}
void add_edge(Graph *G,int x,int y){
    G->edges[G->m].u=x;
    G->edges[G->m].v=y;
    G->m ++;
    G->A[x-1][y-1]=1;
    G->A[y-1][x-1]=1;
}
int adjacent(Graph *G,int x,int y){
    if((G->A[x-1][y-1]==1)&&(G->A[y-1][x-1]==1))
        return 1;
    else
        return 0;
}
int main(){
    Graph G;
    init_graph(&G,3,4);
    
	add_edge(&G,1,3);
	add_edge(&G,2,3);
	printf("\n");
	for(int i=0;i<G.n;i++)
    {
        for(int j=0;j<G.n;j++)
            printf("%d ",G.A[i][j]);
        printf("\n");
    }
	if(adjacent(&G,1,2)==1)
		printf("(1,2) la canh lien ke");
	else
		printf("(1,2) la canh KHONG lien ke");
    return 0;
}
