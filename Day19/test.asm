global _start

section .text
_start:
    mov rcx, message
    call puts
    mov rcx, 0
    call ExitProcess

