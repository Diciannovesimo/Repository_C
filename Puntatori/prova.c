/*
 * puntatori.cpp
 *
 *  Created on: 11 apr 2018
 *      Author: William
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define maxauto 5
#define maxMinuto 90000
#define minMinuto 80000

void conversione(int* x , int* y , int* z);

int main(){
	int i=0;
	int tempofissato=1;
	int millisecondi=0;
	int minuti=0;
	int secondi=0;
	int array[5];

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Formula 1\n");

	int seed = time(NULL);
	srand(seed);

	for(i=0;i<maxauto;i++)
	{
		millisecondi=rand()% (maxMinuto-minMinuto+1)+minMinuto;
		conversione(&minuti,&secondi,&millisecondi);
		printf("Tempo %d macchina:%d' %d'' %d\n",i+1,minuti,secondi,millisecondi);
	}



	return 0;
}

void conversione(int* x , int* y , int* z)
{
	*x=*z/60000;
	*y=(*z%60000)/1000;
	*z=(*z%60000)%1000;
}
