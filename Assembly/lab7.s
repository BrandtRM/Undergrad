################################ data segment
	.data
name:	.asciiz "CSE3666: Lab 7: RyanBrandt (rmb15113)\n\n"
nl:	.asciiz "\n"

	.align 2
fconst: .float	0.0, 1.0, 2.0
arr:    .float	0.1, 0.2, 0.3, 0.4, 0.5, 0.7853981, 1.570796, 3.1415927, 0.0

################################ code segment
	.text
	.globl	main		# declare main to be global

main: 
	la	$a0, name	# load the address of "name" into $a0
	li	$v0, 4		# system call, type 4, print an string
	syscall			# system call

	la	$s0, arr	
	li	$s1, 9		# the number of elements in the array
	sll	$s1, $s1, 2
	add	$s1, $s1, $s0

main_loop:
	# TODO
	la	$s3, fconst
	l.s	$f0, ($s3)
	l.s	$f1, 4($s3)
	l.s	$f2, 8($s3)
	# for valid index i = 0, 1, ..., 
	# print sin(arr[i]), and nl
	l.s	$f12, ($s0)	# load x from $s0
	jal	sin		# call sin(x)
	
	mov.s	$f12, $f0	# move result to print
	li	$v0, 2		# system call, type 2, print a float
	syscall	
	
	la	$a0, 10		
	li 	$v0, 11		
	syscall			# add a newline
	
	j 	main_continue
	
main_continue:
	addi	$s0, $s0, 4
	bne	$s0, $s1, main_loop
	
Exit:	li	$v0, 10		# System call, type 10, standard exit
	syscall			# ...and call the OS

# TODO
# your implementation of sin
sin: 
	add.s	$f3, $f0, $f1	# sign = 1.0
	add.s	$f4, $f0, $f1	# n = 1.0
	add.s	$f5, $f0, $f1	# fact = 1.0
	add.s	$f6, $f0, $f12	# power = x
	add.s	$f7, $f0, $f12	# v = x
	add	$t0, $0, $0	# i = 0
	
	j 	sin_loop


sin_loop:
	beq	$t0, 20, sin_exit# i < 20
	
    	mul.s	$f6, $f6, $f12	# power *= x
    	mul.s	$f6, $f6, $f12	# power *= x * x
    	
    	add.s	$f8, $f4, $f1	# n + 1.0
    	add.s	$f9, $f4, $f2	# n + 2.0
    	mul.s	$f5, $f5, $f8	# fact *= (n + 1.0)
    	mul.s	$f5, $f5, $f9	# fact *= (n + 1.0) * (n + 2.0)
    	
    	add.s	$f4, $f4, $f2	# n += 2.0
    	
    	neg.s	$f3, $f3	# sign = -sign
    	
    	mul.s	$f10, $f5, $f3	# fact * sign
    	div.s	$f10, $f6, $f10	# power / fact * sign
    	add.s	$f7, $f7, $f10	# v += power / fact * sign
    	
    	addi	$t0, $t0, 1	# i += 1
    	
    	j 	sin_loop

sin_exit:	
        # return x for now
	mov.s	$f0, $f7
        jr 	$ra		# return