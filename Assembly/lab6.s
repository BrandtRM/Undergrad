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

	# TODO
	# if str[0] is '\n' or 0, exit from the loop.
	la 	$a0, str
	lb 	$t0, 0($a0)
	beq 	$t0, 0, Exit
	beq 	$t0, 10, Exit
	# call myatoi(str)
	la	$a0, str
	jal 	myatoi
	# if the return value is the error code, print error message 
	# otherwise, print the return value in 3 formats
	bne	$v0, -1, no_error
	# print errmsg
	la	$a0, errmsg
	li	$v0, 4
	syscall
	
no_error:
	# print return value in three different formats, separated by a space.
	# syscall 11 can be used to print a character (e.g., a space, a new line).
	la 	$a0, str
	li 	$v0, 34
	syscall			# print as hexadecimal
		
	la 	$a0, 32
	li 	$v0, 11
	syscall			# add a space
	
	la 	$a0, str
	li 	$v0, 36
	syscall			# print as unsigned
	
	la	$a0, 32
	li 	$v0, 11
	syscall			# add a space
	
	la 	$a0, str
	li 	$v0, 4
	syscall			# print as signed
	
	la	$a0, 10
	li 	$v0, 11
	syscall			# add a newline
	
continue:
	b	main_loop
	
Exit:	li	$v0, 10		# System call, type 10, standard exit
	syscall			# ...and call the OS

# TODO
# your implementation of myatoi
myatoi: 
	addi	$v0, $v0, 0	# v = 0
	addi	$t1, $t1, 0	# i = 0
	la 	$a0, str
	add	$t2, $a0, $t1	# s[i]
	sb 	$s0, 0($t2)	# c = s[i]
	j 	Loop
	
	
Loop:
	sgt	$t3, $s0, 47	# c >= '0'
	slti 	$t4, $s0, 58	# c <= '9'
	and	$t5, $t3, $t4	# c >= '0' and c <= '9'
	beq 	$t5, $0, my_exit# else, exit
	
	addi	$t9, $t9, 10	# set $t9 to 10
	multu  	$v0, $t9	# v * 10
	mflo	$t6		# move low bits
	mfhi	$t8		# move hi bits
	
	sub 	$t7, $s0, 48	# c - '0'
	add 	$s1, $t6, $t7	# v * 10 + (c - '0')
	move	$v0, $s1	# v = v * 10 + (c - '0')
	addi	$t1, $t1, 1	# i += 1
	
	bne	$t8, $0, overflow# check for multiplication overflow
	sltu	$t8, $s1, $t6	# check if result is less than operand
	bne	$t8, $0, overflow# check for addition overflow
	
	la 	$a0, str
	add	$t2, $a0, $t1	# s[i]
	sb 	$s0, 0($t2)	# c = s[i]
	
	j	Loop
	
overflow:
	addi	$v0, $0, -1	# set return to -1 if overflow
	
my_exit:
        jr 	$ra                 # return to calling routine
   
