#include "global.h"

int main(int argc, char** argv) {
	if (argc == 2) {
		char file_pathI[1000];
		strcpy (file_pathI, *(argv + 1));
		
		file_name= estrai_nome (file_pathI);

		FILE* fileI;

		fileI = fopen (file_pathI, "r");

		if (fileI != NULL) {

			FILE* fileO;
			char file_pathO[1000];
			strcpy (file_pathO, file_pathI);
			file_pathO[ strlen(file_pathO) - 2 ] = '\0';
			strcat (file_pathO, "asm");

			fileO = fopen (file_pathO, "w");

			if (fileO != NULL) {
				traduci (fileI, fileO);
			} else
				printf ("Impossibile aprire il file (%s)", file_pathO);
		} else
			printf ("Impossibile aprire il file (%s)", file_pathI);
	} else if (argc > 1)
		printf ("ERRORE: troppi argomenti inseriti!\n");
	else
		printf ("ERRORE: inserire un file di input!\n");

	return (0);
}

