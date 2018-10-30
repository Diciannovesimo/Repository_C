#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX 30
#define Utenti 3
#define Film 10
#define annoM 2010
#define annom 1950
#define PMAX 500

struct film{
	char titolo[MAX];
	int anno;
	int durata_in_minuti;
};

struct utente{
	char nome[MAX];
	char cognome[MAX];
	int giorno;
	int mese;
	int anno;
	char password[MAX];
};

struct preferenze{
	char idnome[MAX];
	char idtitolo[MAX];
	int preferenza;
};

struct utente utenti[Utenti];
struct film archivio_film[Film];
struct preferenze Pref[PMAX];

const char *nomiP[MAX]={"Luigi","Donato","Sabino","Stefano","Claudio","Martina","Simona","Claudia","Colette","Daniela","Franco","Albano","Alfio","Beniamino","Berto","Calogeno","Dalmazio","Emilio","Gabriele","William","Carlo","Durante","Elma","Emma","Alessia","Asia","Lorenzo","Amos","Ulisse","Fabiana"};
const char *cognP[MAX]={"Abate","Lorusso","Carone","Capurro","Rossi","Crozza","Leone","Razzi","Desmo","Aresta","Aiello","Alfano","Bellini","Boschi","Capone","Berlusconi","Cirillo","Tuono","Fiadone","Greco","Russo","Ferrari","Lamborghini","Esposito","Ricci","Marino","Bruno","Conti","Gallo","Mancini"};
const char *numeri[10]={"1","2","3","4","5","6","7","8","9","0"};
const char *special[7]={"@","#","?","!","*","%","&"};

void Popolamento()
{
	int i=0;
	for(i=0;i<MAX;i++)
	{
		//nomi e cognomi
		strcpy(utenti[i].nome,nomiP[rand()% (29-0+1)+0]);
		strcpy(utenti[i].cognome,cognP[rand()% (29-0+1)+0]);
		//data
		utenti[i].giorno=rand()% (30-1+1)+1;
		utenti[i].mese=rand()% (12-1+1)+1;
		utenti[i].anno=rand()% (annoM-annom+1)+annom;
	}
}

void Output()
{
	int i=0;
	for(i=0;i<Utenti;i++)
	{
		printf("nome e cognome: %s , %s\nPassword: %s\nData di nascita: %d/%d/%d\n",utenti[i].nome,utenti[i].cognome,utenti[i].password,utenti[i].giorno,utenti[i].mese,utenti[i].anno);
	}
	printf("-------------------------------------------\n");
	for(i=0;i<Film;i++)
	{
		printf("Titolo: %s\nAnno: %d\nDurata: %d min\n",archivio_film[i].titolo,archivio_film[i].anno,archivio_film[i].durata_in_minuti);
	}
	printf("-------------------------------------------\n");

}

void RicercaFilm(char nomefilm[MAX])
{
	int i=0;
	for(i=0;i<Film;i++)
	{
		if(strcmp(nomefilm,archivio_film[i].titolo)==0)
		{

		}
	}
}
int ModificaPreferenza(char nomeutente[MAX], char nomefilm[MAX],int N[PMAX], int F[PMAX])
{
	int i=0,j=0,k=0,n=0,f=0;
	//CONTROLLO
	for(i=0;i<Utenti;i++)
	{
		for(j=0;j<Film;j++)
		{
			if(strcmp(nomeutente,utenti[i].nome)==0 && strcmp(nomefilm,archivio_film[j].titolo)==0)
			{
				k=2;
				n=i;
				f=j;
			}
			else
				k=3;
		}
		if(k==2)
			break;
	}

	if(k==2)
	{
		for(i=0;i<PMAX;i++)
		{
			if(N[i]==n && F[i]==f)
				{
					if(Pref[i].preferenza==1)
					{
						k=0;
						Pref[i].preferenza=k;
					}
					else
					{
						k=1;
						Pref[i].preferenza=k;
					}
					break;
				}
			else
				k=4;
			}
	}

	return k;
}
int Controllo(char nomeutente[MAX], char nomefilm[MAX])
{
	int i=0,j=0,k=0;
	//CONTROLLO
	for(i=0;i<Utenti;i++)
	{
		for(j=0;j<Film;j++)
		{
			if(strcmp(nomeutente,utenti[i].nome)==0 && strcmp(nomefilm,archivio_film[j].titolo)==0)
			{
				k=2;
				break;
			}
			else
				k=3;
		}
		if(k==2)
			break;
	}
	return k;
}
int NuovePreferenze(int N[PMAX], int F[PMAX], char nomeutente[MAX], char nomefilm[MAX])
{
	int i=0,k=0;
	//AGGIUNTA
		for(i=0;i<PMAX;i++)
			{
				if(N[i]==0 && F[i]==0)
				{
					k=rand()% (1-0+1)+0;
					break;
				}
				else
				{
					k=4;
				}
			}

	return k;
}

void Preferenze(int N[PMAX], int F[PMAX])
{
	int i=0,f=0,n=0,j=0,k=0;

	do{

		n=rand()% (49-0+1)+0;
		f=rand()% (9-0+1)+0;

		for(j=0;j<=100;j++)
		{
			if((n==N[j]) && (f==F[j]))
			{
				k=1;
				break;
			}
		}

		if(k!=1)
		{
			Pref[i].preferenza=rand()% (1-0+1)+0;
			N[i]=n;
			F[i]=f;
			i++;
		}

		k=0;

	}while(i!=100);



}
char* Gen_Pass_Auto(int i,int k)
{
	int j=0;
	static char str[MAX];
	*str='\0';
	//Scelta generazione automatica
	if(k==1)
		for(j=0;j<3;j++)
			strcat(str,numeri[rand()% (9-0+1)+0]);
	else
		if(k==2)
			for(j=0;j<6;j++)
				strcat(str,numeri[rand()% (9-0+1)+0]);
		else
			if(k==3)
				for(j=0;j<8;j++)
					{
						strcat(str,numeri[rand()% (9-0+1)+0]);
						strcat(str,special[rand()% (6-0+1)+0]);
					}
	return str;
}

/*int Casuale(int max,int min)
{
	int n=0;
	n= rand()% (max-min+1) +min;
	return n;
}


void CaricamentoFilm()
{
	int i=0;
	for(i=0;i<Film;i++)
	{
		strcpy(archivio_film[i].titolo,Titolo[i]);
		archivio_film[i].anno=Anno[i];
		archivio_film[i].durata_in_minuti=Durata[i];
	}
}
*/

