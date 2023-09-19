	.text
	.global main
main:
	call readi32
	movl %eax, %ecx // ecx = size of array

	call readi32
	movl %eax, %edx // edx = shift length

	movl %ecx, %ebx // ebx = how much to read
read:
	call readi32
	pushl %eax // add new array element to stack
	decl %ebx
	cmpl $0, %ebx // check if ebx - 0 > 0
	jg read

	movl %edx, %ebx // ebx = shift lengths
write_first:
	decl %ebx // ebx = current index to write
	movl (%esp, %ebx, 4), %eax
	call writei32
	cmpl $0, %ebx
	jg write_first

	leal (%esp, %edx, 4), %esp // esp = esp + edx * 4
	subl %edx, %ecx // ecx = size of second part of array

	movl %ecx, %ebx
write_second:
	decl %ebx // ebx = current index to write
	movl (%esp, %ebx, 4), %eax
	call writei32
	cmpl $0, %ebx
	jg write_second

	call finish

