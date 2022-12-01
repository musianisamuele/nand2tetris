#include "global.h"

void traduci (FILE* fileI, FILE* fileO) {

	int const MAX_INST_LEN = 1000;

	char* I;
	I = (char*) malloc (MAX_INST_LEN * sizeof(char));


	while (fgets (I, MAX_INST_LEN , fileI) != NULL) {
		printf("I: %s", I);
		clean_string (I);
		printf("I_post: %s\n", I);

		fprintf (fileO, "%s", I);
	}
}

void clean_string (char* s) {
	int i = 0;
	int found = 0;
	
	while (i < strlen(s) && found == 0) {
		if (s[i] != ' ' && s[i] != '\t')
			found = 1;
		else
			i = i + 1;
	}
	printf ("i: %d\n", i);

	for (int k = 0; k < strlen(s) - i; k++) {
		s[k] = s[k + i];
	}

	found = 0;
	i = 0;
	while (i < strlen(s) && found == 0) {
		if (s[i] == '/')
			found = 1;
		else
			i = i + 1;
	}

	if (found == 1)
		s[i] = '\0';
}
