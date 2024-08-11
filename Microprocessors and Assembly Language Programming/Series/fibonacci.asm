
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
; 


org 100h

lea si,arr1 
mov [si],0
inc si
mov [si],1
inc si

mov cx,8

loop1:
mov al,[si-1]
mov bl,[si-2]
add al,bl
mov [si],al
inc si
loop loop1


ret

arr1 db 10 dup (0)


