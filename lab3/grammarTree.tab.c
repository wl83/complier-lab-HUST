/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "grammarTree.y" /* yacc.c:339  */

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "grammarTree.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct ASTNode *,int);

#line 78 "grammarTree.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammarTree.tab.h".  */
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
#line 15 "grammarTree.y" /* yacc.c:355  */

	int    type_int;
        char   type_char[5];
	float  type_float;
	char   type_id[32];
        char   type_string[32];
        char   struct_name[32];
	struct ASTNode *ptr;

#line 225 "grammarTree.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 256 "grammarTree.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    59,    60,    62,    63,    64,    65,    67,
      68,    70,    71,    73,    76,    77,    80,    81,    84,    85,
      88,    89,    91,    92,    94,    97,    99,   100,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     116,   117,   120,   121,   124,   125,   126,   128,   130,   131,
     133,   134,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   170,   171
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "STRUCT_DEC", "STRUCT_TAG", "EXP_ELE", "SWITCH_STMT", "CASE_STMT",
  "DEFAULT_STMT", "EXP_ARRAY", "EXT_STRUCT_DEF", "ARRAY_DEC", "AUTOPLUS_L",
  "AUTOPLUS_R", "AUTOMINUS_L", "AUTOMINUS_R", "UMINUS", "LOWER_THEN_ELSE",
  "$accept", "program", "ExtDefList", "ExtDef", "Specifier",
  "StructSpecifier", "OptTag", "ExtDecList", "VarDec", "Arraylist",
  "FuncDec", "VarList", "ParamDec", "CompSt", "StmList", "Stmt",
  "CaseType", "ForDec", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351
};
# endif

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    -6,  -122,    10,    35,  -122,     9,    22,    44,  -122,
    -122,    53,  -122,  -122,    30,    55,    52,    73,  -122,    29,
      27,   247,  -122,  -122,    79,   140,  -122,    67,    79,  -122,
      82,   140,  -122,    79,    85,    80,  -122,  -122,    31,  -122,
    -122,   247,   247,   247,   247,   247,   267,    87,  -122,    74,
    -122,    78,    94,   104,  -122,  -122,  -122,  -122,    54,   202,
    -122,   295,   105,   105,   105,   105,   247,    87,   119,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,  -122,  -122,   114,   115,   116,   247,    88,   111,
     113,   121,    71,  -122,   120,    74,   323,   247,  -122,    79,
    -122,  -122,   351,   123,  -122,    70,  -122,  -122,    45,    45,
     -18,   -18,   -18,   243,   243,   243,   243,   243,   243,   609,
     603,   247,   247,   236,   379,   186,  -122,  -122,   247,  -122,
    -122,    92,  -122,  -122,  -122,   575,  -122,   247,  -122,   407,
     435,   247,   124,   463,  -122,  -122,   491,   186,  -122,   186,
     186,   519,   186,   247,   186,  -122,   100,  -122,  -122,  -122,
     547,  -122,   186,   247,  -122,   575
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     9,     0,     0,     2,     0,     0,    10,     8,
      13,    12,     1,     4,    16,     0,    14,     0,     6,     0,
       0,    82,    17,     5,     0,     0,     7,     0,     0,    10,
       0,     0,    21,     0,     0,    22,    77,    76,    75,    78,
      79,    82,    82,    82,    82,    82,     0,    16,    15,    82,
      46,    50,     0,    48,    11,    45,    24,    20,     0,    82,
      80,     0,    71,    72,    68,    69,    82,    18,     0,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    66,    67,     0,     0,     0,    82,     0,     0,
       0,     0,     0,    29,     0,    82,     0,    82,    47,     0,
      23,    74,    84,     0,    70,    60,    19,    81,    61,    62,
      63,    64,    65,    52,    53,    54,    55,    56,    57,    58,
      59,    82,    82,    82,     0,    82,    35,    36,    82,    41,
      40,     0,    25,    27,    28,    51,    49,    82,    73,     0,
       0,    82,     0,     0,    30,    39,     0,    82,    83,    82,
      82,     0,    82,    82,    82,    38,    31,    33,    43,    34,
       0,    37,    82,    82,    32,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,   133,  -122,     5,     7,  -122,   127,   -27,   -35,
    -122,    95,  -122,   139,    62,  -121,  -122,  -122,   -17,  -122,
      41,  -122,   -21,    49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    28,    29,    11,    15,    16,    22,
      17,    34,    35,    93,    94,    95,   131,   142,    30,    31,
      52,    53,    96,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    51,    68,    60,   145,     7,    56,     8,    49,    -3,
       1,     7,     9,     8,    55,    10,     2,    82,    83,     3,
      61,    62,    63,    64,    65,    33,   155,    14,   156,   157,
      27,   159,   106,   161,     2,    12,     2,     3,   102,     3,
      32,   164,    20,    59,   -44,   105,    21,    21,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     2,    18,    33,     3,    68,   124,    19,    71,    72,
      73,    24,    51,    23,   129,   130,   135,    36,    37,    38,
      82,    83,    39,    40,    47,    50,    41,    25,    25,   -26,
      68,    69,    70,    71,    72,    73,    42,    54,    57,    58,
     139,   140,   143,    21,    97,    82,    83,   146,    43,    44,
      45,    84,    98,    85,    86,    87,   102,    88,    89,    90,
     151,    91,    92,    99,   107,    68,   121,   122,   123,   126,
     125,   127,   160,   128,   147,   132,   138,   152,   162,    13,
     136,    27,   165,   -44,   -44,   -44,   -44,     2,   -44,   -44,
       3,    48,   -44,   100,   -44,   -44,    26,   133,   -44,     0,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   148,   -44,   -44,    36,
      37,    38,     0,     0,    39,    40,     0,     0,    41,     0,
      25,     0,     0,     0,     0,    36,    37,    38,    42,     0,
      39,    40,     0,     0,    41,   101,     0,     0,     0,     0,
      43,    44,    45,    84,    42,    85,    86,    87,     0,    88,
      89,    90,     0,    91,    92,     0,    43,    44,    45,    36,
      37,    38,     0,     0,    39,    40,     0,     0,    41,    66,
      36,    37,    38,     0,   141,    39,    40,     0,    42,    41,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    42,
      43,    44,    45,    66,     0,    80,    81,     0,    82,    83,
       0,    43,    44,    45,    67,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    66,    82,    83,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    66,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    66,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    66,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    66,    82,    83,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    66,    82,    83,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    66,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    66,    82,    83,
       0,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    66,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    66,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    66,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    66,
      82,    83,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    68,
      69,    70,    71,    72,    73,    80,     0,     0,    82,    83,
       0,     0,     0,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
      21,    28,    20,    38,   125,     0,    33,     0,    25,     0,
       1,     6,    18,     6,    31,     5,     7,    35,    36,    10,
      41,    42,    43,    44,    45,    20,   147,     5,   149,   150,
       1,   152,    67,   154,     7,     0,     7,    10,    59,    10,
      13,   162,    12,    12,    15,    66,    16,    16,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     7,    18,    58,    10,    20,    87,    14,    23,    24,
      25,    19,    99,    18,     3,     4,    97,     3,     4,     5,
      35,    36,     8,     9,     5,    18,    12,    14,    14,    15,
      20,    21,    22,    23,    24,    25,    22,    15,    13,    19,
     121,   122,   123,    16,    26,    35,    36,   128,    34,    35,
      36,    37,    18,    39,    40,    41,   137,    43,    44,    45,
     141,    47,    48,    19,     5,    20,    12,    12,    12,    18,
      42,    18,   153,    12,    42,    15,    13,    13,    38,     6,
      99,     1,   163,     3,     4,     5,     6,     7,     8,     9,
      10,    24,    12,    58,    14,    15,    17,    95,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    -1,    43,    44,    45,   137,    47,    48,     3,
       4,     5,    -1,    -1,     8,     9,    -1,    -1,    12,    -1,
      14,    -1,    -1,    -1,    -1,     3,     4,     5,    22,    -1,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    22,    39,    40,    41,    -1,    43,
      44,    45,    -1,    47,    48,    -1,    34,    35,    36,     3,
       4,     5,    -1,    -1,     8,     9,    -1,    -1,    12,     6,
       3,     4,     5,    -1,    18,     8,     9,    -1,    22,    12,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    22,
      34,    35,    36,     6,    -1,    32,    33,    -1,    35,    36,
      -1,    34,    35,    36,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     6,    35,    36,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     6,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     6,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     6,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     6,    35,    36,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     6,    35,    36,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     6,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     6,    35,    36,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     6,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     6,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     6,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     6,
      35,    36,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    20,
      21,    22,    23,    24,    25,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    10,    98,    99,   100,   101,   102,    18,
       5,   103,     0,    99,     5,   104,   105,   107,    18,    14,
      12,    16,   106,    18,    19,    14,   110,     1,   101,   102,
     115,   116,    13,   101,   108,   109,     3,     4,     5,     8,
       9,    12,    22,    34,    35,    36,   119,     5,   104,   115,
      18,   105,   117,   118,    15,   115,   105,    13,    19,    12,
     106,   119,   119,   119,   119,   119,     6,    17,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    35,    36,    37,    39,    40,    41,    43,    44,
      45,    47,    48,   110,   111,   112,   119,    26,    18,    19,
     108,    13,   119,   120,    13,   119,   106,     5,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,    12,    12,    12,   119,    42,    18,    18,    12,     3,
       4,   113,    15,   111,    18,   119,   117,    19,    13,   119,
     119,    18,   114,   119,    18,   112,   119,    42,   120,    13,
      13,   119,    13,    18,    13,   112,   112,   112,    18,   112,
     119,   112,    38,    18,   112,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    99,    99,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     2,     1,
       1,     5,     2,     1,     1,     3,     1,     2,     3,     4,
       4,     3,     1,     3,     2,     4,     0,     2,     2,     1,
       3,     5,     7,     5,     5,     2,     2,     5,     4,     3,
       1,     1,     5,     3,     0,     2,     2,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       2,     3,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 57 "grammarTree.y" /* yacc.c:1646  */
    {semantic_Analysis0((yyvsp[0].ptr));}
#line 1656 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1662 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,EXT_DEF_LIST,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1668 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,EXT_VAR_DEF,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr));}
#line 1674 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 63 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,EXT_STRUCT_DEF,yylineno,(yyvsp[-1].ptr));}
#line 1680 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3,FUNC_DEF,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1686 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "grammarTree.y" /* yacc.c:1646  */
    { (yyval.ptr) = NULL; fprintf(stderr, "Grammar Error at Line %d Column %d：",yylloc.first_line,yylloc.first_column);}
#line 1692 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,TYPE,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));(yyval.ptr)->type=(!strcmp((yyvsp[0].type_id),"int"))? INT : ((!strcmp((yyvsp[0].type_id), "float")) ? FLOAT : ((!strcmp((yyvsp[0].type_id), "char")) ? CHAR : ((!strcmp((yyvsp[0].type_id), "string")) ? STRING : VOID)));}
#line 1698 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 68 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1704 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, STRUCT_DEF, yylineno, (yyvsp[-3].ptr), (yyvsp[-1].ptr));}
#line 1710 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1, STRUCT_DEC, yylineno, (yyvsp[0].ptr));}
#line 1716 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0, ID, yylineno);strcpy((yyval.ptr)->type_id, (yyvsp[0].type_id));}
#line 1722 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 76 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,EXT_DEC_LIST,yylineno,(yyvsp[0].ptr));}
#line 1728 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,EXT_DEC_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1734 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 80 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1740 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 81 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ARRAY_DEC,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 1746 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ARRAY_LIST,yylineno,(yyvsp[-1].ptr));}
#line 1752 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 85 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ARRAY_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1758 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 88 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,FUNC_DEC,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 1764 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 89 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,FUNC_DEC,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));(yyval.ptr)->ptr[0]=NULL;}
#line 1770 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 91 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,PARAM_LIST,yylineno,(yyvsp[0].ptr));}
#line 1776 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 92 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PARAM_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1782 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 94 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PARAM_DEC,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1788 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 97 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,COMP_STM,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr));}
#line 1794 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 99 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL; }
#line 1800 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 100 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,STM_LIST,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1806 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 102 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,EXP_STMT,yylineno,(yyvsp[-1].ptr));}
#line 1812 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 103 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1818 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,RETURN,yylineno,(yyvsp[-1].ptr));}
#line 1824 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,IF_THEN,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1830 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 106 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3,IF_THEN_ELSE,yylineno,(yyvsp[-4].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1836 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,WHILE,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1842 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,FOR,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1848 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 109 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,CONTINUE, yylineno);}
#line 1854 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 110 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,BREAK,yylineno);}
#line 1860 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 111 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,SWITCH_STMT,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1866 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,CASE_STMT, yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1872 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 113 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,DEFAULT_STMT, yylineno,(yyvsp[0].ptr));}
#line 1878 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 116 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,INT,yylineno);(yyval.ptr)->type_int=(yyvsp[0].type_int);(yyval.ptr)->type=INT;}
#line 1884 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 117 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,CHAR,yylineno);strcpy((yyval.ptr)->type_char, (yyvsp[0].type_char));(yyval.ptr)->type=CHAR;}
#line 1890 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 120 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(3, FOR_DEC, yylineno, (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));}
#line 1896 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 121 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,FOR_DEC, yylineno, (yyvsp[-1].ptr));}
#line 1902 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL; }
#line 1908 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 125 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DEF_LIST,yylineno,(yyvsp[-1].ptr),(yyvsp[0].ptr));}
#line 1914 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 126 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);}
#line 1920 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 128 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,VAR_DEF,yylineno,(yyvsp[-2].ptr),(yyvsp[-1].ptr));}
#line 1926 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 130 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,DEC_LIST,yylineno,(yyvsp[0].ptr));}
#line 1932 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 131 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DEC_LIST,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 1938 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 133 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1944 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 134 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 1950 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 136 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 1956 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 137 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PLUSASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "PLUSASSIGNOP");}
#line 1962 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 138 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MINUSASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "MINUSASSIGNOP");}
#line 1968 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 139 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2, STARASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"STARASSIGNOP");}
#line 1974 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 140 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DIVASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"DIVASSIGNOP");}
#line 1980 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 141 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MODASSIGNOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "MODASSIGNOP");}
#line 1986 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 142 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,AND,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"AND");}
#line 1992 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 143 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,OR,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"OR");}
#line 1998 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 144 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,RELOP,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 2004 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 145 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,PLUS,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"PLUS");}
#line 2010 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 146 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MINUS,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"MINUS");}
#line 2016 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 147 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,STAR,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"STAR");}
#line 2022 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 148 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,DIV,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"DIV");}
#line 2028 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 149 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,MOD,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"MOD");}
#line 2034 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 150 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOPLUS_R,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id, "AUTO");}
#line 2040 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 151 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOMINUS_R,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,"AUTO");}
#line 2046 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 152 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOPLUS_L,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "AUTO");}
#line 2052 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 153 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,AUTOMINUS_L,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id, "AUTO");}
#line 2058 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 154 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[-1].ptr);}
#line 2064 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 155 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,UMINUS,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"UMINUS");}
#line 2070 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 156 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,NOT,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,"NOT");}
#line 2076 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 157 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,FUNC_CALL,yylineno,(yyvsp[-1].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 2082 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 158 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,FUNC_CALL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-2].type_id));}
#line 2088 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 159 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,ID,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 2094 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 160 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,INT,yylineno);(yyval.ptr)->type_int=(yyvsp[0].type_int);(yyval.ptr)->type=INT;}
#line 2100 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 161 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,CHAR,yylineno);strcpy((yyval.ptr)->type_char, (yyvsp[0].type_char));(yyval.ptr)->type=CHAR;}
#line 2106 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 162 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,FLOAT,yylineno);(yyval.ptr)->type_float=(yyvsp[0].type_float);(yyval.ptr)->type=FLOAT;}
#line 2112 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 163 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(0,STRING,yylineno);strcpy((yyval.ptr)->type_string,(yyvsp[0].type_string));(yyval.ptr)->type=STRING;}
#line 2118 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 164 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,EXP_ARRAY,yylineno,(yyvsp[0].ptr));strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 2124 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 165 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,EXP_ELE,yylineno,(yyvsp[-2].ptr)); strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 2130 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 166 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 2136 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 170 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(2,ARGS,yylineno,(yyvsp[-2].ptr),(yyvsp[0].ptr));}
#line 2142 "grammarTree.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 171 "grammarTree.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(1,ARGS,yylineno,(yyvsp[0].ptr));}
#line 2148 "grammarTree.tab.c" /* yacc.c:1646  */
    break;


#line 2152 "grammarTree.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 174 "grammarTree.y" /* yacc.c:1906  */


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
