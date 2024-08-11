
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ah,1
int 21h
sub al,48

mov ch,0
mov cl,al 

lea si,arr1
mov [si],1
inc si
dec cx

loop1:
mov al,[si-1]
add al,2
mov [si],al
inc si
loop loop1



ret

arr1 db 9 dup (0)


