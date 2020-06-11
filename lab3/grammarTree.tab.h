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
    CHAR = 258,
    INT = 259,
    ID = 260,
    RELOP = 261,
    TYPE = 262,
    FLOAT = 263,
    STRING = 264,
    STRUCT = 265,
    DPLUS = 266,
    LP = 267,
    RP = 268,
    LC = 269,
    RC = 270,
    LB = 271,
    RB = 272,
    SEMI = 273,
    COMMA = 274,
    DOT = 275,
    PLUS = 276,
    MINUS = 277,
    STAR = 278,
    DIV = 279,
    MOD = 280,
    ASSIGNOP = 281,
    PLUSASSIGNOP = 282,
    MINUSASSIGNOP = 283,
    STARASSIGNOP = 284,
    DIVASSIGNOP = 285,
    MODASSIGNOP = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    AUTOPLUS = 290,
    AUTOMINUS = 291,
    IF = 292,
    ELSE = 293,
    WHILE = 294,
    FOR = 295,
    RETURN = 296,
    COLON = 297,
    DEFAULT = 298,
    CONTINUE = 299,
    BREAK = 300,
    VOID = 301,
    SWITCH = 302,
    CASE = 303,
    EXT_DEF_LIST = 304,
    EXT_VAR_DEF = 305,
    FUNC_DEF = 306,
    FUNC_DEC = 307,
    EXT_DEC_LIST = 308,
    PARAM_LIST = 309,
    PARAM_DEC = 310,
    VAR_DEF = 311,
    DEC_LIST = 312,
    DEF_LIST = 313,
    COMP_STM = 314,
    STM_LIST = 315,
    EXP_STMT = 316,
    IF_THEN = 317,
    IF_THEN_ELSE = 318,
    ARRAY_LIST = 319,
    ARRAY_ID = 320,
    FUNC_CALL = 321,
    ARGS = 322,
    FUNCTION = 323,
    PARAM = 324,
    ARG = 325,
    CALL = 326,
    LABEL = 327,
    GOTO = 328,
    JLT = 329,
    JLE = 330,
    JGT = 331,
    JGE = 332,
    EQ = 333,
    NEQ = 334,
    FOR_DEC = 335,
    STRUCT_DEF = 336,
    STRUCT_DEC = 337,
    STRUCT_TAG = 338,
    EXP_ELE = 339,
    SWITCH_STMT = 340,
    CASE_STMT = 341,
    DEFAULT_STMT = 342,
    EXP_ARRAY = 343,
    EXT_STRUCT_DEF = 344,
    ARRAY_DEC = 345,
    AUTOPLUS_L = 346,
    AUTOPLUS_R = 347,
    AUTOMINUS_L = 348,
    AUTOMINUS_R = 349,
    UMINUS = 350,
    LOWER_THEN_ELSE = 351
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "grammarTree.y" /* yacc.c:1909  */

	int    type_int;
        char   type_char[5];
	float  type_float;
	char   type_id[32];
        char   type_string[32];
        char   struct_name[32];
	struct ASTNode *ptr;

#line 161 "grammarTree.tab.h" /* yacc.c:1909  */
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
