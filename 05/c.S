	.text
	.global pipe
pipe:
	pushl %ebp
	movl %esp, %ebp

	pushl %esi
	pushl %edi
	pushl %ebx

	movl 8(%ebp), %edi // edi = n
	xorl %esi, %esi // esi = 0 (it will be as i in for loop)
	movl 12(%ebp), %ebx

loop:
	cmpl %edi, %esi
	je loop_end
	movl 16(%ebp, %esi, 4), %eax // (ebp + 16)[esi]
	pushl %ebx
	call *%eax
	movl %eax, %ebx
	addl $4, %esp
	incl %esi
	jmp loop

loop_end:
	movl %ebp, %esp
	subl $12, %esp
	popl %ebx
	popl %edi
	popl %esi
	popl %ebp
	ret
