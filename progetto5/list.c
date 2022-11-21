#include "library.h"
/* FUNZIONI PER LE LISTE */

//Postcondition: Ritorna -1 se non trova L in h. Se lo trova invece ritorna il valore corrispondente 
int get_val (plista h, char L[]) {
	int found;
	found = 0; //1 -> trovato

	while (h != NULL && found == 0) {
		if (strcmp (h->label, L) == 0)
			found = 1;
		else h = h->next;
	}

	if (found == 1)
		return (h->val);
	else
		return (-1);
}

plista insert (plista h, char L[], int R) {
	if (h == NULL) {
		h = (plista) malloc (sizeof (struct lista));
		strcpy(h->label, L);
		h->val = R;
	} else {
		plista tmp = h;

		while (tmp->next != NULL) tmp = tmp->next;

		tmp->next = (plista) malloc (sizeof (struct lista));
		tmp = tmp->next;

		strcpy(tmp->label, L);
		tmp->val = R;
		tmp->next = NULL;

	}
	return (h);
}

void print_lista (plista h) {
	while (h != NULL) {
		printf ("[%s, %d]->", h->label, h->val);
		h = h->next;
	}
	printf ("NULL\n");
}
