	.file	"kete.c"
	.text
	.p2align 4,,15
	.globl	Rutinakete
	.type	Rutinakete, @function
Rutinakete:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	movl	$1, %edx
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	16(%esp), %eax
	movl	20(%esp), %esi
	leal	(%eax,%eax,4), %ebx
	xorl	%eax, %eax
	sall	$4, %ebx
	addl	12(%esp), %ebx
	.p2align 4,,7
	.p2align 3
.L4:
	xorl	%ecx, %ecx
	cmpl	$5, (%ebx,%edx,4)
	sete	%cl
	addl	$1, %edx
	addl	%ecx, %eax
	cmpl	%esi, %edx
	jl	.L4
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	Rutinakete, .-Rutinakete
	.ident	"GCC: (SUSE Linux) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
