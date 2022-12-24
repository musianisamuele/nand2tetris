#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <sys/types.h>		//Per le directories
#include <dirent.h>

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
		printf ("\t%s", I);
	}

	fclose (file);
}

void read_dir (char* path) {
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

	closedir (dir);
}

int main(int argc, char** argv) {
	if (argc == 2) {
		char pathI[1000];
		strcpy (pathI, *(argv + 1));
		
		if ( is_a_dir (pathI) == 1 ) {
			printf ("E' una directory\n");

			//Ci divertiamo :)

			read_dir (pathI);
			

		} else {
			printf ("E' un file\n");
			//Fai le stesse cose che hai sempre fatto
		}

	} else if (argc > 1) {
		printf ("ERRORE: troppi argomenti inseriti!\n");
		abort ();
	}
	else {
		printf ("ERRORE: inserire un file di input!\n");
		abort ();
	}

	return (0);
}

