#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* generaPassword(char* nome, char* cognome);
char* offuscapassword(char* password);

int main(void) {

  char nome[10];
  char cognome[10];
  char* password;

  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

 printf("inserisci nome\n");
 scanf("%s",nome);
 printf("inserisci cognome\n");
 scanf("%s",cognome);

 printf("generazione password in corso...\n");

 password=generaPassword(nome,cognome);

 printf("stampa password %s\n",password);

 password=offuscapassword(password);

 printf("stampa password offuscata %s\n",password);
  return 0;
}

char* generaPassword(char* nome, char* cognome)
{
    int i=0,k=0;
    char simboli[2]={'%','&'};
    int seed=time(NULL);
    srand(seed);
    char* s=(char*) calloc(10, sizeof(char));

  for(i=0;i<3;i++)
  *(s+i)=*(nome+i);

  for(i=3;i<6;i++)
  {
    *(s+i)=*(cognome+k);
    k++;
  }

  *(s+6)=*(simboli + rand()% (1-0+1)-0);
  *(s+7)=*(simboli + rand()% (1-0+1)-0);

  return s;
}

char* offuscapassword(char* password)
{
	//2345
	int i=0;
	for(i=2;i<6;i++)
		*(password+i)='*';
	return password;
}
