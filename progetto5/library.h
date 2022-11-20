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

//Traduzione della A instruction contenuta in I e restituzione dell'output su O
void traduci_A_instruction (char I[], char O[]);

//Converte un numero decimale in una stringa binaria
void dec_to_stringBin (int n, char O[]);

//Traduzione della C instruction contenuta in I e restituzione dell'output su O
void traduci_C_instruction (char I[], char O[], coppiaS* CONV);

//Funzione che dati 4 puntatori ad array di coppiaS genere le tabelle di conversione
coppiaS* genera_conversioni ();

//Cerca la stringa f in s. Se la trova restituisce 1, altrimenti 0
int is_in_string (char s[], char f[], int a, int b);
