org 100h

MOV ah, 1 
int 21h 
sub al, '0'
mov bl, al     
int 21h 
sub al, '0'
mov bh, al
int 21h 
sub al, '0'
mov cl, al 
cmp bh, bl
jl bhcl
cmp bl, cl
jl blmin

bhcl:
cmp bh, cl
jl bhmin
jmp clmin

blmin:
mov min, bl 
jmp exit
bhmin:
mov min, bh 
jmp exit
clmin:
mov min, cl  

exit:
ret   

min db ?




