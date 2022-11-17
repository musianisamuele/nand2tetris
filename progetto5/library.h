#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int traduci_file (FILE* fileI, FILE* fileO);

// 0 -> A
// 1 -> C
// 2 -> Labels
// 3 -> Commento
// -1 -> Errore
int detect_instruction_type (char I[]);

