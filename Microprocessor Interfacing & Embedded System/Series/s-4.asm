org 100h

mov ah, 1
int 21h  
sub al, '0'
mov cl, al 
mov ch, 0 
lea si, arr1
mov [si], 1    
inc si 
dec cx  
mov dx, cx

loop1:
mov al, [si-1]
add al, 2
mov [si], al 
inc si        
loop loop1 

lea si, arr1
mov al, [si]   
mov bl, al
inc si 
mov cx, dx

loop2:
mov al, [si]
add bl, al  
inc si  
loop loop2   

mov sum, bl

ret

arr1 db 9 dub (?)
sum db ?


