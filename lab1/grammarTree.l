%{
#include "parser.tab.h"
#include "string.h"
#include "stdio.h"
#include "def.h"
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
typedef union {
	int type_int;
	float type_float;
	char type_char;
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
/* yylineno 记录行号 */
%option yylineno

INT_DEX [-+]?[1-9][0-9]*|[0]
INT_HEX [0][Xx]([1-9][0-9]*|[0])
INT_OCT [0][0-7]*
FLOAT [-+]?[0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?f?
CHAR ['][a-zA-z0-9][']
STRING ["][^\n]*["]
ID [a-zA-Z][a-zA-Z0-9]*
TYPEINT int
TYPEFLOAT float
TYPECHAR char
TYPECLASS class
TYPESTRING string
TYPEVOID void
TYPEBOOL bool
IF if
ELSE else
BREAK break
WHILE while
CONTINUE continue
FOR for
THIS this
NEW new
NULL null
EXTENDS extends
RETURN return
STATIC static
TRUE true
FALSE false
LC [{]
RC [}]
LB [[]
RB []]
LP [(]
RP [)]
RELOP >|<|>=|<=|==|!=
PLUS [+]
MINUS [-]
STAR [*]
DIV [/]
MOD [%]
SEMI [;]
DOT [.]
COMMA [,]
ASSIGNOP [=]
PLUSASSIGNOP [+][=]
MINUSASSIGNOP [-][=]
STARASSIGNOP [*][=]
DIVASSIGNOP [/][=]
MODASSIGNOP [%][=]
AUTOPLUS [+][+]
AUTOMINUS [-][-]
AND [&][&]
OR [|][|]
NOT [!]
EOL [\n]
SPACE [ \t\r]*
LINECOM "//"[^\n]*
BLOCKCOM "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"

%%
{INT_DEX} {
    printf("(%s, CONSTANTINT)\n", yytext);
    yylval.type_int = atoi(yytext);
    return INT;
}

{INT_HEX} {
    printf("(%s, CONSTANTINTH)\n", yytext);
    yylval.type_int = atoi(yytext);
    return INT;
}

{INT_OCT} {
    printf("(%s, CONSTANTINTO)\n", yytext);
    yylval.type_int = atoi(yytext);
    return INT;
}

{FLOAT} {
    printf("(%s, CONSTANTFLOAT)\n", yytext);
    yylval.type_float = atof(yytext);
    return FLOAT;
}

{CHAR} {
    printf("(%s, CONSTANTCHAR)\n", yytext);
    yylval.type_char = yytext[0];
    return CHAR;
}

{ID} {
    printf("(%s, IDENTIFIER)\n", yytext);
    strcpy(yylval.type_id, ID);
    return ID;
}

{STRING} {
    printf("(%s, CONSTANTSTRING)\n", yytext);
    return STRING;
}

{TYPEINT} {
    printf("(%s, TYPEINT)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{TYPEFLOAT} {
    printf("(%s, TYPEFLOAT)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{TYPECHAR} {
    printf("(%s, TYPECHAR)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{TYPESTRING} {
    printf("(%s, TYPESTRING)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{TYPECLASS} {
    printf("(%s, TYPECLASS)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{TYPEVOID} {
    printf("(%s, TYPEVOID)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{TYPEBOOL} {
    printf("(%s, TYPEBOOL)\n", yytext);
    strcpy(yylval.type_id, yytext);
    return TYPE;
}

{IF} {
    printf("(%s, IF)\n", yytext);
    return IF;
}

{ELSE} {
    printf("(%s, ELSE)\n", yytext);
    return ELSE;
}

{BREAK} {
    printf("(%s, BREAK)\n", yytext);;
    return BREAK;
}

{WHILE} {
    printf("(%s, WHILE)\n", yytext);
    return WHILE;
}

{CONTINUE} {
    printf("(%s, CONTINUE)\n", yytext);
    return CONTINUE;
}

{FOR} {
    printf("(%s, FOR)\n", yytext);
    return FOR;
}

{THIS} {
    printf("(%s, THIS)\n", yytext);
    return THIS;
}

{NEW} {
    printf("(%s, NEW)\n", yytext);
    return NEW;
}

{NULL} {
    printf("(%s, NULL)\n", yytext);
    return NULL;
}

{EXTENDS} {
    printf("(%s, EXTENDS)\n", yytext);
    return EXTENDS;
}

{RETURN} {
    printf("(%s, RETURN)\n", yytext);
    return RETURN;
}

{STATIC} {
    printf("(%s, STATIC)\n", yytext);
    return STATIC;
}

{TRUE} {
    printf("(%s, TRUE)\n", yytext);
    return TRUE;
}

{FALSE} {
    printf("(%s, FALSE)\n", yytext);
    return FALSE;
}

{LC} {
    printf("(%s, LC)\n", yytext);
    return LC;
}

{RC} {
    printf("(%s, RC)\n", yytext);
    return RC;
}

{LB} {
    printf("(%s, LB)\n", yytext);
    return LB;
}

{RB} {
    printf("(%s, RB)\n", yytext);
    return RB;
}

{LP} {
    printf("(%s, LP)\n", yytext);
    return LP;
}

{RP} {
    printf("(%s, RP)\n", yytext);
    return RP;
}

{RELOP} {
    printf("(%s, RELOP)\n", yytext);
    return RELOP;
}

{PLUS} {
    printf("(%s, PLUS)\n", yytext);
    return PLUS;
}

{MINUS} {
    printf("(%s, MINUS)\n", yytext);
    return MINUS;
}

{STAR} {
    printf("(%s, STAR)\n", yytext);
    return STAR;
}

{DIV} {
    printf("(%s, DIV)\n", yytext);
    return DIV;
}

{MOD} {
    printf("(%s, MOD)\n", yytext);
    return MOD;
}

{SEMI} {
    printf("(%s, SEMI)\n", yytext);
    return SEMI;
}

{DOT} {
    printf("(%s, DOT)\n", yytext);
    return DOT;
}

{COMMA} {
    printf("(%s, COMMA)\n", yytext);
    return COMMA;
}

{ASSIGNOP} {
    printf("(%s, ASSIGNOP)\n", yytext);
    return ASSIGNOP;
}

{PLUSASSIGNOP} {
    printf("(%s, PLUSASSIGNOP)\n", yytext);
    return PLUSASSIGNOP;
}

{MINUSASSIGNOP} {
    printf("(%s, MINUSASSIGNOP)\n", yytext);
    return MINUSASSIGNOP;
}

{STARASSIGNOP} {
    printf("(%s, STARASSIGNOP)\n", yytext);
    return STARASSIGNOP;
}

{DIVASSIGNOP} {
    printf("(%s, DIVASSIGNOP)\n", yytext);
    return DIVASSIGNOP;
}

{MODASSIGNOP} {
    printf("(%s, MODASSIGNOP)\n", yytext);
    return MODASSIGNOP;
}

{AUTOPLUS} {
    printf("(%s, AUTOPLUS)\n", yytext);
    return AUTOPLUS;
}

{AUTOMINUS} {
    printf("(%s, AUTOMINUS)\n", yytext);
    return AUTOMINUS;
}

{AND} {
    printf("(%s, AND)\n", yytext);
    return AND;
}

{OR} {
    printf("(%s, OR)\n", yytext);
    return OR;
}

{NOT} {
    printf("(%s, NOT)\n", yytext);
    return NOT;
}

{EOL} {
    printf("(\\n, EOL)\n");
    return EOL;
}
{LINECOM} {printf("(%s, LINECOM)\n", yytext);}
{BLOCKCOM} {printf("(%s, BLOCKCOM)\n", yytext);}
{SPACE} {}

%%

int yywrap() {
    return 1;
}

int main(int argc, char **argv){
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))){
            perror(argv[1]);
            return 1;
        }
    }
    while(yylex()) ;
    return 0;
}
