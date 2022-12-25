#include "global.h"



plistaf insert_function (plistaf h, char* name, plistas val) {
	if (h == NULL) {
		h = malloc ( sizeof (struct lista_function) );
		h->name = malloc ( (strlen (name) + 1) * sizeof (char));
		strcpy (h->name, name);

		h->val = val;
		h->next = NULL;
		return h;
	} else {
		h->next = insert_function (h->next, name, val);
		return h;
	}
}

plistas insert_instruction (plistas h, char* val) {
	if (h == NULL) {
		h = malloc ( sizeof (struct string_list) );
		h->val = (char*) malloc ( (strlen (val) + 1) * sizeof (char) );
		strcpy (h->val, val);
		
		h->next = NULL;

		return h;
	} else {
		h->next = insert_instruction (h->next, val);
		return h;
	}
}

//Rimuove la testa
plistas remove_function (plistas h) {
	if (h == NULL) return NULL;
	else {
		plistas tmp = h->next;
		free (h);
		return tmp;
	}
}

//Funzione che faccio solo per avere una pulizia dei nomi
plistas tail_insert (plistas s, char* val) {
	return ( insert_instruction (s, val) );
}

plistas get_function_body (plistaf h, char* name) {
	if (h == NULL) return NULL;
	else if ( strcmp (h->name, name) == 0 ) return h->val;
	else return (get_function_body (h->next, name));
}

void print_lista_string (plistas h) {
	while (h != NULL) {
		printf ("\t%s", h->val);
		h = h->next;
	}

	printf ("NULL\n");
}

void print_lista (plistaf h) {
	while (h != NULL) {
		printf ("%s->\n", h->name);
		print_lista_string (h->val);
		h = h->next;
	}

	printf ("NULL\n");
}
