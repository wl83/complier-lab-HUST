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

void display(node *node, int level){

}