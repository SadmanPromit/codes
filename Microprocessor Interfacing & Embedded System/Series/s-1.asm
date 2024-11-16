
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

lea si,arr1
mov [si],1
inc si

mov cx,49
loop1:
mov al,[si-1]
add al,2
mov [si],al
inc si
loop loop1


mov al,[si-1]
mov temp,al


ret


arr1 db 50 dup (0)
temp db 0
