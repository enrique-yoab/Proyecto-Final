section .text
global bubble_sort:

bubble_sort:
    push ebp
    mov ebp, esp
    push ebx

    mov esi, [ebp + 08]   ;se mueve al registro esi el puntero del arreglo a ordenar
    mov edi, [ebp + 12]   ;se mueve al registro edi el tamaño del arreglo 

    mov ebx, 1
    cyclei:
    cmp ebx, edi
    jge regreso     ;si es mayor o igual al tamaño del arreglo ya termino de ordenar
    xor ecx, ecx    ;indice del arreglo j
    push edi
    sub edi, ebx    ;al tamaño del arreglo se le resta ebx
        cyclej:
        cmp ecx, edi       ;si llega al ultimo elemento a contar entonces el mayor ya esta hasta el final
        jge next           ;salta a la siguiente etiqueta
        
        ;se compara los datos e ir intercambiando el mayor 
        mov eax, [esi + ecx*4]
        inc ecx
        cmp eax, [esi + ecx*4]
        jle siguiente

        ;se intercambia si es que al es mayor eax siguiente dato
        push ebx
        mov ebx, [esi + ecx*4]
        dec ecx 
        mov [esi + ecx*4], ebx
        inc ecx
        mov [esi + ecx*4], eax
        pop ebx
        jmp siguiente

    siguiente:
    ;si salto aqui es que no es mayor el numero anterior y ecx ya esta incrementado anteriormente
    jmp cyclej   ;se repite para que compare el mayor con otro numeor e irlo arrastrando hasta el final

    next:
    pop edi
    inc ebx
    jmp cyclei

    regreso:
        pop ebx
        pop ebp
        ret