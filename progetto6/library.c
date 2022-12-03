#include "global.h"

//VARIABILI GLOBALI
plista ARITHM, MEMORY, PROGRAM, FUNCTION;
int boolJMP = 0;
char* file_name;

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
	fprintf(fileO, "@300\nD=A\n@LCL\nM=D\n");	//LCL = 5; // MOMENTANEO
	fprintf(fileO, "@400\nD=A\n@ARG\nM=D\n");	//ARG = 9; // MOMENTANEO

	// TRADUZIONE
	while (fgets (I, MAX_INST_LEN , fileI) != NULL) {
		clean_string (I);
		O[0] = '\0';

		int I_type = detect_instruction (I);
		printf("I: %s\t--> %d\n", I, I_type);

		if (I_type == 1)
			traduci_arithm (I, O);
		else if (I_type == 2)
			traduci_memory (I, O);

		if (strlen (O) != 0)
			fprintf (fileO, "%s\n", O);
	}

	free (I);
	free (O);
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
		for (int i = 1; i < strlen(O); i++) {
			if (O[i] == 'N' && O[i - 1] == '_')
				O[i] = (char) boolJMP;
		}
			boolJMP = boolJMP + 1;
	}
}

void traduci_memory (char* I, char* O) {
	char* segment = (char*) malloc (100 * sizeof (char));
	segment[0] = '\0';
	char* number = (char*) malloc (100 * sizeof (char));
	number[0] = '\0';

	int i = 0;

	int pop_or_push = 0; 	// 0 = pop, 1 = push

	while (I[i] != ' ')
			i = i + 1;

	if(i == 3)
		pop_or_push = 0;
	else
		pop_or_push = 1;

	int offset = i;
	i = i + 1;

	while (I[i] != ' ') {
		segment[i - offset - 1] = I[i];
		i = i + 1;
	}
	segment[i - offset - 1] = '\0';

	offset = i;
	i = i + 1;
	
	while (i < strlen(I)) {
		number[i - offset - 1] = I[i];
		i = i + 1;
	}
	number[i - offset - 1] = '\0';
	
	strcat (O, "@"); strcat (O, number);
	strcat (O, "\nD=A\n");

	if (pop_or_push == 0) {	//I == "pop"
		if (strcmp (segment, "argument") == 0) {
			strcat (O, "@ARG\n");
			strcat (O, "D=D+M\n");
		} else if (strcmp (segment, "local") == 0) {
			strcat (O, "@LCL\n");
			strcat (O, "D=D+M\n");
		} else if (strcmp (segment, "static") == 0) {
			strcpy (O, "@");
			strcat (O, file_name);
			strcat (O, ".");
			strcat (O, number);
			strcat (O, "\nD=A\n");
		}

		strcat (O, "@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D");

	} else {	//I = "push"
		if (strcmp (segment, "constant") != 0) {
			if (strcmp (segment, "argument") == 0) {
				strcat (O, "@ARG\n");
				strcat (O, "A=D+M\n");
			} else if (strcmp (segment, "local") == 0) {
				strcat (O, "@LCL\n");
				strcat (O, "A=D+M\n");
			} else if (strcmp (segment, "static") == 0) {
				strcpy (O, "@");
				strcat (O, file_name);
				strcat (O, ".");
				strcat (O, number);
				strcat (O, "\nD=A\n");
			}

			strcat (O, "D=M\n");
		}
		strcat (O, "@SP\nM=M+1\nA=M-1\nM=D");
	}

	free (segment);
	free (number);
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

char* estrai_nome (char* path) {
	char* name = (char*) malloc (1000 * sizeof (char));
	name[0] = '\0';
	
	int i;
	i = strlen (path) - 1;
	while (i >= 0 && path[i] != '/')
		i = i - 1;

	if (i != 0)
		i = i + 1;

	int off_set = i;

	while (i < strlen (path)) {
		name [i - off_set] = path[i];
		i = i + 1;
	}
	name [i - off_set - 3] = '\0';

	return (name);
}

