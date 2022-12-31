#include "global.h"

struct lista {
	char* val;
	int instruction_type;
	struct lista* next;
};


//Precondizione: Prende un puntatore ad un lista, e i valori che devono
//esere inseriti ed esegue una head insert sulla lista.
//
//Postcondizione: Ritorna un puntatore alla lista con il nuovo elemento inserito

plista insert (plista h, char* val, int instruction_type) {
	plista tmp = (plista) malloc (sizeof (struct lista));

	//Alloco dinamicamente la grandezza di val in modo da risparmiare spazio
	tmp->val = (char*) malloc ((strlen(val) + 1 ) * sizeof(char));
	strcpy (tmp->val, val);
	tmp->instruction_type = instruction_type;
	tmp->next = h;
	return (tmp);
}


//Precondizione: Prende un puntatore ad una lista e una stringa e controlla
//che la stringa sia contenuta nella lista.
//
//Postcondizione: Se trova la stringa presa in input restituisce il relativo
//valore dell'istruzione ad essa associata associata (instruction_type), se no ritorna -1;

int get_type (plista h, char* val) {
	if (h == NULL)
		return (-1);		//L'istruzione non è stata trovata o la lista è vuota
	else {
		if (strcmp (h->val, val) == 0)
			return (h->instruction_type);
		else
			return (get_type (h->next, val));
	}
}

//Precondizione: Prende un puntatore ad una lista.
//
//Postcondizione: Restituisce una lista in cui sono inseriti tutti i 
//comandi che la VM puo' gestire insieme al loro tipo:
//		0 -> arithm
//		1 -> memory
//		2 -> program
//		3 -> function

plista insert_predefined (plista h) {
	char val[10];
	int instruction_type;

	val[0] = '\0';
	instruction_type = 0;

	strcpy (val, "add");
	h = insert (h, val, instruction_type);
	strcpy (val, "sub");
	h = insert (h, val, instruction_type);
	strcpy (val, "neg");
	h = insert (h, val, instruction_type);

	strcpy (val, "eq");
	h = insert (h, val, instruction_type);
	strcpy (val, "gt");
	h = insert (h, val, instruction_type);
	strcpy (val, "lt");
	h = insert (h, val, instruction_type);
	strcpy (val, "and");
	h = insert (h, val, instruction_type);
	strcpy (val, "or");
	h = insert (h, val, instruction_type);
	strcpy (val, "not");
	h = insert (h, val, instruction_type);

	val[0] = '\0';
	instruction_type = 1;
	
	strcpy (val, "push");
	h = insert (h, val, instruction_type);
	strcpy (val, "pop");
	h = insert (h, val, instruction_type);

	val[0] = '\0';
	instruction_type = 2;
	
	strcpy (val, "label");
	h = insert (h, val, instruction_type);
	strcpy (val, "goto");
	h = insert (h, val, instruction_type);
	strcpy (val, "if-goto");
	h = insert (h, val, instruction_type);

	val[0] = '\0';
	instruction_type = 3;
	
	strcpy (val, "function");
	h = insert (h, val, instruction_type);
	strcpy (val, "call");
	h = insert (h, val, instruction_type);
	strcpy (val, "return");
	h = insert (h, val, instruction_type);
	
	return (h);
}

/* ------------------------------ NUOVO ------------------------------ */    

plistaf insert_function (plistaf h, char* name, plistas val) {
	if (h == NULL) {
		h = malloc ( sizeof (struct lista_function) );
		h->name = malloc ( (strlen (name) + 1) * sizeof (char));
		strcpy (h->name, name);

		h->val = val;
		h->translated = 0;
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
	else if ( strcmp (h->name, name) == 0 ) {
		h->translated = 1;
		return h->val;
	}
	else return (get_function_body (h->next, name));
}

int is_already_translated (plistaf f, char* name) {
	if (f == NULL) return -1;
	else if ( strcmp (f->name, name) == 0 ) return (f->translated);
	else return (is_already_translated (f->next, name));
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
