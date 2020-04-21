%{
    #include <stdio.h>
    #include <stdlib.h>
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
EXTENDS extends
NEW new
THIS this
STATIC static
TRUE true
FALSE false
NULL null | NULL
RETURN return
LINECOM [/][/][^\n]*
LEFTBLOCKCOM [/][*]
RIGHTBLOCKCOM [*][/]
IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
SPACE [ ]
EOL [\n]
TAB [\t]
DOT [.]
SPLEFTBRACKER [{]
SPRIGHTBRACKER [}]
SPLEFTPRNT [(]
SPRIGHTPRNT [)]

%%

{TYPEINT} {
    printf("(%s, TYPEINT)\n", yytext);
}
{TYPEFLOAT} {
    printf("(%s, TYPEFLOAT)\n", yytext);
}
{TYPECHAR} {
    printf("(%s, TYPECHAR)\n", yytext);
}
{TYPEVOID} {
    printf("(%s, TYPEVOID)\n", yytext);
}
{TYPEBOOL} {
    printf("(%s, TYPEBOOL)\n", yytext);
}
{TYPECLASS} {
    printf("(%s, TYPECLASS)\n", yytext);
}
{TYPESTRING} {
    printf("(%s, TYPESTRING)\n", yytext);
} 



{IF} |
{ELSE} |
{WHILE} |
{BREAK} |
{CONTINUE} |
{FOR} |
{SWITCH} |
{CASE} |
{EXTENDS} |
{NEW} |
{NULL} |
{RETURN} |
{THIS} |
{STATIC} |
{TRUE} |
{FALSE} {
   printf("(%s, KEYWORD)\n", yytext);
}


{IDENTIFIER} {
    printf("(%s, IDENTIFIER)\n", yytext);
}


{PLUSSELF} {
    printf("(++, PLUSSELFOPERATOR)\n");
}
{MINUSSELF} {
    printf("(--, MINUSSELFOPERATOR)\n");
}


{PLUS} {
    printf("(%s, PLUSOPERATOR)\n", yytext);
}
{MINUS} {
    printf("(%s, MINUSOPERATOR)\n", yytext);
}
{STAR} {
    printf("(%s, STAROPERATOR)\n", yytext);
}
{DIV} {
    printf("(%s, DIVOPERATOR)\n", yytext);
}
{MOD} {
    printf("(%s, MODOPERATOR)\n", yytext);
}


{INT_DEX} |
{INT_HEX} |
{INT_OCT} {
    printf("(%s, CONSTANTINTEGER)\n", yytext);
}


{FLOAT} {
    printf("(%s, CONSTANTFLOAT)\n", yytext);
}


{CHAR} {
    printf("(%s, CHAR)\n", yytext);
}


{STRING} {
    printf("(%s, STRING)\n", yytext);
}


{LTHAN} |
{GTHAN} |
{EQUAL} |
{LETHAN} |
{RETHAN} |
{NOTEQUAL} {
    printf("(%s, OPCOMPARE)\n", yytext);
}


{AND} |
{OR} |
{NOT} {
    printf("(%s, LOGICOPERATOR)\n", yytext);
}


{ASSIGNOP} |
{PLUSASSIGN} |
{MINUSASSIGN} |
{STARASSIGN} |
{DIVASSIGN} {
    printf("(%s, OPASSIGN)\n", yytext);
}


{SPSEMICOLON} {
    printf("(%s, SPSEMICOLON)\n", yytext);
}


{SPCOMMA} {
    printf("(%s, SPCOMMA)\n", yytext);
}


{DOT} {
    printf("(%s, DOT)\n", yytext);
}


{SPLEFTBRACKER} {
    printf("(%s, SPLEFTBRACKER)\n", yytext);
}


{SPRIGHTBRACKER} {
    printf("(%s, SPRIGHTBRACKER)\n", yytext);
}


{SPLEFTPRNT} {
    printf("(%s, SPLEFTPRNT)\n", yytext);
}


{SPRIGHTPRNT} {
    printf("(%s, SPRIGHTPRNT)\n", yytext);
}

{LINECOM} {
    printf("(%s, COMMENT)\n", yytext);
}


{LEFTBLOCKCOM} |
{RIGHTBLOCKCOM} {
    printf("(%s, COMMNET)\n", yytext);
}


{SPACE} {

}


{EOL} {
    printf("(\\n, EOL)\n");
}

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
