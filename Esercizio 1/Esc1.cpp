//LABORATORIO DI INFORMATICA - TRACK A -ITPS
//Docente: Fedelucio NARDUCCI
//Esercitazione 1 - 07/03/2018 (consegna entro: 10/3/2018)
//=====================
//Nome: William                    Gabriele
//Cognome: Colucci        &        D'Agnelli
//Matricola: 677793                676710

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Esami 20       //per conseguire la laurea, abbiamo presupposto che lo studente dovesse superare 20 esami
#define Studenti 10    // il numero di studenti che vogliamo indicizzare
#define MAX 31
#define MIN 1          // queste due costanti servono a definire il range dei voti assegnabili, da 1 a 31, corrispondente a 30 e lode

int main(void)
{
 //parte dichiarativa
 int voti[Studenti][Esami];   //questa è una matrice di 20 righe e 10 colonne, atta a memorizzare tutti i voti di tutti gli studenti
 int CFU[Esami];              //questo array serve a memorizzare quanti CFU si guadagnano per ogni esame
 int Superamento[Esami];      //questo array conter(r)à il numero di studenti che hanno superato un certo esame
 int moda[MAX];               //questo array conter(r)à qual'è il voto preso più volte da uno studente
 int i=0,j=0,k=0,max=0;
 int somma=0,TotCFU=0,sommaponderata=0;
 float media=0,mediaPonderata=0,Percentuale=0;

 setvbuf(stdout, NULL, _IONBF, 0);
 setvbuf(stderr, NULL, _IONBF, 0);

 printf("Programma dell'università\n");

 int seed = time(NULL);
 srand(seed);

 //il seguente ciclo serve al popolamento della matrice mediante numeri randomici (i voti)

 for(i=0;i<Studenti;i++)
   for(j=0;j<Esami;j++)
    voti[i][j] = rand() % (MAX-MIN+1) + MIN;

 printf("Calcolo dei dati terminato\n");

 //il seguente ciclo serve al popolamento dell'array CFU (indcante i CFU corrispondenti ad ogni esame)
 //con valori randomici ma vincolati a tre soli valori (6-9-12)
 //abbiamo tralasciato la regola che indica come CFU necessari ad una laurea triennale, 180
 //quindi la somma di questi valori sarà ogni volta un numero diverso
 //sommare i valori contenuti nell'array è comunque necessario per il calcolo della media ponderata

 for(j=0;j<Esami;j++)
  {
   CFU[j]=rand() % (4-2+1) +2;
   CFU[j]*=3;
   TotCFU+=CFU[j];
  }


 //i seguenti cicli innestati servono a scorrere la matrice in orizzontale
 for(i=0;i<Studenti;i++)
 {

  max=0;
  sommaponderata=0;            //queste tre variabili necessitano di azzeramento ad ogni iterazione
  somma=0;


  for(j=0;j<Esami;j++)
  {
   somma += voti[i][j];                             // l'accumulatore somma conterrà la somma delle valutazioni conseguite da uno studente
   sommaponderata+=(voti[i][j]*CFU[j]);             //sommaponderata conterrà la somma dei prodotti tra valutazione e CFU corrispondenti

   moda[voti[i][j]-1]++;                             //gli elementi dell'array moda sono tanti contatori: il valore della matrice
               //voti[][] (diminuito di 1) diventa l'indice dell'array moda.
               //Per esempio, quando il voto è 26, il valore 25 diventa indice dell'array moda
               //e l'elemento in posizione 25 viene incrementato di 1
  }

  for(k=0;k<MAX-1;k++)     //questo ciclo procede fino al penultimo elemento
  {
   if(moda[k]>moda[k+1])              //confrontiamo ogni elemento con il successivo
     max=k+1;
  }

  for(k=0;k<MAX;k++)
   moda[k]=0;                      //dopo aver calcolato la moda di uno studente riazzeriamo l'array, per far spazio ai voti dello studente successivo

  //le due divisioni per il calcolo di media e media ponderata: i entrambi i casi abbiamo incluso nel computo generale
  // anche le valutazioni negative, e per la media ponderata, i CFU degli esami non superati, in quanto, anche se non
  //effettivamente guadagnati dallo studente, debbono essere inclusi nel calcolo
  //generando altresì i voti randomicamente, abbiamo dato per scontato che tutti gli studenti abbiano sostenuto tutti gli esami, indipendemente dall'esito

  media=somma/Esami;
  mediaPonderata=sommaponderata/TotCFU;

  //le stampe dei valori richiesti
  printf("%d° studente:\n", i+1);
  printf("Media: %f\n",media);
  printf("Media ponderata : %f\n",mediaPonderata);
  printf("Moda : %d\n",max);
  printf("\n");

   }



   //nei seguenti cicli innestati, la matrice scorre in verticale, cioè per esame e non per studente
   //l'array Superamento[] conta quanti studenti hanno determinato
   for(j=0;j<Esami;j++)
    {
     for(i=0;i<Studenti;i++)
      {
       if(voti[i][j]>=18)
        Superamento[j]++;

      }

       Percentuale=Superamento[j]*100/Studenti;
       printf("Percentuale degli studenti che hanno superato l'esame %d : %f\n",j+1,Percentuale);

    }

   return 0;
  }
