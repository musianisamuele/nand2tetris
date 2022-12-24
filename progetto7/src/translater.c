#include "global.h"

void traduci_arithm (char* I, char* O) {
	if ( strcmp (I, "add") == 0 ) {
		strcpy (O, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=D+M");
	} else if ( strcmp (I, "sub") == 0 ) {
		strcpy (O, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=M-D");
	} else if ( strcmp (I, "neg") == 0 ) {
		strcpy (O, "@SP\nA=M-1\nM=-M");
	} else if ( strcmp (I, "and") == 0 ) {
		strcpy (O, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=D&M");
	} else if ( strcmp (I, "or") == 0 ) {
		strcpy (O, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=D|M");
	} else if ( strcmp (I, "not") == 0 ) {
		strcpy (O, "@SP\nA=M-1\nM=!M");	
	} else if ( strcmp (I, "eq") == 0 || strcmp (I, "gt") == 0 || strcmp (I, "lt") == 0) {
		
		//La cosa bella di queste istruzioni è che sono praticamente uguali.
		//Quello che cambia è solo l'istruzione JEQ, JGT o JLT
		strcpy (O, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nD=M-D\n@TRUE");
		
		//Essendoci dei jump devo diffreneziarli e quindi metto un numero che aggiorno
		//tramite una varibiale globale. Tutte le volte quindi i jmp avranno un ID diverso e
		//non ci sara' confusione

		//Per inserire un numero con strcat devo prima convertirlo in stinga
		char JMP_counter_str[30];
		int_to_string (JMP_counter_str, JMP_counter);
		JMP_counter++; //Incremento per la prossima volta

		strcat (O, JMP_counter_str); //Inserisco il numero per distinguere i jump
		strcat (O, "\nD;");
	
		//Faccio la distinzione tra eq, gt e lt
		if ( strcmp (I, "eq") == 0 )
			strcat (O, "JEQ");
		else if ( strcmp (I, "gt") == 0 )
			strcat (O, "JGT");
		else
			strcat (O, "JLT");

		
		strcat (O, "\n@SP\nA=M-1\nM=0\n@END");
		strcat (O, JMP_counter_str);
		strcat (O, "\n0;JMP\n(TRUE");
		strcat (O, JMP_counter_str);
		strcat (O, ")\n@SP\nA=M-1\nM=-1\n@END");
		strcat (O, JMP_counter_str);
		strcat (O, "\n0;JMP\n(END");
		strcat (O, JMP_counter_str);
		strcat (O, ")");
	} else { 
		printf ("ERROR: istruzione di tipo arithm non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}

void traduci_memory (char* I, char* O) {
	char command [100]; command[0] = '\0';
	char segment [100]; segment[0] = '\0';
	char number [100]; number[0] = '\0';

	//Estrapolo dalla string in input (I) il comando (push o pop)
	//il segmento (constant, argument, local, static) e il numero
	ex_next_word (I, command, 0);
	ex_next_word (I, segment, strlen (command));
	ex_next_word (I, number, strlen (command) + strlen (segment) + 1 ); //Aggiungo 1 per lo spazio tra il comando
																																			//e il nome del segmento

	strcat (O, "@"); strcat (O, number);
	strcat (O, "\nD=A\n");

	if ( strcmp (command, "pop") == 0 ) {	
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

	} else if ( strcmp (command, "push") == 0 ) {
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
	} else {
		printf ("ERROR: istruzione di tipo memory non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}

void traduci_program (char* I, char* O) {
	int i = 0;
	char command[10]; command [0] = '\0';
	char name[1000];

	//Estrapolo il comando (label, goto, if-goto) e il nome dell'etichetta
	//di dove si vuole andare
	ex_next_word (I, command, 0);
	ex_next_word (I, name, strlen (command) );

	if (strcmp (command, "label") == 0) {
		strcpy (O, "(");
		strcat (O, function_name);		//Per renderli unici ci aggiungo il nome della funzione in cui sono seguiti da un $
		strcat (O, "$");
		strcat (O, name); 
		strcat (O, ")"); 
	} else if (strcmp (command, "goto") == 0) {
		strcpy (O, "@");
		strcat (O, function_name);
		strcat (O, "$");
		strcat (O, name); 
		strcat (O, "\n0;JMP"); 
	} else if (strcmp (command, "if-goto") == 0) { 
		strcpy (O, "@SP\nM=M-1\nA=M\nD=M\n@");
		strcat (O, function_name);
		strcat (O, "$");
		strcat (O, name); 
		strcat (O, "\nD;JNE");
	} else {
		printf ("ERROR: istruzione di tipo program non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}

void traduci_function (char* I, char* O) {
	int i = 0;
	
	char command[10]; command [0] = '\0';

	ex_next_word (I, command, 0);

	i = strlen (command) + 1;

	if (strcmp (command, "function") == 0) {	
		char str_lcl[5]; str_lcl[0] = '\0';
		int int_lcl = 0;

		ex_next_word (I, function_name, i);				//Tutte le volte che incontro una funzione aggiorno la variabile globale
																							//con il suo nome all'interno. Mi serve per distinguere i jump con i comandi
																							//'program', cioe' (label, goto, if-goto)
		index_return = 0;

		//Dopo il nome della funzione c'e' il numero di varibiali locali. Lo predo in input come stringa
		ex_next_word (I, str_lcl, i + strlen (function_name) );
		
		//Converto la stringa con il numero delle variabili locali ad intero
		int_lcl = atoi (str_lcl);
		strcat (O, "(");
		strcat (O, function_name);
		strcat (O, ")\n@");
		strcat (O, str_lcl);
		strcat (O, "\nD=A\n@SP\nM=M+D\nA=M-D");

		for (i = 0; i < int_lcl; i++)
			strcat (O, "\nM=0\nA=A+1");

	} else if (strcmp (command, "call") == 0) { 
		char name[200]; name[0] = '\0';
		char str_arg [5]; str_arg[0] = '\0';
		char str_index_return[5]; str_index_return[0] = '\0'; 

		int_to_string (str_index_return, index_return); 
		index_return = index_return + 1;
		
		ex_next_word (I, name, i);
		ex_next_word (I, str_arg, i + strlen (name)  + 1);

		strcpy (O, "@5\nD=A\n@SP\nM=M+D\nD=M-1\n@R14\nM=D\n@THAT\nD=M\n@R14\nA=M\nM=D\n@THIS\nD=M\n@R14\nAM=M-1\nM=D\n@ARG\nD=M\n@R14\nAM=M-1\nM=D\n@LCL\nD=M\n@R14\nAM=M-1\nM=D\n");
		strcat (O, "@"); strcat (O, function_name); strcat (O, ":return"); strcat (O, str_index_return); strcat (O, "\n");
		strcat (O, "D=A\n@R14\nAM=M-1\nM=D\n@SP\nD=M\n@LCL\nM=D\n");
		strcat (O, "@"); strcat (O, str_arg); strcat (O, "\n");
		strcat (O, "D=A\n@R14\nD=M-D\n@ARG\nM=D\n");
		strcat (O, "@"); strcat (O, name); strcat (O, "\n0;JMP\n");
		strcat (O, "("); strcat (O, function_name); strcat (O, ":return"); strcat (O, str_index_return); strcat (O, ")\n");

	} else if (strcmp (command, "return") == 0) {
		strcpy (O, "@SP\nA=M-1\nD=M\n@ARG\nA=M\nM=D\nD=A+1\n@SP\nM=D\n@LCL\nD=M\n@R14\nAM=D-1\nD=M\n@THAT\nM=D\n@R14\nAM=M-1\nD=M\n@THIS\nM=D\n@R14\nAM=M-1\nD=M\n@ARG\nM=D\n@R14\nAM=M-1\nD=M\n@LCL\nM=D\n@R14\nAM=M-1\nA=M\n0;JMP");
	} else {
		printf ("ERROR: istruzione di tipo function non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}
