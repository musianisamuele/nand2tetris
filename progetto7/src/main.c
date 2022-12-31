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
	if (argc == 1) {
		printf ("ERRORE: inserire un file di input!\n");
		abort ();
	}

	if (argc > 2) {
		printf ("ERRORE: troppi argomenti inseriti!\n");
		abort ();
	}

	//argc == 2

	char* pathI = *(argv + 1);

	//Apro il file di output e se non esiste lo creo
	FILE* fileO = open_fileO (pathI);
	
	//CREAZIONE LISTA CON I VARI COMANDI
	list_of_command = insert_predefined (list_of_command);

	// INIZIALIZZAZIONI NECESARIE
	fprintf(fileO, "@256\nD=A\n@SP\nM=D\n");	//SP = 256;

	if (is_a_dir (pathI) == 1) {
		printf ("E' una directory\n");

		//Leggo tutti i file dentro la directory e copio le funzioni e il loro corpo nella lista F
		plistaf F = NULL;
		F = read_dir (pathI);

		multi_file_translater (F, fileO);

	} else {
		printf ("E' un file\n");
		//Fai le stesse cose che hai sempre fatto
		
		//Mi serve il nome del file per nominare le variabili durate la push e la pop
		file_name= estrai_nome (pathI);

		FILE* fileI = fopen (pathI, "r");
		
		if (fileI == NULL) {
			printf ("Impossibile aprire il file di input (%s)", pathI);
			abort ();
		}
		
		traduci (fileI, fileO);
	}

	char O[MAX_INST_LEN]; O[0] = '\0';

	//Aggiungo le routine solo se ho effettivamente delle funzioni
	if (strlen (function_name) != 0) {
		get_routine_of_return (O);
		fprintf (fileO, "%s\n", O);
		
		get_routine_of_call (O);
		fprintf (fileO, "%s\n", O);
	}

	return (0);
}
