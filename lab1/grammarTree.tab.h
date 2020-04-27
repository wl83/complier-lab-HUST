/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMARTREE_TAB_H_INCLUDED
# define YY_YY_GRAMMARTREE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    CHAR = 259,
    FLOAT = 260,
    ID = 261,
    TYPE = 262,
    RELOP = 263,
    LC = 264,
    RC = 265,
    LB = 266,
    RB = 267,
    LP = 268,
    RP = 269,
    SEMI = 270,
    COMMA = 271,
    PLUS = 272,
    MINUS = 273,
    STAR = 274,
    DIV = 275,
    MOD = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    AUTOPLUS = 280,
    AUTOMINUS = 281,
    ASSIGNOP = 282,
    PLUSASSIGNOP = 283,
    MINUSASSIGNOP = 284,
    STARASSIGNOP = 285,
    DIVASSIGNOP = 286,
    MODASSIGNOP = 287,
    IF = 288,
    ELSE = 289,
    WHILE = 290,
    BREAK = 291,
    CONTINUE = 292,
    FOR = 293,
    EXTENDS = 294,
    NEW = 295,
    THIS = 296,
    STATIC = 297,
    RETURN = 298,
    UMINUS = 299,
    LOWER_THEN_ELSE = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "grammarTree.y" /* yacc.c:1909  */

    int type_int;
    float type_float;
    char type_char;
    char type_id[32];
    struct node *ptr;

#line 108 "grammarTree.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_GRAMMARTREE_TAB_H_INCLUDED  */
