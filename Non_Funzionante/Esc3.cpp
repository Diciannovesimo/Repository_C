//LABORATORIO DI INFORMATICA - TRACK A -ITPS
//Docente: Fedelucio NARDUCCI
//Esercitazione 3 - 04/04/2018 (consegna entro: 05/04/2018 - ore 18.00)
//=====================
//Nome:
//Cognome:
//Matricola:


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
#define MAX 30
#define Utenti 3
#define Film 10
#define annoM 2010
#define annom 1950
#define PMAX 500



//Funzioni e procedure

//Costanti Film
const char *Titolo[Film]={"Il_Padrino","Lo_Squalo","Chinatown","Casablanca","Blade_Runner","Via_Col_Vento","Alien","Psyco","Sangue_Blu","Matrix"};
const int Anno[Film]={1972,1975,1974,1942,1982,1939,1979,1960,1949,1999};
const int Durata[Film]={120,175,130,200,210,110,135,110,160,140};



int main(){
	int k=0,i=0,x=0,l=0;
	char a[2],nomeutente[MAX],nomefilm[MAX];
	//int Matrice_Pref[PMAX][PMAX];
	int N[PMAX];
	int F[PMAX];

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//OPERAZIONI SU UTENTE

	//popolamento struct
	Popolamento();

	//Generazione password
	for(i=0;i<Utenti;i++)
	{
		printf("Signor %s scelga il livello di complessità della password\n",utenti[i].nome);
		printf("1.poco-sicuro\n");
		printf("2.medio-sicuro\n");
		printf("3.molto-sicuro\n");
		scanf("%d",&k);
		printf("-----------------------------------------\n");

		if((k>=1)&&(k<=3))
		{
			strcpy(utenti[i].password,Gen_Pass_Auto(i,k));
			k=0;
		}
		else
			printf("Errore Scelta Sbagliata\n");

	}

	//FINE OPERAZIONI SU UTENTE

	//OPERAZIONI SU FILM
	//CaricamentoFilm();
	//FINE OPERAZIONI SU FILM

	//PREFERENZE
	Preferenze(N,F);

	//MENUOutput
	Output();
	do
	  {
		printf("-------------------------------------------\n");
	    printf("Seleziona una scelta\n");
	    printf("1.Inserimento nuove preferenze\n");
	    printf("2.Modifica Preferenze\n");
	    printf("3.Visualizza utente che ha espresso piu' like\n");
	    printf("4.Visualizza i tre film piu' graditi\n");
	    printf("5.Ricerca Film per nome\n");
	    printf("6.Visualizza tabella\n");
	    printf("7.Esci");
	    scanf("%s",a);
	    printf("-------------------------------------------\n");

	    if((strcmp(a,"1")==0)||(strcmp(a,"2")==0)||(strcmp(a,"3")==0)||(strcmp(a,"4")==0)||(strcmp(a,"5")==0)||(strcmp(a,"6")==0)||(strcmp(a,"7")==0))
	    {
	    	x=atoi(a);
	    	printf("Condizione verificata\n");
	    }
	    else
	    {
	    	x=8;
	    }

	    switch(x)
	    {
	      case 1:
	    	  printf("Inserisci nuova preferenza:\n");
	    	  printf("Inserisci nome utente:\n");
	    	  scanf("%s",nomeutente);
	    	  printf("Inserisci il nome del film\n");
	    	  scanf("%s",nomefilm);

	    	  l=Controllo(nomeutente,nomefilm);
	    	  if(l==3)
	    		  printf("Errore il nome utente o il nome del film non esistono\n");
	    	  if(l==2)
	    	  l=NuovePreferenze(N,F,nomeutente,nomefilm);
	    	  if(l==4)
	    		  printf("Errore la preferenza è stata gia espressa\n");
	    	  if(l==1 || l==0)
	    		  for(i=0;i<PMAX;i++)
	    			  if(Pref[i].preferenza==0)
	    			  {
	    				  Pref[i].preferenza=l;
	    				  break;
	    			  }
	      	  break;
	      case 2:
	    	  printf("Inserisci nuova preferenza:\n");
	    	  printf("Inserisci nome utente:\n");
	    	  scanf("%s",nomeutente);
	    	  printf("Inserisci il nome del film\n");
	    	  scanf("%s",nomefilm);

	    	  l=ModificaPreferenza(nomeutente,nomefilm,N,F);
	    	  if(l==3)
	    		  printf("Errore il nome utente o il nome del film non esistono\n");
	    	  if(l==4)
	    		  printf("Errore la preferenza non è stata espressa pertanto non puo' essere modificata\n");

	      	  break;
	      case 3:
	    	  break;
	      case 4:
	    	  break;
	      case 5:
	    	  printf("inserisci nome film\n");
	    	  scanf("%s",nomefilm);
	    	  RicercaFilm(nomefilm);
	    	  break;
	      case 6:
	    	  Output();
	    	  break;
	      case 7:
	    	  printf("Chiusura del programma\n");
	    	  break;
	      default: printf("Errore, inserire un numero valido\n");
	        break;
	    }

	  }while(x!=7);

  return 0;
}
//INIZIO FUNZIONI
