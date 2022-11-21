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

#define MAX_LABEL 200

struct lista {
	char label[MAX_LABEL];
	int val;
	struct lista* next;
};

typedef struct lista* plista;


int traduci_file (FILE* fileI, FILE* fileO);

// 0 -> A
// 1 -> C
// 2 -> Labels
// 3 -> Commento
// -1 -> Errore
int detect_instruction_type (char I[]);

//Traduzione della A instruction contenuta in I e restituzione dell'output su O
plista traduci_A_instruction (char I[], char O[], plista LABELS, plista VARIABLES);

//Converte un numero decimale in una stringa binaria
void dec_to_stringBin (int n, char O[]);

//Traduzione della C instruction contenuta in I e restituzione dell'output su O
void traduci_C_instruction (char I[], char O[], coppiaS* CONV);

//Funzione che dati 4 puntatori ad array di coppiaS genere le tabelle di conversione
coppiaS* genera_conversioni ();

//Cerca la stringa f in s. Se la trova restituisce 1, altrimenti 0
int is_in_string (char s[], char f[], int a, int b);


plista get_labels (plista h, FILE* fileI);
void rimuovi_parentesi (char I[]);


/* FUNZIONI PER LE LISTE */

//Postcondition: Ritorna -1 se non trova L in h. Se lo trova invece ritorna il valore corrispondente 
int get_val (plista h, char L[]);

plista insert (plista h, char L[], int R);

void print_lista (plista h);

