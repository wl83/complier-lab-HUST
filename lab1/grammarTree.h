#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "grammarTree.tab.h"

extern int yylineno;
extern char *yytext;

enum{EXT_DEF_LIST, EXT_VAR_DEF, FUNC_DEF, FUNC_DEC, EXT_DEC_LIST, PARAM_LIST,
     PARAM_DEC, VAR_DEF, DEC_LIST, DEF_LIST, COMP_STM, STM_LIST, EXP_STMT, 
     IF_THEN, IF_THEN_ELSE, FUNC_CALL, ARGS, FUNCTION, PARAM, ARG, CALL, 
     LABEL, GOTO, JLT, JLE, JGT, JGE, EQ, NEQ, AUTO_ADD_L, AUTO_ADD_R, 
     AUTO_SUB_L, AUTO_SUB_R, ARRAY_ID, ARRAY_DEC, ARRAY};

// 抽象语法树
typedef struct node{
    int line;
    char *name;
    int level;
    int kind;
    struct node *ptr[4];
    int type;
    union{ // 存放ID/INT/FLOAT/CHAR的值
        char type_id[32];
        int type_int;
        float type_float;
        char type_char;
    };
}node;

// 构造抽象语法树，变长参数，name:语法单元名称，num:变长参数中语法节点的个数
node *mknode(int num, int kind, int pos, ...);