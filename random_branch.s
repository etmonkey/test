	.file	"random_branch.c"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	leaq	-3997696(%rsp), %r11
	.cfi_def_cfa 11, 3997728
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	.cfi_def_cfa_register 7
	subq	$2336, %rsp
	.cfi_def_cfa_offset 4000064
	movq	%fs:40, %rax
	movq	%rax, 4000024(%rsp)
	xorl	%eax, %eax
	leaq	16(%rsp), %rbx
	leaq	4000016(%rsp), %r12
	movq	%rbx, %rbp
	.p2align 4,,10
	.p2align 3
.L2:
	call	rand@PLT
	addq	$4, %rbp
	movslq	%eax, %rdx
	movl	%eax, %ecx
	imulq	$1374389535, %rdx, %rdx
	sarl	$31, %ecx
	sarq	$37, %rdx
	subl	%ecx, %edx
	imull	$100, %edx, %edx
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	cmpq	%r12, %rbp
	jne	.L2
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%rbx), %eax
	cmpl	$49, %eax
	jg	.L3
	movl	12(%rsp), %edx
	addl	%edx, %eax
	movl	%eax, 12(%rsp)
.L3:
	addq	$4, %rbx
	cmpq	%r12, %rbx
	jne	.L4
	movq	4000024(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L10
	addq	$4000032, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
