//LABORATORIO DI INFORMATICA - TRACK A -ITPS
//Docente: Fedelucio NARDUCCI
//Esercitazione 0 - 28/2/2018 (consegna entro: 2/3/2018)
//=====================
//Nome: William
//Cognome: Colucci
//Matricola: 677793

/*appunti
 *BMI=kg/(h*h) -> peso/(altezza*altezza)
 *int randomValue = rand() % (MAX-MIN+1) + MIN;
 *NOTA: l'altezza massima degli over e degli under 40 sembra essere
 *costantemente 2.00 ma dopo un paio di prove sebra essere solo una coincidenza
 *forse c'è qualcosa che mi sfugge nella generazione del numero random(questo problema non riguarda il peso)
*/

//librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NUM 5
//uso una struct (insieme di variabili che possono essere di diverso tipo) per memorizzare i valori richiesti in output
struct Dati{
  int eta;
  float altezza;
  float peso;
  float IBM;
};

//Dichiarazione della struct e della funzione programma
struct Dati dati[NUM];
void programma();
void Generazione(int i,struct Dati dati[NUM]);

int main(void) {
  char k[2];
  int x=0;
  //svuoto il buffer (necessario per avviare la console in eclipse)
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  //uso un do while e dentro una switch con scelta 1 o 2
  do
  {
	printf("-------------------------------------------\n");
    printf("Calcolatore di Body Mass Index\n");
    printf("Seleziona una scelta\n");
    printf("1.Esegui il programma\n");
    printf("2.Esci\n");
    scanf("%s",k);
    printf("-------------------------------------------\n");
    /*case 1 il main richiama la funzione programma()
     *case 2 il programma termina
     *case default riparte il menu
     */

    if(strcmp(k,"1")==0)
    {
    	x=1;
    printf("Condizione 1 verificata\n");
    }
    else
    {
    	if(strcmp(k,"2")==0)
    	    {
    	    	x=2;
    	    	printf("Condizione 2 verificata\n");
    	    }
    	    else
    	    {
    	    	x=3;
    	    	printf("Condizione 3 verificata\n");
    	    }
    }



    switch(x)
    {
      case 1: programma();
        break;
      case 2: printf("Programma terminato\n");
        break;
      default: printf("Errore, inserire un numero valido\n");
        break;
    }
  }while(x!=2);

  return 0;
}

void programma()
{
	/* h= altezza intera , p= peso intero,
	 * MAXh_over massima altezza over cosi come
	 * MAXh_under=0, MAXkg_over=0, MAXkg_under=0
	 * somma= somma di tutti gli IBM
	 * mediaIBM= media degli IBM
	 */
	int i=0,under=0,over=0;
	float MAXh_over=0, MAXh_under=0, MAXkg_over=0, MAXkg_under=0,mediaIBM=0,somma=0,MaxIBM=0;

	int seed = time(NULL);
	srand(seed);

	for(i=0;i<NUM;i++)
	{
		/*input (valori random)
		 * per l'altezza e il peso ho untilizzato questo stratagemma:
		 * dato che rand() % è un operazione che si può effettuare solo su interi,
		 * ho acquisito questi due dati come interi randomici per poi dividere il risultato per 10
		 * e quindi ottenere un float. Dato che è assurdo sostenere che l'altezza o il peso possano essere
		 * di tipo intero.
		 */

		Generazione(i,dati);

		//Massimo IBM
		if(MaxIBM<dati[i].IBM)
			MaxIBM=dati[i].IBM;

		//Selezione dei massimi degli under 40
		if(dati[i].eta<=40)
		{
			if(MAXh_under<dati[i].altezza)
				MAXh_under=dati[i].altezza;
			if(MAXkg_under<dati[i].peso)
				MAXkg_under=dati[i].peso;
			under++;
		}
		//Selezione dei massimi degli over 40
		else
		{
			if(MAXh_over<dati[i].altezza)
				MAXh_over=dati[i].altezza;
			if(MAXkg_over<dati[i].peso)
				MAXkg_over=dati[i].peso;
			over++;
		}
		//somma degli IBM
		somma+=dati[i].IBM;
	}
	//media IBM
	mediaIBM=somma/5;
	//output
	printf("-------------------------------------------\n");
	printf("Altezza massima Under 40: %f\n",MAXh_under);
	printf("Peso massimo Under 40: %f\n",MAXkg_under);
	printf("Altezza massima over 40: %f\n",MAXh_over);
	printf("Peso massimo over 40: %f\n",MAXkg_over);
	printf("Media IBM %f\n",mediaIBM);
	printf("Massimo IBM %f\n",MaxIBM);
	printf("il numero di over 40 è %d\n",over);
	printf("il numero di under 40 è %d\n",under);
}

void Generazione(int i,struct Dati dati[NUM])
{
	int h=0,p=0;
	dati[i].eta = rand() % (80-10+1) + 10;
	h = rand() % (20-16+1) + 16;
	dati[i].altezza=h/10;
	p = rand() % (1200-600+1) + 600;
	dati[i].peso=p/10;
	dati[i].IBM=dati[i].peso/(dati[i].altezza*dati[i].altezza);

	if(dati[i].IBM>25)
		printf("il %d° campione è mediamente in sovrappeso\n",i+1);
	else
		if(dati[i].IBM==25)
			printf("il %d° campione è mediamente in linea\n",i+1);
		else
			printf("il %d° campione è mediamente sottopeso\n",i+1);
}
