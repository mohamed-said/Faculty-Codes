.data

array: .space 12
success: .asciiz "Successfull \n"
failed: .asciiz "failed \n"
newLine: .asciiz "\n"


.text

.globl main

main:


	la $t0, array 	#addressed
	
	li $s0, 50 		#grade
	li $s1, 0 		#initial
	li $s2, 3 		#loop limit
	li $v0, 5 		#read int
	li $s3, 0 		#sum
	
	loop:
		beq $s1, $s2, Exit
		li $v0, 5
		syscall
		sw $a0, ($t0)
		add $s3, $s3, $v0
		addi $t0, $t0, 4
		addi $s1, $s1, 1
	j loop

	Exit:
	li $v0, 4
	la $a0, newLine
	syscall

	add $a0, $0, $s3
	li $v0, 1
	syscall

	li $v0, 10
	syscall

.end main
