org 100h
mov al,a
mov bl,b
cmp al,bl
jl print
mov ah,9
mov dx,offset msg2
int 21h
jmp finish
print:
mov ah,9
mov dx,offset msg1
int 21h
jmp finish
finish:
ret
a db 3
b db 5
msg1 db "5 is greater than 3 $"
msg2 db "3 is greater than 5 $"