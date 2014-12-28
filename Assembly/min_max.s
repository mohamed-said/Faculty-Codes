.data

message1: .asciiz "--- these are arrays --- \n\n"
message2: .asciiz "Enter the size of the array: \n"
arrSize: .word 10
arrElements: .word 10,4,1,6,10,7,8,9,5,10
line: .asciiz "\n"

.text


.globl main

main:

	li $v0, 4
	la $a0, message1
	syscall

	la $t0,arrSize        
	lw $s0, 0($t0)    #s0 = 10
	la $t0,arrElements    
	add $s1,$0,$0 	 # i = 0
	li $t5, -1 		#max
	li $t6, 100	 	# min 
	
	max_loop: 
		slt $t2,$s1,$s0  
		beq $t2,$zero,end_loop    
    	sll $t1,$s1,2           
		add $t3,$t0,$t1         
		lw  $s2, 0($t3)         
		addi $s1,$s1,1
		bgt $s2,$t5,set_max
		j max_loop
	set_max:
		add $t5, $0, $s2
	j max_loop  
	
	end_loop: 

	add $a0, $0, $t5
	li $v0, 1
	syscall
	
	la $a0,line
	li $v0,4
	syscall	
	###############################

	la $t0,arrElements
	add $s1,$0,$0 	 # i = 0
	li $t6, 100	 	# min 
	
	min_loop:
		slt $t2,$s1,$s0
		beq $t2,$zero,end_loop_2    
    	sll $t1,$s1,2           
		add $t3,$t0,$t1         
		lw  $s2, 0($t3)         
		addi $s1,$s1,1
		blt $s2,$t6,set_min
		j min_loop

	set_min:
		add $t6,$0,$s2
		j min_loop

	end_loop_2:
		add $a0, $0, $t6
		li $v0, 1
		syscall


	EXIT:
		li $v0,10
		syscall



.end main


	# int x, y, arr[10];
	# for (int i = 0; i < 10; cin >> arr[i++]);
	# x = y = arr[0];
	# for (int i = 1; i < 10; ++i)
	# 	if (arr[i] < x) x = arr[i];
	# 	else if (arr[i] > y) y = arr[i];
	# cout << x << " " << y << endl;






