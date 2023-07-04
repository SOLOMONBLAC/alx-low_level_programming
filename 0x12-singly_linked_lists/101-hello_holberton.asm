section .data
    hello db 'Hello, Holberton', 10 ; 10 is the ASCII code for newline
    format db '%s', 0

section .text
    extern printf

global main
main:
    sub rsp, 8          ; Align the stack

    mov edi, format     ; Load the format string
    mov esi, hello      ; Load the address of the hello string
    xor eax, eax        ; Clear eax register
    call printf         ; Call printf function

    add rsp, 8          ; Restore the stack

    mov eax, 0x60       ; System call number for exit
    xor edi, edi        ; Exit status 0
    syscall             ; Call the kernel

section .data
    extern printf

