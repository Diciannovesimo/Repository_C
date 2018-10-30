/*
	Strutture --------------------------------------------------------------------------------------------------------------
*/

int nOptions;									// Numero di opzioni del menu
int menIndex = 1;								// Indice di spostamento all'interno del menu
int input;										// Carattere ottenuto in input
int backFlag;									// 0 : Stato normale | 1 : è stato premuto il CANCEL_KEY

/*
	Constanti --------------------------------------------------------------------------------------------------------------
*/

#define UP_KEY 		72							// Codice del tasto di spostamento in alto nelle opzioni del menu(72: UP Arrow)
#define DOWN_KEY 	80							// Codice del tasto di spostamento in basso nel menu (80: Down Arrow)
#define CONFIRM_KEY 13							// Codice del tasto di accettazione del menu (13 : Invio)
#define CANCEL_KEY	27							// Codice del tasto di annullamento del menu (27 : Esc)

/*
	Prototipi --------------------------------------------------------------------------------------------------------------
*/

void startMenu(int n_options);					// Fa partire il ciclo di utilizzo del menu
void switchOptions();
void OnEnter();

/*
	Funzioni ---------------------------------------------------------------------------------------------------------------
*/

/*
	Fa partire il ciclo di utilizzo del menu'

	n_options : 	Numero di opzioni disponibili

	NOTA : IMPLEMENTARE NEL FILE.C LE FUNZIONI switchOptions() e onEnter(), per completare la gestione.
*/
void startMenu(int n_options)
{
	nOptions = n_options;
	menIndex = 1;
	backFlag = 0;
	while(!backFlag)
	{
		input = getch();
		switch(input)
		{
			case UP_KEY:
				if(menIndex > 1)
					menIndex--;
				switchOptions();
				break;
			case DOWN_KEY:
				if(menIndex < nOptions)
					menIndex++;
				switchOptions();
				break;
			case CONFIRM_KEY:
				onEnter();
				break;
			case CANCEL_KEY:
				backFlag = 1;
				break;
		}
	}
}
