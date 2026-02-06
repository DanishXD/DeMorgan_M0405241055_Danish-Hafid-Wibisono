extern printf
extern fflush

section .data
    fmt db "C = %d", 10, 0
    A   dd 3
    B   dd 7
    D   dd 4

section .bss
    C resd 1 

section .text
    global main

main:
    mov eax, [A]
    sub eax, [B]
    mov ecx, [D]
    add ecx, [A]
    cdq
    idiv ecx
    mov [C], eax
    push dword [C]
    push fmt
    call printf
    add esp, 8
    push 0
    call fflush
    add esp, 4

exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80