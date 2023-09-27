	.bss
func_arr: .space 3 * 4
	
	.text
	.global main
main:
	movl $fun1, func_arr
	movl $fun2, func_arr + 4
	movl $fun3, func_arr + 8

	call readi32
	movl func_arr(,%eax, 4), %ebx
	jmp *%ebx

fun1:
	movl $3, %eax
	call writei32
	call finish

fun2:
	movl $5, %eax
	call writei32
	call finish

fun3:
	movl $9, %eax
	call writei32
	call finish
