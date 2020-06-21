.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main
.text
j main
read:
  li $v0,4
  la $a0,_Prompt
  syscall
  li $v0,5
  syscall
  jr $ra
write:
  li $v0,1
  syscall
  li $v0,4
  la $a0,_ret
  syscall
  move $v0,$0
  jr $ra

fibo:
  li $t3, 1
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  beq $t1,$t2,label3
  j label4
label4:
  li $t3, 2
  sw $t3, 28($sp)
  lw $t1, 12($sp)
  lw $t2, 28($sp)
  beq $t1,$t2,label3
  j label2
label3:
  li $t3, 1
  sw $t3, 32($sp)
  lw $v0,32($sp)
  jr $ra
label2:
  li $t3, 3
  sw $t3, 36($sp)
  lw $t1, 12($sp)
  lw $t2, 36($sp)
  bge $t1,$t2,label6
  j label5
label6:
  lw $t1, 76($gp)
  move $t3, $t1
  sw $t3, 16($sp)
  lw $t1, 76($gp)
  move $t3, $t1
  sw $t3, 8($gp)
  li $t3, 1
  sw $t3, 56($sp)
  lw $t1, 12($sp)
  lw $t2, 56($sp)
  sub $t3, $t1, $t2
  sw $t3, 60($sp)
  move $t0,$sp
  addi $sp, $sp, -88
  sw $ra,0($sp)
  lw $t1, 60($t0)
  move $t3,$t1
  sw $t3,12($sp)
  jal fibo
  lw $ra,0($sp)
  addi $sp,$sp,88
  sw $v0,64($sp)
  li $t3, 2
  sw $t3, 68($sp)
  lw $t1, 12($sp)
  lw $t2, 68($sp)
  sub $t3, $t1, $t2
  sw $t3, 72($sp)
  move $t0,$sp
  addi $sp, $sp, -88
  sw $ra,0($sp)
  lw $t1, 72($t0)
  move $t3,$t1
  sw $t3,12($sp)
  jal fibo
  lw $ra,0($sp)
  addi $sp,$sp,88
  sw $v0,76($sp)
  lw $t1, 64($sp)
  lw $t2, 76($sp)
  add $t3, $t1, $t2
  sw $t3, 80($sp)
  lw $v0,80($sp)
  jr $ra
label5:
  li $t3, 0
  sw $t3, 84($sp)
  lw $v0,84($sp)
  jr $ra
label1:

main:
  addi $sp, $sp, -56
  li $t3, 1
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  move $t3, $t1
  sw $t3, 16($sp)
label20:
  li $t3, 10
  sw $t3, 28($sp)
  lw $t1, 16($sp)
  lw $t2, 28($sp)
  blt $t1,$t2,label11
  j label10
label11:
  li $t3, 9
  sw $t3, 0($sp)
  lw $t1, 16($sp)
  lw $t2, 0($sp)
  bgt $t1,$t2,label14
  j label15
label14:
  move $t0,$sp
  addi $sp, $sp, -88
  sw $ra,0($sp)
  lw $t1, 16($t0)
  move $t3,$t1
  sw $t3,12($sp)
  jal fibo
  lw $ra,0($sp)
  addi $sp,$sp,88
  sw $v0,4($sp)
  lw $t1, 4($sp)
  move $t3, $t1
  sw $t3, 20($sp)
  lw $a0, 20($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  j label10
  j label13
label15:
  move $t0,$sp
  addi $sp, $sp, -88
  sw $ra,0($sp)
  lw $t1, 16($t0)
  move $t3,$t1
  sw $t3,12($sp)
  jal fibo
  lw $ra,0($sp)
  addi $sp,$sp,88
  sw $v0,12($sp)
  lw $t1, 12($sp)
  move $t3, $t1
  sw $t3, 20($sp)
  lw $a0, 20($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  j label12
label13:
  li $t3, 1
  sw $t3, 20($sp)
  lw $t1, 16($sp)
  lw $t2, 20($sp)
  add $t3, $t1, $t2
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  move $t3, $t1
  sw $t3, 16($sp)
label12:
  li $t3, 1
  sw $t3, 32($sp)
  lw $t1, 16($sp)
  lw $t2, 32($sp)
  add $t3, $t1, $t2
  sw $t3, 36($sp)
  lw $t1, 36($sp)
  move $t3, $t1
  sw $t3, 16($sp)
  j label20
label10:
  li $t3, 1
  sw $t3, 52($sp)
  li $v0, 10
  syscall
label9:
