#include<stdio.h>
#define maxE 100
typedef int element;
typedef struct{
	element data[maxE];
	int size;
}list;
void makeNull(list *L){
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
///
typedef struct{
	list adj[maxE];
	int n,m;
}Graph;

void initGraph(Graph *pG,int n,int m){
	pG->n=n;
	pG->m=m;
	for(int i=1;i<=n;i++)
		makeNull(&pG->adj[i]);
}
void addEdge(Graph *pG,int x,int y){

		pushBack(&pG->adj[x],y);

		pushBack(&pG->adj[y],x);
}
void addEdge1(Graph *pG,int x,int y){
	int j=1;
	while(sizeList(&pG->adj[x])>=j){
		if(elementAt(&pG->adj[x],j)==y)
			break;
		else j++;
	}
	if(j>sizeList(&pG->adj[x]))
		pushBack(&pG->adj[x],y);
	
	int i=1;
	while(sizeList(&pG->adj[y])>=i){
		if(elementAt(&pG->adj[y],i)==x)
			break;
		else i++;
	}
	if(i>sizeList(&pG->adj[y]))
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
void neighbours(Graph *pG,int x){
	int i;
	for(i=1;i<= sizeList(&pG->adj[x]);i++)
		printf("%d ",elementAt(&pG->adj[x],i));
}
list neigh(Graph *pG,int x){
	int y;
	list l;
	makeNull(&l);
	for(y=1;y<=pG->n;y++)
		if(adjacent(pG,x,y))
			pushBack(&l,y);
	return l;
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
		addEdge(&G,u,v);
	}
	fclose(file);
	for(int i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
/*	list l[G.n];
	for(int i=1;i<=G.n;i++){
		makeNull(&l[i]);
	}
	for(int i=1;i<=G.n;i++){
		l[i]=neigh(&G,i);}
	for(int i=1;i<=G.n;i++){
		
	int j=1;
	printf("%d =",i);
	while(sizeList(&l[i])>=j){
		
		printf("%d ",elementAt(&l[i],j));
		
		j++;
	}
	printf("\n");
}*/
	for(int i=1;i<=G.n;i++){
		int j=1;
		printf("%d =",i);
		while(sizeList(&G.adj[i]) >=j){
			printf("%d ",elementAt(&G.adj[i],j));
			j++;
			}
	printf("\n");
}
printf("\n");
	for(int i=1;i<=G.n;i++){
		printf("%d= ",i);
		neighbours(&G,i);
		printf("\n");
	}
	return 0;
}
