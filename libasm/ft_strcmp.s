bits 64

global ft_strcmp

section .text
    ft_strcmp:
        mov rax, 0
        mov rcx, 0
        jmp loop

    less:
        neg rax
        mov rax, -1
        ret

    great:
        mov rax, 1
        ret

    equal:
        ret

    loop:
        mov al, [rdi + rcx]
        mov bl, [rsi + rcx]
        inc rcx
        cmp al, bl
        jl less
        jg great
        cmp al, 0x00
        je equal
        jmp loop

; bits 64

; global ft_strcmp

; section .text
;     ft_strcmp:
;         mov rax, 0
;         mov rcx, 0
;         jmp loop

;     cloop:
;         inc rcx
    
;     endloop:
;         add rdi, rcx
;         add rsi, rcx
;         sub rdi, rsi
;         mov rax, rdi
;         ret
;     loop:
;         cmp byte [rdi + rcx], 0x00
;         je  endloop
;         cmp byte [rsi + rcx], 0x00
;         je  endloop
;         mov r10, [rdi + rcx]
;         mov r11, [rsi + rcx]
;         cmp byte r10, r11
;         jne  endloop
;         jmp cloop


; bits 64

; global ft_strcmp

; section .text
;     ft_strcmp:
;         mov rax, 0
;         mov rcx, 0
;         jmp loop

;     cloop:
;         inc rcx

;     endloop:
;         mov bl, [rsi + rcx]
;         mov al, [rdi + rcx]
;         sub bl, al
;         mov ax, bl
;         ret

;     loop:
        
;         cmp byte [rdi + rcx], 0x00
;         je endloop
;         cmp byte [rsi + rcx], 0x00
;         je endloop
;         mov al, [rdi + rcx]
;         cmp byte al, [rsi + rcx]
;         jne endloop
;         je cloop
