section .data
    hello db 'hello world!',0

section .text
    global _start

_start:
    ; write hello to stdout (file descriptor 1)
    mov eax, 4
    mov ebx, 1
    mov ecx, hello
    mov edx, 13
    int 0x80

    ; exit the program
    mov eax, 1
    int 0x80
