@256
D=A
@SP
M=D
(Keyboard.init)
@0
D=A
@SP
M=M+D
A=M-D
@0
D=A
@SP
M=M+1
A=M-1
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
D=A+1
@SP
M=D
@LCL
D=M
@R14
AM=D-1
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
(Keyboard.keyPressed)
@0
D=A
@SP
M=M+D
A=M-D
@24576
D=A
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.keyPressed:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@Memory.peek
0;JMP
(Keyboard.keyPressed:return0)

@SP
A=M-1
D=M
@ARG
A=M
M=D
D=A+1
@SP
M=D
@LCL
D=M
@R14
AM=D-1
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
(Keyboard.readChar)
@2
D=A
@SP
M=M+D
A=M-D
M=0
A=A+1
M=0
A=A+1
@0
D=A
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readChar:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@Output.printChar
0;JMP
(Keyboard.readChar:return0)

@0
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
(Keyboard.readChar$WHILE_EXP0)
@1
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@0
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
A=A-1
D=M-D
@TRUE0
D;JEQ
@SP
A=M-1
M=0
@END0
0;JMP
(TRUE0)
@SP
A=M-1
M=-1
@END0
0;JMP
(END0)
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@0
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
A=A-1
D=M-D
@TRUE1
D;JGT
@SP
A=M-1
M=0
@END1
0;JMP
(TRUE1)
@SP
A=M-1
M=-1
@END1
0;JMP
(END1)
@SP
M=M-1
A=M
D=M
A=A-1
M=D|M
@SP
A=M-1
M=!M
@SP
M=M-1
A=M
D=M
@Keyboard.readChar$WHILE_END0
D;JNE
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readChar:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@0
D=A
@R14
D=M-D
@ARG
M=D
@Keyboard.keyPressed
0;JMP
(Keyboard.readChar:return1)

@0
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@0
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
A=A-1
D=M-D
@TRUE2
D;JGT
@SP
A=M-1
M=0
@END2
0;JMP
(TRUE2)
@SP
A=M-1
M=-1
@END2
0;JMP
(END2)
@SP
M=M-1
A=M
D=M
@Keyboard.readChar$IF_TRUE0
D;JNE
@Keyboard.readChar$IF_FALSE0
0;JMP
(Keyboard.readChar$IF_TRUE0)
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@1
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
(Keyboard.readChar$IF_FALSE0)
@Keyboard.readChar$WHILE_EXP0
0;JMP
(Keyboard.readChar$WHILE_END0)
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readChar:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@0
D=A
@R14
D=M-D
@ARG
M=D
@String.backSpace
0;JMP
(Keyboard.readChar:return2)

@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readChar:return3
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@Output.printChar
0;JMP
(Keyboard.readChar:return3)

@0
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@1
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readChar:return4
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@Output.printChar
0;JMP
(Keyboard.readChar:return4)

@0
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@1
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
D=A+1
@SP
M=D
@LCL
D=M
@R14
AM=D-1
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
(Keyboard.readLine)
@5
D=A
@SP
M=M+D
A=M-D
M=0
A=A+1
M=0
A=A+1
M=0
A=A+1
M=0
A=A+1
M=0
A=A+1
@80
D=A
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@String.new
0;JMP
(Keyboard.readLine:return0)

@3
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@0
D=A
@ARG
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@Output.printString
0;JMP
(Keyboard.readLine:return1)

@0
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@0
D=A
@R14
D=M-D
@ARG
M=D
@String.newLine
0;JMP
(Keyboard.readLine:return2)

@1
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return3
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@0
D=A
@R14
D=M-D
@ARG
M=D
@String.backSpace
0;JMP
(Keyboard.readLine:return3)

@2
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
(Keyboard.readLine$WHILE_EXP0)
@4
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
A=M-1
M=!M
@SP
A=M-1
M=!M
@SP
M=M-1
A=M
D=M
@Keyboard.readLine$WHILE_END0
D;JNE
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return4
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@0
D=A
@R14
D=M-D
@ARG
M=D
@Keyboard.readChar
0;JMP
(Keyboard.readLine:return4)

@0
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@1
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
A=A-1
D=M-D
@TRUE3
D;JEQ
@SP
A=M-1
M=0
@END3
0;JMP
(TRUE3)
@SP
A=M-1
M=-1
@END3
0;JMP
(END3)
@4
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@4
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
A=M-1
M=!M
@SP
M=M-1
A=M
D=M
@Keyboard.readLine$IF_TRUE0
D;JNE
@Keyboard.readLine$IF_FALSE0
0;JMP
(Keyboard.readLine$IF_TRUE0)
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@2
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
A=A-1
D=M-D
@TRUE4
D;JEQ
@SP
A=M-1
M=0
@END4
0;JMP
(TRUE4)
@SP
A=M-1
M=-1
@END4
0;JMP
(END4)
@SP
M=M-1
A=M
D=M
@Keyboard.readLine$IF_TRUE1
D;JNE
@Keyboard.readLine$IF_FALSE1
0;JMP
(Keyboard.readLine$IF_TRUE1)
@3
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return5
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@String.eraseLastChar
0;JMP
(Keyboard.readLine:return5)

@0
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@Keyboard.readLine$IF_END1
0;JMP
(Keyboard.readLine$IF_FALSE1)
@3
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readLine:return6
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@2
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(Keyboard.readLine:return6)

@3
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
(Keyboard.readLine$IF_END1)
(Keyboard.readLine$IF_FALSE0)
@Keyboard.readLine$WHILE_EXP0
0;JMP
(Keyboard.readLine$WHILE_END0)
@3
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
D=A+1
@SP
M=D
@LCL
D=M
@R14
AM=D-1
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
(Keyboard.readInt)
@2
D=A
@SP
M=M+D
A=M-D
M=0
A=A+1
M=0
A=A+1
@0
D=A
@ARG
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readInt:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@Keyboard.readLine
0;JMP
(Keyboard.readInt:return0)

@0
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readInt:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@String.intValue
0;JMP
(Keyboard.readInt:return1)

@1
D=A
@LCL
D=D+M
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@0
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@5
D=A
@SP
M=M+D
D=M-1
@R14
M=D
@THAT
D=M
@R14
A=M
M=D
@THIS
D=M
@R14
AM=M-1
M=D
@ARG
D=M
@R14
AM=M-1
M=D
@LCL
D=M
@R14
AM=M-1
M=D
@Keyboard.readInt:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@1
D=A
@R14
D=M-D
@ARG
M=D
@String.dispose
0;JMP
(Keyboard.readInt:return2)

@0
D=A
@R13
M=D
@SP
M=M-1
A=M
D=M
@R13
A=M
M=D
@1
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@SP
A=M-1
D=M
@ARG
A=M
M=D
D=A+1
@SP
M=D
@LCL
D=M
@R14
AM=D-1
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
