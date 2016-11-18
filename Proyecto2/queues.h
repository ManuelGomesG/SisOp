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

typedef struct _childAnswer {
	char path[1024];
	int size;
	dQhead* toAdd;
	struct _childAnswer* next;
} childAnswer;

typedef struct _cAQueue{
	childAnswer* first;
	childAnswer* last;
}	cAQueue;

dQhead* createDQ();
Direc* createD(char [1024]);
void printQ(dQhead*);
void addToQ(dQhead*,Direc*);
void popFromQ(dQhead* q);
dQhead* concatQs(dQhead*, dQhead*);
int isEmptyQ(dQhead*);


cAQueue* createCAQ();
childAnswer* createCA(char [1024], int, dQhead*);
void addCAtoQ(cAQueue*,childAnswer*);
void popFromCAQ(cAQueue*);
cAQueue* concatCAQs(cAQueue*, cAQueue*);
int isEmptyCAQ(cAQueue*);
//void printCAQ(cAQueue*);





