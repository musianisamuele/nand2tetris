#include "library.h"

#ifndef PAIR_STRING
#define PAIR_STRING

struct pair_string {
	char first[10];
	char second[10];
};

typedef struct pair_string coppiaS;

#endif

void genera_conversioni (coppiaS *COMP, coppiaS *DEST, coppiaS *JUMP) {

	coppiaS *p = (coppiaS*) malloc (18 * sizeof (coppiaS));

	COMP = p;
		
	//COMP
	strcpy ((*p).first, "0"); strcpy ((*p).second, "101010");		p++;
	strcpy ((*p).first, "1"); strcpy ((*p).second, "111111"); 	p++;
	strcpy ((*p).first, "-1"); strcpy ((*p).second, "111010");	p++;
	strcpy ((*p).first, "D"); strcpy ((*p).second, "001100");		p++;
	strcpy ((*p).first, "A"); strcpy ((*p).second, "110000");		p++;
	strcpy ((*p).first, "!D"); strcpy ((*p).second, "001101");	p++;
	strcpy ((*p).first, "!A"); strcpy ((*p).second, "110001");	p++;
	strcpy ((*p).first, "-D"); strcpy ((*p).second, "001111");	p++;
	strcpy ((*p).first, "-A"); strcpy ((*p).second, "110011");	p++;
	strcpy ((*p).first, "D+1"); strcpy ((*p).second, "011111");	p++;
	strcpy ((*p).first, "A+1"); strcpy ((*p).second, "110111");	p++;
	strcpy ((*p).first, "D-1"); strcpy ((*p).second, "001110");	p++;
	strcpy ((*p).first, "A-1"); strcpy ((*p).second, "110010");	p++;
	strcpy ((*p).first, "D+A"); strcpy ((*p).second, "000010");	p++;
	strcpy ((*p).first, "D-A"); strcpy ((*p).second, "010011");	p++;
	strcpy ((*p).first, "A-D"); strcpy ((*p).second, "000111");	p++;
	strcpy ((*p).first, "D&A"); strcpy ((*p).second, "000000");	p++;
	strcpy ((*p).first, "D!A"); strcpy ((*p).second, "010101");

	//DEST
	p = (coppiaS*) malloc (8 * sizeof (coppiaS));
	DEST = p;

	strcpy ((*p).first, "null"); strcpy ((*p).second, "000");	p++;
	strcpy ((*p).first, "M"); strcpy ((*p).second, "001");		p++;
	strcpy ((*p).first, "D"); strcpy ((*p).second, "001");		p++;
	strcpy ((*p).first, "MD"); strcpy ((*p).second, "010");		p++;
	strcpy ((*p).first, "A"); strcpy ((*p).second, "100");		p++;
	strcpy ((*p).first, "AM"); strcpy ((*p).second, "101");		p++;
	strcpy ((*p).first, "AD"); strcpy ((*p).second, "110");		p++;
	strcpy ((*p).first, "AMD"); strcpy ((*p).second, "111");	p++;

	//JUMP
	p = (coppiaS*) malloc (8 * sizeof (coppiaS));
	JUMP = p;

	strcpy ((*p).first, "null"); strcpy ((*p).second, "000");	p++;
	strcpy ((*p).first, "JTG"); strcpy ((*p).second, "001");	p++;
	strcpy ((*p).first, "JEQ"); strcpy ((*p).second, "001");	p++;
	strcpy ((*p).first, "JGE"); strcpy ((*p).second, "010");	p++;
	strcpy ((*p).first, "JLT"); strcpy ((*p).second, "100");	p++;
	strcpy ((*p).first, "JNE"); strcpy ((*p).second, "101");	p++;
	strcpy ((*p).first, "JLE"); strcpy ((*p).second, "110");	p++;
	strcpy ((*p).first, "JMP"); strcpy ((*p).second, "111");	p++;

}



int traduci_file (FILE* fileI, FILE* fileO) {
	int global_check = 1; //0 -> false, N\{0} -> True

	int MAX_RIGA = 50;

	char I[MAX_RIGA];

	while (!feof (fileI)) {		//Finché posso leggere -> feof(...) = True quando il file è finito
		fgets (I, MAX_RIGA - 1, fileI);

		//printf ("LEN: %d\n", strlen(tmp));
		//printf ("tmp: %s\n", tmp);

		if (1) { //Dovrei controllare che la stringa non sia vuota
			int instruction_type = detect_instruction_type (I);

			char O[17];
			O[16] = '\0';
			
			strcpy (O, "2222222222222222");

			if (instruction_type == 0) {

				traduci_A_instruction (I, O);
				
			} else if (instruction_type == 1) {
				//traduci_C_instruction (tmp);
				
				traduci_C_instruction (I, O);

				printf ("C isntruction rilevata\n");
				printf ("Tradotta: %s\n", O);
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

void traduci_C_instruction (char I[], char O[]) {
	O[0] = 1; O[1] = 1; O[2] = 1; //I primi 3 bit di una C in. sono sempre a 1
	O[3] = '\0';

	//L'idea è di cercare dentro O tutte le possibili stringe e poi concatenare i risulati con strcat();
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
