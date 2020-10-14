section .data
msg1 db "Enter First 8 bit HEX no: ",10
len1: equ $ -msg1
msg2 db "Enter Second 8 bit HEX no: ",10
len2: equ $ -msg2
msg3 db "Multiplication of two HEX no is: ",10
len3: equ $ -msg3

section .bss

arr1 resb 3
arr2 resb 3
arr3 resb 4
 %macro disp 2
mov rax,01h
mov rdi,01h
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro inn 2
mov rax,00h
mov rdi,00h
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
global _start
_start:

disp msg1,len1
inn arr1,03
disp msg2,len2
inn arr2,03

mov rsi,arr1
mov cl,04
xor bx,bx
mov ch,02
up:
cmp byte[rsi],39h
jng sk
sub byte[rsi],07h
sk:
sub byte[rsi],30h
shl bx,cl
add bl,[rsi]
inc rsi
dec ch
jnz up

xor dx,dx
mov rsi,arr2
mov cl,04
mov ch,02
up1:
cmp byte[rsi],39h
jng sk1
sub byte[rsi],07h
sk1:
sub byte[rsi],30h
shl dx,cl
add dl,[rsi]

inc rsi
dec ch
jnz up1

xor ax,ax
xor cl,cl
cmp dl,bl
jng sph
mov cl,bl
mov bl,dl
jmp outt
sph:
mov cl,dl
outt:
add ax,bx
dec cl
jnz outt

mov rsi,arr3
mov ch,04
mov cl,04
again1:
rol ax,cl
mov bl,al
and bl,0fh
cmp bl,09h
jng skip2
add bl,07h
skip2:
add bl,30h
mov [rsi],bl
inc rsi
dec ch
jnz again1

disp msg3,len3
disp arr3,04

mov rax,3ch
mov rdi,00
syscall
