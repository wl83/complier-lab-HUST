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
     NULL = 294,
     EXTENDS = 295,
     NEW = 296,
     THIS = 297,
     STATIC = 298,
     TRUE = 299,
     FALSE = 300,
     RETURN = 301,
     UMINUS = 302,
     LOWER_THEN_ELSE = 303
   };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define FLOAT 260
#define ID 261
#define TYPE 262
#define RELOP 263
#define LC 264
#define RC 265
#define LB 266
#define RB 267
#define LP 268
#define RP 269
#define SEMI 270
#define COMMA 271
#define PLUS 272
#define MINUS 273
#define STAR 274
#define DIV 275
#define MOD 276
#define AND 277
#define OR 278
#define NOT 279
#define AUTOPLUS 280
#define AUTOMINUS 281
#define ASSIGNOP 282
#define PLUSASSIGNOP 283
#define MINUSASSIGNOP 284
#define STARASSIGNOP 285
#define DIVASSIGNOP 286
#define MODASSIGNOP 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define BREAK 291
#define CONTINUE 292
#define FOR 293
#define NULL 294
#define EXTENDS 295
#define NEW 296
#define THIS 297
#define STATIC 298
#define TRUE 299
#define FALSE 300
#define RETURN 301
#define UMINUS 302
#define LOWER_THEN_ELSE 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "grammarTree.y"
{
    int type_int;
    int type_bool;
    float type_float;
    char type_char;
    char type_id[32];
    struct node *ptr;
}
/* Line 1529 of yacc.c.  */
#line 154 "grammarTree.tab.h"
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
