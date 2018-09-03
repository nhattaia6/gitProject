#include<stdio.h>
#include<vector>
using namespace std;
#define maxE 100
typedef struct{
	vector<int> adj[maxE];
	int n,m;
}Graph;

void init_graph(Graph *G,int n,int m){
	G->n=n;
	G->m=m;
	for(int i=1;i<=n;i++)
		vector<int> adj[i];
}
void add_edge(Graph *G,int x,int y){

		G->adj[x].push_back(y);

		G->adj[y].push_back(x);
}
/*
void add_edge1(Graph *G,int x,int y){
	int j=1;
	while(sizeList(&G->adj[x])>=j){
		if(elementAt(&G->adj[x],j)==y)
			break;
		else j++;
	}
	if(j>sizeList(&G->adj[x]))
		pushBack(&G->adj[x],y);

	int i=1;
	while(sizeList(&G->adj[y])>=i){
		if(elementAt(&G->adj[y],i)==x)
			break;
		else i++;
	}
	if(i>sizeList(&G->adj[y]))
		pushBack(&G->adj[y],x);
}*/
int degree(Graph *G,int x){
	return G->adj[x].size();
}
int adjacent(Graph *G,int x,int y){
	int i;
	for(i=0;i<(int)G->adj[x].size();i++)
		if(G->adj[x].at(i) == y)
			return 1;
	return 0;
}
vector<int> neighbours(Graph *G,int x){
	vector<int> L;
	for(int i=1;i<=G->n;i++)
		if(adjacent(G,x,i))
			L.push_back(i);
	return L;
}
int main(){
	Graph G;
	int n,m;
	int u,v;
	FILE* file=fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n,m);
	for(int i=1;i<=m;i++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	fclose(file);
	for(int i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}

	for(int i=1;i<=G.n;i++){
		vector<int> L= neighbours(&G,i);
		printf("Cac dinh ke cua %d: [",i);
		for(int j=0;j<(int)L.size();j++)
			printf("%d ",L[j]);
		printf("]\n");
	}
	return 0;
}


