#include "global.h"



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

plista insert_predefined_ARITHM (plista ARITHM) {
	char* val = (char*) malloc (4 * sizeof(char));	
	val[0] = '\0';

	strcpy (val, "add");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "sub");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "neq");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "eq");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "gt");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "lt");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "and");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "or");
	ARITHM = insert (ARITHM, val, val);
	strcpy (val, "not");
	ARITHM = insert (ARITHM, val, val);
	return (ARITHM);
}

plista insert_predefined_MEMORY (plista MEMORY) {
	char* val = (char*) malloc (5 * sizeof(char));	
	val[0] = '\0';

	strcpy (val, "push");
	MEMORY = insert (MEMORY, val, val);
	strcpy (val, "pop");
	MEMORY = insert (MEMORY, val, val);
	return (MEMORY);
}

plista insert_predefined_PROGRAM (plista PROGRAM) {
	char* val = (char*) malloc (8 * sizeof(char));	
	val[0] = '\0';

	strcpy (val, "label");
	PROGRAM = insert (PROGRAM, val, val);
	strcpy (val, "goto");
	PROGRAM = insert (PROGRAM, val, val);
	strcpy (val, "if-goto");
	PROGRAM = insert (PROGRAM, val, val);
	return (PROGRAM);
}

plista insert_predefined_FUNCTION (plista FUNCTION) {
	char* val = (char*) malloc (9 * sizeof(char));	
	val[0] = '\0';

	strcpy (val, "function");
	FUNCTION = insert (FUNCTION, val, val);
	strcpy (val, "call");
	FUNCTION = insert (FUNCTION, val, val);
	strcpy (val, "return");
	FUNCTION = insert (FUNCTION, val, val);
	return (FUNCTION);
}
