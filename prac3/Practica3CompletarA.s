.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo
    movl     12(%ebp), %edx      # elementos -> edx
    movl     8(%ebp), %ebx        # @ vector -> $ebx
    movl    -8(%ebp), %ecx      # $ecx -> i
    movl $1, %ecx
FOR:
    cmpl     %edx, %ecx             # i < elementos  ????
    jge FI_FOR    
IF:
    movl    (%ebx, %ecx, 4), %eax   # @vector+i*tamany //  vector[i] > res  ????
    cmpl    -4(%ebp), %eax
    jle FI_IF
    movl     %eax, -4(%ebp)
FI_IF:
    incl     %ecx
    jmp FOR    
FI_FOR:   

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl    %ebp,%esp
	popl   %ebp
	ret
