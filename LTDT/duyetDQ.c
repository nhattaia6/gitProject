#include<stdio.h>
#define max 100
int mark[max];
typedef int element;
typedef struct{
	element data[max];
	int size;
}list;
void makeNulll(list *L){
	L->size=0;
}
void pushBack(list *L,element x){
	L->data[L->size]=x;
	L->size++;
}
element elementAt(list *L,int i){
	return L->data[i-1];
}
int sizeList(list *L){
	return L->size;
}

typedef struct{
	list adj[max];
	int n,m;
}Graph;

void initGraph(Graph *pG,int n,int m){
	int i;
	pG->n=n;
	pG->m=m;
	for( i=1;i<=n;i++)
		makeNulll(&pG->adj[i]);
}
void addEdge(Graph *pG,int x,int y){

		pushBack(&pG->adj[x],y);

		pushBack(&pG->adj[y],x);
}
int degree(Graph *pG,int x){
	return sizeList(&pG->adj[x]);
}
int adjacent(Graph *pG,int x,int y){
	int i;
	for(i=1;i<= sizeList(&pG->adj[x]);i++)
		if(elementAt(&pG->adj[x],i) == y)
			return 1;
	return 0;
}
list neighbours(Graph *pG,int x){
	int i;
	list l;
	makeNulll(&l);
	for(i=1;i<= sizeList(&pG->adj[x]);i++)
		pushBack(&l,elementAt(&pG->adj[x],i));
	return l;
}
void traversal(Graph *G,int x){
    if(mark[x]==1)
        return;
    printf("Duyet %d\n",x);

    list L=neighbours(G,x);
    int j;
    for(j=1;j<=L.size;j++){
        int y=elementAt(&L,j);
        traversal(G,y);
    }
}
void depth_first_search(Graph *G){
    int j;
    for(j=1;j<=G->n;j++)
        mark[j]=0;
    traversal(G,1);
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
		addEdge(&G,u,v);
	}
	fclose(file);
	for( i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}

	depth_first_search(&G);
	return 0;
}
