#include "global.h"

plista ARITHM, MEMORY, PROGRAM, FUNCTION;
int boolJMP = 0;

void print_lista (plista h) {
	while (h != NULL) {
		printf ("%s->", h->val);
		h = h->next;
	}
	printf ("NULL\n");
}

void traduci (FILE* fileI, FILE* fileO) {

	int const MAX_INST_LEN = 1000;

	char* I;
	I = (char*) malloc (MAX_INST_LEN * sizeof(char));
	
	char* O;
	O = (char*) malloc (MAX_INST_LEN * sizeof(char));


	//CREAZIONE LISTE CON I VARI COMANDI
	ARITHM = insert_predefined_ARITHM (ARITHM); 
	MEMORY = insert_predefined_MEMORY (MEMORY); 
	PROGRAM = insert_predefined_PROGRAM (PROGRAM); 
	FUNCTION = insert_predefined_FUNCTION (FUNCTION);

	/*
	print_lista (ARITHM);
	print_lista (MEMORY);
	print_lista (PROGRAM);
	print_lista (FUNCTION);
	*/

	// INIZIALIZZAZIONI NECESARIE
	fprintf(fileO, "@256\nD=A\n@SP\nM=D\n");	//SP = 256;

	// TRADUZIONE
	while (fgets (I, MAX_INST_LEN , fileI) != NULL) {
		clean_string (I);
		strcpy (O, I);

		int I_type = detect_instruction (I);
		printf("I: %s\t--> %d\n", I, I_type);

		if (I_type == 1)
			traduci_arithm (I, O);

		if (strlen (I) != 0)
			fprintf (fileO, "%s\n", O);
	}

	free (I);
}

int detect_instruction (char* I) {

	int type = -1;

	char* tmp = (char*) malloc (100 * sizeof (char));
	tmp[0] = '\0';
	strcpy (tmp, I);

	int i = 0;
	int found = 0;
	
	while (i < strlen(tmp) && found == 0) {
		if (tmp[i] == ' ')
			found = 1;
		else
			i = i + 1;
	}
	tmp[i] = '\0';

	if (is_in (ARITHM, tmp) == 1)
		type = 1;
	else if (is_in (MEMORY, tmp) == 1)
		type = 2;
	else if (is_in (PROGRAM, tmp) == 1)
		type = 3;
	else if (is_in (FUNCTION, tmp) == 1)
		type = 4;
	else
		type = -1; //Non trovata l'istruzione

	free (tmp);

	return (type);
	
}

void traduci_arithm (char* I, char* O) {
	plista tmp = ARITHM;
	int found = 0;

	while (tmp != NULL && found == 0) {
		if (strcmp (tmp->val, I) == 0) {
			found = 1;
		} else tmp = tmp->next;
	}

	strcpy (O, tmp->translated);

	if (strcmp (I, "eq") == 0 || strcmp (I, "gt") == 0 || strcmp (I, "lt") == 0) {
		for (int i = 1; i < strlen(I); i++) {
			if (I[i] == 'N' && I[i - 1] == '_')
				I[i] = (char) boolJMP;
		}
			boolJMP = boolJMP + 1;
	}
}


//Funzione che elimina gli spazi prima di un'istruzione e i commenti successivi ad essa
void clean_string (char* s) {
	int i = 0;
	int found = 0;
	
	while (i < strlen(s) && found == 0) {
		if (s[i] != ' ' && s[i] != '\t')
			found = 1;
		else
			i = i + 1;
	}

	for (int k = 0; k < strlen(s) - i; k++) {
		s[k] = s[k + i];
	}

	found = 0;
	i = 0;
	while (i < strlen(s) && found == 0) {
		if (s[i] == '/')
			found = 1;
		else
			i = i + 1;
	}

	if (found == 1)
		s[i] = '\0';
	else
		s[strlen(s) - 2] = '\0';
}
