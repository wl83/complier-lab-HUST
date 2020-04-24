// 声明部分
%{
    #include <stdio.h>
    #include <string.h>
    #include <grammarTree.h>
%}

%union{
    int type_int;
    float type_float;
    char type_char;
    char type_id[32];
    struct node *ptr;
}

// %type 定义非终结符的语义值类型
%type <ptr> program ExtDefList ExtDef Specifier ExtDecList FuncDec ArrayDec CompSt VarList VarDec ParamDec Stmt StmList DefList Def DecList Dec Exp Args

// %token 定义终结符
%token <type_int> INT
%token <type_char> CHAR
%token <type_float> FLOAT
%token <type_id> ID TYPE RELOP
%token LP RP LB RB LP RP SEMI COMMA
%token PLUS MINUS STAR DIV MOD AND OR NOT PLUSSELF MINUSSELF ASSIGNOP PLUSASSIGNOP MINUSASSIGNOP STARASSIGNOP DIVASSIGNOP IF ELSE WHILE BREAK CONTINUE FOR SWITCH CASE NULL EXTENDS NEW THIS STATIC TRUE FALSE RETURN

// 优先级
%left PLUSASSIGNOP MINUSASSIGNOP STARASSIGNOP DIVASSIGNOP
%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS STAR DIV
%right PLUSSELF MINUSSELF
// %nonassoc的含义是没有结合性,它一般与%prec结合使用表示该操作有同样的优先级
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

// 规则部分
// 程序 ： 外部定义列表

// 外部定义列表 ： 外部定义 外部定义列表 | 空

// 外部定义 ： 类型声明 外部声明列表 分号 |
//           类型声明 数组声明 分号 |
//           类型声明 函数声明 分号 |
//           错误

// 类型声明 ：类型

// 外部声明列表 ： 变量声明 |
//              变量声明 逗号 外部声明列表

// 数组声明 ： 标识符 左中括号 表达式 右中括号 |
//           标识符 左中括号 右总括号 |
//           错误

// 函数声明 ： 标识符 左小括号 变量列表 右小括号 |
//           标识符 左小括号 右小括号 |
//           错误

// 变量声明 ： 标识符

// 变量列表 ： 参数声明 | 
//           参数声明 逗号 变量列表

// 参数声明 ： 类型 变量声明

// 复合语句 ： 左大括号 定义列表 语句列表 右大括号 |
//           错误

// 语句列表 ： 语句 语句列表 |
//           空

// 语句 ： 表达式 分号 |
//        复合语句 |
//        return 表达式 分号 |
//        if 左小括号 表达式 右小括号 语句 %prec LOWER_THEN_ELSE
//        if 左小括号 表达式 右小括号 语句 else 语句
//        while 左小括号 表达式 右小括号 语句
//        for 左小括号 表达式 分号 表达式 分号 表达式 右小括号 语句

// 定义列表 ： 定义 定义列表 |
//           空

// 定义 ： 类型声明 声明列表 分号 |
//        类型声明 



