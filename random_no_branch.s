	.file	"random_no_branch.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	-3997696(%rsp), %r11
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	subq	$2336, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -4000024(%rbp)
	jmp	.L2
.L3:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-4000024(%rbp), %eax
	cltq
	movl	%edx, -4000016(%rbp,%rax,4)
	addl	$1, -4000024(%rbp)
.L2:
	cmpl	$999999, -4000024(%rbp)
	jle	.L3
	movl	$0, -4000020(%rbp)
	jmp	.L4
.L5:
	movl	-4000020(%rbp), %eax
	cltq
	movl	-4000016(%rbp,%rax,4), %eax
	cmpl	$49, %eax
	setle	%al
	movzbl	%al, %edx
	movl	-4000020(%rbp), %eax
	cltq
	movl	-4000016(%rbp,%rax,4), %eax
	imull	%eax, %edx
	movl	-4000028(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4000028(%rbp)
	addl	$1, -4000020(%rbp)
.L4:
	cmpl	$999999, -4000020(%rbp)
	jle	.L5
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
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
