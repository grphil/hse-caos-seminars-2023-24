	.text
	.global mulab
mulab:
	pushl %ebp
	movl %esp, %ebp

	movsd 8(%ebp), %xmm0 // xmm0 = a
	movsd 16(%ebp), %xmm1 // xmm1 = b
	mulsd %xmm1, %xmm0 // xmm0 = a * b

	movl 24(%ebp), %eax
	movsd %xmm0, (%eax)

	popl %ebp
	ret