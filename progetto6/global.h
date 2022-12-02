#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	char* val;
	char* translated;
	struct lista* next;
};
typedef struct lista* plista;

void traduci (FILE* fileI, FILE* fileO);
void clean_string (char* s);
	
int detect_instruction (char* I);

	/* LISTE */

plista insert (plista h, char* val, char* translated); 
int is_in (plista h, char* val); 
char* get_val (plista h, char* val); 
plista insert_predefined_ARITHM (plista ARITHM); 
plista insert_predefined_MEMORY (plista MEMORY); 
plista insert_predefined_PROGRAM (plista PROGRAM); 
plista insert_predefined_FUNCTION (plista FUNCTION); 
