#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista;
typedef struct lista* plista;

void traduci (FILE* fileI, FILE* fileO);
void clean_string (char* s);
