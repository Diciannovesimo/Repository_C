#include <stdio.h>
#include "libr.h"
int main()
{
	int k=0,a=0,b=0,c=0;

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	do
	{
		printf("-------------------------------\n");
		printf("Salve Prova librerie\n");
		printf("1.Somma due cifre\n");
		printf("2.Sottrai due cifre\n");
		printf("3. Prova la struct in libreria\n");
		scanf("%d",&k);
		switch(k)
			{
			case 1:
				printf("inserire primo numero\n");
				scanf("%d",&a);
				printf("inserire secondo numero\n");
				scanf("%d",&b);
				c=Somma(a,b);
				printf("La somma è: %d\n",c);
				break;
			case 2:
				printf("inserire primo numero\n");
				scanf("%d",&a);
				printf("inserire secondo numero\n");
				scanf("%d",&b);
				c=Differenza(a,b);
				printf("La Differenza è: %d\n",c);
				break;
			case 3:
				input();
				output();
				break;
			default:
				printf("Errore\n");
				break;
			}

	}while(k!=4);

return 0;
}
