#include "global.h"

void multi_file_translater (plistaf functions, FILE* file) {
	/* In questa funzione ho già la lista di funzion con relativo codice. Il main è
	 * contenuto in questa lista. Devo inziare la vera e propria traduzione: creo quindi una lista
	 * di stringhe che conterrà le funzioni che devono essere tradotte. Inserirò Sys.init
	 * e il codice del Main. Poi appena incontro una chiamata a funzione che non ho già tradotto
	 * allora la inserirò nella lista in coda e continuerò la mia traduzione.
	*/

	//print_lista (functions);


	plistas da_tradurre = NULL;		//Coda in cui inserisco le funzioni da tradurre
	
  da_tradurre = tail_insert (da_tradurre, "Sys.init");
	//da_tradurre = tail_insert (da_tradurre, "Main.main");

	while (da_tradurre != NULL) {
		int status = is_already_translated (functions, da_tradurre->val);

		if (status == 0) {		//Devo ancora tradurla
			printf ("Devo tradurre %s\n", da_tradurre->val);

			plistas function_body = get_function_body (functions, da_tradurre->val);

			if (function_body == NULL) {
				printf ("Qualcosa è andato storto durante la ricerca della funzione %s\n", da_tradurre->val);
				abort ();
			}

			da_tradurre = traduci_function (function_body, da_tradurre, file);

			//print_lista_string (function_body);

		} else if (status == -1) {
			printf ("ERRORE: Funzione da tradurre non trovata (%s)\n", da_tradurre->val);
			abort();
		}

		da_tradurre = remove_function (da_tradurre);
	}
}

int is_a_call (char* s) {
	if (strlen (s) < 5) return 0;
	
	char tmp [5];

	for (int i = 0; i < 5; i++)
		tmp[i] = s[i];

	tmp [4] = '\0';

	if (strcmp (tmp, "call") == 0) return 1;
	else return 0;
}


plistas traduci_function (plistas funzione_corrente, plistas dependencies, FILE* file) {
	char I[MAX_INST_LEN]; I[0] = '\0';
	char O[MAX_INST_LEN]; O[0] = '\0';
	while (funzione_corrente != NULL) {
		O[0] = '\0';
		//Devo tradurre istruzione per istruzione
	
		//printf ("\t%s", funzione_corrente->val);
		strcpy (I, funzione_corrente->val);
		
		//Rimuovo spiacevoli '\r' e '\n'
		if ( I [strlen (I) - 2] == '\r' )
			I [strlen (I) - 2] = '\n';

		if ( I [strlen (I) - 1] == '\n' && I [strlen (I) - 2] == '\n' )
			I [strlen (I) - 1] = '\0';

		/*
		//Stampo su file l'istruzione
		if ( is_a_function (O) == 1 ) {
			char tmp[1000];
			strcpy (tmp, "\nfunction ");
			char name[1000];
			get_function_name (name, O);

			int i = 0;
			while (name[i] != '.') i++;

			name[i] = '_';

			strcat (tmp, name);

			strcat (tmp, O + 1 + 8 + strlen (name));
			strcpy (O, tmp);
		} 

		if ( is_a_call (O) == 1 ) {
			char tmp[1000];
			strcpy (tmp, "call MYPONG.");
			char name[1000];
			get_function_name (name, O);

			int i = 0;
			while (name[i] != '.') i++;

			name[i] = '_';

			strcat (tmp, name);

			strcat (tmp, O + 1 + 4 + strlen (name));
			strcpy (O, tmp);
		}

		*/

		//Faccio la traduzione

		clean_string (I);
		int I_type = detect_instruction (I);

		if (I_type == 0)
			translate_instruction_of_type_arithm (I, O);
		else if (I_type == 1)
			translate_instruction_of_type_memory (I, O);
		else if (I_type == 2)
			translate_instruction_of_type_program (I, O);
		else if (I_type == 3)
			translate_instruction_of_type_function (I, O);

		//Se ho riconosciuto l'istruzione e non ci sono stati problemi 
		//durante la traduzione la scrivo sul file
		if (I_type != -1)
			fprintf (file, "%s\n", O);

		//Se chiamo una funzione la inserisco nelle dipendeze da risolvere
		if ( is_a_call (funzione_corrente->val) == 1 ) {
			char name[400];
			get_function_name (name, funzione_corrente->val);

			dependencies = tail_insert (dependencies, name);
		}
		
		//Procedo nella truduzione
		funzione_corrente = funzione_corrente->next;
	}

	return dependencies;
}
