#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

	if (argc < 2)
		printf ("INSERIRE UN FILE\n");
	else {
		FILE* fileI;

		fileI = fopen (argv[1], "r");

		if (fileI != NULL) {
			char I[100];

			int i = 0;
			while (fgets(I, 99, fileI)) {
				printf ("%d: %s", i, I);
				i = i + 1;
			}

			printf ("------------------------------\n");
		
			rewind(fileI);

			while (fgets(I, 99, fileI)) {
				printf ("%d: %s", i, I);
				i = i + 1;
			}
			
			fclose(fileI);
		}
	}

	return (0);
}
