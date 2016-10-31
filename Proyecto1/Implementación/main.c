

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * const argv[]) {
	FILE* fp;
	char file[64];
	int n,c,size,obj,b;
	int x,y,imp,r;  	// coordenadas, importancia y radio 

	char pt='n';
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
    strcpy(file,argv[optind]);  // borrar
    fscanf(fp, "%d %d", &size,&obj);
	int objarr[size][4];
	for (int i = 0; i < obj; ++i) {
		fscanf(fp, "%d %d %d", &x,&y,&imp);
		objarr[i][0] = x;
		objarr[i][1] = y;
		objarr[i][2] = imp;
		if (objarr[i][2]>0)	
			objarr[i][3] = 1;	
		
		else
			objarr[i][3] = -1;
	}
	for (int i = 0; i < obj ; ++i) {
		printf("i: %d \n  x: %d, y: %d, imp: %d friendly: %d \n",i,objarr[i][0],objarr[i][1],objarr[i][2],objarr[i][3] );
	}
	fscanf(fp, "%d", &b);
	int bombs[b][4];

	for (int i = 0; i < b; ++i) {
		fscanf(fp, "%d %d %d %d", &x,&y,&r,&imp);
		bombs[i][0] = x;
		bombs[i][1] = y;
		bombs[i][2] = r;
		bombs[i][3] = imp;
	}

	printf("---- BOMBAS -------\n");

	for (int i = 0; i < b ; ++i) {
		printf("i: %d \n  x: %d, y: %d, r: %d p: %d \n",i,bombs[i][0],bombs[i][1],bombs[i][2],bombs[i][3] );
	}

	fclose(fp);
    printf("n: %d, pt : %c, file: %s \n",n,pt,file);  //borrar
    printf("size: %d obj: %d \n", size, obj);
	return 0;
}