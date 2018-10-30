/*
	Strutture -------------------------------------------------------------------------------------------------------------
*/

/*
	Struttura Finestra
*/

typedef struct
{

	int  width,									// Larghezza della finestra
		 height;								// Altezza della finestra

	char title[20];								// Titolo della finestra
	char content[10][20];						// Vettore delle righe della finestra

} WINDOW;

/*
	Constanti --------------------------------------------------------------------------------------------------------------
*/

#define MARGINE_SINISTRO 7						// Spazio lasciato (in numero di caratteri) dal margine sinistro
#define LARGHEZZA_BORDO 1						// Lunghezza (in numero di caratteri) del bordo di finestra

// Minimo di larghezza della finestra
#define MIN_WIDTH ((LARGHEZZA_BORDO * 2) + MARGINE_SINISTRO)

/*
	Prototipi --------------------------------------------------------------------------------------------------------------
*/

void printTopWindow(int width, char* title);	// Stampa la parte superiore della finestra, con titolo e di lunghezza width
void printWindowLine(int width, char* string);	// Stampa una riga della finestra, di lunghezza width e contenuto string
void printBottomWindow(int width);				// Stampa la parte inferiore della finestra di lunghezza width

void initializeWindow(WINDOW *win, char *w_title,// Inizializza la finestra, da chiamare prima del settaggio di tutti i
					  int h, int w);			// parametri della struct stessa

void printWindow(WINDOW *win);					// Stampa l'intera finestra


