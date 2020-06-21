#include "grammarTree.h"

extern struct symboltable symbolTable;

int main_flag = 0;
int call_flag = 0;
int main_call = 0;
int LEV;
int current_offset = 0;

void object_code(struct codenode *head) {
    char opnstr1[32],opnstr2[32],resultstr[32];
    struct codenode *h=head,*p;
    int i;
    FILE *fp;
    fp=fopen("object.s","w");
    fprintf(fp,".data\n");
    fprintf(fp,"_Prompt: .asciiz \"Enter an integer:  \"\n");
    fprintf(fp,"_ret: .asciiz \"\\n\"\n");
    fprintf(fp,".globl main\n");
    fprintf(fp,".text\n");
    fprintf(fp, "j main\n");
    // fprintf(fp, "start:\n");
    // fprintf(fp, "  jal main\n");
    // fprintf(fp, "  li $v0, 10\n");
    // fprintf(fp, "  syscall\n");
    fprintf(fp,"read:\n");
    fprintf(fp,"  li $v0,4\n");
    fprintf(fp,"  la $a0,_Prompt\n");
    fprintf(fp,"  syscall\n");
    fprintf(fp,"  li $v0,5\n");
    fprintf(fp,"  syscall\n");
    fprintf(fp,"  jr $ra\n");
    fprintf(fp,"write:\n");
    fprintf(fp,"  li $v0,1\n");
    fprintf(fp,"  syscall\n");
    fprintf(fp,"  li $v0,4\n");
    fprintf(fp,"  la $a0,_ret\n");
    fprintf(fp,"  syscall\n");
    fprintf(fp,"  move $v0,$0\n");
    fprintf(fp,"  jr $ra\n");
    int cnt = 0;
    do{
        cnt++;
        switch (h->op)
        {
        case ASSIGNOP:
            if(h->opn1.kind == INT) {
                fprintf(fp, "  li $t3, %d\n", h->opn1.const_int);
            }
            else if(h->opn1.kind == FLOAT) {
                fprintf(fp, "  li $t3, %f\n", h->opn1.const_float);
            }
            else if(h->opn1.kind == CHAR) {
                fprintf(fp, "  li $t3, %c\n", h->opn1.const_char);
            }
            else{
                int rtn;
                char sub[20];
                if(strstr(h->opn1.id, " offset ") != NULL) {
                    substr(sub, h->opn1.id, 0, 2);
                    rtn = searchSymbolTableByAlias(sub);
                }
                else
                    rtn = searchSymbolTableByAlias(h->opn1.id);
                // printf("%d %s %d %d\n", rtn, , symbolTable.symbols[rtn].level, LEV);
                if(rtn != -1 && symbolTable.symbols[rtn].level == 0){
                    fprintf(fp, "  lw $t1, %d($gp)\n", h->opn1.offset);
                    fprintf(fp, "  move $t3, $t1\n");
                }
                else{
                    fprintf(fp, "  lw $t1, %d($sp)\n", h->opn1.offset);
                    fprintf(fp, "  move $t3, $t1\n");
                }
            }
            int rtn;
            char sub[20] = {'\0'};
            if(strstr(h->result.id, " offset ") != NULL) {
                for(int i = 0; i < strlen(h->result.id); i++){
                    if(h->result.id[i] != ' '){
                        sub[i] = h->result.id[i];
                    }
                }
                rtn = searchSymbolTableByAlias(sub);
            }
            else
                rtn = searchSymbolTableByAlias(h->result.id);
            // fprintf(fp, "  sw $t3, %d($sp)\n", h->result.offset);
            // printf("%s %d %d\n", h->result.id, symbolTable.symbols[rtn].level, LEV);
            if(rtn != -1 && symbolTable.symbols[rtn].level == 0){
                fprintf(fp, "  sw $t3, %d($gp)\n", h->result.offset);
            }
            else{
                fprintf(fp, "  sw $t3, %d($sp)\n", h->result.offset);
            }
            break;

        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case MOD:
            fprintf(fp, "  lw $t1, %d($sp)\n", h->opn1.offset);
            fprintf(fp, "  lw $t2, %d($sp)\n", h->opn2.offset);
            if(h->op == PLUS) 
                fprintf(fp, "  add $t3, $t1, $t2\n");
            else if(h->op == MINUS)
                fprintf(fp, "  sub $t3, $t1, $t2\n");
            else if(h->op == STAR)
                fprintf(fp, "  mul $t3, $t1, $t2\n");
            else if(h->op == DIV){
                fprintf(fp, "  div $t1, $t2\n");
                fprintf(fp, "  mflo $t3\n");
            }
            else{
                fprintf(fp, "  div $t1, $t2\n");
                fprintf(fp, "  mfhi $t3\n");
            }
            fprintf(fp, "  sw $t3, %d($sp)\n", h->result.offset);
            break;

        case FUNCTION:
            if(!strcmp(h->result.id, "main")){
                main_flag = 1;
                LEV = 0;
                main_call = 0;
            }
            fprintf(fp, "\n%s:\n", h->result.id);
            if(!strcmp(h->result.id, "main"))
                fprintf(fp, "  addi $sp, $sp, -%d\n", symbolTable.symbols[h->result.offset].offset);
            break;

        case PARAM:
            break;

        case LABEL:
            fprintf(fp, "%s:\n", h->result.id);
            break;
        case GOTO:  
            fprintf(fp, "  j %s\n", h->result.id);
            break;

        case JLE:
        case JLT:
        case JGE:
        case JGT:
        case EQ:
        case NEQ:
            fprintf(fp, "  lw $t1, %d($sp)\n", h->opn1.offset);
            fprintf(fp, "  lw $t2, %d($sp)\n", h->opn2.offset);
            if (h->op==JLE) 
                fprintf(fp, "  ble $t1,$t2,%s\n", h->result.id);
            else if (h->op==JLT) 
                fprintf(fp, "  blt $t1,$t2,%s\n", h->result.id);
            else if (h->op==JGE) 
                fprintf(fp, "  bge $t1,$t2,%s\n", h->result.id);
            else if (h->op==JGT) 
                fprintf(fp, "  bgt $t1,$t2,%s\n", h->result.id);
            else if (h->op==EQ)  
                fprintf(fp, "  beq $t1,$t2,%s\n", h->result.id);
            else                 
                fprintf(fp, "  bne $t1,$t2,%s\n", h->result.id);
            break;
        case ARG:
            break;

        case RETURN:
            if(!main_flag){
                fprintf(fp, "  lw $v0,%d($sp)\n",h->result.offset); //����ֵ�͵�$v0
                fprintf(fp, "  jr $ra\n");
            }
            else{
                fprintf(fp, "  li $v0, 10\n");
                fprintf(fp, "  syscall\n");
                main_flag = 0;
            }
            call_flag = 0;
            // main_call--;
            // printf("return : %d\n", main_call);
            LEV--;
            break;

        case CALL:
            call_flag = 1;
            LEV++;
            if (!strcmp(h->opn1.id,"read")){ 
                fprintf(fp, "  addi $sp, $sp, -4\n");
                fprintf(fp, "  sw $ra,0($sp)\n"); 
                fprintf(fp, "  jal read\n"); 
                fprintf(fp, "  lw $ra,0($sp)\n"); 
                fprintf(fp, "  addi $sp, $sp, 4\n");
                fprintf(fp, "  sw $v0, %d($sp)\n",h->result.offset);
                break;
            }
            if (!strcmp(h->opn1.id,"write")){ 
                fprintf(fp, "  lw $a0, %d($sp)\n",h->prior->result.offset);
                fprintf(fp, "  addi $sp, $sp, -4\n");
                fprintf(fp, "  sw $ra,0($sp)\n");
                fprintf(fp, "  jal write\n");
                fprintf(fp, "  lw $ra,0($sp)\n");
                fprintf(fp, "  addi $sp, $sp, 4\n");
                break;
            }
            for(p = h,i = 0;i < symbolTable.symbols[h->opn1.offset].paramnum; i++)  
                p=p->prior;

            // printf("call: %d\n", main_call);
            // if(main_call == 0){
            //     fprintf(fp, "  move $t4,$sp\n");
            // }
            // else if(main_call > 0)
                fprintf(fp, "  move $t0,$sp\n"); 
            // main_call++;
            // printf("call: %d\n", main_call);
            fprintf(fp, "  addi $sp, $sp, -%d\n", symbolTable.symbols[h->opn1.offset].offset);
            fprintf(fp, "  sw $ra,0($sp)\n"); 
            i=h->opn1.offset+1;  
            while (symbolTable.symbols[i].flag == 'P'){
                fprintf(fp, "  lw $t1, %d($t0)\n", p->result.offset);
                fprintf(fp, "  move $t3,$t1\n");
                fprintf(fp, "  sw $t3,%d($sp)\n",  symbolTable.symbols[i].offset);
                p=p->next; 
                i++;
            }
            fprintf(fp, "  jal %s\n",h->opn1.id);
            fprintf(fp, "  lw $ra,0($sp)\n");
            fprintf(fp, "  addi $sp,$sp,%d\n",symbolTable.symbols[h->opn1.offset].offset);
            fprintf(fp, "  sw $v0,%d($sp)\n", h->result.offset); 
            break;
        
        default:
            break;
        }
    h = h->next;
    }while(h != head);
    fclose(fp);
}