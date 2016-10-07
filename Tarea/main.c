#include "graph_tree.h"


int main(int argc, char const *argv[])
{
	if (argv[1] == NULL) {
		printf("Entrada vacía. \n");
		return 0;
	}
	int a,b,i;

	FILE* fp;
	fp = fopen(argv[1], "r");
	Graph* g = createG();
	i = 1;
	while (fscanf(fp,"%d %d", &a,&b) != EOF){
		if (a > 0 && b > 0) {
			addPair(g,a,b);

		}
		else if (a == 0 && a == 0) {
			printf("Caso %d ", i);
			isTree(g) ? printf("es") : printf("no es");
			printf(" una arborescencia.\n");
			//printGraph(g);
			deleteGraph(g);
			g = createG();
			i++;
		}
		else
			break;
	}
	fclose(fp);
	deleteGraph(g);
	return 0;
}