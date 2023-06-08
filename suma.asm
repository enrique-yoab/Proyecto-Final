section .text
global suma_asm

suma_asm:
    push ebp
    mov ebp, esp
    
    mov eax, [ebp+8]    ; Primer argumento (a)
    add eax, [ebp+12]   ; Segundo argumento (b)
    
    pop ebp
    ret
