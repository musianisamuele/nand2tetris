// FILE MAIN
#include "library.h"


int main (int argc, char *argv[]) {

	if (argc == 2) {
		
		char pathI[1000];
		strcpy(pathI, argv[1]); //argv[0] è il nome del programma. Copio l'input nella stringa path
		
		FILE* fileI;
		FILE* fileO;
		
		//Apro il file di INPUT
		fileI = fopen (pathI, "r");

		//Se il file è aperto il puntatore è diverso da NULL
		if (fileI != NULL) {

			char pathO[1000];
			strcpy (pathO, "hack/test.hack");
			//Cambiare l'estenzione!!	

			fileO = fopen (pathO, "w");

			if (fileO == NULL) {
				printf ("ERRORE: Qualcosa è andato storto con il file di OUTPUT\n");
			} else {

				if (traduci_file (fileI, fileO) == 0) {
					printf ("ERRORE duranta la traduzione del file\n");
				}
				
			}

			
			fclose (fileI); //Chiusura del FILE di input

		} else {
			
			printf ("ERRORE: Impossibile aprire il file di input o file di input non esistente\n");
			printf ("Controllare il path inserito (%s)", pathI);

		}

	} else if (argc > 1) {
		printf ("Troppi argomenti inseriti!\n");
	} else {
		printf ("Non abbastanza argoneti\n");
	}

	

	return(0);
}
