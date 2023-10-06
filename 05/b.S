	.text
	.global calc_depth
calc_depth:
	pushl %ebp
	movl %esp, %ebp

	// Should put all used registers to stack
	pushl %ecx
	pushl %esi

	movl %ebp, %ecx // ecx stores ebp pointer
	xorl %eax, %eax // eax stores recursion depth
loop:
	movl 4(%ecx), %esi
	
	subl $main, %esi

	testl %esi, %esi
	jge loop_end

	incl %eax
	movl (%ecx), %ecx
	jmp loop

loop_end:
	popl %edi
	popl %esi
	popl %ecx

	movl %ebp, %esp
	popl %ebp
	ret