bits 64

global ft_strcmp

section .text
    ft_strcmp:
        mov rax, 0
        jmp loop

    less:
        neg rax
        mov rax, -1
        ret

    great:
        mov rax, 1
        ret

    equal:
        mov rax, 0
        ret

    loop:
        movzx rbx, byte [rdi + rax]
        movzx rcx, byte [rsi + rax]
        inc rax
        cmp rbx, rcx
        jl less
        jg great
        cmp rbx, 0x00
        je equal
        jmp loop
