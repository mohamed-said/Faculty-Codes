.data
	str: .space 10
	arr: .word 1, 2, 1, 2, 1, 2, 1, 2, 1, 2
	READ_INT  = 5
	PRINT_INT = 1
	READ_STRING = 8
	PRINT_STRING = 4
	line: .asciiz "\n"
	yes: .asciiz "Palindrome"
	no: .asciiz "Not Palindrome"
.text

.globl main

main:

	la $a0, str
	li $a1, 10

	li $v0, READ_STRING
	syscall

	#a0 feha el string
	#a1 feha el size

	add $t0, $0, $a0 #t0 = awel address (pointer)
	
	li $s0, 0 #sum

SIZE_LOOP:
	
	lb $s5, ($a0)
	beq $s5, 0, EX
	addi $a0, 1
	addi $s0, 1 
	j SIZE_LOOP

EX:
	addi $s0, -1

	add $t1, $a0, $s0 #t1 = last address (pointers)

LOOP:

	beq $t0, $t1, EXIT_YES
	lb $s0, ($t0)
	
	lb $s1, ($t1)
	bne $s0, $s1, EXIT_NO

	addi $t0, 1
	addi $t1, -1
	j LOOP

EXIT_YES:
	la $a0, yes
	j EXIT

EXIT_NO:
	la $a0, no

EXIT:
	li $v0, 4
	syscall

	li $v0, 10
	syscall

.end main
