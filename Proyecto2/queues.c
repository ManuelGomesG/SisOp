

#include "queues.h"


dQhead* createDQ(){
	dQhead* dqh  = (dQhead*)malloc(sizeof(dQhead));
	dqh -> first = NULL;
	dqh -> last  = NULL;
	return dqh;
}

Direc* createD(char d[1024]) {
	Direc* nd = (Direc*)malloc(sizeof(Direc));
	strcpy(nd -> dir , d);
	nd ->  next = NULL;
	return nd;
}

void printQ(dQhead* q){
	printf("Imprimiendo cola : \n");
	if (q -> first == NULL)
		return;
	for ( Direc* aux = q -> first ; aux != NULL; aux = aux -> next) {
		printf("%s\n", aux -> dir );
	}
}

void addToQ(dQhead* q, Direc* d){
	if (q -> first == NULL) {
		q -> first = d;
		q -> last  = d;
	}
	else {
		q -> last -> next = d;
		q -> last = d;
	}

}


void popFromQ(dQhead* q) {
	Direc* aux = q -> first;
	q -> first = aux -> next;
	free(aux);
}

dQhead* concatQs(dQhead* q1, dQhead* q2) {
	q1 -> last -> next = q2 -> first;
	q1 -> last = q2 -> last;
	return q1;
}

