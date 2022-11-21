#include "library.h"

coppiaS* genera_conversioni () {

	coppiaS *p = (coppiaS*) malloc ((18 + 10 + 8 + 8) * sizeof (coppiaS));

	coppiaS *head = p;
		
	//COMP
	strcpy ((*p).first, "0"); strcpy ((*p).second, "0101010");		p++;
	strcpy ((*p).first, "1"); strcpy ((*p).second, "0111111"); 		p++;
	strcpy ((*p).first, "-1"); strcpy ((*p).second, "0111010");		p++;
	strcpy ((*p).first, "D"); strcpy ((*p).second, "0001100");		p++;
	strcpy ((*p).first, "A"); strcpy ((*p).second, "0110000");		p++;
	strcpy ((*p).first, "M"); strcpy ((*p).second, "1110000");		p++;
	strcpy ((*p).first, "!D"); strcpy ((*p).second, "0001101");		p++;
	strcpy ((*p).first, "!A"); strcpy ((*p).second, "0110001");		p++;
	strcpy ((*p).first, "!M"); strcpy ((*p).second, "1110001");		p++;
	strcpy ((*p).first, "-D"); strcpy ((*p).second, "0001111");		p++;
	strcpy ((*p).first, "-A"); strcpy ((*p).second, "0110011");		p++;
	strcpy ((*p).first, "D+1"); strcpy ((*p).second, "0011111");	p++;
	strcpy ((*p).first, "A+1"); strcpy ((*p).second, "0110111");	p++;
	strcpy ((*p).first, "M+1"); strcpy ((*p).second, "1110111");	p++;
	strcpy ((*p).first, "D-1"); strcpy ((*p).second, "0001110");	p++;
	strcpy ((*p).first, "A-1"); strcpy ((*p).second, "0110010");	p++;
	strcpy ((*p).first, "M-1"); strcpy ((*p).second, "1110010");	p++;
	strcpy ((*p).first, "D+A"); strcpy ((*p).second, "0000010");	p++;
	strcpy ((*p).first, "D-A"); strcpy ((*p).second, "0010011");	p++;
	strcpy ((*p).first, "A-D"); strcpy ((*p).second, "0000111");	p++;
	strcpy ((*p).first, "D&A"); strcpy ((*p).second, "0000000");	p++;
	strcpy ((*p).first, "D|A"); strcpy ((*p).second, "0010101"); 	p++;
	strcpy ((*p).first, "D+M"); strcpy ((*p).second, "1000010");	p++;
	strcpy ((*p).first, "D-M"); strcpy ((*p).second, "1010011");	p++;
	strcpy ((*p).first, "M-D"); strcpy ((*p).second, "1000111");	p++;
	strcpy ((*p).first, "D&M"); strcpy ((*p).second, "1000000");	p++;
	strcpy ((*p).first, "D|M"); strcpy ((*p).second, "1010101"); 	p++;

	//DEST

	strcpy ((*p).first, "null"); strcpy ((*p).second, "000");	p++;
	strcpy ((*p).first, "M"); strcpy ((*p).second, "001");		p++;
	strcpy ((*p).first, "D"); strcpy ((*p).second, "010");		p++;
	strcpy ((*p).first, "MD"); strcpy ((*p).second, "011");		p++;
	strcpy ((*p).first, "A"); strcpy ((*p).second, "100");		p++;
	strcpy ((*p).first, "AM"); strcpy ((*p).second, "101");		p++;
	strcpy ((*p).first, "AD"); strcpy ((*p).second, "110");		p++;
	strcpy ((*p).first, "AMD"); strcpy ((*p).second, "111");	p++;

	//JUMP

	strcpy ((*p).first, "null"); strcpy ((*p).second, "000");	p++;
	strcpy ((*p).first, "JGT"); strcpy ((*p).second, "001");	p++;
	strcpy ((*p).first, "JEQ"); strcpy ((*p).second, "010");	p++;
	strcpy ((*p).first, "JGE"); strcpy ((*p).second, "011");	p++;
	strcpy ((*p).first, "JLT"); strcpy ((*p).second, "100");	p++;
	strcpy ((*p).first, "JNE"); strcpy ((*p).second, "101");	p++;
	strcpy ((*p).first, "JLE"); strcpy ((*p).second, "110");	p++;
	strcpy ((*p).first, "JMP"); strcpy ((*p).second, "111");

	return (head);
}

plista predefined_labels (plista h) {
	char I[100];
	
	strcpy (I, "SP"); h = insert (h, I, 0);
	strcpy (I, "LCL"); h = insert (h, I, 1);
	strcpy (I, "ARG"); h = insert (h, I, 2);
	strcpy (I, "THIS"); h = insert (h, I, 3);
	strcpy (I, "THAT"); h = insert (h, I, 4);
	strcpy (I, "SCREEN"); h = insert (h, I, 16384);
	strcpy (I, "KDB"); h = insert (h, I, 24576);

	for (int i = 0; i <= 9; i++) {
		strcpy (I, "R");
		char N[2]; N[0] = (char) i + '0'; N[1] = '\0';

		strcat (I, N);
		h = insert (h, I, i);	
	}
	
	for (int i = 0; i <= 5; i++) {
		strcpy (I, "R");
		char N[3]; N[0] = '1'; N[1] = (char) i + '0'; N[2] = '\0';

		strcat (I, N);
		h = insert (h, I, i + 10);	
	}

	return (h);
}
