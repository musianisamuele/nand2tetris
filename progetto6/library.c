#include "global.h"

//VARIABILI GLOBALI
plista ARITHM, MEMORY, PROGRAM, FUNCTION;
int boolJMP = 0;
char* file_name;
char function_name [400] = ""; //Nome della funzione in cui sono attualmente

void print_lista (plista h) {
	while (h != NULL) {
		printf ("%s->", h->val);
		h = h->next;
	}
	printf ("NULL\n");
}

void traduci (FILE* fileI, FILE* fileO) {

	int const MAX_INST_LEN = 2000;

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
	//fprintf(fileO, "@300\nD=A\n@LCL\nM=D\n");	//LCL = 5; // MOMENTANEO
	//fprintf(fileO, "@400\nD=A\n@ARG\nM=D\n");	//ARG = 9; // MOMENTANEO

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
		else if (I_type == 3)
			traduci_program (I, O);
		else if (I_type == 4)
			traduci_function (I, O);

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
		char boolJMP_s[30];
		
		for (int i = 0; i < strlen(O); i++) {
			if (O[i] == '_') {
				int_to_string (boolJMP_s, boolJMP);
				insert_in_string (O, boolJMP_s, i);
			}
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

	ex_next_word (I, segment, i);

	i = i + 1;

	while (I[i] != ' ')
		i = i + 1;
	
	ex_next_word (I, number, i);

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

void traduci_program (char* I, char* O) {
	int i = 0;
	char command[10];
	char name[1000];

	for (i = 0; i < 10; i++)
		command[i] = I[i];

	i = 0;
	while (I[i] != ' ')
		i = i + 1;

	command[i] = '\0';

	ex_next_word (I, name, i);

	plista tmp = PROGRAM;
	
	while (strcmp (tmp->val, command) != 0)
		tmp = tmp->next;

	strcpy (O, tmp->translated);

	for (i = 0; i < strlen (O); i++) {
		if (O[i] == '_') {
			int len = strlen (function_name);
			strcat (function_name, "$");
			strcat (function_name, name);
			insert_in_string (O, function_name, i);
			function_name[len] = '\0';
			i = i + strlen (name); //LOOP INFINITO SE CI SONO DEI _ NE name
		}
	}
}

void traduci_function (char* I, char* O) {
	int i = 0;

	while (I[i] != ' ')
		i = i + 1;

	if (i == 8) {					//I = function ...
		char str_lcl[5]; str_lcl[0] = '\0';
		int int_lcl = 0;

		ex_next_word (I, function_name, i);
		i = next_space (I, i);

		ex_next_word (I, str_lcl, i);
		int_lcl = atoi (str_lcl);

		strcat (O, "(");
		strcat (O, function_name);
		strcat (O, ")\n@");
		strcat (O, str_lcl);
		strcat (O, "\nD=A\n@SP\nM=M+D\nA=M-D");

		for (i = 0; i < int_lcl; i++)
			strcat (O, "\nM=0\nA=A+1");

	} else if (i == 4){		//I = call ...
		char name[200]; name[0] = '\0';
		char str_arg [5]; str_arg[0] = '\0';
		
		ex_next_word (I, name, i);
		
		i = next_space (I, i);

		ex_next_word (I, str_arg, i);

		strcpy (O, "@5\nD=A\n@SP\nM=M+D\nD=M-1\n@R14\nM=D\n");
		strcat (O, "@THAT\nD=M\n@R14\nA=M\nM=D\n");
		strcat (O, "@THIS\nD=M\n@R14\nAM=M-1\nM=D\n");
		strcat (O, "@ARG\nD=M\n@R14\nAM=M-1\nM=D\n");
		strcat (O, "@LCL\nD=M\n@R14\nAM=M-1\nM=D\n");
		strcat (O, "@"); strcat (O, function_name); strcat (O, ".return\n");
		strcat (O, "D=A\n@R14\nAM=M-1\nM=D\n");
		strcat (O, "@SP\nD=M\n@LCL\nM=D\n");
		strcat (O, "@"); strcat (O, str_arg); strcat (O, "\n");
		strcat (O, "D=A\n@R14\nD=M-D\n@ARG\nM=D\n");
		strcat (O, "@"); strcat (O, name); strcat (O, "\n0;JMP\n");
		strcat (O, "("); strcat (O, function_name); strcat (O, ".return)\n");


	} else {							//I = return
		//DA FINIRE
		strcpy (O, "@SP\nA=M-1\nD=M\n@ARG\nA=M\nM=D\nD=A+1\n@SP\nM=D\n@LCL\nD=M\n@R14\nAM=D-1\nD=M\n@THAT\nM=D\n@R14\nAM=M-1\nD=M\n@THIS\nM=D\n@R14\nAM=M-1\nD=M\n@ARG\nM=D\n@R14\nAM=M-1\nD=M\n@LCL\nM=D\n@R14\nAM=M-1\nA=M\n0;JMP");
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

char* estrai_nome (char* path) {
	char* name = (char*) malloc (1000 * sizeof (char));
	name[0] = '\0';
	
	int i;
	i = strlen (path) - 1;
	while (i >= 0 && path[i] != '/')
		i = i - 1;

	
	if (i != 0)
		i = i + 1;

	ex_next_word (path, name, i);
	
	name [strlen (name) - 3] = '\0';
	
	return (name);
}

void insert_in_string (char* s, char* in, int pos) {
	char tmp[1000];

	int i = 0;
	for (i = pos + 1; i < strlen (s); i++)
		tmp [i - pos - 1] = s[i];

	tmp [i - pos - 1] = '\0';

	s[pos] = '\0';
	strcat (s, in);
	strcat (s, tmp);
}

int my_log10 (int n) {
	int i = 0;

	while (n >= 1) {
		n = n / 10;
		i = i + 1;
	}
	return (i - 1);
}

void int_to_string (char s[], int n) {
	int dim;

	if (n == 0)
		dim = 1;
	else
		dim = my_log10 (n) + 1;
	
	int i = 0;

	int power = 1;

	for (i = 0; i < dim - 1; i++) power = power * 10;

	i = 0;

	while (power > 0) {
		char tmp = '0';

		tmp = tmp + (n / power);
		n = n % power;
		power = power / 10;

		s[i] = tmp;
		i = i + 1;
	}
}

void ex_next_word (char* s, char* d, int pos) {
	int j = 0;
	
	if (s[pos] == ' ') {
		pos = pos + 1;
	}

	while (s[pos] != ' ' && pos < strlen (s)) {
		d[j] = s[pos];
		pos = pos + 1;
		j = j + 1;
	}
	d[j] = '\0';
}

int next_space (char* s, int i) {
	if (s[i] == ' ')
		i = i + 1;

	while (s[i] != ' ')
		i = i + 1;

	return (i);
}
