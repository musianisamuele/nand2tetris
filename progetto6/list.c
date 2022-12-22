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
