	.text
	.global minsq
minsq:
	pushl %ebp
	movl %esp, %ebp

	flds 12(%ebp) // [y]
	flds 8(%ebp) // [x, y]

	fcomi %st(1) // compare stack[0] and stack[1]
	jc less

	// x >= y
	fstp %st // stack.pop() [y]
	fld %st(0) // stack.push(stack[0]) [y, y]
	fmulp // stack[1] *= stack[0]; stack.pop() [y^2]

	flds 8(%ebp) // [x, y^2]
	faddp // [x + y^2]

	jmp end

less:
	// stack[0] < stack[1] x < y

	fmul %st // [x^2, y]
	faddp // [x^2 + y]

end:
	popl %ebp
	ret