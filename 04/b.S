	.text
	.global main
main:
	pushl %ebx
	xorl %ebx, %ebx

zalup:
	call read_int

	cmpl $0, %eax
	je unzalup

	addl %eax, %ebx
	jmp zalup

unzalup:
	movl %ebx, %eax
	call write_int

	popl %ebx
	xorl %eax, %eax // eax = 0
	ret


write_int:
	pushl %ebp
	movl %esp, %ebp

	pushl %eax
	pushl $printf_str
	call printf

	movl %ebp, %esp
	popl %ebp
	ret

read_int:
	pushl %ebp
	movl %esp, %ebp

	pushl $a
	pushl $scanf_str
	call scanf

	movl a, %eax

	movl %ebp, %esp
	popl %ebp
	ret



	.data
a:	.int 0

	.text
scanf_str:
	.asciz "%d"
printf_str:
	.asciz "%d\n"