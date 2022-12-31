#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

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
FILE* open_fileO (char* pathI);


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

/*------------------------------ NUOVO ------------------------------ */

	/* LISTE */

#ifndef DEF_string_list
#define DEF_string_list
struct string_list {
	char* val;
	struct string_list* next;
};
typedef struct string_list* plistas;
#endif


#ifndef DEF_string_function
#define DEF_string_function
struct lista_function {
	char* name;
	struct string_list* val;
	int translated;			//0 -> flase, 1 -> true
	struct lista_function* next;
};
typedef struct lista_function* plistaf;
#endif


plistaf insert_function (plistaf h, char* name, plistas val);
plistas insert_instruction (plistas h, char* val); 
plistas remove_function (plistas h); 
plistas tail_insert (plistas s, char* val);
plistas get_function_body (plistaf h, char* name);
int is_already_translated (plistaf f, char* name);
void print_lista_string (plistas h);
void print_lista (plistaf h); 

	/* DIR */

plistaf read_dir (char* path); 
plistaf get_functions_from_file (plistaf list_of_function, char* path);
plistas get_code_from_main (char* path);
int is_a_dir (char* s);
void genera_path_to_file (char* d, char* s1, char* s2); 
int is_a_function (char* s); 
int is_a_return (char* s);
void get_function_name (char* d, char* s); 

	/* TRANSLATER	*/

void multi_file_translater (plistaf functions, FILE* file);
plistas traduci_function (plistas funzione_corrente, plistas dependencies, FILE* file);
