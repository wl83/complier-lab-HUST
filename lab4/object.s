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

main:
  addi $sp, $sp, -28
  li $t3, 1
  sw $t3, 20($sp)
  lw $t1, 20($sp)
  move $t3, $t1
  sw $t3, 0($sp)
  li $t3, 2
  sw $t3, 20($sp)
  lw $t1, 20($sp)
  move $t3, $t1
  sw $t3, 4($sp)
  li $t3, 0
  sw $t3, 20($sp)
  lw $t1, 20($sp)
  move $t3, $t1
  sw $t3, 12($sp)
label7:
  li $t3, 10
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  blt $t1,$t2,label4
  j label1
label4:
  li $t3, 10
  sw $t3, 0($sp)
  lw $t1, 12($sp)
  lw $t2, 0($sp)
  mul $t3, $t1, $t2
  sw $t3, 4($sp)
  lw $t1, 4($sp)
  move $t3, $t1
  sw $t3, 0($sp)
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
label5:
  li $t3, 1
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  add $t3, $t1, $t2
  sw $t3, 28($sp)
  lw $t1, 28($sp)
  move $t3, $t1
  sw $t3, 12($sp)
  j label7
label1:
