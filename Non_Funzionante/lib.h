/*
 * lib.h
 *
 *  Created on: 06 apr 2018
 *      Author: William
 */


#define MAX 30
#define Utenti 3
#define Film 10
#define annoM 2010
#define annom 1950
#define PMAX 500
#ifndef LIB_H_
#define LIB_H_
#include "lib.c"


void Popolamento();
char* Gen_Pass_Auto(int i,int k);
int Casuale(int max,int min);
void CaricamentoFilm();
void Preferenze(int N[PMAX], int F[PMAX]);
int NuovePreferenze(int N[PMAX], int F[PMAX], char nomeutente[MAX], char nomefilm[MAX]);
int Controllo(char nomeutente[MAX], char nomefilm[MAX]);
int ModificaPreferenza(char nomeutente[MAX], char nomefilm[MAX],int N[PMAX], int F[PMAX]);
void RicercaFilm(char nomefilm[MAX]);
void Output();


#endif /* LIB_H_ */
