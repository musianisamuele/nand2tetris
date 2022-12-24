#include "global.h"

struct string_list {
	char* val;
	struct string_list* next;
};

struct lista_function {
	char* name;
	struct string_list* val;
	struct lista_function* next;
};

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

plistaf remove_function (plistaf h) {
	if (h == NULL) return NULL;
	else {
		plistaf tmp = h->next;
		free (h);
		return tmp;
	}
}

void print_lista (plistaf h) {
	while (h != NULL) {
		printf ("%s->\n", h->name);
		h = h->next;
	}

	printf ("NULL\n");
}
