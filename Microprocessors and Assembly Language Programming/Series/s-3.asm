
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

lea si,arr1
mov [si],1
inc si

mov cx,9
loop1:
mov al,[si-1]
add al,2
mov [si],al
inc si
loop loop1

lea si,arr1
mov al,[si]
inc si
mov cx,9
loop2:
mov bl,[si]
add al,bl
inc si
loop loop2
mov sum,al

ret

arr1 db 10 dup (0)
sum db 0


