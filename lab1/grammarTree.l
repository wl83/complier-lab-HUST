%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "grammarTree.h"
    #include "grammarTree.tab.h"
    typedef union{
        int type_int;
        float type_float;
        char type_char;
        char *type_id;
        char *type_string;
        node *ptr;
    }
%}

INT_DEX [-+]?[1-9][0-9]*|[0]
INT_HEX [0][Xx]([1-9][0-9]*|[0])
INT_OCT [0][0-7]*
FLOAT [-+]?[0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?f?
CHAR ['][a-zA-Z][']
STRING ["][^\n]*["]
PLUS [+]
MINUS [-]
STAR [*]
DIV [/]
MOD [%]
PLUSSELF [+][+]
MINUSSELF [-][-]
LTHAN [<]
GTHAN [>]
LETHAN [<][=]
RETHAN [>][=]
EQUAL [=][=]
NOTEQUAL [!][=]
AND [&][&]
OR [|][|]
NOT [!]
SPSEMICOLON [;]
SPCOMMA [,]
ASSIGNOP [=]
PLUSASSIGN [+][=]
MINUSASSIGN [-][=]
STARASSIGN [*][=]
DIVASSIGN [/][=]
TYPEINT int
TYPEFLOAT float
TYPECHAR char
TYPEVOID void
TYPEBOOL bool
TYPECLASS class
TYPESTRING string
IF if
ELSE else
WHILE while
BREAK break
CONTINUE continue
FOR for
SWITCH switch
CASE case
NULL null
EXTENDS extends
NEW new
THIS this
STATIC static
TRUE true
FALSE false
RETURN return
LINECOM [/][/][^\n]*
LEFTBLOCKCOM [/][*]
RIGHTBLOCKCOM [*][/]
IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
SPACE [ ]
EOL [\n]
TAB [\t]
DOT [.]
LC [{]
RC [}]
LP[(]
RP [)]
LB [\[]
RB [\]]
PRINTFUNC Print

%%

{TYPEINT} {printf("(%s, TYPEINT)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
{TYPEFLOAT} {printf("(%s, TYPEFLOAT)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
{TYPECHAR} {printf("(%s, TYPECHAR)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
{TYPEVOID} {printf("(%s, TYPEVOID)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
{TYPEBOOL} {printf("(%s, TYPEBOOL)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
{TYPECLASS} {printf("(%s, TYPECLASS)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;}
{TYPESTRING} {printf("(%s, TYPESTRING)\n", yytext);strcpy(yylval.type_id, yytext);return TYPE;} 

{IF} {printf("(%s, IF)\n", yytext); return IF};
{ELSE} {printf("(%s, ELSE)\n", yytext); return ELSE};
{WHILE} {printf("(%s, WHILE)\n", yytext); return WHILE};
{BREAK} {printf("(%s, BREAK)\n", yytext); return BREAK};
{CONTINUE} {printf("(%s, CONTINUE)\n", yytext); return CONTINUE};
{FOR} {printf("(%s, FOR)\n", yytext); return FOR};
{SWITCH} {printf("(%s, SWITCH)\n", yytext); return SWITCH};
{CASE} {printf("(%s, CASE)\n", yytext); return CASE};
{NULL} {printf("(%s, NULL)\n", yytext); return NULL};
{EXTENDS} {printf("(%s, EXTENDS)\n", yytext); return EXTENDS};
{NEW} {printf("(%s, NEW)\n", yytext); return NEW};
{THIS} {printf("(%s, THIS)\n", yytext); return THIS};
{STATIC} {printf("(%s, STATIC)\n", yytext); return STATIC};
{TRUE} {printf("(%s, TRUE)\n", yytext); return TRUE};
{FALSE} {printf("(%s, FALSE)\n", yytext); return FALSE};
{RETURN} {printf("(%s, RETURN)\n", yytext);return RETURN;}

{PRINTFUNC} {printf("(%s, PRINTFUNCTION)\n", yytext);return PRINTFUNC;}

{IDENTIFIER} {printf("(%s, IDENTIFIER)\n", yytext);strcpy(yylval.type_id, yytext);return ID;}

{PLUSSELF} {printf("(++, PLUSSELFOPERATOR)\n");return PLUSSELF;}
{MINUSSELF} {printf("(--, MINUSSELFOPERATOR)\n");return MINUSSELF;}


{PLUS} {printf("(%s, PLUSOPERATOR)\n", yytext);return PLUS;}
{MINUS} {printf("(%s, MINUSOPERATOR)\n", yytext);return MINUS;}
{STAR} {printf("(%s, STAROPERATOR)\n", yytext);return STAR;}
{DIV} {printf("(%s, DIVOPERATOR)\n", yytext);return DIV;}
{MOD} {printf("(%s, MODOPERATOR)\n", yytext);return MOD;}


{INT_DEX} {printf("(%s, CONSTANTINTEGER)\n", yytext);yylval.type_int = atoi(yytext);return INT;}
{INT_HEX} {printf("(%s, CONSTANTINTH)\n", yytext);yylval.type_int = atoi(yytext);return INT;}
{INT_OCT} {printf("(%s, CONSTANTINTO)\n", yytext);yylval.type_int = atoi(yytext);return INT;}


{FLOAT} {printf("(%s, CONSTANTFLOAT)\n", yytext);yylval.type_float = atof(yytext);return FLOAT;}


{CHAR} {printf("(%s, CHAR)\n", yytext);yylval.type_char = yytext[0];return CONSTANTCHAR;}


{STRING} {printf("(%s, STRING)\n", yytext);yylval.type_string = yytext;return STRING;}


{LTHAN} |
{GTHAN} |
{EQUAL} |
{LETHAN} |
{RETHAN} |
{NOTEQUAL} {
    printf("(%s, OPCOMPARE)\n", yytext);
    return RELOP;
}


{AND} {printf("(%s, ANDOPERATOR)\n", yytext);return AND;}
{OR} {printf("(%s, OROPERATOR)\n", yytext);return OR;}
{NOT} {printf("(%s, NOTOPERATOR)\n", yytext);return NOT;}


{ASSIGNOP} {printf("(%s, ASSIGNOPERATOR)\n", yytext);return ASSIGNOP}
{PLUSASSIGN} {printf("(%s, PLUSASSIGNOPERATOR)\n", yytext);return PLUSASSIGNOP}
{MINUSASSIGN} {printf("(%s, MINUSASSIGNOPERATOR)\n", yytext);return MINUSASSIGNOP}
{STARASSIGN} {printf("(%s, STARASSIGNOPERATOR)\n", yytext);return STARASSIGNOP}
{DIVASSIGN} {printf("(%s, DIVASSIGNOPERATOR)\n", yytext);return DIVASSIGNOP;}


{SPSEMICOLON} {printf("(%s, SPSEMICOLON)\n", yytext);return SEMI;}
{SPCOMMA} {printf("(%s, SPCOMMA)\n", yytext);return COMMA;}
{DOT} {printf("(%s, DOT)\n", yytext);return DOT;}


{LC} {printf("(%s, SPLEFTBRACKER)\n", yytext);return LC;}
{RC} {printf("(%s, SPRIGHTBRACKER)\n", yytext);return RC;}
{LP} {printf("(%s, SPLEFTPRNT)\n", yytext);return LP;}
{RP} {printf("(%s, SPRIGHTPRNT)\n", yytext);return RP;}

{LINECOM} {
    printf("(%s, COMMENT)\n", yytext);
    return LINECOM;
}


{LEFTBLOCKCOM} |
{RIGHTBLOCKCOM} {
    printf("(%s, COMMNET)\n", yytext);
    return COMMENT;
}

{SPACE} {}

{EOL} {printf("(\\n, EOL)\n");return EOL;}

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
