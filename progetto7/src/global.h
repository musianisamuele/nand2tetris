#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista;
typedef struct lista* plista;

#define MAX_INST_LEN 2000

#define ROUTINE_OF_RETURN "ROUTINE_OF_RETURN"
#define ROUTINE_OF_CALL "ROUTINE_OF_CALL"

//VARIABILI GLOBALI
extern plista list_of_command;
extern int JMP_counter; 					
extern char* file_name;						
extern char function_name [400]; 	
extern int index_return;	

	/* LIBRARY */

void traduci (FILE* fileI, FILE* fileO);
int my_log10 (int n);


	/* TRANSLATER */

int detect_instruction (char* I);
void translate_instruction_of_type_arithm (char* I, char* O);
void translate_instruction_of_type_memory (char* I, char* O);
void translate_instruction_of_type_program (char* I, char* O);
void translate_instruction_of_type_function (char* I, char* O);
void get_routine_of_return (char* O);
void get_routine_of_call (char* O);


	/* LISTE */

plista insert (plista h, char* val, int instruction_type); 
int get_type (plista h, char* val); 
plista insert_predefined (plista h); 


	/* STRINGE */

void clean_string (char* s);
char* estrai_nome (char* path);
void int_to_string (char s[], int n);
void ex_next_word (char* s, char* d, int pos);
