
//Inizializzazione
@258
D=A
@SP
M=D

//Aggiungo allo stack due numeri
@69
D=A
@256
M=D
@69
D=A
@257
M=D

//Provo l'uguaglianza
@SP
M=M-1
A=M
D=M
A=A-1
D=M-D
@TRUE_N							//Devo indicizzare bene in base al programma
D;JEQ

@SP
A=M-1;
M=0;
@END_N
0;JMP

(TRUE_N)
@SP
A=M-1
M=-1;
@END_N
0;JMP

(END_N)




(LOOP)
@LOOP
0;JMP


