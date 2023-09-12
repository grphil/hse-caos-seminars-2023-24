	.text
	.global main
main:
	call readi32
	movl %eax, %ebx
	call readi32

	movl %eax, %ecx
	addl %ecx, %ebx // ebx += ecx
	subl %ebx, %ecx // ecx -= ebx

	incl %eax // eax++
	decl %eax // eax--

	imull %eax // (edx, eax) = ecx * eax (eax часть меньше 2^32, edx часть больше 2^32)
	mull %ecx // Для беззнаковых (edx, eax) = ecx * eax (eax - младшие, edx - старшие)

	andl %eax, %ecx // ecx &= eax
	notl %ebx // ebx = ~ebx

	call writei32
	call finish


