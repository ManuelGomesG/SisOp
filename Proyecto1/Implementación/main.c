

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "bombs.h"


int main(int argc, char * const argv[]) {
	FILE* fp;
	int n,c,size,obj,b;
	int x,y,imp,r;  	// coordenadas, importancia y radio 

	char pt='j';
	n = 0;
	while ((c = getopt(argc, argv, "n:pt")) != -1) {
        switch(c) {
        case 'p':
        	pt = 'p';
        	break;
        case 't':
        	pt = 't';
        	break;
        case 'n':
        	if (atoi(optarg)<0) {
        		n=0;
        	}
            n = atoi(optarg);
            break;
            case ':':       
                    fprintf(stderr,
                            "La opción -%c necesita un argumento\n", optopt);
                    break;
        case '?':
                    fprintf(stderr,
                            "Opción no reconocida: -%c\n", optopt);
        }
    }
    fp = fopen(argv[optind],"r");
    fscanf(fp, "%d %d", &size,&obj);
	int objarr[size][5];
	for (int i = 0; i < obj; ++i) {
		fscanf(fp, "%d %d %d", &x,&y,&imp);
		objarr[i][0] = x;
		objarr[i][1] = y;
		objarr[i][2] = imp;
		objarr[i][4] = 0;
		if (objarr[i][2]>0)	
			objarr[i][3] = 1;	// Allies
		
		else
			objarr[i][3] = -1;	// Enemies
	}
	/*
	for (int i = 0; i < obj ; ++i) {
		printf("i: %d \n  x: %d, y: %d, imp: %d friendly: %d \n",i,objarr[i][0],objarr[i][1],objarr[i][2],objarr[i][3] );
	}*/
	fscanf(fp, "%d", &b);
	int bombs[b][4];

	for (int i = 0; i < b; ++i) {
		fscanf(fp, "%d %d %d %d", &x,&y,&r,&imp);
		bombs[i][0] = x;
		bombs[i][1] = y;
		bombs[i][2] = r;
		bombs[i][3] = imp;
	}
	fclose(fp);
/*
	printf("---- BOMBAS -------\n");

	for (int i = 0; i < b ; ++i) {
		printf("i: %d \n  x: %d, y: %d, r: %d p: %d \n",i,bombs[i][0],bombs[i][1],bombs[i][2],bombs[i][3] );
	}

	printf("---- LANZAMIENTOS -------\n");*/




	if (pt == 'j' || n==0) {
		for (int i = 0; i < b; ++i) {
			launch( objarr, bombs, i, obj);
		}
	}

	else if (pt == 't') {
		printf("entro en threads\n");

		pthread_t threads[n];
        int rc, t;
        int *tid[n];

        int bpt  = b/n,
       	    macc = b%n,
       	    adv	 = 0;
        for (t=0; t < n; t++) {
           tid[t] = (int *)malloc(sizeof(int));
           *tid[t]  = t;

           printf("Creando el Hilo %d\n",t);
           if (macc == 0 ) {
           rc = pthread_create(&threads[t],NULL,launchR(objarr,bombs,adv,obj,bpt), (void *)tid[t]);
           printf("\n Cree el Hilo THID: %d \n",*(tid[t]));
           if (rc) {
              printf("Error, %d\n",rc);
              exit(-1);
     		}
     		adv=adv+bpt;
           }
           if (macc > 0 ) {
           rc = pthread_create(&threads[t],NULL,launchR(objarr,bombs,adv,obj,bpt+1), (void *)tid[t]);
           printf("\n Cree el Hilo THID: %d \n",*(tid[t]));
           if (rc) {
              printf("Error, %d\n",rc);
              exit(-1);
     		}
     		adv=adv+bpt+1;
           }
           macc--;
  		}

	  	for (t=0; t < n; t++) {
	    	pthread_join(threads[t],NULL);
	  	}



	}

	else if (pt == 't')
	{
		printf("entro en procesos");
	}

/*
	for (int i = 0; i < obj ; ++i) {
		printf("i: %d \n  x: %d, y: %d, imp: %d friendly: %d \n",i,objarr[i][0],objarr[i][1],objarr[i][2],objarr[i][3] );
	}
	//printf("---- REPORT -------\n");*/

	report(objarr,obj);
	return 0;
}