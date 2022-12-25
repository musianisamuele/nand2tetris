#include "global.h"

int main(int argc, char** argv) {
	if (argc == 2) {
		char pathI[1000];
		strcpy (pathI, *(argv + 1));
		
		if ( is_a_dir (pathI) == 1 ) {
			printf ("E' una directory\n");
			
			FILE* fileO;
			char* file_pathO = (char* ) malloc ( (strlen (pathI) + 5) * sizeof (char) );

			strcpy (file_pathO, pathI);

			if ( file_pathO [ strlen (file_pathO) - 1] == '/' )
				file_pathO [ strlen (file_pathO) - 1] = '\0';

			strcat (file_pathO, ".asm");

			fileO = fopen (file_pathO, "w");
			free (file_pathO);
			file_pathO = NULL;

			if (fileO == NULL) {
				printf ("Impossibile aprire il file di output (%s)", file_pathO);
				abort ();
			}

			//Leggo tutti i file dentro la directory e copio le funzioni e il loro corpo
			//nella lista F
			plistaf F = NULL;
			F = read_dir (pathI);

			multi_file_translater (F, fileO);

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

