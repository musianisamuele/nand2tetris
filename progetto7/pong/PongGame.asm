@256
D=A
@SP
M=D
(PongGame.new)
@
D=A
@SP
M=M+D
A=M-D
@
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
@PongGame.new:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Memory.alloc
0;JMP
(PongGame.new:return0)

@
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
@PongGame.new:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Screen.clearScreen
0;JMP
(PongGame.new:return1)

@
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
M=M+1
A=M-1
M=D
@
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
@23
D=A
@SP
M=M+1
A=M-1
M=D
@22
D=A
@SP
M=M+1
A=M-1
M=D
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.new:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.new
0;JMP
(PongGame.new:return2)

@
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
@25
D=A
@SP
M=M+1
A=M-1
M=D
@22
D=A
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@51
D=A
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@22
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
@PongGame.new:return3
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.new
0;JMP
(PongGame.new:return3)

@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@40
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.new:return4
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.setDestination
0;JMP
(PongGame.new:return4)

@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
@23
D=A
@SP
M=M+1
A=M-1
M=D
@51
D=A
@SP
M=M+1
A=M-1
M=D
@24
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
@PongGame.new:return5
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Screen.drawRectangle
0;JMP
(PongGame.new:return5)

@
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
@2
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.new:return6
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Output.moveCursor
0;JMP
(PongGame.new:return6)

@
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
@
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
@PongGame.new:return7
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.new
0;JMP
(PongGame.new:return7)

@8
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
@PongGame.new:return8
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return8)

@9
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
@PongGame.new:return9
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return9)

@11
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
@PongGame.new:return10
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return10)

@11
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
@PongGame.new:return11
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return11)

@10
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
@PongGame.new:return12
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return12)

@5
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
@PongGame.new:return13
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return13)

@3
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
@PongGame.new:return14
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return14)

@4
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
@PongGame.new:return15
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.new:return15)

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
@PongGame.new:return16
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Output.printString
0;JMP
(PongGame.new:return16)

@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
(PongGame.dispose)
@
D=A
@SP
M=M+D
A=M-D
@
D=A
@ARG
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
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
@PongGame.dispose:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.dispose
0;JMP
(PongGame.dispose:return0)

@
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
@
D=A
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
@PongGame.dispose:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.dispose
0;JMP
(PongGame.dispose:return1)

@
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
@
D=A
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
@PongGame.dispose:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Memory.deAlloc
0;JMP
(PongGame.dispose:return2)

@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
(PongGame.newInstance)
@
D=A
@SP
M=M+D
A=M-D
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
@PongGame.newInstance:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@PongGame.new
0;JMP
(PongGame.newInstance:return0)

@PongGame.
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
@
D=A
@SP
M=M+1
A=M-1
M=D
(PongGame.getInstance)
@
D=A
@SP
M=M+D
A=M-D
@PongGame.
D=A
D=M
@SP
M=M+1
A=M-1
M=D
(PongGame.run)
@
D=A
@SP
M=M+D
A=M-D
@
D=A
@ARG
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
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
(PongGame.run$WHILE_EXP)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$WHILE_END
D;JNE
(PongGame.run$WHILE_EXP)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$WHILE_END
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
@PongGame.run:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Keyboard.keyPressed
0;JMP
(PongGame.run:return0)

@
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
@
D=A
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
@PongGame.run:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.move
0;JMP
(PongGame.run:return1)

@
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
@
D=A
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
@PongGame.run:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@PongGame.moveBall
0;JMP
(PongGame.run:return2)

@
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
@PongGame.run$WHILE_EXP
0;JMP
(PongGame.run$WHILE_END)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@13
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$IF_TRUE
D;JNE
@PongGame.run$IF_FALSE
0;JMP
(PongGame.run$IF_TRUE)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.run:return3
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.setDirection
0;JMP
(PongGame.run:return3)

@
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
@PongGame.run$IF_END
0;JMP
(PongGame.run$IF_FALSE)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@13
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$IF_TRUE
D;JNE
@PongGame.run$IF_FALSE
0;JMP
(PongGame.run$IF_TRUE)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.run:return4
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.setDirection
0;JMP
(PongGame.run:return4)

@
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
@PongGame.run$IF_END
0;JMP
(PongGame.run$IF_FALSE)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@14
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$IF_TRUE
D;JNE
@PongGame.run$IF_FALSE
0;JMP
(PongGame.run$IF_TRUE)
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
(PongGame.run$IF_FALSE)
(PongGame.run$IF_END)
(PongGame.run$IF_END)
(PongGame.run$WHILE_EXP)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$WHILE_END
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
@PongGame.run:return5
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Keyboard.keyPressed
0;JMP
(PongGame.run:return5)

@
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
@
D=A
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
@PongGame.run:return6
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.move
0;JMP
(PongGame.run:return6)

@
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
@
D=A
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
@PongGame.run:return7
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@PongGame.moveBall
0;JMP
(PongGame.run:return7)

@
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
@PongGame.run$WHILE_EXP
0;JMP
(PongGame.run$WHILE_END)
@PongGame.run$WHILE_EXP
0;JMP
(PongGame.run$WHILE_END)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.run$IF_TRUE
D;JNE
@PongGame.run$IF_FALSE
0;JMP
(PongGame.run$IF_TRUE)
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
@PongGame.run:return8
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Output.moveCursor
0;JMP
(PongGame.run:return8)

@
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
@
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
@PongGame.run:return9
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.new
0;JMP
(PongGame.run:return9)

@7
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
@PongGame.run:return10
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return10)

@9
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
@PongGame.run:return11
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return11)

@10
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
@PongGame.run:return12
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return12)

@10
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
@PongGame.run:return13
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return13)

@3
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
@PongGame.run:return14
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return14)

@7
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
@PongGame.run:return15
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return15)

@11
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
@PongGame.run:return16
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return16)

@10
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
@PongGame.run:return17
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return17)

@11
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
@PongGame.run:return18
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@String.appendChar
0;JMP
(PongGame.run:return18)

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
@PongGame.run:return19
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Output.printString
0;JMP
(PongGame.run:return19)

@
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
(PongGame.run$IF_FALSE)
@
D=A
@SP
M=M+1
A=M-1
M=D
(PongGame.moveBall)
@
D=A
@SP
M=M+D
A=M-D
@
D=A
@ARG
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
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
@PongGame.moveBall:return0
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.move
0;JMP
(PongGame.moveBall:return0)

@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.moveBall$IF_TRUE
D;JNE
@PongGame.moveBall$IF_FALSE
0;JMP
(PongGame.moveBall$IF_TRUE)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
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
@PongGame.moveBall:return1
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.getLeft
0;JMP
(PongGame.moveBall:return1)

@
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
@
D=A
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
@PongGame.moveBall:return2
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.getRight
0;JMP
(PongGame.moveBall:return2)

@
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
@
D=A
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
@PongGame.moveBall:return3
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.getLeft
0;JMP
(PongGame.moveBall:return3)

@
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
@
D=A
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
@PongGame.moveBall:return4
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.getRight
0;JMP
(PongGame.moveBall:return4)

@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.moveBall$IF_TRUE
D;JNE
@PongGame.moveBall$IF_FALSE
0;JMP
(PongGame.moveBall$IF_TRUE)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.moveBall$IF_TRUE
D;JNE
@PongGame.moveBall$IF_FALSE
0;JMP
(PongGame.moveBall$IF_TRUE)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.moveBall$IF_TRUE
D;JNE
@PongGame.moveBall$IF_FALSE
0;JMP
(PongGame.moveBall$IF_TRUE)
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.moveBall$IF_END
0;JMP
(PongGame.moveBall$IF_FALSE)
@
D=A
@LCL
A=D+M
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@SP
M=M+1
A=M-1
M=D
@SP
M=M-1
A=M
D=M
@PongGame.moveBall$IF_TRUE
D;JNE
@PongGame.moveBall$IF_FALSE
0;JMP
(PongGame.moveBall$IF_TRUE)
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
(PongGame.moveBall$IF_FALSE)
(PongGame.moveBall$IF_END)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
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
@PongGame.moveBall:return5
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Bat.setWidth
0;JMP
(PongGame.moveBall:return5)

@
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
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@2
D=A
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.moveBall:return6
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Output.moveCursor
0;JMP
(PongGame.moveBall:return6)

@
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
@
D=A
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
@PongGame.moveBall:return7
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Output.printInt
0;JMP
(PongGame.moveBall:return7)

@
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
(PongGame.moveBall$IF_FALSE)
(PongGame.moveBall$IF_FALSE)
@
D=A
D=M
@SP
M=M+1
A=M-1
M=D
@
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
@PongGame.moveBall:return8
D=A
@R14
AM=M-1
M=D
@SP
D=M
@LCL
M=D
@
D=A
@R14
D=M-D
@ARG
M=D
@Ball.bounce
0;JMP
(PongGame.moveBall:return8)

@
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
(PongGame.moveBall$IF_FALSE)
@
D=A
@SP
M=M+1
A=M-1
M=D
