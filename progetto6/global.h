#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* file_name;

struct lista {
	char* val;
	char* translated;
	struct lista* next;
};
typedef struct lista* plista;

void traduci (FILE* fileI, FILE* fileO);
void clean_string (char* s);
char* estrai_nome (char* path);
void insert_in_string (char* s, char* in, int pos);
int my_log10 (int n);
void int_to_string (char s[], int n);
	
int detect_instruction (char* I);
void traduci_arithm (char* I, char* O);
void traduci_memory (char* I, char* O);

	/* LISTE */

plista insert (plista h, char* val, char* translated); 
int is_in (plista h, char* val); 
char* get_val (plista h, char* val); 
plista insert_predefined_ARITHM (plista ARITHM); 
plista insert_predefined_MEMORY (plista MEMORY); 
plista insert_predefined_PROGRAM (plista PROGRAM); 
plista insert_predefined_FUNCTION (plista FUNCTION); 
