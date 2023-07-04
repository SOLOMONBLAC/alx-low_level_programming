section .data
    format db 'Hello, Holberton', 10, 0

section .text
    global _start

_start:
    mov eax, 4            ; Syscall number for write
    mov ebx, 1            ; File descriptor for stdout
    mov ecx, format       ; Address of the message
    mov edx, 16           ; Length of the message
    int 0x80              ; Perform the system call

    mov eax, 1            ; Syscall number for exit
    xor ebx, ebx          ; Exit status 0
    int 0x80              ; Perform the system call
