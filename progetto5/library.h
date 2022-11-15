#include <stdio.h>
#include <string.h>


int traduci_file (FILE* fileI, FILE* fileO);

// 0 -> A
// 1 -> C
// 2 -> Commento
// -1 -> Errore
int detect_instruction_type (char I[]);


