org 100h

mov ah, 9
mov dx, offset str2
int 21h            
mov dx, offset str1
int 21h  
mov ah, 2
mov dl, 0DH
int 21h    
mov dl, 0AH
int 21h    

lea si, str1
lea di, cnst  
mov al, [di]

loop1:    
mov ah, [si]
inc si
cmp ah, al   
jz consonants
cmp ah, '$'
jz incvwl 
jmp loop1

incvwl:
inc di
mov al, [di]   
lea si, str1
cmp al, '$' 
jz output
jmp loop1

output:
mov ah, 9
mov dx, offset str3
int 21h
mov ah, 2
mov dl, count  
add dl, '0'
int 21h
jmp exit

consonants:       
inc count
jmp loop1

exit:
ret

str1 db "habijabi$" 
str2 db "Given string is: $"
str3 db "Total number of consonants are: $"          
cnst db "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ$"
count db 0


