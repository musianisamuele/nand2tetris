// Script per fare test

load OSPONG,
output-file OSPONG.out,

set RAM[0] 256,

output-list line%S1.20.1
						RAM[0]%D1.6.1
						RAM[1]%D1.6.1
						RAM[2]%D1.6.1
						RAM[3]%D1.6.1
						RAM[4]%D1.6.1
						argument[0]%D1.6.1
						argument[1]%D1.6.1
						local[0]%D1.6.1
						local[1]%D1.6.1
						local[2]%D1.6.1
						local[3]%D1.6.1
						local[4]%D1.6.1;

repeat 110000 {
	vmstep;
	output;
}
