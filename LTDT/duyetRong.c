#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct{
	int data[max];
	int front,rear;
}queue;
void makeNull(queue *q){
	q->front=0;
	q->rear=-1;
}
void push(queue *q,int x){
	q->rear++;
	q->data[q->rear]=x;
}
int top(queue *q){
	return q->data[q->front];
}
void pop(queue *q){
	q->front++;
}
int empty(queue *q){
	return q->front>q->rear;
}

//
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
//
void depth_first_search(Graph *G){
	queue q;
	int mark[max];
	makeNull(&q);
	int j;
	for(j=1;j<=G->n;j++)
		mark[j]=0;

	push(&q,1);
	mark[1]=1;

	while(!empty(&q)){
		int x;
		x=top(&q);
		pop(&q);
		printf("Duyet %d\n",x);
		list l=neighbours(G,x);
		for(j=1;j<=l.size;j++){
			int y=elementAt(&l,j);
			if(mark[y]==0){
				mark[y]=1;
				push(&q,y);
			}
		}
	}
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
