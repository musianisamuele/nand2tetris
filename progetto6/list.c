#include "global.h"

struct lista {
	char* val;
	char* translated;
	plista next;
};

plista insert (plista h, char* val, char* translated) {
	plista tmp = (plista) malloc (sizeof (struct lista));
	tmp->val = (char*) malloc ((strlen(val) + 1 ) * sizeof(char));
	strcpy (tmp->val, val);
	tmp->translated = (char*) malloc ((strlen(translated) + 1 ) * sizeof(char));
	strcpy (tmp->translated, translated);
	tmp->next = h;
	return (tmp);
}

int is_in (plista h, char* val) {
	if (h == NULL)
		return (0);		//false
	else {
		if (strcmp (h->val, val) == 0)
			return 1;
		else
			return (is_in (h->next, val));
	}
}

char* get_val (plista h, char* val) {
	if (h == NULL)
		return (NULL);		//false
	else {
		if (strcmp (h->val, val) == 0)
			return (h->val);
		else
			return (get_val (h->next, val));
	}
}

plista insert_predefined (plista h) {
	char* val = (char*) malloc (1000 * sizeof(char));
	val[0] = '\0';

	h = insert (h, val, NULL);
	return (h);
}
