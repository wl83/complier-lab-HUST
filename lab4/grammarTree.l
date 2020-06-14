%{
#include "grammarTree.tab.h"
#include "string.h"
#include "grammarTree.h"
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
typedef union {
	int type_int;
	char type_char[5];
	float type_float;
	char type_id[32];
	char type_string[32];
	char struct_name[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
%option yylineno

ID   [A-Za-z_]([A-Za-z0-9_])*  
INT_DEX [1-9][0-9]*|[0]
INT_HEX [0][Xx]([1-9a-fA-F][0-9a-fA-F]*|[0])
INT_OCT [0][0-7]*
FLOAT [0-9]*[.][0-9]+([eE][-+]?([1-9][0-9*]|[0]))?
CHAR \'(\\.|[^'])\'
STRING \"(\\.|[^"\\])*\"


%%
{INT_DEX} {yylval.type_int=atoi(yytext); return INT;}
{INT_HEX} {
	char sub[20] = {'\0'};
	int s = 0;
	int base = 1; 
	strncpy(sub, yytext+2, strlen(yytext)-2);
	for(int i = strlen(sub)-1; i >= 0;i--){
		if(sub[i] >= '0' && sub[i] <= '9'){
			s += (sub[i] - '0') * base;
		}
		else if(sub[i] >= 'a' && sub[i] <= 'f'){
			s += (sub[i] - 'a' + 10) * base;
		}
		else if(sub[i] >= 'A' && sub[i] <= 'F'){
			s += (sub[i] - 'A' + 10) * base;
		}
		base *= 16;
	}
	yylval.type_int = s;
	return INT;
}
{INT_OCT} {
	char sub[20] = {'\0'};
	int s = 0;
	int base = 1;
	strncpy(sub, yytext+1, strlen(yytext)-1);
	for(int i = strlen(sub)-1; i >= 0;i--){
		if(sub[i] >= '0' && sub[i] <= '7'){
			s += (sub[i] - '0') * base;
		}
		base *= 8;
	}
	yylval.type_int = s; 
	return INT;
}
{FLOAT}  {yylval.type_float=atof(yytext); return FLOAT;}
{CHAR}   {strcpy(yylval.type_char,yytext);return CHAR;}
{STRING} {strcpy(yylval.type_string,yytext);return STRING;}
"int"    {strcpy(yylval.type_id, yytext);return TYPE;}
"float"  {strcpy(yylval.type_id, yytext);return TYPE;}
"char"   {strcpy(yylval.type_id, yytext);return TYPE;}
"string" {strcpy(yylval.type_id, yytext);return TYPE;}
"void"   {strcpy(yylval.type_id, yytext);return TYPE;}
"struct" {return STRUCT;}
"return" {return RETURN;}
"if"     {return IF;}
"else"   {return ELSE;}
"while"  {return WHILE;}
"for"    {return FOR;}
"continue" {return CONTINUE;}
"break"  {return BREAK;}
"switch" {return SWITCH;}
"case"   {return CASE;}
"default" {return DEFAULT;}


{ID}     {strcpy(yylval.type_id,  yytext); return ID;}
";"		 {return SEMI;}
":"      {return COLON;}
","		 {return COMMA;}
"."      {return DOT;}
">"|"<"|">="|"<="|"=="|"!=" {strcpy(yylval.type_id, yytext);return RELOP;}
"="		 {return ASSIGNOP;}
"+"		 {return PLUS;}
"-"		 {return MINUS;}
"*"		 {return STAR;}
"/"		 {return DIV;}
"%"      {return MOD;}
"&&"     {return AND;}
"||"     {return OR;}
"!"		 {return NOT;}
"++"     {return AUTOPLUS;}
"--"     {return AUTOMINUS;}
"+="     {return PLUSASSIGNOP;}
"-="     {return MINUSASSIGNOP;}
"*="     {return STARASSIGNOP;}
"/="     {return DIVASSIGNOP;}
"%="     {return MODASSIGNOP;}
"("		 {return LP;}
")"		 {return RP;}
"{"		 {return LC;}
"}"		 {return RC;}
"["      {return LB;}
"]"      {return RB;}
[\n]     {yycolumn=1;}   
[ \r\t]  {}   
.		 {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
[\/][\/].* {}//匹配注释的正则表达式
[\/][\*][^\*]*[\*]+([^\*\/][^\*]*[\*]+)*[\/] {}//匹配注释的正则表达式

%%

/* 和bison联用时，不需要这部分
void main()
{
yylex();
return 0;
}

*/
int yywrap()
{
    return 1;
}