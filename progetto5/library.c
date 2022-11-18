#include "library.h"

int traduci_file (FILE* fileI, FILE* fileO) {
	int global_check = 1; //0 -> false, N\{0} -> True

	int MAX_RIGA = 50;

	char I[MAX_RIGA];

	while (!feof (fileI)) {		//Finché posso leggere -> feof(...) = True quando il file è finito
		fgets (I, MAX_RIGA, fileI);

		//printf ("LEN: %d\n", strlen(tmp));
		//printf ("tmp: %s\n", tmp);

		if (1) { //Dovrei controllare che la stringa non sia vuota
			int instruction_type = detect_instruction_type (I);

			char O[17];
			O[16] = '\0';

			if (instruction_type == 0) {

				traduci_A_instruction (I, O);
				
				printf ("A isntruction rilevata\n");
				printf ("\t %s = %s\n", I, O);

			} else if (instruction_type == 1) {
				//traduci_C_instruction (tmp);
				printf ("C isntruction rilevata\n");
			} else if (instruction_type == 2) {
				printf ("Labels rilevata");
			} else if (instruction_type == 3) {
				//Qui non dovrei neanche stampare la riga...come faccio?
				printf ("Commento rilevato\n");
			} else {
				printf ("ERRORE: Qualcosa è andato storto durante la detection dell'instruction\n");
			}

			fprintf (fileO, "%s", I);
		}
	}

	return (global_check);
}

// 0 -> A, 1 -> C, 2 -> Labels, 3 -> Commento, -1 -> Errore
int detect_instruction_type (char I[]) {
	char t = I[0];
	int return_value = -1;

	if (t == '@') {
		return_value = 0;
	} else if (t == 'A' || t == 'M' || t == 'D') {
		return_value = 1;
	} else if (t == '(') {
		return_value = 2;
	} else if (t == '/') {
		return_value = 3;
	}

	return (return_value);
}

void traduci_A_instruction (char I[], char O[]) {
	O[0] = '0'; //Essendo una A in. inizia sempre con uno zero

	int len = strlen (I);

	//traduco in numero da stringa:
	int i = 1;
	int n = 0;

	while (I[i] != '\n' && I[i] != '\0' && I[i] != '\r') {
		n = n * 10;
		n = n + (int) I[i] - (int) '0';
		i = i + 1;
	}

	dec_to_stringBin (n, O);

}

void dec_to_stringBin (int n, char O[]) {
	int tmp = (1 << 14); //2^14;

	int indice = 1;
	
	while (indice < 16) {
		//printf ("\nindice: %d\nn: %d\ntmp: %d\nO[]: %s\n", indice, n, tmp, O);
		
		if (n >= tmp) {
			n = n - tmp;
			O[indice] = '1';
		} else {
			O[indice] = '0';
		}

		tmp = (tmp >> 1);
		indice = indice + 1;
	}
	
}
