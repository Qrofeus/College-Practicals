section .data

rmsg db 10, "Processor is in Real Mode"
rlen equ $ -rmsg

pmsg db 10, "Processor is in Protected Mode"
plen equ $ -pmsg

gdtmsg db 10, "GDT contents are:: "
glen equ $ -gdtmsg

ldtmsg db 10, "LDT contents are:: "
llen equ $ -ldtmsg

idtmsg db 10, "IDT contents are:: "
ilen equ $ -idtmsg

trmsg db 10, "TR contents are:: "
tlen equ $ -trmsg

mswmsg db 10, "Machine Status Word:: "
mlen equ $ -mswmsg

colon db ':'

nwline db 10

section .bss

gdt resd 1
	resw 1
ldt resw 1
idt resd 1
	resw 1
tr resw 1

cr0_data resd 1
dnum_buff resb 04

%macro disp 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
global _start
_start:
smsw rax
mov [cr0_data],rax
bt rax, 0
	jc prmode
	disp rmsg,rlen
	jmp nxt1
prmode:
	disp pmsg,plen
nxt1:
sgdt [gdt]
sldt [ldt]
sidt [idt]
str [tr]

disp gdtmsg,glen
mov bx,[gdt+4]
call disp_num
mov bx,[gdt+2]
call disp_num
disp colon,1
mov bx,[gdt]
call disp_num

disp ldtmsg,llen
mov bx,[ldt]
call disp_num

disp idtmsg,ilen
mov bx,[idt+4]
call disp_num
mov bx,[idt+2]
call disp_num
disp colon,1
mov bx,[idt]
call disp_num

disp trmsg,tlen
mov bx,[tr]
call disp_num

disp mswmsg,mlen
mov bx,[cr0_data+2]
call disp_num
mov bx,[cr0_data]
call disp_num

disp nwline,1

exit:
mov rax,01
mov rbx,60
syscall

disp_num:
	mov rsi,dnum_buff
	mov rcx,04
	up1:
		rol bx,04
		mov dl,bl
		and dl,0fh
		add dl,30h
		cmp dl,39h
		jbe skip1
		add dl,07h
	skip1:
		mov [rsi],dl
		inc rsi
		loop up1
	disp dnum_buff,4
	ret
