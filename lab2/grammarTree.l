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
{INT_DEX} {printf("(%s, CONSTANTINT)\n", yytext);yylval.type_int=atoi(yytext); return INT;}
{INT_HEX} {
	char sub[20] = {'\0'};
	int s = 0;
	int base = 1;
	printf("(%s, CONSTANTINTH)\n", yytext); 
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
	printf("(%s, CONSTANTINTO)\n", yytext); 
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
{FLOAT}  {printf("(%s, CONSTANTFLOAT)\n", yytext);yylval.type_float=atof(yytext); return FLOAT;}
{CHAR}   {printf("(%s, CONSTANTCHAR)\n", yytext);strcpy(yylval.type_char,yytext);return CHAR;}
{STRING} {printf("(%s, CONSTANTSTRING)\n", yytext);strcpy(yylval.type_string,yytext);return STRING;}
"int"    {printf("(%s, TYPEINT)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"float"  {printf("(%s, TYPEFLOAT)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"char"   {printf("(%s, TYPECHAR)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"string" {printf("(%s, TYPESTRING)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"void"   {printf("(%s, TYPEVOID)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
"struct" {printf("(%s, TYPESTRUCT)\n", yytext);return STRUCT;}
"return" {printf("(%s, RETURN)\n", yytext);return RETURN;}
"if"     {printf("(%s, IF)\n", yytext);return IF;}
"else"   {printf("(%s, ELSE)\n", yytext);return ELSE;}
"while"  {printf("(%s, WHILE)\n", yytext);return WHILE;}
"for"    {printf("(%s, FOR)\n", yytext); return FOR;}
"continue" {printf("(%s, CONTINUE)\n", yytext);return CONTINUE;}
"break"  {printf("(%s, BREAK)\n", yytext); return BREAK;}
"switch" {printf("(%s, SWITCH)\n", yytext);return SWITCH;}
"case"   {printf("(%s, CASE)\n", yytext);return CASE;}
"default" {printf("(%s, DEFAULT)\n", yytext);return DEFAULT;}


{ID}     {printf("(%s, INDENTIFIER)\n", yytext);strcpy(yylval.type_id,  yytext); return ID;}
";"		 {printf("(%s, SEMI)\n", yytext);return SEMI;}
":"      {printf("(%s, COLON)\n", yytext);return COLON;}
","		 {printf("(%s, COMMA)\n", yytext);return COMMA;}
"."      {printf("(%s, DOT)\n", yytext);return DOT;}
">"|"<"|">="|"<="|"=="|"!=" {printf("(%s, RELOP)\n", yytext);strcpy(yylval.type_id, yytext);return RELOP;}
"="		 {printf("(%s, ASSIGNOP)\n", yytext);return ASSIGNOP;}
"+"		 {printf("(%s, PLUSOP)\n", yytext);return PLUS;}
"-"		 {printf("(%s, MINUSOP)\n", yytext);return MINUS;}
"*"		 {printf("(%s, STAROP)\n", yytext);return STAR;}
"/"		 {printf("(%s, DIVOP)\n", yytext);return DIV;}
"%"      {printf("(%s, MODOP)\n", yytext);return MOD;}
"&&"     {printf("(%s, ANDOP)\n", yytext);return AND;}
"||"     {printf("(%s, OROP)\n", yytext);return OR;}
"!"		 {printf("(%s, NOTOP)\n", yytext);return NOT;}
"++"     {printf("(%s, AUTOPLUSOP)\n", yytext); return AUTOPLUS;}
"--"     {printf("(%s, AUTOMINUSOP)\n", yytext); return AUTOMINUS;}
"+="     {printf("(%s, PLUSASSIGNOP)\n", yytext); return PLUSASSIGNOP;}
"-="     {printf("(%s, MINUSASSIGNOP)\n", yytext); return MINUSASSIGNOP;}
"*="     {printf("(%s, STARASSIGNOP)\n", yytext);return STARASSIGNOP;}
"/="     {printf("(%s, DIVASSIGNOP)\n)", yytext);return DIVASSIGNOP;}
"%="     {printf("(%s, MODASSIGNOP)\n", yytext);return MODASSIGNOP;}
"("		 {printf("(%s, LP)\n", yytext);return LP;}
")"		 {printf("(%s, RP)\n", yytext);return RP;}
"{"		 {printf("(%s, LC)\n", yytext);return LC;}
"}"		 {printf("(%s, RC)\n", yytext);return RC;}
"["      {printf("(%s, LB)\n", yytext);return LB;}
"]"      {printf("(%s, LC)\n", yytext);return RB;}
[\n]     {printf("(\\n, EOL)\n");yycolumn=1;}   
[ \r\t]  {}   
.		 {printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
[\/][\/].* {printf("(%s, LINECOMMENT)\n", yytext);}//匹配注释的正则表达式
[\/][\*][^\*]*[\*]+([^\*\/][^\*]*[\*]+)*[\/] {printf("(%s, BLOCKCOMMENT)\n", yytext);}//匹配注释的正则表达式

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