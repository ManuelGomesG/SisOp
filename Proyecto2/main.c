
#include "listing.h"
#include <pthread.h>


int main(int argc, char  * const argv[]) {
	
  	char* directory = NULL;

    int children = 0;
    int c;

    /*int estado;
    int ocupados = -1;*/



    opterr = 0;
    while ((c = getopt (argc, argv, "hn:d:")) != -1) {
        switch (c) {
            case 'h':
                printf("UsoDisco [-h] | [-n i] [-d directorio] [salida]\n");
                printf("\n");
                printf("-h  Muestra esta información de uso.\n");
                printf("-n  Numero de procesos a usar.\n");
                printf("-d  Directorio al que se aplica el programa.\n");
                exit(0);
            case 'd':
                directory = optarg;
                break;
            case 'n':
                children = atoi(optarg);
                break;
            case '?':
                if (optopt == 'n')
                    fprintf (stderr, "Opción -%c requiere un argumento.\n", optopt);
                else if (optopt == 'd')
                    fprintf (stderr, "Opción -%c requiere un argumento.\n", optopt);
                else
                    fprintf (stderr, "Opción desconocida -%c.\n", optopt);
            default:
                exit(1);
        }
    }
 

    if (directory == NULL) 
        directory = ".";
    else 
        chdir(directory);

 

    dQhead* dq = createDQ();
    cAQueue* ca= createCAQ();
    addCAtoQ(ca,list(directory));
    dq = ca -> first -> toAdd;
 	while (isEmptyQ(dq) == 0) {
 		addCAtoQ(ca,list(dq -> first -> dir));
 		concatQs(dq,ca -> last -> toAdd);
 		popFromQ(dq);
 	}
 	if (argv[optind] == NULL) {
	 	while (!isEmptyCAQ(ca)) {
	 		printf("%d 		%s\n",  ca -> first -> size, ca -> first -> path);
	 		popFromCAQ(ca);
	 	}
 	}
 	else {
 		FILE* fp;
 		fp = fopen(argv[optind],"w");

 		while (!isEmptyCAQ(ca)) {
	 		fprintf(fp,"%d 		%s\n",  ca -> first -> size, ca -> first -> path);
	 		popFromCAQ(ca);
	 	}
 	}

	return 0;
}