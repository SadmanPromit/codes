org 100h

mov ah,1
int 21h
mov char, al 

cmp char, 61h
jl upper 

lower: 
mov ah, 9
mov dx, offset msg2
int 21h  
jmp exit

upper:
mov ah, 9
mov dx, offset msg1
int 21h
jmp exit 
         
exit:
ret

char db ?
msg1 db 'Upper case.$'
msg2 db 'Lower case.$'


