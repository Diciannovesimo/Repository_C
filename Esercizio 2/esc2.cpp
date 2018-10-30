//LABORATORIO DI INFORMATICA - TRACK A -ITPS
//Docente: Fedelucio NARDUCCI
//Esercitazione 2 - 16/03/2018 (consegna entro: 19/3/2018)
//=====================
//Nome: william
//Cognome: colucci
//Matricola: 677793
//NOTA: La funzione Popolamento è disabilitata , la generazione della struct avviene nel main

//Librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
//Numero Degli account
#define MAX 3
//Valori massimi delle stringhe
#define x 50
//Valori per la generazione dell'anno di nascita
#define annoM 2010
#define annom 1950
//Struct contenente tutti i dati di ogni singolo individuo
struct account{
	char nome[x];
	char cognome[x];
	int giorno;
	int mese;
	int anno;
	char email[x];
	char password[x];
};

//Funzioni
//void Popolamento(int i,char temp[x],char temp2[x],struct account ac[MAX]);
char* Gen_Pass_Auto(int i,int k);
int Gen_Pass_Manuale(int count,char temp[x]);
//Funzione per generare Casualeicamento un numero
int Casuale(int max,int min);
//Array per la generazione di valori Random
const char *nomiP[10]={"Albano","Alfio","Beniamino","Berto","Calogero","Dalmazio","Emilio","Gabriele","William","Carlo"};
const char *cognomiP[10]={"Aiello","Alfano","Bellini","Boschi","Capone","Berlusconi","Cirillo","Tuono","Fiadone","Greco"};
const char *email[5]={"@gmail.com","@hotmail.com","@virgilio.it","@uniba.it","@libero.com"};
const char *numeri[10]={"1","2","3","4","5","6","7","8","9","0"};
const char *special[7]={"@","#","?","!","*","%","&"};

int main(void) {
  /*Dichiarazione variabili
   * count -> 			intero usato per calcolare la lunghezza di una stringa
   * temp , temp2 -> 	variabili temporanee per contenere stringhe
   */
  int i=0,k=0,count=0,s=0;
  char temp[x],temp2[x];
  struct account ac[MAX];

  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

  printf("Programma dell'università Benvenuto\n");
  printf("Generazione Account in corso...\n");

  int seed = time(NULL);
  srand(seed);
  //popolamento struct
  for(i=0;i<MAX;i++)
 	  {
 		  //nomi e cognomi
 		  strcpy(ac[i].nome,nomiP[Casuale(9,0)]);
 		  strcpy(ac[i].cognome,cognomiP[Casuale(9,0)]);
 		  //data
 		  ac[i].giorno=Casuale(30,1);
 		  ac[i].mese=Casuale(12,1);
 		  ac[i].anno=Casuale(annoM,annom);
 		  //email
 		  strcpy(temp2,email[Casuale(4,0)]);
 		  strcpy(temp, ac[i].nome);
 		  strcat(temp,ac[i].cognome);
 		  strcat(temp,temp2);
 		  strcpy(ac[i].email,temp);
 		  //svuoto le stringhe temporanee
 		  *temp='\0';
 		  *temp2='\0';
 	  }

  printf("-----------------------------------------\n");
  printf("Generazione account completata\n");
  printf("Generazione Password in corso...\n");

  //generazione password
  for(i=0;i<MAX;i++)
  	  {
	  	  printf("-----------------------------------------\n");
	  	  printf("Signor %s scelga come impostare la password\n",ac[i].nome);
	  	  printf("1. Automatico\n");
	  	  printf("2. Manualmente\n");
	  	  scanf("%d",&k);
	  	  printf("-----------------------------------------\n");
	  	  switch(k)
	  	  	  {
	  	  	  	  case 1:
	  	  	  		  //Automatico
	  	  	  		  do{
	  	  	  			  printf("Scegli il livello di sicurezza\n");
	  	  	  			  printf("1.poco-sicuro\n");
	  	  	  			  printf("2.medio-sicuro\n");
	  	  	  			  printf("3.molto-sicuro\n");
	  	  	  			  scanf("%d",&k);
	  	  	  			  printf("-----------------------------------------\n");

	  	  	  			  if((k>=1)&&(k<=3))
	  	  	  			  	  {
	  	  	  				  	  strcpy(ac[i].password,Gen_Pass_Auto(i,k));
	  	  	  				  	  k=0;
	  	  	  			  	  }
	  	  	  			  	  else
	  	  	  			  		  printf("Errore Scelta Sbagliata\n");

	  	  	  		  	  }while(k!=0);

	  	  	  		  break;

	  	  	  	  case 2:
	  	  	  		  //Manuale
	  	  	  		  do{
	  	  	  			  printf("-----------------------------------------\n");
	  	  	  			  printf("inserire la password\n");
	  	  	  			  scanf("%24s",temp);
	  	  	  			  count=strlen(temp);
	  	  	  			  s=Gen_Pass_Manuale(count,temp);

	  	  	  			  if(s==1)
	  	  	  				  printf("La password minore di 8 caratteri\n");
	  	  	  			  if(s==2)
	  	  	  				  printf("La password non ha almeno un numero\n");
	  	  	  			  if(s==3)
	  	  	  				  printf("La password non ha almeno una lettera maiuscola\n");

	  	  	  		  	  }while(s!=0);

	  	  	  		  break;

	  	  	  	  	  default:
	  	  	  	  		  printf("Errore scelta errata\n");
	  	  	  	  		  i-=1;
	  	  	  	  		  break;
	  	  	  }
  	  }
  printf("Generazione Password Completate\n");

  printf("Output in corso...\n");
  printf("-----------------------------------------\n");
  //output
  for(i=0;i<MAX;i++)
  	  {
	  	  printf("%s , %s\n data: %d/%d/%d\n email: %s\n",ac[i].nome,ac[i].cognome,ac[i].giorno,ac[i].mese,ac[i].anno,ac[i].email);
	  	  count=strlen(ac[i].password);
	  	  printf("password: %c****%c\n\n",ac[i].password[0],ac[i].password[count-1]);
  	  }

  return 0;
}

char* Gen_Pass_Auto(int i,int k)
{
	int j=0;
	static char str[x];
	//Scelta generazione automatica
	if(k==1)
		for(j=0;j<3;j++)
			strcat(str,numeri[Casuale(9,0)]);
	else
		if(k==2)
			for(j=0;j<6;j++)
				strcat(str,numeri[Casuale(9,0)]);
		else
			if(k==3)
				for(j=0;j<8;j++)
					{
						strcat(str,numeri[Casuale(9,0)]);
						strcat(str,special[Casuale(6,0)]);
					}
	return str;
}

int Gen_Pass_Manuale(int count,char temp[x])
{
	int s=0,j=0,upper=0,digit=0;
	//Generazione manuale della password
	s=0;
	upper=0;
	digit=0;
	/*controllo se ci sono almeno 8 caratteri e se
	 * ci sono almeno 1 numero e 1 maiuscola
	*/
	for(j=0;j<count;j++)
		{
			upper+=isupper(temp[j]);
			digit+=isdigit(temp[j]);
		}

	if(upper>=1)
		if(digit>=1)
			if(count>=8)
				s=0;	//password corretta
			else
				s=1;	//password minore di 8 caratteri
		else
			s=2;		//non ha almeno un numero
	else
		s=3;			//non ha almeno una lettera maiuscola

	return s;
}

int Casuale(int max,int min)
{
	int n=0;
	n= rand()% (max-min+1) +min;
	return n;
}

/*
void Popolamento(int i,char temp[x],char temp2[x],struct account ac[MAX])
{
	 for(i=0;i<MAX;i++)
	 	 {
		  	  //nomi e cognomi
		  	  strcpy(ac[i].nome,nomiP[Casuale(9,0)]);
		  	  strcpy(ac[i].cognome,cognomiP[Casuale(9,0)]);
		  	  //data
		  	  ac[i].giorno=Casuale(30,1);
		  	  ac[i].mese=Casuale(12,1);
		  	  ac[i].anno=Casuale(annoM,annom);
		  	  //email

		  	  strcpy(temp2,email[Casuale(4,0)]);
		  	  strcpy(temp, ac[i].nome);
		  	  strcat(temp,ac[i].cognome);
		  	  strcat(temp,temp2);
		  	  strcpy(ac[i].email,temp);
		  	  //svuoto le stringhe temporanee
		  	  *temp='\0';
		  	  *temp2='\0';
	 	 }
}
*/
