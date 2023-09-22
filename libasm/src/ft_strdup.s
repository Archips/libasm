bits 64

extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

section .text
    ft_strdup:
        mov     r8, rdi ; save pointer of the string to be ducplicate
        call    ft_strlen ; get size of string to duplicate (return in rax)
        inc     rax ; add 1 for the '\0'
        push    r8 ; push rdi on the stack to save its value
        mov     rdi, rax ;save the value of the len in rdi - it will be the first arg of malloc
        call    malloc wrt ..plt ; call malloc (return in rax)
        cmp     rax, 0 ; check if the string of "rax" octets has been allocated correctly
        je      error ; if not, return 
        mov     rdi, rax ; mov rax (the allocated string) in rdi
        ; mov     rsi, r8
        pop     rsi ;
        call    ft_strcpy
        ret

    error:
        ret
