#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>



typedef struct _direc {
	char dir[1024];
	struct _direc * next;
} Direc;

typedef struct _dQhead{
	Direc* first;
	Direc* last;
}	dQhead;

dQhead* createDQ();
Direc* createD(char [1024]);
void printQ(dQhead*);
void addToQ(dQhead*,Direc*);
void popFromQ(dQhead* q);


