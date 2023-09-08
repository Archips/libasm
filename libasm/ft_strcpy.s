bits 64

global ft_strcpy

section .text
    ft_strcpy:
        mov rax, 0
        mov rcx, 0

    endloop:
        mov [rsi + rcx], 0x00
        mov rax, rsi
        ret

    loop:
        cmp byte [rdi + rcx], 0x00
        je endloop
        mov [rsi + rcx], [rdi + rcx]
        inc rcx
