################################ data segment
	.data
name:	.asciiz "CSE3666: Lab 6: RyanBrandt (rmb15113)\n\n"
errmsg: .asciiz "The number is too large.\n"
nl:	.asciiz "\n"
str:    .space 128

################################ code segment
	.text
	.globl	main		# declare main to be global

main: 
	la	$a0, name	# load the address of "name" into $a0
	li	$v0, 4		# system call, type 4, print an string
	syscall			# system call
	
main_loop:
	# use a system call to read a string into str
	la	$a0, str
	li	$a1, 128
	li	$v0, 8
	syscall

	la 	$a0, str
	li 	$v0, 34
	syscall			# print as hexadecimal
		
	li 	$a0, 32
	li 	$v0, 11
	syscall			# add a space
	
	la 	$a0, str
	li 	$v0, 36
	syscall			# print as unsigned
	
	li	$a0, 32
	li 	$v0, 11
	syscall			# add a space
	
	la 	$a0, str
	li 	$v0, 4
	syscall			# print as signed
	
	j	Exit
	
Exit:	li	$v0, 10		# System call, type 10, standard exit
	syscall			# ...and call the OS
	
	
