#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

	/* LISTE */

struct string_list;
typedef struct string_list* plistas;

struct lista_function;
typedef struct lista_function* plistaf;

plistaf insert_function (plistaf h, char* name, plistas val);
plistas insert_instruction (plistas h, char* val); 
plistaf remove_function (plistaf h); 
void print_lista (plistaf h); 

	/* DIR */

void read_dir (char* path); 
plistaf get_functions_from_file (plistaf list_of_function, char* path);
plistas get_code_from_main (char* path);
int is_a_dir (char* s);
void genera_path_to_file (char* d, char* s1, char* s2); 
int is_a_function (char* s); 
int get_function_name (char* d, char* s); 

	/* TRANSLATER	*/

void multi_file_translater (plistas main_code, plistaf functions);
