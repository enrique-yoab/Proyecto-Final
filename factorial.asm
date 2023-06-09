section .text
global factorial

factorial:
    push ebp
    mov ebp, esp
    push ebx

    mov esi, [ebp+8]
    cmp esi, 0
    je cero
    mov ebx, 1
    mov ecx, 2
    mov edi, 1
multiplicacion:
    cmp edi, esi
    je fin
    push edi
    mov eax, ecx
    mul ebx
    mov edi, eax
    mov ebx, edi
    inc ecx
    pop edi
    inc edi
    jmp multiplicacion

cero:
    mov eax,1
    pop ebx
    pop ebp
    ret
fin:
    mov eax, ebx
    pop ebx
    pop ebp
    ret