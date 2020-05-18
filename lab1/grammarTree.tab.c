/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 3 "grammarTree.y"

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "grammarTree.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct ASTNode *,int);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 294 "grammarTree.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 319 "grammarTree.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   681

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    13,    16,    20,    23,
      25,    27,    33,    36,    37,    39,    41,    43,    47,    49,
      52,    56,    61,    66,    70,    72,    76,    79,    84,    85,
      88,    91,    93,    97,   103,   111,   117,   123,   126,   129,
     135,   140,   144,   146,   148,   154,   158,   159,   162,   165,
     169,   171,   175,   177,   181,   185,   189,   193,   197,   201,
     205,   209,   213,   217,   221,   225,   229,   233,   237,   240,
     243,   246,   249,   253,   256,   259,   262,   265,   270,   274,
     276,   278,   280,   282,   284,   287,   291,   292,   296
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      90,     0,    -1,    91,    -1,    -1,    92,    91,    -1,    93,
      97,    18,    -1,    93,    18,    -1,    93,   100,   103,    -1,
       1,    18,    -1,     7,    -1,    94,    -1,    10,    95,    14,
     108,    15,    -1,    10,    96,    -1,    -1,     5,    -1,     5,
      -1,    98,    -1,    98,    19,    97,    -1,     5,    -1,     5,
      99,    -1,    16,   112,    17,    -1,    16,   112,    17,    99,
      -1,     5,    12,   101,    13,    -1,     5,    12,    13,    -1,
     102,    -1,   102,    19,   101,    -1,    93,    98,    -1,    14,
     108,   104,    15,    -1,    -1,   105,   104,    -1,   112,    18,
      -1,   103,    -1,    41,   112,    18,    -1,    37,    12,   112,
      13,   105,    -1,    37,    12,   112,    13,   105,    38,   105,
      -1,    39,    12,   112,    13,   105,    -1,    40,    12,   107,
      13,   105,    -1,    44,    18,    -1,    45,    18,    -1,    47,
      12,   112,    13,   105,    -1,    48,   106,    42,   105,    -1,
      43,    42,   105,    -1,     4,    -1,     3,    -1,   112,    18,
     112,    18,   112,    -1,    18,   112,    18,    -1,    -1,   109,
     108,    -1,     1,    18,    -1,    93,   110,    18,    -1,   111,
      -1,   111,    19,   110,    -1,    98,    -1,    98,    26,   112,
      -1,   112,    26,   112,    -1,   112,    27,   112,    -1,   112,
      28,   112,    -1,   112,    29,   112,    -1,   112,    30,   112,
      -1,   112,    31,   112,    -1,   112,    32,   112,    -1,   112,
      33,   112,    -1,   112,     6,   112,    -1,   112,    21,   112,
      -1,   112,    22,   112,    -1,   112,    23,   112,    -1,   112,
      24,   112,    -1,   112,    25,   112,    -1,   112,    35,    -1,
     112,    36,    -1,    35,   112,    -1,    36,   112,    -1,    12,
     112,    13,    -1,    22,   112,    -1,    34,   112,    -1,    11,
     112,    -1,   112,    11,    -1,     5,    12,   113,    13,    -1,
       5,    12,    13,    -1,     5,    -1,     4,    -1,     3,    -1,
       8,    -1,     9,    -1,     5,    99,    -1,   112,    20,     5,
      -1,    -1,   112,    19,   113,    -1,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    59,    60,    62,    63,    64,    65,    67,
      68,    70,    71,    73,    74,    76,    80,    81,    84,    85,
      88,    89,    92,    93,    95,    96,    98,   101,   103,   104,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   124,   125,   128,   129,   130,   132,
     134,   135,   137,   138,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   176,   177
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "INT", "ID", "RELOP", "TYPE",
  "FLOAT", "STRING", "STRUCT", "DPLUS", "LP", "RP", "LC", "RC", "LB", "RB",
  "SEMI", "COMMA", "DOT", "PLUS", "MINUS", "STAR", "DIV", "MOD",
  "ASSIGNOP", "PLUSASSIGNOP", "MINUSASSIGNOP", "STARASSIGNOP",
  "DIVASSIGNOP", "MODASSIGNOP", "AND", "OR", "NOT", "AUTOPLUS",
  "AUTOMINUS", "IF", "ELSE", "WHILE", "FOR", "RETURN", "COLON", "DEFAULT",
  "CONTINUE", "BREAK", "VOID", "SWITCH", "CASE", "EXT_DEF_LIST",
  "EXT_VAR_DEF", "FUNC_DEF", "FUNC_DEC", "EXT_DEC_LIST", "PARAM_LIST",
  "PARAM_DEC", "VAR_DEF", "DEC_LIST", "DEF_LIST", "COMP_STM", "STM_LIST",
  "EXP_STMT", "IF_THEN", "IF_THEN_ELSE", "ARRAY_LIST", "ARRAY_ID",
  "FUNC_CALL", "ARGS", "FUNCTION", "PARAM", "ARG", "CALL", "LABEL", "GOTO",
  "JLT", "JLE", "JGT", "JGE", "EQ", "NEQ", "FOR_DEC", "STRUCT_DEF",
  "STRUCT_TAG", "EXP_ELE", "SWITCH_STMT", "CASE_STMT", "DEFAULT_STMT",
  "UMINUS", "LOWER_THEN_ELSE", "$accept", "program", "ExtDefList",
  "ExtDef", "Specifier", "StructSpecifier", "OptTag", "Tag", "ExtDecList",
  "VarDec", "Arraylist", "FuncDec", "VarList", "ParamDec", "CompSt",
  "StmList", "Stmt", "CaseType", "ForDec", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     2,     1,
       1,     5,     2,     0,     1,     1,     1,     3,     1,     2,
       3,     4,     4,     3,     1,     3,     2,     4,     0,     2,
       2,     1,     3,     5,     7,     5,     5,     2,     2,     5,
       4,     3,     1,     1,     5,     3,     0,     2,     2,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     2,     2,     2,     2,     4,     3,     1,
       1,     1,     1,     1,     2,     3,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     9,    13,     0,     2,     0,     0,    10,     8,
      15,     0,    12,     1,     4,    18,     6,     0,    16,     0,
       0,     0,    86,    19,     5,     0,     0,     7,     0,     0,
       0,     0,    23,     0,     0,    24,    81,    80,    79,    82,
      83,    86,    86,    86,    86,    86,    86,     0,    18,    17,
      86,    48,    52,     0,    50,    11,    47,    26,    22,     0,
      86,    84,    75,     0,    73,    74,    70,    71,    86,    76,
      20,     0,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    68,    69,     0,     0,     0,
      86,     0,     0,     0,     0,     0,    31,     0,    86,     0,
      86,    49,     0,    25,    78,    88,     0,    72,    62,    21,
      85,    63,    64,    65,    66,    67,    54,    55,    56,    57,
      58,    59,    60,    61,    86,    86,    86,     0,    86,    37,
      38,    86,    43,    42,     0,    27,    29,    30,    53,    51,
      86,    77,     0,     0,    86,     0,     0,    32,    41,     0,
      86,    87,    86,    86,     0,    86,    86,    86,    40,    33,
      35,    45,    36,     0,    39,    86,    86,    34,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    29,     8,    11,    12,    17,    18,
      23,    19,    34,    35,    96,    97,    98,   134,   145,    30,
      31,    53,    54,    99,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
       8,    -7,  -123,    32,    39,  -123,     8,    -2,  -123,  -123,
      34,    53,  -123,  -123,  -123,    28,  -123,    29,    52,    62,
     125,    79,    61,  -123,  -123,    70,   142,  -123,    59,    70,
      67,   142,  -123,    70,    80,    75,  -123,  -123,    33,  -123,
    -123,    61,    61,    61,    61,    61,    61,   258,    83,  -123,
      76,  -123,    74,    87,    82,  -123,  -123,  -123,  -123,    22,
     204,  -123,    16,   286,    16,    16,    16,    16,    61,  -123,
      83,   101,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,  -123,  -123,    95,    96,   102,
      61,    85,   107,   110,   117,    10,  -123,   115,    76,   314,
      61,  -123,    70,  -123,  -123,   342,   118,  -123,   628,  -123,
    -123,   645,   645,     6,     6,     6,   594,   594,   594,   594,
     594,   594,   622,   600,    61,    61,   238,   370,   188,  -123,
    -123,    61,  -123,  -123,    91,  -123,  -123,  -123,   566,  -123,
      61,  -123,   398,   426,    61,   123,   454,  -123,  -123,   482,
     188,  -123,   188,   188,   510,   188,    61,   188,  -123,    99,
    -123,  -123,  -123,   538,  -123,   188,    61,  -123,   566
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,   132,  -123,     4,  -123,  -123,  -123,   114,   -28,
     -36,  -123,   100,  -123,   122,    44,  -122,  -123,  -123,   -19,
    -123,    56,  -123,   -22,    15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      47,    52,    61,    15,     7,    57,   148,    50,    -3,     1,
       7,     9,    56,   132,   133,     2,    16,    69,     3,    62,
      63,    64,    65,    66,    67,    33,    71,    69,   158,     2,
     159,   160,     3,   162,   109,   164,    71,    10,   105,    13,
      21,    85,    86,   167,    22,    60,   108,    24,   -14,    22,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    33,    36,    37,    38,    20,   127,    39,
      40,    25,    41,    42,    52,    48,    26,    51,   138,    36,
      37,    38,    55,    43,    39,    40,     2,    41,    42,     3,
      26,   -28,    32,    58,    59,    44,    45,    46,    43,    22,
     100,   102,   142,   143,   146,   101,   110,   124,   125,   149,
      44,    45,    46,    87,   126,    88,    89,    90,   105,    91,
      92,    93,   154,    94,    95,   129,    28,   128,   130,   131,
     135,   141,     2,   150,   163,     3,   155,   165,    14,    49,
     -46,    27,   136,    28,   168,   -46,   -46,   -46,   -46,     2,
     -46,   -46,     3,   -46,   -46,   151,   -46,   -46,   139,   103,
     -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
       0,   -46,   -46,   -46,     0,   -46,   -46,   -46,     0,   -46,
     -46,    36,    37,    38,     0,     0,    39,    40,     0,    41,
      42,     0,    26,     0,     0,     0,     0,    36,    37,    38,
      43,     0,    39,    40,     0,    41,    42,   104,     0,     0,
       0,     0,    44,    45,    46,    87,    43,    88,    89,    90,
       0,    91,    92,    93,     0,    94,    95,     0,    44,    45,
      46,    36,    37,    38,     0,     0,    39,    40,     0,    41,
      42,     0,     0,     0,     0,     0,   144,     0,     0,     0,
      43,     0,     0,     0,    68,     0,     0,     0,     0,    69,
       0,     0,    44,    45,    46,    70,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    68,    85,    86,     0,     0,    69,     0,   107,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      68,    85,    86,     0,     0,    69,     0,     0,     0,     0,
       0,     0,   137,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    68,    85,
      86,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,   140,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    68,    85,    86,     0,
       0,    69,     0,     0,     0,     0,     0,     0,   147,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    68,    85,    86,     0,     0,    69,
       0,   152,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    68,    85,    86,     0,     0,    69,     0,   153,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      68,    85,    86,     0,     0,    69,     0,     0,     0,     0,
       0,     0,   156,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    68,    85,
      86,     0,     0,    69,     0,   157,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    68,    85,    86,     0,
       0,    69,     0,     0,     0,     0,     0,     0,   161,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    68,    85,    86,     0,     0,    69,
       0,     0,     0,     0,     0,     0,   166,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    68,    85,    86,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      68,    85,    86,     0,     0,    69,    68,     0,     0,     0,
       0,    69,     0,     0,    71,    72,    73,    74,    75,    76,
      71,    72,    73,    74,    75,    76,    83,    84,    68,    85,
      86,     0,    83,    69,     0,    85,    86,     0,     0,    69,
       0,     0,    71,    72,    73,    74,    75,    76,    71,    72,
      73,    74,    75,    76,     0,     0,    69,    85,    86,     0,
       0,     0,     0,    85,    86,    71,     0,     0,    74,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86
};

static const yytype_int16 yycheck[] =
{
      22,    29,    38,     5,     0,    33,   128,    26,     0,     1,
       6,    18,    31,     3,     4,     7,    18,    11,    10,    41,
      42,    43,    44,    45,    46,    21,    20,    11,   150,     7,
     152,   153,    10,   155,    70,   157,    20,     5,    60,     0,
      12,    35,    36,   165,    16,    12,    68,    18,    14,    16,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    59,     3,     4,     5,    14,    90,     8,
       9,    19,    11,    12,   102,     5,    14,    18,   100,     3,
       4,     5,    15,    22,     8,     9,     7,    11,    12,    10,
      14,    15,    13,    13,    19,    34,    35,    36,    22,    16,
      26,    19,   124,   125,   126,    18,     5,    12,    12,   131,
      34,    35,    36,    37,    12,    39,    40,    41,   140,    43,
      44,    45,   144,    47,    48,    18,     1,    42,    18,    12,
      15,    13,     7,    42,   156,    10,    13,    38,     6,    25,
      15,    19,    98,     1,   166,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   140,    14,    15,   102,    59,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    -1,    43,    44,    45,    -1,    47,
      48,     3,     4,     5,    -1,    -1,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,     3,     4,     5,
      22,    -1,     8,     9,    -1,    11,    12,    13,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    22,    39,    40,    41,
      -1,    43,    44,    45,    -1,    47,    48,    -1,    34,    35,
      36,     3,     4,     5,    -1,    -1,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    34,    35,    36,    17,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     6,    35,    36,    -1,    -1,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       6,    35,    36,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     6,    35,
      36,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     6,    35,    36,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     6,    35,    36,    -1,    -1,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     6,    35,    36,    -1,    -1,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       6,    35,    36,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     6,    35,
      36,    -1,    -1,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     6,    35,    36,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     6,    35,    36,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     6,    35,    36,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       6,    35,    36,    -1,    -1,    11,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    20,    21,    22,    23,    24,    25,
      20,    21,    22,    23,    24,    25,    32,    33,     6,    35,
      36,    -1,    32,    11,    -1,    35,    36,    -1,    -1,    11,
      -1,    -1,    20,    21,    22,    23,    24,    25,    20,    21,
      22,    23,    24,    25,    -1,    -1,    11,    35,    36,    -1,
      -1,    -1,    -1,    35,    36,    20,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    10,    90,    91,    92,    93,    94,    18,
       5,    95,    96,     0,    91,     5,    18,    97,    98,   100,
      14,    12,    16,    99,    18,    19,    14,   103,     1,    93,
     108,   109,    13,    93,   101,   102,     3,     4,     5,     8,
       9,    11,    12,    22,    34,    35,    36,   112,     5,    97,
     108,    18,    98,   110,   111,    15,   108,    98,    13,    19,
      12,    99,   112,   112,   112,   112,   112,   112,     6,    11,
      17,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    35,    36,    37,    39,    40,
      41,    43,    44,    45,    47,    48,   103,   104,   105,   112,
      26,    18,    19,   101,    13,   112,   113,    13,   112,    99,
       5,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,    12,    12,    12,   112,    42,    18,
      18,    12,     3,     4,   106,    15,   104,    18,   112,   110,
      19,    13,   112,   112,    18,   107,   112,    18,   105,   112,
      42,   113,    13,    13,   112,    13,    18,    13,   105,   105,
     105,    18,   105,   112,   105,    38,    18,   105,   112
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "grammarTree.y"
    { display((yyvsp[(1) - (1)].ptr),0);;}
    break;

  case 3:
#line 59 "grammarTree.y"
    {(yyval.ptr)=NULL;;}
    break;

  case 4:
#line 60 "grammarTree.y"
    {(yyval.ptr)=mknode(2,EXT_DEF_LIST,yylineno,(yyvsp[(1) - (2)].ptr),(yyvsp[(2) - (2)].ptr));;}
    break;

  case 5:
#line 62 "grammarTree.y"
    {(yyval.ptr)=mknode(2,EXT_VAR_DEF,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(2) - (3)].ptr));;}
    break;

  case 7:
#line 64 "grammarTree.y"
    {(yyval.ptr)=mknode(3,FUNC_DEF,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(2) - (3)].ptr),(yyvsp[(3) - (3)].ptr));;}
    break;

  case 8:
#line 65 "grammarTree.y"
    { (yyval.ptr) = NULL; fprintf(stderr, "Grammar Error at Line %d Column %d：",yylloc.first_line,yylloc.first_column);;}
    break;

  case 9:
#line 67 "grammarTree.y"
    {(yyval.ptr)=mknode(0,TYPE,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (1)].type_id));(yyval.ptr)->type=!strcmp((yyvsp[(1) - (1)].type_id),"int")?INT:FLOAT;;}
    break;

  case 10:
#line 68 "grammarTree.y"
    {;}
    break;

  case 11:
#line 70 "grammarTree.y"
    {(yyval.ptr)=mknode(2, STRUCT_DEF, yylineno, (yyvsp[(2) - (5)].ptr),(yyvsp[(4) - (5)].ptr));;}
    break;

  case 12:
#line 71 "grammarTree.y"
    {(yyval.ptr)=mknode(1, STRUCT_DEF, yylineno, (yyvsp[(2) - (2)].ptr));;}
    break;

  case 13:
#line 73 "grammarTree.y"
    {(yyval.ptr)=NULL;;}
    break;

  case 14:
#line 74 "grammarTree.y"
    {(yyval.ptr)=mknode(0, STRUCT_TAG, yylineno);strcpy((yyval.ptr)->struct_name, (yyvsp[(1) - (1)].type_id));;}
    break;

  case 15:
#line 76 "grammarTree.y"
    {(yyval.ptr)=mknode(0, STRUCT_TAG, yylineno); strcpy((yyval.ptr)->struct_name, (yyvsp[(1) - (1)].type_id));;}
    break;

  case 16:
#line 80 "grammarTree.y"
    {(yyval.ptr)=mknode(1,EXT_DEC_LIST,yylineno,(yyvsp[(1) - (1)].ptr));;}
    break;

  case 17:
#line 81 "grammarTree.y"
    {(yyval.ptr)=mknode(2,EXT_DEC_LIST,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));;}
    break;

  case 18:
#line 84 "grammarTree.y"
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (1)].type_id));;}
    break;

  case 19:
#line 85 "grammarTree.y"
    {(yyval.ptr)=mknode(1,ARRAY_LIST,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (2)].type_id));;}
    break;

  case 20:
#line 88 "grammarTree.y"
    {(yyval.ptr)=mknode(1,ARRAY_LIST,yylineno,(yyvsp[(2) - (3)].ptr));;}
    break;

  case 21:
#line 89 "grammarTree.y"
    {(yyval.ptr)=mknode(2,ARRAY_LIST,yylineno,(yyvsp[(2) - (4)].ptr),(yyvsp[(4) - (4)].ptr));;}
    break;

  case 22:
#line 92 "grammarTree.y"
    {(yyval.ptr)=mknode(1,FUNC_DEC,yylineno,(yyvsp[(3) - (4)].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (4)].type_id));;}
    break;

  case 23:
#line 93 "grammarTree.y"
    {(yyval.ptr)=mknode(0,FUNC_DEC,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (3)].type_id));(yyval.ptr)->ptr[0]=NULL;;}
    break;

  case 24:
#line 95 "grammarTree.y"
    {(yyval.ptr)=mknode(1,PARAM_LIST,yylineno,(yyvsp[(1) - (1)].ptr));;}
    break;

  case 25:
#line 96 "grammarTree.y"
    {(yyval.ptr)=mknode(2,PARAM_LIST,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));;}
    break;

  case 26:
#line 98 "grammarTree.y"
    {(yyval.ptr)=mknode(2,PARAM_DEC,yylineno,(yyvsp[(1) - (2)].ptr),(yyvsp[(2) - (2)].ptr));;}
    break;

  case 27:
#line 101 "grammarTree.y"
    {(yyval.ptr)=mknode(2,COMP_STM,yylineno,(yyvsp[(2) - (4)].ptr),(yyvsp[(3) - (4)].ptr));;}
    break;

  case 28:
#line 103 "grammarTree.y"
    {(yyval.ptr)=NULL; ;}
    break;

  case 29:
#line 104 "grammarTree.y"
    {(yyval.ptr)=mknode(2,STM_LIST,yylineno,(yyvsp[(1) - (2)].ptr),(yyvsp[(2) - (2)].ptr));;}
    break;

  case 30:
#line 106 "grammarTree.y"
    {(yyval.ptr)=mknode(1,EXP_STMT,yylineno,(yyvsp[(1) - (2)].ptr));;}
    break;

  case 31:
#line 107 "grammarTree.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);;}
    break;

  case 32:
#line 108 "grammarTree.y"
    {(yyval.ptr)=mknode(1,RETURN,yylineno,(yyvsp[(2) - (3)].ptr));;}
    break;

  case 33:
#line 109 "grammarTree.y"
    {(yyval.ptr)=mknode(2,IF_THEN,yylineno,(yyvsp[(3) - (5)].ptr),(yyvsp[(5) - (5)].ptr));;}
    break;

  case 34:
#line 110 "grammarTree.y"
    {(yyval.ptr)=mknode(3,IF_THEN_ELSE,yylineno,(yyvsp[(3) - (7)].ptr),(yyvsp[(5) - (7)].ptr),(yyvsp[(7) - (7)].ptr));;}
    break;

  case 35:
#line 111 "grammarTree.y"
    {(yyval.ptr)=mknode(2,WHILE,yylineno,(yyvsp[(3) - (5)].ptr),(yyvsp[(5) - (5)].ptr));;}
    break;

  case 36:
#line 112 "grammarTree.y"
    {(yyval.ptr)=mknode(2,FOR,yylineno,(yyvsp[(3) - (5)].ptr),(yyvsp[(5) - (5)].ptr));;}
    break;

  case 37:
#line 113 "grammarTree.y"
    {(yyval.ptr)=mknode(0,CONTINUE, yylineno);;}
    break;

  case 38:
#line 114 "grammarTree.y"
    {(yyval.ptr)=mknode(0,BREAK,yylineno);;}
    break;

  case 39:
#line 115 "grammarTree.y"
    {(yyval.ptr)=mknode(2,SWITCH_STMT,yylineno,(yyvsp[(3) - (5)].ptr),(yyvsp[(5) - (5)].ptr));;}
    break;

  case 40:
#line 116 "grammarTree.y"
    {(yyval.ptr)=mknode(2,CASE_STMT, yylineno,(yyvsp[(2) - (4)].ptr),(yyvsp[(4) - (4)].ptr));;}
    break;

  case 41:
#line 117 "grammarTree.y"
    {(yyval.ptr)=mknode(1,DEFAULT_STMT, yylineno,(yyvsp[(3) - (3)].ptr));;}
    break;

  case 42:
#line 120 "grammarTree.y"
    {(yyval.ptr)=mknode(0,INT,yylineno);(yyval.ptr)->type_int=(yyvsp[(1) - (1)].type_int);(yyval.ptr)->type=INT;;}
    break;

  case 43:
#line 121 "grammarTree.y"
    {(yyval.ptr)=mknode(0,CHAR,yylineno);strcpy((yyval.ptr)->type_char, (yyvsp[(1) - (1)].type_char));(yyval.ptr)->type=CHAR;;}
    break;

  case 44:
#line 124 "grammarTree.y"
    {(yyval.ptr)=mknode(3, FOR_DEC, yylineno, (yyvsp[(1) - (5)].ptr), (yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr));;}
    break;

  case 45:
#line 125 "grammarTree.y"
    {(yyval.ptr)=mknode(1,FOR_DEC, yylineno, (yyvsp[(2) - (3)].ptr));;}
    break;

  case 46:
#line 128 "grammarTree.y"
    {(yyval.ptr)=NULL; ;}
    break;

  case 47:
#line 129 "grammarTree.y"
    {(yyval.ptr)=mknode(2,DEF_LIST,yylineno,(yyvsp[(1) - (2)].ptr),(yyvsp[(2) - (2)].ptr));;}
    break;

  case 48:
#line 130 "grammarTree.y"
    {(yyval.ptr)=NULL;fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);;}
    break;

  case 49:
#line 132 "grammarTree.y"
    {(yyval.ptr)=mknode(2,VAR_DEF,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(2) - (3)].ptr));;}
    break;

  case 50:
#line 134 "grammarTree.y"
    {(yyval.ptr)=mknode(1,DEC_LIST,yylineno,(yyvsp[(1) - (1)].ptr));;}
    break;

  case 51:
#line 135 "grammarTree.y"
    {(yyval.ptr)=mknode(2,DEC_LIST,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));;}
    break;

  case 52:
#line 137 "grammarTree.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);;}
    break;

  case 53:
#line 138 "grammarTree.y"
    {(yyval.ptr)=mknode(2,ASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"ASSIGNOP");;}
    break;

  case 54:
#line 140 "grammarTree.y"
    {(yyval.ptr)=mknode(2,ASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"ASSIGNOP");;}
    break;

  case 55:
#line 141 "grammarTree.y"
    {(yyval.ptr)=mknode(2,PLUSASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id, "PLUSASSIGNOP");;}
    break;

  case 56:
#line 142 "grammarTree.y"
    {(yyval.ptr)=mknode(2,MINUSASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id, "MINUSASSIGNOP");;}
    break;

  case 57:
#line 143 "grammarTree.y"
    {(yyval.ptr)=mknode(2, STARASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"STARASSIGNOP");;}
    break;

  case 58:
#line 144 "grammarTree.y"
    {(yyval.ptr)=mknode(2,DIVASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"DIVASSIGNOP");;}
    break;

  case 59:
#line 145 "grammarTree.y"
    {(yyval.ptr)=mknode(2,MODASSIGNOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id, "MODASSIGNOP");;}
    break;

  case 60:
#line 146 "grammarTree.y"
    {(yyval.ptr)=mknode(2,AND,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"AND");;}
    break;

  case 61:
#line 147 "grammarTree.y"
    {(yyval.ptr)=mknode(2,OR,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"OR");;}
    break;

  case 62:
#line 148 "grammarTree.y"
    {(yyval.ptr)=mknode(2,RELOP,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[(2) - (3)].type_id));;}
    break;

  case 63:
#line 149 "grammarTree.y"
    {(yyval.ptr)=mknode(2,PLUS,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"PLUS");;}
    break;

  case 64:
#line 150 "grammarTree.y"
    {(yyval.ptr)=mknode(2,MINUS,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"MINUS");;}
    break;

  case 65:
#line 151 "grammarTree.y"
    {(yyval.ptr)=mknode(2,STAR,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"STAR");;}
    break;

  case 66:
#line 152 "grammarTree.y"
    {(yyval.ptr)=mknode(2,DIV,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"DIV");;}
    break;

  case 67:
#line 153 "grammarTree.y"
    {(yyval.ptr)=mknode(2,MOD,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));strcpy((yyval.ptr)->type_id,"MOD");;}
    break;

  case 68:
#line 154 "grammarTree.y"
    {(yyval.ptr)=mknode(1,AUTOPLUS,yylineno,(yyvsp[(1) - (2)].ptr));strcpy((yyval.ptr)->type_id, "RPAUTOPLUS");;}
    break;

  case 69:
#line 155 "grammarTree.y"
    {(yyval.ptr)=mknode(1,AUTOMINUS,yylineno,(yyvsp[(1) - (2)].ptr));strcpy((yyval.ptr)->type_id,"RPAUTOMINUS");;}
    break;

  case 70:
#line 156 "grammarTree.y"
    {(yyval.ptr)=mknode(1,AUTOPLUS,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id, "LPAUTOPLUS");;}
    break;

  case 71:
#line 157 "grammarTree.y"
    {(yyval.ptr)=mknode(1,AUTOMINUS,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id, "LPAUTOMINUS");;}
    break;

  case 72:
#line 158 "grammarTree.y"
    {(yyval.ptr)=(yyvsp[(2) - (3)].ptr);;}
    break;

  case 73:
#line 159 "grammarTree.y"
    {(yyval.ptr)=mknode(1,UMINUS,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id,"UMINUS");;}
    break;

  case 74:
#line 160 "grammarTree.y"
    {(yyval.ptr)=mknode(1,NOT,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id,"NOT");;}
    break;

  case 75:
#line 161 "grammarTree.y"
    {(yyval.ptr)=mknode(1,DPLUS,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id,"DPLUS");;}
    break;

  case 76:
#line 162 "grammarTree.y"
    {(yyval.ptr)=mknode(1,DPLUS,yylineno,(yyvsp[(1) - (2)].ptr));strcpy((yyval.ptr)->type_id,"DPLUS");;}
    break;

  case 77:
#line 163 "grammarTree.y"
    {(yyval.ptr)=mknode(1,FUNC_CALL,yylineno,(yyvsp[(3) - (4)].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (4)].type_id));;}
    break;

  case 78:
#line 164 "grammarTree.y"
    {(yyval.ptr)=mknode(0,FUNC_CALL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (3)].type_id));;}
    break;

  case 79:
#line 165 "grammarTree.y"
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (1)].type_id));;}
    break;

  case 80:
#line 166 "grammarTree.y"
    {(yyval.ptr)=mknode(0,INT,yylineno);(yyval.ptr)->type_int=(yyvsp[(1) - (1)].type_int);(yyval.ptr)->type=INT;;}
    break;

  case 81:
#line 167 "grammarTree.y"
    {(yyval.ptr)=mknode(0,CHAR,yylineno);strcpy((yyval.ptr)->type_char, (yyvsp[(1) - (1)].type_char));(yyval.ptr)->type=CHAR;;}
    break;

  case 82:
#line 168 "grammarTree.y"
    {(yyval.ptr)=mknode(0,FLOAT,yylineno);(yyval.ptr)->type_float=(yyvsp[(1) - (1)].type_float);(yyval.ptr)->type=FLOAT;;}
    break;

  case 83:
#line 169 "grammarTree.y"
    {(yyval.ptr)=mknode(0,STRING,yylineno);strcpy((yyval.ptr)->type_string,(yyvsp[(1) - (1)].type_string));(yyval.ptr)->type=STRING;}
    break;

  case 84:
#line 170 "grammarTree.y"
    {(yyval.ptr)=mknode(1,ARRAY_ID,yylineno,(yyvsp[(2) - (2)].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[(1) - (2)].type_id));;}
    break;

  case 85:
#line 171 "grammarTree.y"
    {(yyval.ptr)=mknode(1,EXP_ELE,yylineno,(yyvsp[(1) - (3)].ptr)); strcpy((yyval.ptr)->type_id,(yyvsp[(3) - (3)].type_id));;}
    break;

  case 86:
#line 172 "grammarTree.y"
    {(yyval.ptr)=NULL;;}
    break;

  case 87:
#line 176 "grammarTree.y"
    {(yyval.ptr)=mknode(2,ARGS,yylineno,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));;}
    break;

  case 88:
#line 177 "grammarTree.y"
    {(yyval.ptr)=mknode(1,ARGS,yylineno,(yyvsp[(1) - (1)].ptr));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2234 "grammarTree.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 180 "grammarTree.y"


int main(int argc, char *argv[]){
        yyin=fopen(argv[1],"r");
	if (!yyin) 
        return 0;
	yylineno=1;
	yyparse();
	return 0;
}

void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

