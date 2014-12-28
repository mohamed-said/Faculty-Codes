.data

.text


.globl main

main:

	# program total execution time
	li $v0, 6
	syscall
	mov.s $f1, $f0


	# execution time affected by improvement
	li $v0, 6
	syscall
	mov.s $f2, $f0

	# amount of improvement
	li $v0, 6
	syscall
	mov.s $f3, $f0

	div.s $f4, $f2, $f3
	add.s $f4, $f4, $f1

	mov.s $f12, $f4
	
	#prints the result
	li $v0, 2
	syscall

	li $v0, 10
	syscall

.end main
