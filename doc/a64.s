bits 64 ;specify that the program is for a 64 bits architecture

; A section is a block of code or data that occupies contiguous space in the memory map
; . text tells the assembler to switch to the text segment (where code goes), and . data tells the assembler to switch to the data segment (where data goes).

section  .data ; (10 = '\n')
    message db 'Hello World !', 10

section .text
    global _start
    _start: ;_start is a label
        mov rax, 1 ;The mov instruction copies the data item referred to by its second operand (i.e. register contents, memory contents, or a constant value) 
                   ;into the location referred to by its first operand (i.e. a register or memory).
                   ;rax, 1 signifies we gonna use the system call "1" wich corresponds to the function "size_t write(int fildes, const void *buf, size_t nbyte)"
        mov rdi, 1 ;indicates on wich fd we want to write (rdi is the first parameter of a function)
        mov rsi, message ;second argument of the function
        mov rdx, 13+1 ;third argument of the function
        syscall ;call the kernel and clean the register

        mov rax, 60 ;60 is the exit function
        mov rdi, 0  ;exit will return 0
        syscall