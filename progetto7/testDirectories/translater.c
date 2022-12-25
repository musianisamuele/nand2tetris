#include "global.h"

void multi_file_translater (plistaf functions, FILE* file) {
	/* In questa funzione ho già la lista di funzion con relativo codice. Il main è
	 * contenuto in questa lista. Devo inziare la vera e propria traduzione: creo quindi una lista
	 * di stringhe che conterrà le funzioni che devono essere tradotte. Inserirò Sys.init
	 * e il codice del Main. Poi appena incontro una chiamata a funzione che non ho già tradotto
	 * allora la inserirà nella lista in coda e continuerò la mia traduzione.
	*/

	//print_lista (functions);


	plistas da_tradurre = NULL;
	
//	da_tradurre = tail_insert (da_tradurre, "Sys.init");
	da_tradurre = tail_insert (da_tradurre, "Main.main");
	da_tradurre = tail_insert (da_tradurre, "PongGame.new");

	while (da_tradurre != NULL) {
		printf ("Devo tradurre %s\n", da_tradurre->val);

		plistas function_body = get_function_body (functions, da_tradurre->val);

		if (function_body == NULL) {
			printf ("Qualcosa è andato storto durante la ricerca della funzione %s\n", da_tradurre->val);
			abort ();
		}

		da_tradurre = traduci_function (function_body, da_tradurre, file);

		//print_lista_string (function_body);

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
	while (funzione_corrente != NULL) {
		//Devo tradurre istruzione per istruzione
		
		printf ("\t%s", funzione_corrente->val);
		fprintf (file, funzione_corrente->val);
		//Per adesso mi preoccupo solo di inserire le dipendenze

		if ( is_a_call (funzione_corrente->val) == 1 ) {
			char name[400];
			get_function_name (name, funzione_corrente->val);

			dependencies = tail_insert (dependencies, name);
		}

		funzione_corrente = funzione_corrente->next;
	}

	return dependencies;
}
