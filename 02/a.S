	.text
	.global main
main:
	call readi32 // В eax находится первое число
	movl %eax, %ebx // ebx = eax
	call readi32 // В eax считалось второе число
	addl %ebx, %eax // eax += ebx
	call writei32 // Вывести eax
	call finish
