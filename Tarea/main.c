#include "graph_tree.h"


int main(int argc, char const *argv[])
{
	/*
	int a,b;

	while (a!=-1 && b!=-1)
		Graph* g = createG();
		while (scanf("%d %d",a,b) && (a!=0 && b!=0)){
			;
		};
		printGraph(g);
		deleteGraph(g);
	*/
	int a,b,i;
	Graph* t=createG();

	FILE* fp;
	fp = fopen("input", "r");
	i=0;
	while (fscanf(fp,"%d %d", &a,&b) != EOF){
		printf("PAR %d : %d %d\n", i,a,b);
		i++;
		if (a > 0 && b > 0) {
			addPair(t,a,b);
			printf("Par %d\n", i );
			//printGraph(t);
			printf("---------------------------------------\n");
		}
		else if (a == 0 && a == 0) {
			//isTree
			printGraph(t);
			deleteGraph(t);
			t=createG();
		}
		else
			break;
	}

	return 0;
}