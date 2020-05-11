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
     EXT_DEF_LIST = 301,
     EXT_VAR_DEF = 302,
     FUNC_DEF = 303,
     FUNC_DEC = 304,
     EXT_DEC_LIST = 305,
     PARAM_LIST = 306,
     PARAM_DEC = 307,
     VAR_DEF = 308,
     DEC_LIST = 309,
     DEF_LIST = 310,
     COMP_STM = 311,
     STM_LIST = 312,
     EXP_STMT = 313,
     IF_THEN = 314,
     IF_THEN_ELSE = 315,
     ARRAY_LIST = 316,
     ARRAY_ID = 317,
     FUNC_CALL = 318,
     ARGS = 319,
     FUNCTION = 320,
     PARAM = 321,
     ARG = 322,
     CALL = 323,
     LABEL = 324,
     GOTO = 325,
     JLT = 326,
     JLE = 327,
     JGT = 328,
     JGE = 329,
     EQ = 330,
     NEQ = 331,
     FOR_DEC = 332,
     STRUCT_DEF = 333,
     STRUCT_TAG = 334,
     EXP_ELE = 335,
     UMINUS = 336,
     LOWER_THEN_ELSE = 337
   };
#endif
/* Tokens.  */
#define CHAR 258
#define INT 259
#define ID 260
#define RELOP 261
#define TYPE 262
#define FLOAT 263
#define STRING 264
#define STRUCT 265
#define DPLUS 266
#define LP 267
#define RP 268
#define LC 269
#define RC 270
#define LB 271
#define RB 272
#define SEMI 273
#define COMMA 274
#define DOT 275
#define PLUS 276
#define MINUS 277
#define STAR 278
#define DIV 279
#define MOD 280
#define ASSIGNOP 281
#define PLUSASSIGNOP 282
#define MINUSASSIGNOP 283
#define STARASSIGNOP 284
#define DIVASSIGNOP 285
#define MODASSIGNOP 286
#define AND 287
#define OR 288
#define NOT 289
#define AUTOPLUS 290
#define AUTOMINUS 291
#define IF 292
#define ELSE 293
#define WHILE 294
#define FOR 295
#define RETURN 296
#define COLON 297
#define DEFAULT 298
#define CONTINUE 299
#define BREAK 300
#define EXT_DEF_LIST 301
#define EXT_VAR_DEF 302
#define FUNC_DEF 303
#define FUNC_DEC 304
#define EXT_DEC_LIST 305
#define PARAM_LIST 306
#define PARAM_DEC 307
#define VAR_DEF 308
#define DEC_LIST 309
#define DEF_LIST 310
#define COMP_STM 311
#define STM_LIST 312
#define EXP_STMT 313
#define IF_THEN 314
#define IF_THEN_ELSE 315
#define ARRAY_LIST 316
#define ARRAY_ID 317
#define FUNC_CALL 318
#define ARGS 319
#define FUNCTION 320
#define PARAM 321
#define ARG 322
#define CALL 323
#define LABEL 324
#define GOTO 325
#define JLT 326
#define JLE 327
#define JGT 328
#define JGE 329
#define EQ 330
#define NEQ 331
#define FOR_DEC 332
#define STRUCT_DEF 333
#define STRUCT_TAG 334
#define EXP_ELE 335
#define UMINUS 336
#define LOWER_THEN_ELSE 337




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "grammarTree.y"
{
	int    type_int;
        char   type_char[5];
	float  type_float;
	char   type_id[32];
        char   type_string[32];
        char   struct_name[32];
	struct ASTNode *ptr;
}
/* Line 1529 of yacc.c.  */
#line 223 "grammarTree.tab.h"
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
