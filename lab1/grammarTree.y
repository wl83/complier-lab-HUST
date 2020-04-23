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


// 规则部分


