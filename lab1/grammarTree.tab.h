/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     INT = 259,
     ID = 260,
     RELOP = 261,
     TYPE = 262,
     FLOAT = 263,
     DPLUS = 264,
     LP = 265,
     RP = 266,
     LC = 267,
     RC = 268,
     LB = 269,
     RB = 270,
     SEMI = 271,
     COMMA = 272,
     PLUS = 273,
     MINUS = 274,
     STAR = 275,
     DIV = 276,
     ASSIGNOP = 277,
     PLUSASSIGNOP = 278,
     MINUSASSIGNOP = 279,
     STARASSIGNOP = 280,
     DIVASSIGNOP = 281,
     AND = 282,
     OR = 283,
     NOT = 284,
     AUTOPLUS = 285,
     AUTOMINUS = 286,
     IF = 287,
     ELSE = 288,
     WHILE = 289,
     RETURN = 290,
     FOR = 291,
     SWITCH = 292,
     CASE = 293,
     COLON = 294,
     DEFAULT = 295,
     EXT_DEF_LIST = 296,
     EXT_VAR_DEF = 297,
     FUNC_DEF = 298,
     FUNC_DEC = 299,
     EXT_DEC_LIST = 300,
     PARAM_LIST = 301,
     PARAM_DEC = 302,
     VAR_DEF = 303,
     DEC_LIST = 304,
     DEF_LIST = 305,
     COMP_STM = 306,
     STM_LIST = 307,
     EXP_STMT = 308,
     IF_THEN = 309,
     IF_THEN_ELSE = 310,
     FUNC_CALL = 311,
     ARGS = 312,
     FUNCTION = 313,
     PARAM = 314,
     ARG = 315,
     CALL = 316,
     LABEL = 317,
     GOTO = 318,
     JLT = 319,
     JLE = 320,
     JGT = 321,
     JGE = 322,
     EQ = 323,
     NEQ = 324,
     UMINUS = 325,
     LOWER_THEN_ELSE = 326
   };
#endif
/* Tokens.  */
#define CHAR 258
#define INT 259
#define ID 260
#define RELOP 261
#define TYPE 262
#define FLOAT 263
#define DPLUS 264
#define LP 265
#define RP 266
#define LC 267
#define RC 268
#define LB 269
#define RB 270
#define SEMI 271
#define COMMA 272
#define PLUS 273
#define MINUS 274
#define STAR 275
#define DIV 276
#define ASSIGNOP 277
#define PLUSASSIGNOP 278
#define MINUSASSIGNOP 279
#define STARASSIGNOP 280
#define DIVASSIGNOP 281
#define AND 282
#define OR 283
#define NOT 284
#define AUTOPLUS 285
#define AUTOMINUS 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define RETURN 290
#define FOR 291
#define SWITCH 292
#define CASE 293
#define COLON 294
#define DEFAULT 295
#define EXT_DEF_LIST 296
#define EXT_VAR_DEF 297
#define FUNC_DEF 298
#define FUNC_DEC 299
#define EXT_DEC_LIST 300
#define PARAM_LIST 301
#define PARAM_DEC 302
#define VAR_DEF 303
#define DEC_LIST 304
#define DEF_LIST 305
#define COMP_STM 306
#define STM_LIST 307
#define EXP_STMT 308
#define IF_THEN 309
#define IF_THEN_ELSE 310
#define FUNC_CALL 311
#define ARGS 312
#define FUNCTION 313
#define PARAM 314
#define ARG 315
#define CALL 316
#define LABEL 317
#define GOTO 318
#define JLT 319
#define JLE 320
#define JGT 321
#define JGE 322
#define EQ 323
#define NEQ 324
#define UMINUS 325
#define LOWER_THEN_ELSE 326




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "grammarTree.y"
{
	int    type_int;
        char   type_char;
	float  type_float;
	char   type_id[32];
	struct ASTNode *ptr;
}
/* Line 1529 of yacc.c.  */
#line 199 "grammarTree.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
