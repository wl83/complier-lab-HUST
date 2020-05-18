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
     STRUCT_TAG = 337,
     EXP_ELE = 338,
     SWITCH_STMT = 339,
     CASE_STMT = 340,
     DEFAULT_STMT = 341,
     UMINUS = 342,
     LOWER_THEN_ELSE = 343
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
#define VOID 301
#define SWITCH 302
#define CASE 303
#define EXT_DEF_LIST 304
#define EXT_VAR_DEF 305
#define FUNC_DEF 306
#define FUNC_DEC 307
#define EXT_DEC_LIST 308
#define PARAM_LIST 309
#define PARAM_DEC 310
#define VAR_DEF 311
#define DEC_LIST 312
#define DEF_LIST 313
#define COMP_STM 314
#define STM_LIST 315
#define EXP_STMT 316
#define IF_THEN 317
#define IF_THEN_ELSE 318
#define ARRAY_LIST 319
#define ARRAY_ID 320
#define FUNC_CALL 321
#define ARGS 322
#define FUNCTION 323
#define PARAM 324
#define ARG 325
#define CALL 326
#define LABEL 327
#define GOTO 328
#define JLT 329
#define JLE 330
#define JGT 331
#define JGE 332
#define EQ 333
#define NEQ 334
#define FOR_DEC 335
#define STRUCT_DEF 336
#define STRUCT_TAG 337
#define EXP_ELE 338
#define SWITCH_STMT 339
#define CASE_STMT 340
#define DEFAULT_STMT 341
#define UMINUS 342
#define LOWER_THEN_ELSE 343




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
#line 235 "grammarTree.tab.h"
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
