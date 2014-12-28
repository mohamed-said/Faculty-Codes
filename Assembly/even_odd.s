.data
	
	arr: .word 1, 2, 1, 2, 1, 2, 1, 2, 1, 2
	READ_INT  = 5
	PRINT_INT = 1
	READ_STRING = 8
	PRINT_STRING = 4
	line: .asciiz "\n"

.text

.globl main

main:

	li $s0, 10
	la $t0, arr

	#s3 even
	#s4 odd
	li $s3, 0
	li $s4, 0

LOOP:
	beq $s0, 0, EXIT
	lw $s1, ($t0)
	andi $s2, $s1, 1
	beq $s2, 0, IS_EVEN
	j IS_ODD

IS_EVEN:
	add $s3, $s3, $s1
	j CONT_LOOP	

IS_ODD:	
	add $s4, $s4, $s1

CONT_LOOP:
	addi $t0, 4
	addi $s0, -1
	j LOOP

EXIT:
	add $a0, $0, $s3
	li $v0, 1
	syscall

	la $a0, line
	li $v0, PRINT_STRING
	syscall 


	add $a0, $0, $s4
	li $v0, 1
	syscall

	li $v0, 10
	syscall

.end main