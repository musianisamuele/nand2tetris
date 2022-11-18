#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PAIR_STRING
#define PAIR_STRING

struct pair_string {
	char first[10];
	char second[10];
};

typedef struct pair_string coppiaS;

#endif


int traduci_file (FILE* fileI, FILE* fileO);

// 0 -> A
// 1 -> C
// 2 -> Labels
// 3 -> Commento
// -1 -> Errore
int detect_instruction_type (char I[]);

void traduci_A_instruction (char I[], char O[]);
void dec_to_stringBin (int n, char O[]);

void traduci_C_instruction (char I[], char O[]);

void genera_conversioni (coppiaS *COMP, coppiaS *DEST, coppiaS *JUMP);
