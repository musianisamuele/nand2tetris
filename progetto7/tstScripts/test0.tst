// Script per fare test

load test0.vm,
output-file test0.out,

set RAM[0] 256,

output-list RAM[256]%D1.6.1 RAM[257]%D1.6.1 RAM[258]%D1.6.1;
output;

repeat 10 {
	vmstep;
	output;
}
