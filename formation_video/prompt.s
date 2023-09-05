bits 64

STDOUT: equ 1
STDIN: equ 0

section .data
	message: db "What's your name ? "
	message_len: equ $ - message
	username_max_len: equ 11

section .bss
	username: resb username_max_len

section .text
	global _start
	_start:
	; Demande de saisie
		mov rax, 1
		mov rdi, STDOUT
		mov rsi, message
		mov rdx, message_len
		syscall

	; Lecture au clavier
		mov rax, 0
		mov rdi, STDIN
		mov rsi, username
		mov rdx, username_max_len
		syscall

	; Affichage de la saisie
		mov rax, 1
		mov rdi, STDOUT
		mov rsi, username
		mov rdx, username_max_len
		syscall

	; quitte le programme
		mov rax, 60
		xor rdi, rdi
		syscall
