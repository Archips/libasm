bits 64

STDOUT: equ 1
SYS_EXIT: equ 60
SYS_WRITE: equ 1

section .data
	message: db "Looping on GNU/LINUX", 10
	message_len: equ $ - message	

section .text
	global _start
	_start:

		;compteur
		mov rbx, 5

		loop_message:
			;affichage du message
			mov rax, SYS_WRITE
			mov rdi, STDOUT
			mov rsi, message
			mov rdx, message_len
			syscall

			;decrementation
			dec rbx
			jnz loop_message ;jnz stands for "Jump if not zero (ZF = 0)", and NOT "Jump if the ZF is set"

		;exit
		mov rax, SYS_EXIT
		mov rdi, 0
		syscall
