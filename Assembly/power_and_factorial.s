.data
	
	READ_INT  = 5
	PRINT_INT = 1
	READ_STRING = 8
	PRINT_STRING = 4
	line: .asciiz "\n"

.text

.globl main

main:

	li $v0, READ_INT
	syscall
	add $s0, $0, $v0

	li $v0, READ_INT
	syscall
	add $s1, $0, $v0

	add $s2, $0, $s0

power_loop:
	beq	$s1, 1, POWER
	mul $s2, $s0, $s2
	addi $s1, $s1, -1
	j power_loop

POWER: 

	add $a0, $0, $s2
	li $v0, PRINT_INT
	syscall

	la $a0, line
	li $v0, PRINT_STRING
	syscall 

	li $s3, 1

fac_loop:
	beq $s0, 1, EXIT
	mul $s3, $s3, $s0
	addi $s0, -1
	j fac_loop

EXIT:
	add $a0, $0, $s3
	li $v0, PRINT_INT
	syscall

	li $v0, 10
	syscall

.end main