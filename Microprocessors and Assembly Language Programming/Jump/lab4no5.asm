org 100h

mov ah, 1
int 21h 
mov bl, 2
div bl
cmp ah, 0
jz even
mov ah, 9
mov dx, offset msg2  
int 21h
jmp exit

even:
mov ah, 9
mov dx, offset msg1  
int 21h

exit:
ret

msg1 db "The number is even.$"
msg2 db "The number is odd.$"


