// FILE MAIN
#include "library.h"

char pathI[] = "asm/Add.asm";
char pathO[] = "hack/Add.hack";

FILE* fileI;
FILE* fileO;


int main ()  {
	
	// Prendo in input il path del file da tradurre
	//char path[50];
	//scanf ("%s", &path);		//DA DECOMMENTARE IN FUTURO!!
	
	//Apro il file di INPUT
	fileI = fopen (pathI, "r");

	//Se il file non è aperto il puntatore è NULL
	if (fileI == NULL) {
		printf ("ERRORE: Impossibile aprire il file di input o file di input non esistente\n");
		printf ("Controllare il path inserito (%s)", pathI);
	
	} else {
		//Sono riuscito ad aprire il file :)
	
		fileO = fopen (pathO, "w");

		if (fileO == NULL) {
			printf ("ERRORE: Qualcosa è andato storto con il file di OUTPUT\n");
		} else {

			if (traduci (fileI, fileO) == 0) {
				printf ("ERRORE duranta la traduzione del file\n");
			}
			
		}

		
		fclose (fileI); //Chiusura del FILE di input
	}

	return(0);
}
