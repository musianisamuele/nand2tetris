#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <sys/types.h>		//Per le directories
#include <dirent.h>
int is_a_dir (char* s);
void genera_path_to_file (char* d, char* s1, char* s2); 
void read_file (char* path); 
void read_dir (char* path); 
