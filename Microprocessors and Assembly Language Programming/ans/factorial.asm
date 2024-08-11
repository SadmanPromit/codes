org 100h

mov ah, 9
mov dx, offset str1
int 21h
mov ah, 1
int 21h
sub al, '0' 
mov bl, al
dec bl  

loop1:    
mul bl 
dec bl
cmp bl, 1
jnz loop1        
mov fac, al

mov ah, 2
mov dl, 0DH
int 21h    
mov dl, 0AH
int 21h 
mov ah, 9
mov dx, offset str2
int 21h
mov ah, 2   
add fac, '0'
mov dl, fac 
int 21h 
 
ret

str1 db "Enter the number: $"  
str2 db "The factorial of the given number is: $" 
fac db ?


