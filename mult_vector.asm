section .text
global mult_vector:

mult_vector:
    push ebp
    mov ebp, esp
    push ebx

    mov esi, [ebp + 8]  ;se mueve el puntero a eax
    mov edi, [ebp + 12] ;se mueve el puntero a ecx
    mov ecx, [ebp + 16] ;se mueve el tamano de los arreglos
    
    xor eax, eax
bucle:
    cmp eax, ecx
    je suma
    mov edx, [esi + eax * 4]
    mov ebx, edx
    mov edx, [edi + eax * 4]
    push eax
    mov eax, edx
    mul ebx
    mov edx, eax
    pop eax
    mov ebx, edx
    push ebx
    inc eax
    jmp bucle

suma:
    mov esi, 0
    mov eax, 0
    principal:
        cmp eax, ecx
        je fin
        pop ebx
        push eax
        mov eax, ebx
        add esi, eax
        pop eax
        inc eax
        jmp principal
fin:
    mov eax, esi
    pop ebx
    pop ebp
    ret