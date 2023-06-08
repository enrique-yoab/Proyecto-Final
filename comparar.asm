section .text
global comparar_nasm

comparar_nasm:
  	push ebp
    mov ebp, esp
    push ebx

  	mov eax, [ebp + 8]
  	mov ebx, [ebp + 12]
  	mov ecx, [ebp + 16]

cmp eax, ebx;
jl comp1     ;si eax es menor a ebx, entonces ebx es mayor   
jmp comp2    ;si eax es mayor a ebx, entonces ebx es menor
    comp1: 
    ;se compara ebx con ecx ya que eax es menor a ebx
    cmp ebx, ecx 
    jl comp3      ;si ebx es menor a ecx, ecx es el mayor 
    jmp comp4     ;si ecx es menor a ebx, ebx es el mayor
    comp2:
    ;se compara eax con ecx ya que ebx es menor a eax
    cmp eax, ecx 
    jl comp3     ;si eax es menor, ecx es el mayor
    jmp comp5    ;si ecx es menor, entonces eax es el mayor
    comp3:
    ;si llega aqui es que ecx es el mayor
    mov eax, ecx
    jmp salida
    comp4:
    ;si llega aqui es que ebx es el mayor
    mov eax, ebx
    jmp salida
    comp5:
    ;si llega aqui es que eax es el mayor
    mov eax, eax
    jmp salida

salida:
    pop ebx
    pop ebp
    ret