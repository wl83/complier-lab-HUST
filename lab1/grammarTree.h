#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

extern int yylineno;
extern char *yytext;
void yyerror(char *s, ...);

// 抽象语法树
typedef struct node{
    int line;
    char *name;
    int level;
    int kind;
    node *ptr[3];
    union{ // 存放ID/INT/FLOAT/CHAR的值
        char *identifier;
        int constant_int;
        float constant_float;
    };
}node;

// 构造抽象语法树，变长参数，name:语法单元名称，num:变长参数中语法节点的个数
node *mknode(int kind, node *node1, node *node2, node *node3, int pos);

// 遍历抽象语法树, level:语法树的层次
void eval(node *node, int level);