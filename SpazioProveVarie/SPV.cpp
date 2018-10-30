/*
 * SPV.cpp
 *
 *  Created on: 21 mar 2018
 *      Author: William
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char* createStr();

int main()
{
	int k=0,i=0,scelta=0,MAX=0,MIN=0;
	char W[6];

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("inserisci quante volte vuoi ciclare\n");
	scanf("%d",&scelta);
	printf("inserisci il MAX\n");
	scanf("%d",&MAX);
	printf("inserisci il MIN\n");
	scanf("%d",&MIN);

	int seed = time(NULL);
	srand(seed);

	for(i=0;i<scelta;i++)
	{
		k= rand()% (MAX-MIN+1) +MIN;
		printf("il numero %d° randomico è : %d\n",i+1,k);
	}

	strcpy(W,createStr());

	printf("Funzione :%s\n",W);
	printf("FINE\n");
	return 0;
}

char* createStr() {
	static char str[20] = "my";
	return str;
}
