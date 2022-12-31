#include "global.h"

void translate_instruction_of_type_arithm (char* I, char* O) {
	if ( strcmp (I, "add") == 0 ) {
		strcpy (O, "@SP\nAM=M-1\nD=M\nA=A-1\nM=D+M");
	} else if ( strcmp (I, "sub") == 0 ) {
		strcpy (O, "@SP\nAM=M-1\nD=M\nA=A-1\nM=M-D");
	} else if ( strcmp (I, "neg") == 0 ) {
		strcpy (O, "@SP\nA=M-1\nM=-M");
	} else if ( strcmp (I, "and") == 0 ) {
		strcpy (O, "@SP\nAM=M-1\nD=M\nA=A-1\nM=D&M");
	} else if ( strcmp (I, "or") == 0 ) {
		strcpy (O, "@SP\nAM=M-1\nD=M\nA=A-1\nM=D|M");
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

void translate_instruction_of_type_memory (char* I, char* O) {
	char command [100]; command[0] = '\0';
	char segment [100]; segment[0] = '\0';
	char number [100]; number[0] = '\0';

	//Estrapolo dalla string in input (I) il comando (push o pop)
	//il segmento (constant, argument, local, static) e il numero
	ex_next_word (I, command, 0);
	ex_next_word (I, segment, strlen (command));
	ex_next_word (I, number, strlen (command) + strlen (segment) + 1 ); //Aggiungo 1 per lo spazio tra il comando
																																			//e il nome del segmento

	//Nonostante i codici siano simili e ci siano delle stringhe
	//ripetute, per una pulizia del codice preferisco dividere pop e push

	if ( strcmp (command, "pop") == 0 ) {	
		//Per i segmento argument, local, static, this e that
		//l'implementazione è praticamete uguale quindi faccio solo una piccola
		//distinzione per sapere a che indirizzo devo puntare, ma il codice
		//si ripete quindi alcune istruzioni le ho rese "generali"
		//
		//Per il segmento pointer e il segmento temp invece l'implementazione differisce
		//abbastanza e quindi lo traduco in maniera diversa

		if ( strcmp (segment, "pointer") == 0 ) {
			strcat (O, "@SP\nAM=M-1\nD=M\n");

			//Per una piccola ottimizzazione del codice, essendo che pointer può avere solo
			//due "valori" come numero che lo seguono faccio il caso e così riparimio qualche istruzione
			
			if ( strcmp (number, "0") == 0 )
				strcat (O, "@THIS\n");
			else 
				strcat (O, "@THAT\n");

			strcat (O, "M=D");

		} else if ( strcmp (segment, "temp") == 0 ) {
			//Per ottimizzare il codice faccio un precalcolo sull'indirizzo in cui
			//dovro' scrivere il risultato. In pratica essendo il segmento temp compreso 
			//tra RAM[5] e RAM[12], il numero dopo il comando vm sarò compreso per forza tra 0
			//e 7 (12 - 5). Quindi posso calcolare gia' l'indirizzo di in cui scrivere il valore
			//della pop semplicemente scrivendo (x + 5) e facendo gia' io il calcolo

			strcat (O, "@SP\nAM=M-1\nD=M\n@");

			char tmp[3]; tmp[0] = '\0';
			int_to_string (tmp, atoi (number) + 5);

			strcat (O, tmp);
			strcat (O, "\nM=D");
		} else {
			strcat (O, "@"); strcat (O, number);
			strcat (O, "\nD=A\n");

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
			} else if (strcmp (segment, "this") == 0) {
				strcat (O, "@THIS\n");
				strcat (O, "D=D+M\n");
			} else if (strcmp (segment, "that") == 0) {
				strcat (O, "@THAT\n");
				strcat (O, "D=D+M\n");
			}

			strcat (O, "@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D");
		}

	} else if ( strcmp (command, "push") == 0 ) {
		if ( strcmp (segment, "pointer") == 0 ) {

			if ( strcmp (number, "0") == 0 )
				strcat (O, "@THIS\n");
			else
				strcat (O, "@THAT\n");

			strcat (O, "D=M\n@SP\nM=M+1\nA=M-1\nM=D");

		} else if ( strcmp (segment, "temp") == 0 ) {
			strcat (O, "@");

			char tmp[3]; tmp[0] = '\0';
			int_to_string (tmp, atoi (number) + 5);
			strcat (O, tmp);

			strcat (O, "\nD=M\n@SP\nM=M+1\nA=M-1\nM=D");
		} else {
			strcat (O, "@"); strcat (O, number);
			strcat (O, "\nD=A\n");
			
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
					strcat (O, "\n");	
				} else if (strcmp (segment, "this") == 0) {
					strcat (O, "@THIS\n");
					strcat (O, "A=D+M\n");
				} else if (strcmp (segment, "that") == 0) {
					strcat (O, "@THAT\n");
					strcat (O, "A=D+M\n");
				} else if (strcmp (segment, "temp") == 0) {
					strcat (O, "@R5\n");
					strcat (O, "A=A+D\n");
				}

				strcat (O, "D=M\n");
			}
			strcat (O, "@SP\nM=M+1\nA=M-1\nM=D");
		}
	} else {
		printf ("ERROR: istruzione di tipo memory non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}

void translate_instruction_of_type_program (char* I, char* O) {
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
		strcat (O, "\nD;JNE");	//E' giusta come implementazione? Salta tutte le volte che il valore != 0 e non quando è uguale a -1
	} else {
		printf ("ERROR: istruzione di tipo program non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}

void translate_instruction_of_type_function (char* I, char* O) {
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
		strcat (O, ")");

		if (int_lcl > 0)  {
			strcat (O, "\n@");
			strcat (O, str_lcl);
			strcat (O, "\nD=A\n@SP\nM=M+D\nA=M-D");

			for (i = 0; i < int_lcl; i++)
				strcat (O, "\nM=0\nA=A+1");
		}

	} else if (strcmp (command, "call") == 0) { 
		char name[200]; name[0] = '\0';
		char str_arg [5]; str_arg[0] = '\0';
		char str_index_return[5]; str_index_return[0] = '\0'; 

		int_to_string (str_index_return, index_return); 
		index_return = index_return + 1;
		
		ex_next_word (I, name, i);
		ex_next_word (I, str_arg, i + strlen (name)  + 1);

		//NUOVA IMPLEMENTAZIONE
		
		strcpy (O, "@"); strcat (O, function_name); strcat (O, ":return"); strcat (O, str_index_return); strcat (O, "\n");
		strcat (O, "D=A\n@SP\nA=M\nM=D\n");
		strcat (O, "@"); strcat (O, str_arg); strcat (O, "\n");
		strcat (O, "D=A\n@R13\nM=D\n");
		strcat (O, "@"); strcat (O, name); strcat (O, "\n");
		strcat (O, "D=A\n@R14\nM=D\n");
		strcat (O, "@"); strcat (O, ROUTINE_OF_CALL);
		strcat (O, "\n0;JMP\n");
		strcat (O, "("); strcat (O, function_name); strcat (O, ":return"); strcat (O, str_index_return); strcat (O, ")");

	} else if (strcmp (command, "return") == 0) {
		strcpy (O, "@");
		strcat (O, ROUTINE_OF_RETURN);
		strcat (O, "\n0;JMP");
	} else {
		printf ("ERROR: istruzione di tipo function non riconosciuta!\n");
		printf ("Istruzione: %s\n", I);
		abort ();
	}
}

void get_routine_of_return (char* O) {
	strcpy (O, "(");
	strcat (O, ROUTINE_OF_RETURN);
	strcat (O, ")\n");
	strcat (O, "@5\nD=A\n@LCL\nA=M-D\nD=M\n@R13\nM=D\n");
	strcat (O, "@SP\nD=M\n@LCL\nD=M-D\n@NO_RETURN_VALUE\nD;JEQ\n");
	strcat (O, "@SP\nA=M-1\nD=M\n@ARG\nA=M\nM=D\n");
	strcat (O, "@ARG\nD=M+1\n@SP\nM=D\n");
	strcat (O, "@RESUME_RETURN\n0;JMP\n");
	strcat (O, "(NO_RETURN_VALUE)\n");
	strcat (O, "@ARG\nD=M\n@SP\nM=D\n");
	strcat (O, "(RESUME_RETURN)\n");
	strcat (O, "@LCL\nAM=M-1\nD=M\n@THAT\nM=D\n");
	strcat (O, "@LCL\nAM=M-1\nD=M\n@THIS\nM=D\n");
	strcat (O, "@LCL\nAM=M-1\nD=M\n@ARG\nM=D\n");
	strcat (O, "@LCL\nAM=M-1\nD=M\n@LCL\nM=D\n");
	strcat (O, "@R13\nA=M\n0;JMP");
}

void get_routine_of_call (char* O) {
	strcpy (O, "(");
	strcat (O, ROUTINE_OF_CALL);
	strcat (O, ")\n");
	strcat (O, "@LCL\nD=M\n@SP\nAM=M+1\nM=D\n");
	strcat (O, "@ARG\nD=M\n@SP\nAM=M+1\nM=D\n");
	strcat (O, "@THIS\nD=M\n@SP\nAM=M+1\nM=D\n");
	strcat (O, "@THAT\nD=M\n@SP\nAM=M+1\nM=D\n");
	strcat (O, "@SP\nMD=M+1\n@LCL\nM=D\n");
	strcat (O, "@5\nD=A\n@R13\nD=D+M\n@SP\nD=M-D\n@ARG\nM=D\n");
	strcat (O, "@R14\nA=M\n0;JMP");
}

