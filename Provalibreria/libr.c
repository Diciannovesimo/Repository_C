#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define MAX 15
#define Ut  3

struct Dati{
	char nome[MAX];
	char cognome[MAX];
};

struct Dati d[MAX];

const char *nomiP[4]={"Luigi","Donato","Sabino"};
const char *cognomiP[4]={"Abate","Lorusso","Carone"};
const char *numeri[10]={"1","2","3","4","5","6","7","8","9","0"};
const char *special[7]={"@","#","?","!","*","%","&"};

int Casuale(int max,int min)
{
	int n=0;
	n= rand()% (max-min+1) +min;
	return n;
}

void input()
{
	int i=0;
	for(i=0;i<Ut;i++)
	{

		strcpy(d[i].nome,nomiP[Casuale(3,0)]);
		strcpy(d[i].cognome,cognomiP[Casuale(3,0)]);
	}
}

void output()
{
	int i=0;
	for(i=0;i<Ut;i++)
	printf("nome: %s\ncognome: %s\n",d[i].nome,d[i].cognome);
}

int Somma(int x, int y)
{
	return x+y;
}

int Differenza(int x, int y)
{
	return x-y;
}
