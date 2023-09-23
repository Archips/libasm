bits 64

STDOUT: equ 1
SYS_EXIT: equ 60
SYS_WRITE: equ 1

section .data
	nb1: dq 5
	nb2: dq 9
	equality_res: db "nb1 equals nb2", 10
	equality_res_len: equ $ - equality_res
	inequality_res: db "nb1 does not equal nb2", 10
	inequality_res_len: equ $ - inequality_res	

section .text
	global _start
	_start:

		mov rax, [nb1]
		mov rbx, [nb2]
		cmp rax, rbx
		je equals
		jne not_equals

		equals:
			mov rax, SYS_WRITE
			mov rdi, STDOUT
			mov rsi, equality_res
			mov rdx, equality_res_len
			syscall
			jmp exit

		not_equals:
			mov rax, SYS_WRITE
			mov rdi, STDOUT
			mov rsi, inequality_res
			mov rdx, inequality_res_len
			syscall
			jmp exit

		exit:
			;quitter le programme
			mov rax, SYS_EXIT
			mov rdi, 0
			syscall

