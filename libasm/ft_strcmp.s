bits 64

global ft_strcmp

section .text
    ft_strcmp:
        mov rcx, 0
        jmp loop

    cloop:
        inc rcx
    
    endloop:
        add rdi, rcx
        add rsi, rcx
        sub rdi, rsi
        mov rax, rdi
        ret
    loop:
        cmp byte [rdi + rcx], 0x00
        je  endloop
        cmp byte [rsi + rcx], 0x00
        je  endloop
        cmp byte [rdi + rcx], [rsi + rax]
        je  endloop
        jmp cloop

