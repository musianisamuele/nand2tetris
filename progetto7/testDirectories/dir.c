#include "global.h"

plistaf list_of_function;

int is_a_dir (char* s) {
	int len = strlen (s);

	if (len < 4) return 1;	//false
	else {
		char* tmp;
		tmp = s + len - 3;

		if ( strcmp (tmp, ".vm") != 0) return 1; //true
		else return 0;
	}
}

void genera_path_to_file (char* d, char* s1, char* s2) {
	strcpy (d, s1);
	if (d [strlen (d) - 1] != '/')
		strcat (d, "/");

	strcat (d, s2);
}

int is_a_function (char* s) {
	if (strlen (s) < 10) return 0; //false
	else {
		char tmp[9];

		int i = 0;

		while (i < 9 && i < strlen (s)) {
			tmp[i] = s[i];
			i++;
		}

		tmp [8] = '\0';

		if ( strcmp (tmp, "function") == 0 ) return 1; //true
		else return 0;
	}
}

int get_function_name (char* d, char* s) {
	char tmp [600];

	while (*s != ' ') s++;
	s++;

	strcpy (tmp, s);

	int i = 0;

	while (tmp[i] != ' ') i++;

	tmp[i] = '\0';

	strcpy (d, tmp);
}

int is_a_return (char* s) {
	if (strlen (s) < 6) return 0; //false
	else {
		char tmp[7];

		int i = 0;

		while (i < 7 && i < strlen (s)) {
			tmp[i] = s[i];
			i++;
		}

		tmp [6] = '\0';

		if ( strcmp (tmp, "return") == 0 ) return 1; //true
		else return 0;
	}
}

void read_file (char* path) {
	FILE* file = NULL;
	file = fopen (path, "r");

	//Controllo di aver aperto correttamente il file

	if (file == NULL) {
		printf ("ERRORE: Impossibile aprire il file (%s)\n", path);
		abort();
	}

	//Procedo in quanto il file è stato aperto correttamente
	
	char I[1000];

	while ( fgets (I, 1000, file) != NULL ) {
		//printf ("\t%s", I);

		if ( is_a_function (I) == 1 ) {
			char name[100];
			get_function_name (name, I);
			list_of_function = insert_function (list_of_function, name, NULL);
			//printf ("-----> FUNCTION: %s\n", name);
		}

		//if ( is_a_return (I) == 1 ) printf ("-----> RETURN\n");

	}

	fclose (file);
}

void read_dir (char* path) {
	//Inizializzo la lista di funzioni globale a vuota
	list_of_function = NULL;

	DIR* dir = NULL;
	dir = opendir (path);

	//Controllo di aver aperto correttammente la cartella

	if (dir == NULL) {
		printf ("ERRORE: Impossibile aprire la cartella (%s)\n", path);
		abort();
	}

	//Procendo in quanto la cartella si e' aperta

	printf ("Cartella aperta con successo\n");
	printf ("\n\tCONTENUTO:\n");

	//In linux per leggere una cartella ti viene restituito un puntatore ad
	//una struttura che contiene vari parametri.
	struct dirent* pippo = NULL;

	while ( NULL != ( pippo = readdir(dir)) ) {
		if ( is_a_dir (pippo->d_name) == 1 )
			printf ("DIR:\t%s", pippo->d_name);
		else {
			printf ("FILE:\t%s\n", pippo->d_name);
			char path_file[400];

			genera_path_to_file (path_file, path, pippo->d_name);

			read_file (path_file);
		}

		printf("\n");
	}

	printf ("\n\nFUNZIONI:\n");
	print_lista (list_of_function);

	closedir (dir);
}
