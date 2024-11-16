org 100h

lea si, arr1
mov [si], 3
inc si         
mov cx, 4

loop1:
mov al, [si-1]
add al, 5   
mov [si], al
inc si
loop loop1

ret  

arr1 db 5 dup (?)




