%macro disp 2	;display function decleration
mov rax,01h
mov rdi,01h
mov rsi ,%1
mov rdx,%2
syscall
%endmacro

%macro inn 2	;user input decleration
mov rax,00h
mov rdi,00h
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data	;data member decleration
msg1 db "Enter the 8 bit number:",0ah,0dh 
len1 equ $  -msg1

msg2 db "The factorial of given 8 bit number in HEX is:",0ah,0dh
len2 equ $  -msg2

msg3 db "The factorial for 0 or 1 is:",0ah,0dh
len3 equ $  -msg3

zeroonefact db "0001"
zeroonefactlen equ $-zeroonefact

section .bss
num resb 3
res resb 16

section .text
global _start
_start:

disp msg1, len1
inn num, 3
call accept

xor rax, rax	;clear rax register
mov ax,bx
cmp ax,01h		;check input 0 or 1
jbe onezero		;call function onezero if input is 0 or 1

call factorial	;factorial function call
call display	;display function call
mov rax,60
mov rdi,0
syscall			;end program


;function definitions
onezero:
disp msg3,  len3
disp zeroonefact,  zeroonefactlen

;exit:


accept:
       mov rsi,num
       mov cl,04
       xor rbx,rbx
       mov ch,02
       up:
       cmp byte[rsi],39h
       jng sk
       sub byte[rsi],07h
       sk:
       sub byte[rsi],30h
       rol bl,cl
       add bl,[rsi]
       inc rsi
       dec ch
       jnz up
ret

factorial:
 xor rbx, rbx
 mov rbx,rax
 up1:sub rbx ,01
 mul rbx
 cmp rbx,01
 jne up1
ret

display:
 mov rsi,res
 mov ch,16
 mov cl,04

 again1:
 rol rax,cl
 mov bl,al
 and bl,0fh
 cmp bl,09h
 jng skip2
 add bl,07h
 skip2:
 add bl, 30h
 mov [rsi],bl
 inc rsi
 dec ch
 jnz again1

 disp msg2, len2
 disp res, 16
ret
