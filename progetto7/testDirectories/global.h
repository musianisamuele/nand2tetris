#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

	/* DIR */

int is_a_dir (char* s);
void genera_path_to_file (char* d, char* s1, char* s2); 
void read_file (char* path); 
void read_dir (char* path); 


	/* LISTE */

struct string_list;
typedef struct string_list* plistas;

struct lista_function;
typedef struct lista_function* plistaf;

plistaf insert_function (plistaf h, char* name, plistas val);
plistas insert_instruction (plistas h, char* val); 
plistaf remove_function (plistaf h); 
void print_lista (plistaf h); 
