#include <stdio.h>
#include "bombs.h"

void launch ( int obj[][5] , int bombs[][4] , int bomb, int objs ) {
	for (int i = 0; i < objs; ++i) {
		if ( obj[i][0] <= (bombs[bomb][0] + bombs[bomb][2]) && 
			obj[i][0] >= (bombs[bomb][0] - bombs[bomb][2]) &&
			obj[i][1] <= (bombs[bomb][1] + bombs[bomb][2]) && 
			obj[i][1] >= (bombs[bomb][1] - bombs[bomb][2])){

			if (obj[i][3] == 1) {
				obj[i][2] = obj[i][2] - bombs[bomb][2];
				obj[i][4] = 1;
			}

			else if (obj[i][3] == -1){
				obj[i][2] = obj[i][2] + bombs[bomb][2];
				obj[i][4] = 1;
			}
		}
	}
}

void report(int array[][5], int objs){
	int omtd  = 0,
	ompd = 0,
	omna = 0,
	octd = 0,
	ocpd = 0,
	ocna = 0;
	for (int i = 0; i < objs; ++i)
	{
		if (array[i][3] == 1 &&  array[i][4] == 0)
			ocna++;
		else if (array[i][3] == -1 &&  array[i][4] == 0)
			omna++;
		else if (array[i][3] == 1 &&  array[i][4] == 1 && array[i][2] > 0)
			ocpd++;
		else if (array[i][3] == -1 &&  array[i][4] == 1 && array[i][2] < 0)
			ompd++;
		else if (array[i][3] == 1 &&  array[i][4] == 1 && array[i][2] < 1)
			octd++;
		else if (array[i][3] == -1 &&  array[i][4] == 1 && array[i][2] > -1)
			omtd++;
	}
	printf("Objetivos Militares totalmente destruidos: %d\n", omtd);
	printf("Objetivos Militares parcialmente destruidos: %d\n", ompd);
	printf("Objetivos Militares no afectados: %d\n", omna);
	printf("Objetivos Civiles totalmente destruidos: %d\n", octd);
	printf("Objetivos Civiles parcialmente destruidos: %d\n", ocpd);
	printf("Objetivos Civiles no afectados: %d\n", ocna);
}

void *launchR(int obj[][5] , int bombs[][4] , int ibomb, int objs, int cant){
	for (int i = ibomb; i <= cant; ++i) {
		launch(obj,bombs,i,objs);
	}
}