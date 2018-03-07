 .text
	.align 4
	.globl Ordenar
	.type Ordenar,@function
Ordenar:
        
        pushl %ebp
        movl %esp, %ebp
        subl $12, %esp
        pushl %ebp
        
        movl -8(%ebp),%esi #possiblement innecessari
        movl $0, %esi
        movl 12(%ebp), %eax
        
for1:   cmpl $0x80000000, %eax
        je fifor1
        movl %esi, $edi
        incl %edi
        imul %12, %edi, %ebx
        addl 12(%ebp), %ebx
        
for2:   cmpl $0x8, %ebx
        je fifor2
        
if:     cmpl %ebx, %eax
        jle fiif
        pushl %esi
        pushl %edi
        pushl 8(%ebp)
        movl %eax, -12(%ebp)  #guardem el eax
        
        call Intercambiar
        
        movl -12(%ebp), %eax
        addl $12, %esp
    
fiif:   incl %edi
fifor1: incl %esi
        
        addl $12, %eax

fifor2: incl %esi, %eax
