 .text
	.align 4
	.globl Intercambiar
	.type Intercambiar,@function
Intercambiar:

    pushl %ebp
    movl %esp, %ebp
    subl $12, %esp
    pushl %edi
    pushl %esi
    imul $12, 12(%ebp), %ecx
    movl 8(%ebp), %edx
    addl %edx, %ecx
    imul $12, 16(%ebp), %eax
    addl %eax, %edx
    
    #part1
    movl (%ecx), %esi
    movl %esi, -4(%ebp)
    movl (%edx), %edi
    movl %edi, (%ecx)
    movl -4(%ebp), %eax
    movl %eax, (%edx)
    
    #part2
    movl 4(%ecx), %esi
    movl %esi, -12(%ebp)
    movl 4(%edx), %edi
    movl %edi, 4(%ecx)
    movl -12(%ebp), %eax
    movl %eax, 4(%edx)
    
    #part3
    movl 8(%ecx), %esi
    movl %esi, -8(%ebp)
    movl 8(%edx), %edi
    movl %edi, 8(%ecx)
    movl -8(%ebp), %eax
    movl %eax, 8(%edx)
    
    popl %esi
    popl %edi
    
    movl %ebp, %esp
    popl %ebp
    ret
