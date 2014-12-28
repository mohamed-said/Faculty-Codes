.data

.text
.globl main

main:

	li $v0, 5 #takes input from user
	syscall
	add $s0, $0, $v0

	li $v0, 5 #takes input from user
	syscall
	add $s1, $0, $v0

	# prints the area
	mul $s2, $s0, $s1
	add $a0, $0, $s2
	li $v0, 1
	syscall

	# prints a space
	li $a0, 32
	li $v0, 11
	syscall


	# prints the circumference
	add $s2, $s0, $s1
	add $s2, $s2, $s2
	add $a0, $0, $s2
	li $v0, 1
	syscall


	li $v0, 10
	syscall

.end main