/*30/09/2016
 *Autor: Manuel Gomes 11-10375
 *Descripción: Archivo con las funciones empeadas en la resolución del problema
 */


#include "graph_tree.h"

Graph* createG(){
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	g -> first = NULL;
	g -> n = 0;
	return g;
}

Node* createN(int i){
	Node* n = (Node*)malloc(sizeof(Node));
	n -> n = i;
	n -> children = NULL;
	n -> next = NULL;
	return n;
}

Edge* createE(Node* n) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e -> to = n;
	e -> next = NULL;
	return e;
}





Node* existsNode(Graph* g, int a){
	Node* aux = g -> first;
	while (aux!=NULL){
		if (aux->n == a){
			break;
		}
		aux = aux -> next;
	}
	return aux;

}


void addNode(Graph* g, Node* n){
	n -> next = g -> first;
	g -> first = n;
	g -> n++;
}




void addEdge(Node* a, Node* b) {
	Edge* e = createE(b);
	e -> next = a -> children;
	a -> children = e;	
}

void addPair(Graph* g, int a, int b){
	Node* nodeA = existsNode(g,a);
	Node* nodeB = existsNode(g,b);
	if (nodeA == NULL)
		addNode(g,nodeA);
	if (nodeB == NULL)
		addNode(g,nodeB);
	addEdge(nodeA,nodeB);
}

void deleteE(Edge* e) {
	if (e==NULL)
		return;
	deleteE(e->next);
	free(e);
}

void deleteN(Node* n){
	if (n==NULL)
		return;
	deleteN(n->next);
	deleteE(n->children);
	free(n);
}

void deleteGraph(Graph* g) {
	if (g==NULL)
		return;
	deleteN(g->first);
	free(g);
}


void printE(Edge* e) {
	if (e==NULL)
		return;
	printf("%d,",e->to->n);
	printE(e->next);
}

void printN(Node* n) {
	if (n==NULL)
		return;
	printf("%d\n",n->n);
	printE(n->children);
	printN(n->next);
}

void printGraph(Graph* g){
	if (g==NULL)
		return;
	printN(g->first);
}