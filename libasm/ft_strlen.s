bits 64

global ft_strlen

section .text
    ft_strlen:
        mov rax, 0
        jmp loop    

    cloop:
        inc rax

    loop:
        cmp byte [rdi + rax], 0x00
        jne cloop
        ret

;rcx doesn't work - rax does... why ?
