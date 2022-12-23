/* File main del progetto 6 del corso di Architettura degli elaboratori.
 * Si tratta di costruire un traduttore pariziale (mancano alcune cose rispetto al
 * progetto di nand2taatris) da linguaggio Virtual machine a linguaggio assembly.
 *
 * Il traduttore (VMtranslator) prende in input un file da linea di comando con estensione .vm
 * e genera un file con il medesimo nome e nella medesima posizione con estensione .asm con tutte
 * le istruzioni tradotte.
 *
 * Il segmento pointer e tmp non sono usati. Static è stato fatto come da consegna e non come
 * vorebbe nand2tatris. THIS e THAT non sono abilitati.
 *
*/
#include "global.h"

int main(int argc, char** argv) {
	if (argc == 2) {
		char* file_pathI = *(argv + 1);
		
		file_name= estrai_nome (file_pathI);	//Mi serve il nome del file per nominare le variabili
																					//durate la push e la pop

		FILE* fileI;

		fileI = fopen (file_pathI, "r");

		if (fileI != NULL) {

			FILE* fileO;
			char* file_pathO = (char* ) malloc ( (strlen (file_pathI) + 2) * sizeof (char) );

			strcpy (file_pathO, file_pathI);

			file_pathO[ strlen(file_pathO) - 2 ] = '\0';	//Un po' brutale, ma cambio l'estensione al file
			strcat (file_pathO, "asm");

			fileO = fopen (file_pathO, "w");
			free (file_pathO);
			file_pathO = NULL;

			if (fileO != NULL) {
				traduci (fileI, fileO);
			} else {
				printf ("Impossibile aprire il file di output (%s)", file_pathO);
				abort ();
			}
		} else {
			printf ("Impossibile aprire il file di input (%s)", file_pathI);
			abort ();
		}
	} else if (argc > 1) {
		printf ("ERRORE: troppi argomenti inseriti!\n");
		abort ();
	}
	else {
		printf ("ERRORE: inserire un file di input!\n");
		abort ();
	}

	return (0);
}

