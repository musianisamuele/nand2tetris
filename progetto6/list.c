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
	
	char* translated = (char*) malloc (1000 * sizeof (char));
	translated[0] = '\0';

	strcpy (val, "add");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=D+M");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "sub");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=M-D");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "neg");
	strcpy (translated, "@SP\nA=M-1\nM=-M");
	ARITHM = insert (ARITHM, val, translated);

	strcpy (val, "eq");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nD=M-D\n@TRUE_N\nD;JEQ\n@SP\nA=M-1\nM=0\n@END_N\n0;JMP\n(TRUE_N)\n@SP\nA=M-1\nM=-1\n@END_N\n0;JMP\n(END_N)");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "gt");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nD=M-D\n@TRUE_N\nD;JGT\n@SP\nA=M-1\nM=0\n@END_N\n0;JMP\n(TRUE_N)\n@SP\nA=M-1\nM=-1\n@END_N\n0;JMP\n(END_N)");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "lt");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nD=M-D\n@TRUE_N\nD;JLT\n@SP\nA=M-1\nM=0\n@END_N\n0;JMP\n(TRUE_N)\n@SP\nA=M-1\nM=-1\n@END_N\n0;JMP\n(END_N)");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "and");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=D&M");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "or");
	strcpy (translated, "@SP\nM=M-1\nA=M\nD=M\nA=A-1\nM=D|M");
	ARITHM = insert (ARITHM, val, translated);
	strcpy (val, "not");
	strcpy (translated, "@SP\nA=M-1\nM=!M");
	ARITHM = insert (ARITHM, val, translated);
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
