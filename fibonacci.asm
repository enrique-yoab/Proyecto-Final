section .text
global fibonacci

fibonacci:
    push ebp
    mov ebp, esp
    push ebx
    
    mov esi, [ebp + 8]  ;e mueve al registro eax, las sumas a realizar
_fibo:
    mov ebx, 0
    mov ecx, 1
    cmp esi, 1
    jle _fin2
    mov eax, 1
    mov edx, ecx
    add ebx, ecx
    cicle:
        mov ecx, edx
        cmp eax, esi  
        je fin
        mov edx, ebx
        add ebx, ecx
        inc eax
        jmp cicle
_fin2:
    mov eax, esi
    pop ebx
    pop ebp
    ret
fin:
    mov eax, ecx
    pop ebx
    pop ebp
    ret