#include "grammarTree.h"

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
    switch (node->kind)
    {
    case EXT_DEF_LIST:
        display(node->ptr[0], indent);   // 显示外部定义列表的第一个
        display(node->ptr[1], indent);   // 显示外部定义列表其他定义
        break;
    case EXT_VAR_DEF:
        printf("%*c%s", indent, ' ', "外部变量定义:"); 
        display(node->ptr[0], indent+5); // 显示外部变量类型 
        printf("%*c%s", indent, ' ', "变量名:");
        display(node->ptr[1], indent+5); // 显示外部变量列表
        break;
    case TYPE:
        if(node->type == INT)
            printf("%*c%s\n", indent, ' ', "类型为: int");
        else if(node->type == CHAR)
            printf("%*c%s\n", indent, ' ', "类型为: char");
        else if(node->type == FLOAT)
            printf("%*c%s\n", indent, ' ', "类型为: float");
    default:
        break;
    }
}