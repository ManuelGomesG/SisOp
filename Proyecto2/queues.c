

#include "queues.h"


dQhead* createDQ() {
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

void printQ(dQhead* q) {
	printf("Imprimiendo cola : \n");
	if (q -> first == NULL)
		return;
	for ( Direc* aux = q -> first ; aux != NULL; aux = aux -> next) {
		printf("%s\n", aux -> dir );
	}
}

void addToQ(dQhead* q, Direc* d) {
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

int isEmptyQ(dQhead* q) {
    if (q -> first == NULL)
        return 1;
    return 0;   
}

dQhead* concatQs(dQhead* q1, dQhead* q2) {
	if (isEmptyQ(q1))
		return q2;
	else if (isEmptyQ(q2))
		return q1;
	q1 -> last -> next = q2 -> first;
	q1 -> last = q2 -> last;
	return q1;
}



cAQueue* createCAQ() {
	cAQueue* caq  = (cAQueue*)malloc(sizeof(cAQueue));
	caq -> first = NULL;
	caq -> last  = NULL;
	return caq;
}

childAnswer* createCA(char d[1024], int i, dQhead* dq) {
	childAnswer* nca = (childAnswer*)malloc(sizeof(childAnswer));
	strcpy(nca -> path , d);
	nca ->  next = NULL;
	nca ->  size = i; 
	nca -> toAdd = createDQ();
	nca -> toAdd = dq;
	return nca;
}

void addCAtoQ(cAQueue* caq, childAnswer* ca) {
	if (caq -> first == NULL) {
		caq -> first = ca;
		caq -> last  = ca;
	}
	else {
		caq -> last -> next = ca;
		caq -> last = ca;
	}
}


void popFromCAQ(cAQueue* caq) {
	childAnswer* aux = caq -> first;
	caq -> first = aux -> next;
	free(aux);
}


int isEmptyCAQ(cAQueue* caq) {
    if (caq -> first == NULL)
        return 1;
    return 0; 	
}




cAQueue* concatCAQs(cAQueue* caq1, cAQueue* caq2) {
	if (isEmptyCAQ(caq1))
		return caq2;
	else if (isEmptyCAQ(caq2))
		return caq1;
	caq1 -> last -> next = caq2 -> first;
	caq1 -> last = caq2 -> last;
	return caq1;	
}




