bits 64

global ft_strcpy

section .text
    ft_strcpy:
        mov rax, 0
        mov rcx, 0
        jmp loop

    endloop:
        mov byte [rdi + rcx], 0x00
        mov rax, rdi
        ret

    loop:
        cmp byte [rsi + rcx], 0x00
        je endloop
        mov bl, byte [rsi + rcx]
        mov byte [rdi + rcx], bl
        inc rcx
        jmp loop
