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
     MOD = 277,
     ASSIGNOP = 278,
     PLUSASSIGNOP = 279,
     MINUSASSIGNOP = 280,
     STARASSIGNOP = 281,
     DIVASSIGNOP = 282,
     MODASSIGNOP = 283,
     AND = 284,
     OR = 285,
     NOT = 286,
     AUTOPLUS = 287,
     AUTOMINUS = 288,
     IF = 289,
     ELSE = 290,
     WHILE = 291,
     RETURN = 292,
     FOR = 293,
     SWITCH = 294,
     CASE = 295,
     COLON = 296,
     DEFAULT = 297,
     EXT_DEF_LIST = 298,
     EXT_VAR_DEF = 299,
     FUNC_DEF = 300,
     FUNC_DEC = 301,
     EXT_DEC_LIST = 302,
     PARAM_LIST = 303,
     PARAM_DEC = 304,
     VAR_DEF = 305,
     DEC_LIST = 306,
     DEF_LIST = 307,
     COMP_STM = 308,
     STM_LIST = 309,
     EXP_STMT = 310,
     IF_THEN = 311,
     IF_THEN_ELSE = 312,
     ARRAY_LIST = 313,
     ARRAY_ID = 314,
     FUNC_CALL = 315,
     ARGS = 316,
     FUNCTION = 317,
     PARAM = 318,
     ARG = 319,
     CALL = 320,
     LABEL = 321,
     GOTO = 322,
     JLT = 323,
     JLE = 324,
     JGT = 325,
     JGE = 326,
     EQ = 327,
     NEQ = 328,
     UMINUS = 329,
     LOWER_THEN_ELSE = 330
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
#define MOD 277
#define ASSIGNOP 278
#define PLUSASSIGNOP 279
#define MINUSASSIGNOP 280
#define STARASSIGNOP 281
#define DIVASSIGNOP 282
#define MODASSIGNOP 283
#define AND 284
#define OR 285
#define NOT 286
#define AUTOPLUS 287
#define AUTOMINUS 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define RETURN 292
#define FOR 293
#define SWITCH 294
#define CASE 295
#define COLON 296
#define DEFAULT 297
#define EXT_DEF_LIST 298
#define EXT_VAR_DEF 299
#define FUNC_DEF 300
#define FUNC_DEC 301
#define EXT_DEC_LIST 302
#define PARAM_LIST 303
#define PARAM_DEC 304
#define VAR_DEF 305
#define DEC_LIST 306
#define DEF_LIST 307
#define COMP_STM 308
#define STM_LIST 309
#define EXP_STMT 310
#define IF_THEN 311
#define IF_THEN_ELSE 312
#define ARRAY_LIST 313
#define ARRAY_ID 314
#define FUNC_CALL 315
#define ARGS 316
#define FUNCTION 317
#define PARAM 318
#define ARG 319
#define CALL 320
#define LABEL 321
#define GOTO 322
#define JLT 323
#define JLE 324
#define JGT 325
#define JGE 326
#define EQ 327
#define NEQ 328
#define UMINUS 329
#define LOWER_THEN_ELSE 330




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
#line 207 "grammarTree.tab.h"
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
