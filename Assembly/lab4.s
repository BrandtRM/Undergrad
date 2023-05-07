################################ data segment
	.data
name:	.asciiz "CSE3666: Lab 4: RyanBrandt (rmb15113)\n\n"
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
	# call strtoupper
	jal strtoupper
	# print the returned string
	la $a0, str
	li $v0, 4
	syscall
	# if str[0] is '\n' or 0, exit from the loop. 
	# Goto main_loop otherwise.
	la $a0, str
	lb $t1, 0($a0)
	beq $t1, 0, Exit
	beq $t1, 10, Exit
	j main_loop
	
	
Exit:	li	$v0, 10		# System call, type 10, standard exit
	syscall			# ...and call the OS

# TODO
# your implementation of strtoupper
strtoupper: 
	addi	$sp, $sp, -8
	sw	$a0, 4($sp)	# save $a0
	sw	$ra, ($sp)
		
	lb	$t0, ($a0)
	beq	$t0, $0, str_exit
	
str_next:
	slti	$at, $t0, 'a'		#greater than or equal to 'a'
	bne	$at, $0, str_skip	#skip if less than 'a'
	
	# 'z' is 122
	slti	$at, $t0, 123		#less than or equal to 'z'
	beq 	$at, $0, str_skip	#skip if greater than 'z'
	
	subi	$t0, $t0, 32		#subtract 32 if in between 'a' and 'z'
	sb	$t0, ($a0)

str_skip:
	addi	$a0, $a0, 1
	jal	strtoupper

str_exit:
	lw	$ra, ($sp)
	lw	$v0, 4($sp)	# return $a0
	addi	$sp, $sp, 8
        jr 	$ra                 # return to calling routine
