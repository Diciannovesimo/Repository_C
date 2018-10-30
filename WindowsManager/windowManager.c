#include "windowManager.h"

/*
	Funzioni ---------------------------------------------------------------------------------------------------------------
*/

/*
	Inizializza la finestra, da chiamare prima del settaggio di tutti i parametri della struct stessa

	win :		puntatore della struct di tipo WINDOW da inizializzare
	w_title : 	titolo da assegnare alla finestra
	h:			altezza della finestra, espressa in numero di caratteri
	w:			larghezza della finestra, espressa in numero di caratteri
*/

void initializeWindow(WINDOW *win, char *w_title, int h, int w)
{

	win->height = h;							  	// Imposta l'altezza della finestra
	win->width = w;									// Imposta la larghezza

	strcpy(win->title, w_title);					// Assegna il titolo alla finestra

	/* Imposta la grandezza della matrice del contenuto della finestra come:
													   righe = altezza - i due caratteri di bordo finestra
													   colonne = larghezza - 9 caratteri di cui :	- 2 di bordo finestra
													 												- 7 di tab
	*/
	win->content[h-(LARGHEZZA_BORDO*2)][w - MIN_WIDTH];

}

/*
	Stampa l'intera finestra

	win :	puntatore della struct di tipo WINDOW.
			NOTA: la struct deve essere pre-settata
*/

void printWindow(WINDOW *win)
{

	printTopWindow(win->width, win->title);			// Stampa la parte superiore della finestra

	int i;
	for(i = 0; i < win->height; i++)				// Stampa tutto il contenuto della finestra, riga per riga
		printWindowLine(win->width, win->content[i]);

	printBottomWindow(win->width);					// Stampa il bordo inferiore della finestra
}

/*
	Stampa la parte superiore della finestra

	width :		lunghezza della finestra (in caratteri)
	title :		puntatore della stringa contenente il titolo della finestra da stampare
				NOTA : Passare la stringa tramite variabile per evitare problemi.
*/

void printTopWindow(int width, char *title)
{

	int titleLenght = strlen(title);				// Calcolo lunghezza del titolo

	/*
		Parameters check <---
	*/

	/*
		In caso di lunghezza minore al minimo consentito, essa verrà considerata uguale al minimo stesso.
	*/
	if(width < MIN_WIDTH)
		width = MIN_WIDTH;

	/*
		In caso di larghezza bassa, se il titolo dovesse superare il minimo consentito, esso verrà troncato.
	*/
	if((MIN_WIDTH + titleLenght) > width)
	{
		title[width - MIN_WIDTH] = 0;				// Assegna terminatore di stringa
		titleLenght = strlen(title);				// Ricalcola la lunghezza della sottostringa ottenuta
	}

	/*
		Body <---
	*/

	printf("%c", 201);								// Stampa carattere di apertura alta-sinistra della finestra

	int semiLenght;									// Meta' del numero di caratteri 'linea' della finestra da stampare

	semiLenght = ((width - titleLenght) / 2) -
				LARGHEZZA_BORDO - 1;				// Calcolo della meta' del numero di caratteri da stampare
													// (Viene sottratto 2 per escludere i caratteri di angolo dell finestra
													// e di spazio prima del titolo da entrambe le metà)

	char firstBorder[semiLenght];					// Stringa che conterrà la prima metà del bordo superiore della finestra

	int i;
	for(i = 0; i < semiLenght; i++)					// Assegnazione del contenuto della stringa
		firstBorder[i] = 205;

	printf("%s %s ",firstBorder, title);			// Stampa della prima meta' del bordo superiore della finestra,
													// del titolo, e dei due spazi che circondano quest'ultimo.

	/*
		Correzione lunghezza finestra in caso di lunghezza del titolo o della finestra dispari
		(Poichè calcolando la lunghezza di metà finestra, in caso di numeri dispari si ottiene un arrotondamento)
	*/
	if(titleLenght % 2 != 0 && width % 2 == 0 || titleLenght % 2 == 0 && width % 2 != 0)
		semiLenght += 1;

	char lastBorder[semiLenght];					// Stringa che conterrà la 2a metà del bordo superiore della finestra

	for(i = 0; i < semiLenght; i++)					// Assegnazione del contenuto della stringa
		lastBorder[i] = 205;

	lastBorder[semiLenght] = 0;						// Assegnazione terminatore di stringa

	printf("%s%c\n", lastBorder, 187);				// Stampa della seconda metà del bordo superiore della finestra
													// e del carattere di chiusura di finestra ad angolo.
}

/*
	Stampa una riga della finestra

	width :		Lunghezza della riga (in caratteri)
	string:		Puntatore della stringa con iil contenuto da stampare
				NOTA : Passare la stringa tramite variabile per evitare problemi.
*/
void printWindowLine(int width, char *string)
{
	/*
		Parameters check <---
	*/

	/*
		In caso di lunghezza minore al minimo consentito, essa verrà considerata uguale al minimo stesso.
	*/
	if(width < MIN_WIDTH)
		width = MIN_WIDTH;

	/*
		In caso di larghezza bassa, se la stringa dovesse superare il minimo consentito, essa verrà troncata.
	*/
	if((width - MIN_WIDTH) < strlen(string))
	{
		string[width - MIN_WIDTH] = 0;				// Assegna il terminatore di stringa
	}

	/*
		Body <---
	*/

	int nCharsToPrint;								// Numero di caratteri da stampare ancora

	printf("%c\t", 186);							// Stampa il margine di finestra iniziale della riga e
													// lascia un margine di spazio (alias tab) pari a 7 spazi.

	printf("%s", string);							// Stampa il contenuto desiderato

	nCharsToPrint = width - (strlen(string) +
							MIN_WIDTH);				// Calcola il numero di caratteri rimanenti da stampare per la fine
													// della riga, sottraendo alla lunghezza della finestra, la lunghezza
													// della stringa stampata + (la lunghezza totale dei margini di finestra
													// + il numero di caratteri del tab (totale : 9))

	if(nCharsToPrint > 0)							// Se ci sono caratteri da stampare
	{
		char emptyString[nCharsToPrint-1];			// Variabile contenente il resto della stringa da stampare

		int i;
		for(i = 0; i < nCharsToPrint; i++)
			emptyString[i] = 32;					// Assegna il carattere spazio (' ')

		emptyString[nCharsToPrint] = 0;				// Aggiunge alla fine il terminatore di stringa (0 ascii)

		printf("%s", emptyString);					// Stampa la stringa restante
	}

	printf("%c\n", 186);							// Stampa il margine di finestra finale della riga
}

/*
	Stampa la parte inferiore della finestra

	width :		lunghezza della finestra (in caratteri)
*/

void printBottomWindow(int width)
{
	/*
		Parameters check <---
	*/

	/*
		In caso di lunghezza minore al minimo consentito, essa verrà considerata uguale al minimo stesso.
	*/
	if(width < MIN_WIDTH)
		width = MIN_WIDTH;

	/*
		Body <---
	*/

	width -= LARGHEZZA_BORDO*2;						// Sottrazione dei caratteri di chiusura della finestra nel conteggio

	printf("%c", 200);								// Stampa carattere di chiusura bassa-sinistra della finestra

	char border[width];								// Variabile contenente il bordo inferiore della finestra da stampare

	int i;
	for(i = 0; i < width; i++)						// Stampa dei caratteri del bordo inferiore della finestra
		border[i] = 205;

	printf("%s%c\n", border, 188);					// Stampa stringa e carattere di chiusura bassa-destra della finestra
}
