# libasm

This project is a library of 64-bit Assembly language functions that adhere to specific requirements and conventions. It includes implementations of essential functions like `ft_strlen`, `ft_strcpy`, `ft_strcmp`, `ft_write`, `ft_read`, and `ft_strdup`.

## Project Highlights

- Written in 64-bit Assembly language.
- Adheres to specified calling conventions and conventions.
- Utilizes NASM for assembly code compilation.
- Follows the Intel syntax, not the AT&T syntax.
- Properly handles errors during syscalls and sets the `errno` variable.

## Usage
1. Clone the repository.
2. Compile the library using the provided Makefile.
3. Include the `libasm.h` header in your C projects.
4. Use the `libasm.a` library in your projects.
5. Use this command to test it with a test main.c `gcc -Wall -Wextra -Werror main.c -L. -lasm` 

## Complete Tutorial

[Yet another libasm](https://cute-balance-43f.notion.site/Yet-another-libasm-f15a6a72e0f041e293ae7bcfb6c564cd)

Tuto: 
  - https://www.youtube.com/watch?v=GPx4fUEmYJ8
  - https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture
