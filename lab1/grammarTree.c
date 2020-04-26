#include "grammarTree.h"
#define OFFSET 5

node *mknode(int num, int kind, int pos, ...){
    node *temp = (node *)malloc(sizeof(node));
    temp->kind = kind;
    temp->line = pos;
    va_list pArgs;
    va_start(pArgs, pos);
    int i;
    for(i = 0; i < num; i++){
        temp->ptr[i] = va_arg(pArgs, node *);
    }
    while(i < 4) 
        temp->ptr[i++] = NULL;
    va_end(pArgs);
    return temp;
}

void display(node *node, int indent){
    struct node *temp;
    switch (node->kind)
    {
    case EXT_DEF_LIST:
        display(node->ptr[0], indent);   // 显示外部定义列表的第一个
        display(node->ptr[1], indent);   // 显示外部定义列表其他定义
        break;
    case EXT_VAR_DEF:
        printf("%*c%s", indent, ' ', "外部变量定义:"); 
        display(node->ptr[0], indent+OFFSET); // 显示外部变量类型 
        printf("%*c%s", indent, ' ', "变量名:");
        display(node->ptr[1], indent+OFFSET); // 显示外部变量列表
        break;
    case TYPE:
        printf("%*c类型为: %s", indent, ' ', node->type_id);
        break;
    case EXT_DEC_LIST:
        display(node->ptr[0], indent);
        display(node->ptr[1], indent);
        break;
    case FUNC_DEF:
        printf("%*c函数定义: (%d)\n", indent, ' ', node->line);
        display(node->ptr[0], indent+OFFSET);
        display(node->ptr[1], indent+OFFSET);
        display(node->ptr[2], indent+OFFSET);
        break;
    case FUNC_DEC:
        printf("%*c函数名: %s\n", indent, ' ', node->type_id);
        if(node->ptr[0]){
            printf("%*c函数形参: ", indent, ' ');
            display(node->ptr[0], indent+OFFSET);
        }
        else
        {
            printf("%*c无参函数\n", indent, ' ');
        }
        break;
    case PARAM_LIST:
        display(node->ptr[0], indent);
        display(node->ptr[1], indent);
        break;
    case PARAM_DEC:
        printf("%*c类型: %s, 参数名: %s\n", indent, ' ', node->ptr[0]->type == INT ? "int":(node->ptr[0]->type==FLOAT?"float":"char"), node->ptr[1]->type_id);
        break;
    case EXP_STMT:
        printf("%*c表达式语句: (%d)\n", indent, ' ', node->line);
        display(node->ptr[0], indent+OFFSET);
    case RETURN:
        printf("%*c返回语句: (%d)\n", indent, ' ', node->line);
        display(node->ptr[0], indent+OFFSET);
        break;
    case BREAK:
        printf("%*c跳出语句: (%d)\n", indent, ' ', node->line);
        break;
    case CONTINUE:
        printf("%*c继续语句: (%d)\n", indent, ' ', node->line);
        break;
    case COMP_STM:
        printf("%*c复合语句: (%d)\n", indent, ' ', node->line);
        printf("%*c复合语句变量定义部分: \n", indent+OFFSET, ' ');
        display(node->ptr[0], indent+OFFSET*2);
        printf("%*c复合语句语句部分: \n", indent, ' ');
        display(node->ptr[1], indent+OFFSET*2);    
        break;
    case STM_LIST:
        display(node->ptr[0], indent);
        display(node->ptr[1], indent);
        break;
    case WHILE:
        printf("%*c循环语句: (%d)\n", indent, ' ', node->line);
        printf("%*c循环条件: \n", indent+OFFSET, ' ');
        display(node->ptr[0], indent+OFFSET*2);
        printf("%*c循环体: (%d)\n", indent, ' ', node->line);
        display(node->ptr[1], indent+OFFSET*2);
        break;
    case FOR:
        printf("%*c循环语句: (%d)\n", indent, ' ', node->line);
        printf("%*c循环初始定义: \n", indent+OFFSET, ' ');
        display(node->ptr[0], indent+OFFSET*2);
        printf("%*c循环条件: \n", indent+OFFSET, ' ');
        display(node->ptr[1], indent+OFFSET*2);
        printf("%*c循环变化表达式: \n", indent+OFFSET, ' ');
        display(node->ptr[2], indent+OFFSET*2);
        printf("%*c循环体: \n", indent+OFFSET, ' ');
        display(node->ptr[3], indent+OFFSET*2);
        break;
    case IF_THEN:
        printf("%*c条件语句(IF_THEN): (%d)\n", indent, ' ', node->line);
        printf("%*c条件: \n", indent+OFFSET, ' ');
        display(node->ptr[0], indent+OFFSET*2);
        printf("%*cIF子句: \n", indent+OFFSET, ' ');
        display(node->ptr[1], indent+OFFSET*2);
        break;
    case IF_THEN_ELSE:
        printf("%*c条件语句(IF_THEN_ELSE): (%d)\n", indent, ' ', node->line);
        printf("%*c条件: \n", indent+OFFSET, ' ');
        display(node->ptr[0], indent+OFFSET*2);
        printf("%*cIF子句: \n");
        display(node->ptr[1], indent+OFFSET*2);
        printf("%*cELSE子句: \n", indent+OFFSET, ' ');
        display(node->ptr[2], indent+OFFSET*2);
        break;
    case DEF_LIST:
        printf("%*c变量名: \n", indent, ' ');
        temp = node;
        while(temp){
            if(temp->ptr[0]->kind == ID){
                printf("%*c%s\n", indent+OFFSET*2, ' ', temp->ptr[0]->type_id);
            }
            else if(temp->ptr[0]->kind == ARRAY_DEC){
                printf("%*c %s\n", indent+OFFSET*2, ' ', temp->ptr[0]->type_id);
                printf("%*c 数组维度\n", indent+OFFSET*2, ' ');
                display(temp->ptr[0]->ptr[0], indent+OFFSET*2);
            }
            else if(temp->ptr[0]->kind == ASSIGNOP){
                printf("%*c %s ASSIGNOP\n", indent+OFFSET*2, ' ', temp->ptr[0]->ptr[0]->type_id);
                display(temp->ptr[0]->ptr[1], indent+strlen(temp->ptr[0]->ptr[0]->type_id)+OFFSET*2+1);
            }
            temp = temp->ptr[0];
        }
        break;
    case ARRAY_DEC:
        display(node->ptr[0], indent);
        display(node->ptr[0], indent);
        break;
    case ID:
        printf("%*cID : %s\n", indent, ' ', node->type_id);
        break;
    case INT:
        printf("%*cINT : %d\n", indent, ' ', node->type_int);
        break;
    case FLOAT:
        printf("%*cFLOAT: %f\n", indent, ' ', node->type_float);
        break;
    case CHAR:
        printf("%*cCHAR: %c\n", indent, ' ', node->type_char);
        break;
    case ASSIGNOP:
    case PLUSASSIGNOP:
    case MINUSASSIGNOP:
    case STARASSIGNOP:
    case DIVASSIGNOP:
    case MODASSIGNOP:
    case PLUS:
    case MINUS:
    case STAR:
    case DIV:
    case MOD:
    case AND:
    case OR:
    case RELOP:
        printf("%*c%s\n", indent, ' ', node->type_id);
        display(node->ptr[0], indent+OFFSET);
        display(node->ptr[0], indent+OFFSET);
        break;
    case UMINUS:
    case NOT:
        printf("%*c%s\n", indent, ' ', node->type_id);
        display(node->ptr[0], indent+OFFSET);
        break;
    case FUNC_CALL:
        printf("%*c函数调用: (%d)\n", indent, node->line);
        printf("%*c函数名: %s\n", indent+OFFSET, ' ', node->type_id);
        display(node->ptr[0], indent+OFFSET);
        break;
    case ARGS:{
        int i = 1;
        while(node){
            struct node *temp = node->ptr[0];
            printf("%*c第%d个实际参数表达式: \n", indent, ' ', i++);
            display(temp, indent+OFFSET);
            temp = temp->ptr[1];
        }
        printf("\n");
        break;
    }
    default:
        break;
    }
}