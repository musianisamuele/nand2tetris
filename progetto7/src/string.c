#include "global.h"

/* Postcondizione: presa una stringa elimina gli spazi prima di un'istruzione e i commenti successivi ad essa
*/
void clean_string (char* s) {
	
	//Se la stringa e' vuota non ho niente da fare
	if (strlen (s) == 0) return;

	int i = 0;
	int found = 0;

	//Rimuovo \n
	if (s [strlen (s) - 1] == '\n')
		s [strlen (s) - 1] = '\0';

	//Rimuovo \r
	if (s [strlen (s) - 1] == '\r')
		s [strlen (s) - 1] = '\0';

	//Tolgo i commenti
	while (i < strlen(s) && found == 0) {
		if (s[i] == '/')
			found = 1;
		else
			i = i + 1;
	}

	if (found == 1)
		s[i] = '\0';

	//Tolgo spazi finali
	i = strlen(s) - 1;
	if (s[i] == ' ') {
		while (s[i] == ' ')
			i = i - 1;
		s[i + 1] = '\0';
	}
	
	//Tolgo gli spazi iniziali
	i = 0;
	found = 0;

	while (i < strlen(s) && found == 0) {
		if (s[i] != ' ' && s[i] != '\t')
			found = 1;
		else
			i = i + 1;
	}

	if (i != 0) {
		for (int k = 0; k <= strlen(s) - i; k++) {
			s[k] = s[k + i];
		}
	}
}

/* Precondizione: prende una stringa di un path di un file linux (quindi con '/' come separatore)
 * con estensione .vm
 *
 * Postcondizione: Ritorna un puntatore a char ad una stringa nell'heap dove è contenuto solo il nome
 * del file senza estensione e senza path assoluto
*/
char* estrai_nome (char* path) {
	int i;
	i = strlen (path) - 1;
	while (i >= 0 && path[i] != '/')
		i = i - 1;

	
	if (i != 0) //Per evitare di prendere il carattere '/' nel nome
		i = i + 1;

	char* name = (char*) malloc ( (strlen (path) - i) * sizeof (char));
	name[0] = '\0';
	
	ex_next_word (path, name, i);
	
	name [strlen (name) - 3] = '\0';		//Tolgo l'estensione al file (.vm)
	
	return (name);
}


/* Precondizone: s e' una stringa con abbastanza spazio per contenere le cifre di n
 *
 * Postcondizione: scrive in s il numero contenuto in n, ma convertito in stringa.
*/
void int_to_string (char* s, int n) {
	int dim;

	//Calcolo quante cifre ha il numero
	if (n == 0)
		dim = 1;
	else
		dim = my_log10 (n) + 1;
	
	int i = 0;
	int power = 1;

	for (i = 0; i < dim - 1; i++) power = power * 10;

	i = 0;

	while (power > 0) {
		char tmp = '0';

		tmp = tmp + (n / power);
		n = n % power;
		power = power / 10;

		s[i] = tmp;
		i = i + 1;
	}

	s[dim] = '\0';
}

/* Precondizione: s è una stringa che dalla posizione pos contiene una parole e d e' 
 * una stringa abbastanza lunga da contenere quella parola.
 *
 * Postcondizione: Estrapola la parola in s subito successiva alla posizione pos e la
 * copia nella strina d
*/
void ex_next_word (char* s, char* d, int pos) {
	int j = 0;
	
	if (s[pos] == ' ') {
		pos = pos + 1;
	}

	while (s[pos] != ' ' && pos < strlen (s)) {
		d[j] = s[pos];
		pos = pos + 1;
		j = j + 1;
	}
	d[j] = '\0';
}
