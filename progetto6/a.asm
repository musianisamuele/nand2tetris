push constant 7
call FibonacciElement.fibonacci 1   
label WHILE
goto WHILE              
function FibonacciElement.fibonacci 0
push argument 0
push constant 2
lt                     
if-goto IF_TRUE
goto IF_FALSE
label IF_TRUE          
push argument 0        
return
label IF_FALSE         
push argument 0
push constant 2
sub
call FibonacciElement.fibonacci 1  
push argument 0
push constant 1
sub
call FibonacciElement.fibonacci 1  
add                    
return
