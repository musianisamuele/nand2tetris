#include "global.h"

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

