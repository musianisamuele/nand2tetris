#include "library.h"

int traduci_file (FILE* fileI, FILE* fileO) {
	int global_check = 1; //0 -> false, N\{0} -> True

	int MAX_RIGA = 100;

	char tmp[MAX_RIGA];

	while (!feof (fileI)) {		//Finché posso leggere -> feof(...) = True quando il file è finito
		fgets (tmp, 100, fileI);
	
		int instruction_type = detect_instruction_type (tmp);

		if (instruction_type == 0) {
			//traduci_A_instruction (tmp);
			printf ("A isntruction rilevata\n");
		} else if (instruction_type == 1) {
			//traduci_C_instruction (tmp);
			printf ("C isntruction rilevata\n");
		} else if (instruction_type == 2) {
			//Qui non dovrei neanche stampare la riga...come faccio?
			printf ("Commento rilevato\n");
		} else {
			printf ("ERRORE: Qualcosa è andato storto durante la detection dell'instruction\n");
		}

		fprintf (fileO, "%s", tmp);
	}

	return (global_check);
}

// 0 -> A, 1 -> C, 2 -> Commento, -1 -> Errore
int detect_instruction_type (char I[]) {
	char t = I[0];
	int return_value = -1;

	if (t == '@') {
		return_value = 0;
	} else if (t == 'A' || t == 'M' || t == 'D') {
		return_value = 1;
	} else if (t == '/') {
		return_value = 2;
	}

	return (return_value);
}
