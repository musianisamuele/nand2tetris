#include "library.h"

void rimuovi_parentesi (char I[]) {
	for (int i = 0; i < strlen (I) - 1; i++) {
		I[i] = I[i + 1];
	}

	I[ strlen (I) - 4] = '\0';
}

void dec_to_stringBin (int n, char O[]) {
	int tmp = (1 << 14); //2^14;

	int indice = 1;
	
	while (indice < 16) {
		//printf ("\nindice: %d\nn: %d\ntmp: %d\nO[]: %s\n", indice, n, tmp, O);
		
		if (n >= tmp) {
			n = n - tmp;
			O[indice] = '1';
		} else {
			O[indice] = '0';
		}

		tmp = (tmp >> 1);
		indice = indice + 1;
	}
	
}

int is_in_string (char s[], char f[], int a, int b) {
	int found = 0;

	int i;
	int j;
	int lenS = strlen(s);
	int lenF = strlen(f);

	i = a;
	while (i < lenS && found == 0 && i < b) {
		if (s[i] == f[0] && lenS >= i + lenF ) {
			found = 1;
			j = 0;
			while (j < lenF) {
				if (s[i + j] != f[j])
					found = 0;
				
				j = j + 1;
			}
		}
		i = i + 1;
	}

	return (found);
}
