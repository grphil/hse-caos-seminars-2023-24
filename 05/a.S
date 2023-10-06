	.text
	.global calc_depth
calc_depth:
	pushl %ebp
	movl %esp, %ebp

	// Should put all used registers to stack
	pushl %ebx
	pushl %ecx

	movl (%ebp), %ecx // ecx stores ebp pointer
	movl 4(%ecx), %ebx // ebx stores return address in rec
	movl $1, %eax // eax stores recursion depth
loop:
	cmpl 4(%ecx), %ebx
	jne loop_end

	incl %eax
	movl (%ecx), %ecx
	jmp loop

loop_end:
	popl %ecx
	popl %ebx

	movl %ebp, %esp
	popl %ebp
	ret