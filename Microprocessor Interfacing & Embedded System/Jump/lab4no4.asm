org 100h

mov ah, 1 
int 21h
add al, 20h
mov ah, 2
mov dl, al
int 21h

ret




