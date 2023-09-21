bits 64

extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

section .text
    ft_strdup:
        call    ft_strlen
        inc     rax
        push    rdi
        mov     rdi, rax
        call    malloc wrt ..plt
        cmp     rdi, 0
        je      error
        mov     rdi, rax
        pop     rsi
        call    ft_strcpy
        ret

    error:
        ret
