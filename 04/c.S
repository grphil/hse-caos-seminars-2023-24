	.text
	.global ab4
ab4:
	pushl %ebp
	movl %esp, %ebp

	movl 12(%ebp), %eax // eax = second param (b)
	shll $2, %eax

	addl 8(%ebp), %eax // eax += first param (a)

	movl %ebp, %esp
	popl %ebp
	ret