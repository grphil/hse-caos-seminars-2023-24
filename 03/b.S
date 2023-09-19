	.global A, inc_a
	
	.text
inc_a:
	// can change only eax, ecx, edx
	pushl %ebx

	movl A, %ebx
	incl %ebx
	movl %ebx, A

	popl %ebx

	call aaaa

	ret