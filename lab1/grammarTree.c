#include "grammarTree.h"

node *mknode(int kind, node *node1, node *node2, node *node3, int line){
    node *temp = (node *)malloc(sizeof(node));
    temp->kind = kind;
    temp->ptr[0] = node1;
    temp->ptr[1] = node2;
    temp->ptr[2] = node3;
    temp->line = line;
    return temp;
}

void eval(node *node, int level){

}