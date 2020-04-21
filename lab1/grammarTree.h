#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

extern int yylineno;
extern char *yytext;
void yyerror(char *s, ...);

// 抽象语法树
typedef struct AST{
    int line;
    char *name;
    int level;
    AST *left;
    AST *right;
    union{ // 存放ID/INT/FLOAT/CHAR的值
        char *identifier;
        int integer;
        float flt;
    };
}AST;

// 构造抽象语法树，变长参数，name:语法单元名称，num:变长参数中语法节点的个数
AST *mknode(char *name, int num, ...);

// 遍历抽象语法树, level:语法树的层次
void eval(AST *ast, int level);