/*30/09/2016
 *Autor: Manuel Gomes 11-10375
 *Descripción: Archivo con las firmas de las funciones empleadas en la resolución del problema
 */

#ifndef GRAPH
#define GRAPH

#include <stdio.h>
#include <stdlib.h>

struct _node;

typedef struct _edge {
	struct _node* to;
	struct _edge* next;
} Edge;


typedef struct _node {
	int n;
	struct _edge* children;
	struct _node* next;
} Node;

typedef struct _graph {
	int n;
	Node* first;
} Graph;

#include "matrix.h"


Graph* createG();
void printGraph(Graph*);
void deleteGraph(Graph*);
int isTreeAux(Node*, Matrix*);
int isTree(Graph*);
void addPair(Graph*, int, int);


#endif