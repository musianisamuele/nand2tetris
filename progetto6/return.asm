@256
D=A
@SP
M=D
@1
D=A
@SP
M=M+1
A=M-1
M=D
@1
D=A
@SP
M=M+1
A=M-1
M=D
@2
D=A
@SP
M=M+1
A=M-1
M=D
@2
D=A
@SP
M=M+1
A=M-1
M=D
@999
D=A
@SP
M=M+1
A=M-1
M=D
@300
D=A
@SP
M=M+1
A=M-1
M=D
@400
D=A
@SP
M=M+1
A=M-1
M=D
@500
D=A
@SP
M=M+1
A=M-1
M=D
@600
D=A
@SP
M=M+1
A=M-1
M=D
@3
D=A
@SP
M=M+1
A=M-1
M=D
@3
D=A
@SP
M=M+1
A=M-1
M=D
@555
D=A
@SP
M=M+1
A=M-1
M=D

@258
D=A
@ARG
M=D

@265
D=A
@LCL
M=D

@777

@SP
A=M-1				//Punto alla return-value
D=M					//Salvo la ret-value in D
@ARG
A=M
M=D					//Salvo la return-value nel primo posto di argument (è giusto?)

D=A+1				//Inizializzazione di SP
@SP
M=D

@LCL				//Implementazione di FRAME su R14
D=M
@R14
AM=D-1			//A = M[R14] = M[LCL] - 1

//A punta a LCL - 1

D=M
@THAT
M=D

@R14
AM=M-1
D=M
@THIS
M=D

@R14
AM=M-1
D=M
@ARG
M=D

@R14
AM=M-1
D=M
@LCL
M=D

@R14
AM=M-1
A=M
0;JMP


