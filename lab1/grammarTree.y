%error-verbose
%locations
// 声明部分
%{
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <grammarTree.h>
    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;
    void yyerror(const char *fmt, ...);
    void display(node *, int);
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
// program : 初始语法单元
// ExtDefList : 全局定义列表
// ExtDef : 全局定义：变量、函数、结构体
// Specifier : 类型描述符
// ExtDecList : 声明列表
// FuncDec : 函数头
// ArrayDec : 数组名
// CompSt : 复合语句:函数体、由花括号括起来的语句
// VarList : 变量列表
// VarDec : 变量名
// ParamDec : 形参定义
// Stmt : 语句
// StmtList : 语句列表
// DefList : 变量定义列表
// Def : 变量定义
// DecList : 
// Dec :
// Exp : 表达式
// Args : 实参列表


// %token 定义终结符
%token <type_int> INT
%token <type_char> CHAR
%token <type_float> FLOAT
%token <type_id> ID TYPE RELOP
%token LC RC LB RB LP RP SEMI COMMA
%token PLUS MINUS STAR DIV MOD AND OR NOT AUTOPLUS AUTOMINUS ASSIGNOP PLUSASSIGNOP MINUSASSIGNOP STARASSIGNOP DIVASSIGNOP MODASSIGNOP IF ELSE WHILE BREAK CONTINUE FOR EXTENDS NEW THIS STATIC RETURN

// 优先级
%left PLUSASSIGNOP MINUSASSIGNOP STARASSIGNOP DIVASSIGNOP
%left ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS STAR DIV
%left AUTOPLUS AUTOMINUS
%right NOT UMINUS
// %nonassoc的含义是没有结合性,它一般与%prec结合使用表示该操作有同样的优先级
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%
// 规则部分
// 程序 ： 外部定义列表
program : ExtDefList {display($1, 0);} 
    ;

// 外部定义列表 ： 外部定义 外部定义列表 | 空
ExtDefList : ExtDef ExtDefList {$$ = mknode(2, EXT_DEF_LIST, yylineno, $1, $2);} |
             {$$ = NULL}
    ;

// 外部定义 ： 类型声明 外部声明列表 分号 |
//           类型声明 数组声明 分号 |
//           类型声明 函数声明 分号 |
//           错误
ExtDef : Specifier ExtDecList SEMI {$$ = mknode(2, EXT_VAR_DEF, yylineno, $1, $2);} |
         Specifier FuncDec SEMI {$$ = mknode(2, FUNC_DEF, yylineno, $1, $2);}
    ;

// 类型声明 ：类型
Specifier : TYPE {$$ = mknode(0, TYPE, yylineno);strcpy($$->type_id, $1);$$->type = (!strcmp($1, "int") ? INT : (!strcmp($1, "float") ? FLOAT : CHAR;));}
    ;

// 外部声明列表 ： 变量声明 |
//              变量声明 逗号 外部声明列表
ExtDecList : VarDec {$$ = $1;}|
             VarDec COMMA ExtDecList {$$ = mknode(2, EXT_DEC_LIST, yylineno, $1, $3);}
    ;

// 数组声明 ： 标识符 左中括号 表达式 右中括号 |
//           标识符 左中括号 右总括号 |
//           错误
ArrayDec : LB Exp RB {$$ = $2}| 
           LB Exp RB ArrayDec {$$ = mknode(2, ARRAY_DEC, yylineno, $2, $4);}
    ;

// 函数声明 ： 标识符 左小括号 变量列表 右小括号 |
//           标识符 左小括号 右小括号 |
//           错误
FuncDec : ID LP VarList RP {$$ = mknode(1, FUNC_DEC, yylineno, $3);strcpy($$->type_id, $1);}|
          ID LP RP {$$ = mknode(0, FUNC_DEC, yylineno); strcpy($$->type_id, $1);$$->ptr[0]=NULL;}
    ;

// 变量声明 ： 标识符|
//           标识符 数组声明
VarDec : ID {$$ = mknode(0, ID, yylineno); strcpy($$->type_id, $1);}|
         ID ArrayDec {$$ = mknode(1, ARRAY_DEC, yylineno, $2); strcpy($$->type_id, $1);}
    ;

// 变量列表 ： 参数声明 | 
//           参数声明 逗号 变量列表
VarList : ParamDec {$$ = mknode(1, PARAM_LIST, yylineno, $1);}|
          ParamDec COMMA VarList {$$ = mknode(2, PARAM_LIST, yylineno, $1, $3);}
    ;

// 参数声明 ： 类型 变量声明
ParamDec : Specifier VarDec {$$ = mknode(2, PARAM_DEC, yylineno, $1, $2);}
    ;

// 复合语句 ： 左大括号 定义列表 语句列表 右大括号 |
//           错误
CompSt : LC DefList StmList RC {$$ = mknode(2, COMP_STM, yylineno, $2, $3);}
    ;

// 语句列表 ： 语句 语句列表 |
//           空
StmList : Stmt StmList {$$ = mknode(2, STM_LIST, yylineno, $1, $2);} |
          {$$ = NULL;}
    ;

// 语句 ： 表达式 分号 |
//        复合语句 |
//        return 表达式 分号 |
//        if 左小括号 表达式 右小括号 语句 %prec LOWER_THEN_ELSE
//        if 左小括号 表达式 右小括号 语句 else 语句
//        while 左小括号 表达式 右小括号 语句
//        for 左小括号 表达式 分号 表达式 分号 表达式 右小括号 语句
Stmt : Exp SEMI {$$ = mknode(1, EXP_STMT, yylineno, $1);}|
       CompSt {$$ = $1;}|
       RETURN Exp SEMI {$$ = mknode(1, RETURN, yylineno, $2);}|
       IF LP Exp RP Stmt %prec LOWER_THEN_ELSE {$$ = mknode(2, IF_THEN, yylineno, $3, $5);}|
       IF LP Exp RP Stmt ELSE Stmt {$$ = mknode(3, IF_THEN_ELSE, yylineno, $3, $5, $7);}|
       WHILE LP Exp RP Stmt {$$ = mknode(2, WHILE, yylineno, $3, $5);}|
       FOR LP Exp SEMI Exp SEMI Exp RP Stmt {$$ = mknode(4, FOR, yylineno, $3, $5, $7, $9);} |
       CONTINUE SEMI {$$ = mknode(0, CONTINUE, yylineno);} |
       BREAK SEMI {$$ = mknode(0, BREAK, yylineno);}
    ;

// 定义列表 ： 定义 定义列表 |
//           空
DefList: Def DefList {$$ = mknode(2, DEF_LIST, yylineno, $1, $2);}|
          {$$ = NULL;}

// 定义 ： 类型声明 声明列表 分号 |
//        类型声明 数组声明 分号
Def: Specifier DecList SEMI {$$ = mknode(2, VAR_DEF, yylineno, $1, $2);}|
      Specifier ArrayDec SEMI {$$ = mknode(2, ARRAY_DEF, yylineno, $1, $2);}
    ;

// DecList
DecList : Dec {$$ = mknode(1, DEC_LIST, yylineno, $1);}|
          Dec COMMA DecList {$$ = mknode(2, DEC_LIST, yylineno, $1, $3);}
    ;

// Dec
Dec : VarDec {$$ = $1;} |
      VarDec ASSIGNOP Exp {$$ = mknode(2, ASSIGNOP, yylineno, $1, $3);strcpy($$->type_id, "ASSIGNOP");}

// 表达式 : 整型常数 |
//         浮点常数 |
//         字符型常数 |
//         布尔型常数 |
//         表达式 加 表达式 |
//         表达式 减 表达式 |
//         表达式 乘 表达式 |
//         表达式 除 表达式 |
//         表达式 模 表达式 |
//         表达式 自增 |
//         表达式 自减 |
//         自增 表达式 |
//         自减 表达式 |
//         表达式 赋值 表达式 |
//         表达式 加赋值 表达式 |
//         表达式 减赋值 表达式 |
//         表达式 乘赋值 表达式 |
//         表达式 除赋值 表达式 |
//         表达式 模赋值 表达式 |
//         表达式 按位与 表达式 |
//         表达式 按位或 表达式 |
//         表达式 大小比较 表达式 |
//         非 表达式 |
//         括号 表达式 括号 |
//         负号 表达式 |
//         标识符 |
//         标识符 左小括号 右小括号 |
//         标识符 左小括号 实参列表 右小括号 |
//         标识符 数组
Exp : INT {$$ = mknode(0, INT, yylineno); $$->type = INT; $$->type_int = $1;}|
      FLOAT {$$ = mknode(0, FLOAT, yylineno); $$->type = FLOAT; $$->type_float = $1;}|
      CHAR {$$ = mknode(0, CHAR, yylineno); $$->type = CHAR; $$->type_char = $1;}|
    //   TRUE {$$ = mknode(0, BOOL, yylineno); $$->type = BOOL; $$->type_bool = 1;}|
    //   FALSE {$$ = mknode(0, BOOL, yylineno); $$->type = BOOL; $$->type_bool = 0;}|
      Exp PLUS Exp {$$ = mknode(2, PLUS, yylineno, $1, $3); strcpy($$->type_id, "PLUS");}|
      Exp MINUS Exp {$$ = mknode(2, MINUS, yylineno, $1, $3); strcpy($$->type_id, "MINUS");}|
      Exp STAR Exp {$$ = mknode(2, STAR, yylineno, $1, $3); strcpy($$->type_id, "STAR");}|
      Exp DIV Exp {$$ = mknode(2, DIV, yylineno, $1, $3); strcpy($$->type_id, "DIV");}|
      Exp MOD Exp {$$ = mknode(2, MOD, yylineno, $1, $3); strcpy($$->type_id, "MOD");}|
      Exp AUTOPLUS {$$ = mknode(1, AUTOPLUS, yylineno, $1); strcpy($$->type_id, "AUTOPLUS");}|
      Exp AUTOMINUS {$$ = mknode(1, AUTOMINUS, yylineno, $1); strcpy($$->type_id, "AUTOMINUS");}|
      AUTOPLUS Exp {$$ = mknode(1, AUTOPLUS, yylineno, $2); strcpy($$->type_id, "AUTOPLUS");}|
      AUTOMINUS Exp {$$ = mknode(1, AUTOMINUS, yylineno, $2); strcpy($$->type_id, "AUTOMINUS");}|
      Exp ASSIGNOP Exp {$$ = mknode(2, ASSIGNOP, yylineno, $1, $3); strcpy($$->type_id, "ASSIGNOP");}|
      Exp PLUSASSIGNOP Exp {$$ = mknode(2, PLUSASSIGNOP, yylineno, $1, $3); strcpy($$->type_id, "PLUSASSIGNOP");}|
      Exp MINUSASSIGNOP Exp {$$ = mknode(2, MINUSASSIGNOP, yylineno, $1, $3); strcpy($$->type_id, "MINUSASSIGNOP");}|
      Exp STARASSIGNOP Exp {$$ = mknode(2, STARASSIGNOP, yylineno, $1, $3); strcpy($$->type_id, "STARASSIGNOP");}|
      Exp DIVASSIGNOP Exp {$$ = mknode(2, DIVASSIGNOP, yylineno, $1, $3); strcpy($$->type_id, "DIVASSIGNOP");}|
      Exp MODASSIGNOP Exp {$$ = mknode(2, MODASSIGNOP, yylineno, $1, $3); strcpy($$->type_id, "MODASSIGNOP");}|
      Exp AND Exp {$$ = mknode(2, AND, yylineno, $1, $3); strcpy($$->type_id, "AND");}|
      Exp OR Exp {$$ = mknode(2, OR, yylineno, $1, $3); strcpy($$->type_id, "OR");}|
      Exp RELOP Exp {$$ = mknode(2, RELOP, yylineno, $1, $3); strcpy($$->type_id, "RELOP");}|
      NOT Exp {$$ = mknode(1, NOT, yylineno, $2); strcpy($$->type_id, "NOT");}|
      LP Exp RP {$$ = $2;}|
      MINUS Exp %prec UMINUS {$$ = mknode(1, UMINUS, yylineno, $2); strcpy($$->type_id, "UMINUS");}|
      ID {$$ = mknode(0, ID, yylineno); strcpy($$->type_id, $1);} |
      ID LP RP {$$ = mknode(0, FUNC_CALL, yylineno); strcpy($$->type_id, $1);} |
      ID LP Args RP {$$ = mknode(1, FUNC_CALL, yylineno, $3); strcpy($$->type_id, $1);} |
      ID ArrayDec {$$ = mknode(1, ARRAY_ID, yylineno, $2); strcpy($$->type_id, $1);}
    ;

// 实参列表
Args : Exp COMMA Args {$$ = mknode(2, ARGS, yylineno, $1, $3);}|
       Exp {$$ = mknode(1, ARGS, yylineno, $1);}
    ;

%%
int main(int args, int *argv[]){
    yyin = fopen(argv[1], "r");
    if(!yyin) 
        return 0;
    yylineno = 1;
    yyparse();
    return 0;
}

#include <stdarg.h>
void yyerror(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}



