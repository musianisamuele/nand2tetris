// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/08/FunctionCalls/FibonacciElement/FibonacciElement.tst

// FibonacciElement.asm is the result of translating both Main.vm and Sys.vm.

load test0.asm,
output-file test0.out,
//compare-to FibonacciElement.cmp,
output-list RAM[0]%D1.6.1 RAM[256]%D1.6.1;

repeat 10000000 {
  ticktock;
}

output;
