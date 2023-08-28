global _start

section .text

_start: 
    MOV rax, 0x0
    MOV rdi, 0x0
    MOV rsi, msg
    MOV rdx, msglength
    SYSCALL

    MOV rax, 0x1
    MOV rdi, 0x1
    MOV rsi, msg
    MOV rdx, msglength
    SYSCALL


    MOV rax, 0x3C
    MOV rdi, 0x0
    SYSCALL

section .data
    msg: DB "Test"
    msglength: EQU 0x20
