#include "library.h"

int traduci (FILE* fileI, FILE* fileO) {
	int global_check = 1; //0 -> false, N\{0} -> True

	char tmp[100];
	while (!feof (fileI)) {		//Finché posso leggere -> feof(...) = True quando il file è finito
		fgets (tmp, 100, fileI);
		fprintf (fileO, "%s", tmp);
	}

	return (global_check);
}

