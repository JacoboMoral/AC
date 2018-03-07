.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
   /*
    movl    $0, -4(%ebp)    # res = 0
    movl    $0, -8(%ebp)    # i = 0
    movl    $0, -12(%ebp)   # j = 0
      */
    movl    12(%ebp), %edi  # %edi <- salto
    movl    8(%ebp), %ebx   # %ebx <- @Matriz
  
    
    xorl    %ecx, %ecx      # %ecx = 0
    xorl    %edx, %edx      # %edx = 0dd
    
    /*
    movl    -8(%ebp), %ecx
    movl    -12 (%ebp), %edx
    movl    -4(%ebp), %esi # $esi = res = 0
    */
FOR1:
    cmpl    $3, %ecx        # i < 3 ????
    jge FI_FOR1
FOR2:
    cmpl    $3, %edx                   # j < 3 ????
    jge     FI_FOR2
    imul    $12, %ecx, %eax            # i * 3 * 4  (i*N*tamany)
    addl    %ebx, %eax                 # @Matriz + (i*12)
    addl    (%eax, %edx, 4), %esi      # %esi = %esi + Matriz[i][j]
    movl    %esi, -4(%ebp)             # res = %esi
    addl     %edi, %edx                # j + = salto
    jmp FOR2
FI_FOR2:
    addl    %edi, %ecx      # i + = salto
    xorl    %edx, %edx      # j = 0
    jmp FOR1
FI_FOR1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
