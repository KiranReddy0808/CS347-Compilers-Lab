/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y" /* yacc.c:337  */

#include <bits/stdc++.h>
#include "compiler.h"
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(string s){
	return;	
}


#line 84 "parser.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    GTE = 258,
    LTE = 259,
    LT = 260,
    GT = 261,
    NEQ = 262,
    EQ = 263,
    ASGN = 264,
    AND = 265,
    OR = 266,
    NOT = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    DIVIDE = 271,
    MODULO = 272,
    INCREMENT = 273,
    DECREMENT = 274,
    IF = 275,
    ELSE = 276,
    SWITCH = 277,
    CASE = 278,
    DEFAULT = 279,
    BREAK = 280,
    CONTINUE = 281,
    THEN = 282,
    WHILE = 283,
    FOR = 284,
    OPEN_PAR = 285,
    OPEN_CURLY = 286,
    CLOSE_PAR = 287,
    CLOSE_CURLY = 288,
    COMMA = 289,
    SEMI = 290,
    OPEN_BRAC = 291,
    CLOSE_BRAC = 292,
    COLON = 293,
    INT = 294,
    FLOAT = 295,
    VOID = 296,
    RETURN = 297,
    CONST = 298,
    EXTERN = 299,
    STATIC = 300,
    REAL = 301,
    ID = 302,
    ERROR = 303,
    END = 304,
    NEG = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:352  */

	Node *node;

#line 182 "parser.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

#define YYUNDEFTOK  2
#define YYMAXUTOK   305

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    48,    49,    53,    54,    55,    59,    60,
      61,    62,    63,    64,    65,    66,    70,    71,    72,    73,
      77,    78,    79,    83,    87,    88,    92,    93,    97,    98,
      99,   100,   101,   102,   106,   107,   108,   109,   113,   117,
     118,   122,   126,   127,   131,   132,   136,   137,   141,   142,
     146,   147,   148,   149,   150,   151,   152,   153,   157,   161,
     162,   166,   167,   171,   172,   176,   177,   181,   182,   186,
     187,   191,   192,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   209,   210,   211,   212,   213,   214,   215,
     216,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GTE", "LTE", "LT", "GT", "NEQ", "EQ",
  "ASGN", "AND", "OR", "NOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "MODULO",
  "INCREMENT", "DECREMENT", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "CONTINUE", "THEN", "WHILE", "FOR", "OPEN_PAR", "OPEN_CURLY",
  "CLOSE_PAR", "CLOSE_CURLY", "COMMA", "SEMI", "OPEN_BRAC", "CLOSE_BRAC",
  "COLON", "INT", "FLOAT", "VOID", "RETURN", "CONST", "EXTERN", "STATIC",
  "REAL", "ID", "ERROR", "END", "NEG", "$accept", "Input",
  "Global_Statement", "Var_Decl", "Var_List", "Var", "Var_Asgn",
  "Dim_List", "Brac_Dim_List", "Func_Decl", "Decl_Param_List", "Func_Call",
  "Param_List", "Func_Defn", "Decl_Param", "Defn_Param", "Statements",
  "Statement", "Non_Conditional_Statement", "Block", "Loop_Block",
  "For_Control", "Init_Statement", "Conditional_Block", "If_Else_Block",
  "Switch_Block", "Switch_Body", "Condition", "Constant_Expression",
  "Expression", YY_NULLPTR
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
     305
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,   -13,    -2,    33,    40,   -31,    51,    99,  -164,   109,
     120,  -164,    36,  -164,  -164,    -8,    90,     6,    96,    13,
     127,   125,   133,   133,   133,   133,   133,   133,  -164,  -164,
     177,  -164,  -164,   135,   195,  -164,  -164,   195,   133,   133,
     147,  -164,   153,   152,   155,   180,   183,   200,   231,   259,
     195,   133,   133,   273,   274,   272,   277,   278,   279,   195,
    -164,   133,   133,   195,  -164,   168,  -164,    86,  -164,  -164,
     280,   177,  -164,  -164,  -164,  -164,  -164,  -164,   243,  -164,
     264,   267,   299,   298,   300,   103,   313,  -164,  -164,  -164,
     301,  -164,   304,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,   164,    -9,  -164,  -164,   164,    80,   283,   248,
     195,  -164,  -164,  -164,  -164,   195,   195,   195,   195,   195,
    -164,  -164,  -164,  -164,   131,   131,   195,   270,  -164,  -164,
     164,   164,    16,   338,    -7,    -7,  -164,   305,   303,    47,
    -164,   306,   154,   260,  -164,  -164,   307,   271,    97,   134,
     237,  -164,  -164,  -164,  -164,   310,   276,   195,  -164,  -164,
      92,   223,   164,   164,   177,   195,   195,   195,   195,   195,
     195,  -164,   308,   317,    -7,    -7,    -7,    -7,    -7,   318,
     177,   177,   195,     9,  -164,  -164,   195,  -164,   195,   235,
    -164,   269,   269,   329,   313,   313,   313,   313,   313,   313,
    -164,   258,   217,   254,   285,  -164,  -164,   258,  -164,  -164,
     313,   195,  -164,  -164,   177,    -7,   319,   323,   325,   313,
    -164,   230,   177,  -164,  -164,   177,  -164,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     5,     0,     7,     3,    20,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     6,    41,     0,     0,    22,     8,     0,     0,     0,
       0,     9,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,    91,    20,    52,    92,    93,    94,
       0,    47,    48,    50,    51,    49,    65,    66,     0,    31,
      42,    43,     0,    36,    37,     0,    23,    16,    17,    32,
       0,    33,     0,    10,    11,    14,    15,    12,    13,   105,
      97,    98,     0,     0,    54,    55,     0,     0,     0,     0,
       0,    95,    96,    58,    46,     0,     0,     0,     0,     0,
      53,    44,    45,    28,     0,     0,     0,    27,    29,    30,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
      64,     0,     0,     0,    99,    56,     0,    40,   100,   101,
     102,   103,   104,    34,    35,     0,    25,     0,    26,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    38,     0,    21,     0,     0,
      73,    76,    75,    67,    80,    79,    77,    78,    82,    81,
      84,     0,    85,    86,    87,    88,    89,     0,    60,    59,
      62,     0,    39,    24,     0,     0,     0,     0,     0,    61,
      68,     0,     0,    70,    69,     0,    72,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,   349,  -164,    14,   119,     8,    39,   172,   234,  -164,
     -36,  -164,   176,  -164,  -164,  -164,   -69,  -163,  -164,   351,
    -164,  -164,  -164,  -164,  -164,  -164,   157,   -56,  -122,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    66,    16,    67,    68,   155,    35,    12,
      82,    69,   146,    13,    83,    84,    70,    71,    72,    73,
      74,   141,   142,    75,    76,    77,   217,   132,   138,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      85,   193,   114,    86,    90,   134,    92,   134,    22,    23,
      17,    17,   171,   172,    11,    37,    99,   208,   209,   162,
     163,   135,    33,   135,    11,   108,   162,   163,    34,   109,
      17,    17,    17,    17,    17,    17,    14,   136,    43,   136,
      38,    18,    18,    40,   211,    15,    17,    17,   164,    34,
     139,   220,   202,   203,   204,   205,   206,   162,   163,   100,
     101,    18,    18,    18,    18,    18,    18,    30,   133,    17,
      17,    31,   133,   143,   159,   160,   147,    18,    18,   180,
      19,   148,   149,   150,   151,   152,   183,    21,   153,   154,
      24,    25,   156,   221,    50,    37,   133,   161,    51,    52,
      18,    18,   162,   163,   111,   112,   191,   192,   133,    28,
      59,   137,   117,   118,   119,   140,   115,   116,   117,   118,
     119,     1,    20,   189,   190,    36,    64,    65,   133,   133,
      39,   194,   195,   196,   197,   198,   199,   126,    26,    27,
     127,    44,    45,    46,    47,    48,    49,   115,   210,   117,
     118,   119,   147,   226,   156,    42,   227,    87,    88,     2,
       3,     4,    41,     5,     6,     7,   130,    79,    50,     8,
      80,    81,    51,    52,    80,    81,   130,   219,    50,    89,
      43,    20,    51,    52,   131,    91,    80,    81,    34,   182,
      93,    50,    80,    81,   131,    51,    52,    53,   110,    54,
      64,    65,    55,    56,    34,    57,    58,    59,    30,    50,
      64,    65,    60,    51,    52,    94,    61,    62,    95,    63,
       5,     6,     7,    64,    65,    59,   165,   166,   167,   168,
     169,   170,   176,   177,   178,    96,   115,   116,   117,   118,
     119,    64,    65,   174,   175,   176,   177,   178,   115,   116,
     117,   118,   119,   118,   119,   144,   115,   116,   117,   118,
     119,   115,   116,   117,   118,   119,    97,   174,   225,   176,
     177,   178,   127,   115,   116,   117,   118,   119,   120,   162,
     163,   215,   216,   145,   115,   116,   117,   118,   119,   115,
     116,   117,   118,   119,    98,   184,   115,   116,   117,   118,
     119,   177,   178,   102,   103,   186,   157,   104,   106,   107,
     188,   121,   105,   113,   122,   144,   174,   175,   176,   177,
     178,   174,   175,   176,   177,   178,   115,   116,   117,   118,
     119,   123,   124,   128,   125,   179,   129,   173,   181,   185,
     200,   165,   166,   167,   168,   169,   170,   187,   201,   207,
     214,   115,   116,   117,   118,   119,   223,   222,   224,    29,
     213,   158,   212,    32,   218
};

static const yytype_uint8 yycheck[] =
{
      34,   164,    71,    37,    40,    14,    42,    14,    39,    40,
       2,     3,   134,   135,     0,     9,    50,   180,   181,    10,
      11,    30,    30,    30,    10,    59,    10,    11,    36,    63,
      22,    23,    24,    25,    26,    27,    49,    46,    47,    46,
      34,     2,     3,    30,    35,    47,    38,    39,    32,    36,
     106,   214,   174,   175,   176,   177,   178,    10,    11,    51,
      52,    22,    23,    24,    25,    26,    27,    31,   102,    61,
      62,    35,   106,   107,   130,   131,   110,    38,    39,    32,
      47,   115,   116,   117,   118,   119,   142,    47,   124,   125,
      39,    40,   126,   215,    14,     9,   130,   131,    18,    19,
      61,    62,    10,    11,    18,    19,   162,   163,   142,     0,
      30,   103,    15,    16,    17,    35,    13,    14,    15,    16,
      17,     1,     3,   157,    32,    35,    46,    47,   162,   163,
      34,   165,   166,   167,   168,   169,   170,    34,    39,    40,
      37,    22,    23,    24,    25,    26,    27,    13,   182,    15,
      16,    17,   186,   222,   188,    30,   225,    38,    39,    39,
      40,    41,    35,    43,    44,    45,    12,    32,    14,    49,
      39,    40,    18,    19,    39,    40,    12,   211,    14,    32,
      47,    62,    18,    19,    30,    32,    39,    40,    36,    35,
      35,    14,    39,    40,    30,    18,    19,    20,    30,    22,
      46,    47,    25,    26,    36,    28,    29,    30,    31,    14,
      46,    47,    35,    18,    19,    35,    39,    40,    35,    42,
      43,    44,    45,    46,    47,    30,     3,     4,     5,     6,
       7,     8,    15,    16,    17,    35,    13,    14,    15,    16,
      17,    46,    47,    13,    14,    15,    16,    17,    13,    14,
      15,    16,    17,    16,    17,    32,    13,    14,    15,    16,
      17,    13,    14,    15,    16,    17,    35,    13,    38,    15,
      16,    17,    37,    13,    14,    15,    16,    17,    35,    10,
      11,    23,    24,    35,    13,    14,    15,    16,    17,    13,
      14,    15,    16,    17,    35,    35,    13,    14,    15,    16,
      17,    16,    17,    30,    30,    34,    36,    35,    30,    30,
      34,    47,    35,    33,    47,    32,    13,    14,    15,    16,
      17,    13,    14,    15,    16,    17,    13,    14,    15,    16,
      17,    32,    34,    32,    34,    32,    32,    32,    32,    32,
      32,     3,     4,     5,     6,     7,     8,    37,    31,    31,
      21,    13,    14,    15,    16,    17,    33,    38,    33,    10,
     188,   127,   186,    12,   207
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    39,    40,    41,    43,    44,    45,    49,    52,
      53,    54,    60,    64,    49,    47,    55,    56,    57,    47,
      55,    47,    39,    40,    39,    40,    39,    40,     0,    52,
      31,    35,    70,    30,    36,    59,    35,     9,    34,    34,
      30,    35,    30,    47,    55,    55,    55,    55,    55,    55,
      14,    18,    19,    20,    22,    25,    26,    28,    29,    30,
      35,    39,    40,    42,    46,    47,    54,    56,    57,    62,
      67,    68,    69,    70,    71,    74,    75,    76,    80,    32,
      39,    40,    61,    65,    66,    80,    80,    55,    55,    32,
      61,    32,    61,    35,    35,    35,    35,    35,    35,    80,
      56,    56,    30,    30,    35,    35,    30,    30,    80,    80,
      30,    18,    19,    33,    67,    13,    14,    15,    16,    17,
      35,    47,    47,    32,    34,    34,    34,    37,    32,    32,
      12,    30,    78,    80,    14,    30,    46,    56,    79,    78,
      35,    72,    73,    80,    32,    35,    63,    80,    80,    80,
      80,    80,    80,    61,    61,    58,    80,    36,    59,    78,
      78,    80,    10,    11,    32,     3,     4,     5,     6,     7,
       8,    79,    79,    32,    13,    14,    15,    16,    17,    32,
      32,    32,    35,    78,    35,    32,    34,    37,    34,    80,
      32,    78,    78,    68,    80,    80,    80,    80,    80,    80,
      32,    31,    79,    79,    79,    79,    79,    31,    68,    68,
      80,    35,    63,    58,    21,    23,    24,    77,    77,    80,
      68,    79,    38,    33,    33,    38,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    62,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     2,     1,     3,     3,
       4,     4,     4,     4,     4,     4,     3,     3,     1,     1,
       1,     6,     2,     3,     3,     1,     4,     3,     5,     5,
       5,     4,     4,     4,     3,     3,     1,     1,     4,     3,
       1,     2,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     3,     1,     3,     5,
       5,     4,     3,     2,     1,     1,     1,     5,     7,     7,
       7,     4,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 47 "parser.y" /* yacc.c:1667  */
    {  }
#line 1456 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 3:
#line 48 "parser.y" /* yacc.c:1667  */
    { cout<<"Invalid Syntax\n"<<endl; YYABORT; }
#line 1462 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 4:
#line 49 "parser.y" /* yacc.c:1667  */
    { YYABORT; }
#line 1468 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 5:
#line 53 "parser.y" /* yacc.c:1667  */
    { cout<<"\n\n$$Var_Decl$$\n\n"; printTree((yyvsp[0].node)); }
#line 1474 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 6:
#line 54 "parser.y" /* yacc.c:1667  */
    { cout<<"\n\n$$Func_Decl$$\n\n"; printTree((yyvsp[-1].node)); }
#line 1480 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 7:
#line 55 "parser.y" /* yacc.c:1667  */
    { cout<<"\n\n$$Func_Defn$$\n\n"; printTree((yyvsp[0].node)); }
#line 1486 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 59 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "int"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1492 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 9:
#line 60 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "flt"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1498 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 61 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "const_int"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1504 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 62 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "flt"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1510 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 63 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "static_int"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1516 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 64 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "flt"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1522 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 65 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "extern_int"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1528 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 66 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_decl", "flt"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1534 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 16:
#line 70 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_list", "var_more"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1540 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 71 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_list", "var_asgn_more"); (yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node));	}
#line 1546 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 72 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_list", "var"); (yyval.node)->childs.push_back((yyvsp[0].node));	}
#line 1552 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 19:
#line 73 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_list", "var_asgn"); (yyval.node)->childs.push_back((yyvsp[0].node));	}
#line 1558 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 77 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var", "id");}
#line 1564 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 21:
#line 78 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var", "id_dim_list"); (yyval.node)->childs.push_back((yyvsp[-3].node)); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1570 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 22:
#line 79 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var", "id_brac"); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1576 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 83 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("var_asgn", "default");  (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1582 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 24:
#line 87 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("dim_list", "more");  (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1588 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 25:
#line 88 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("dim_list", "one");  (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1594 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 26:
#line 92 "parser.y" /* yacc.c:1667  */
    {(yyval.node) = new Node("brac_list", "more");  (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1600 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 93 "parser.y" /* yacc.c:1667  */
    {(yyval.node) = new Node("brac_list", "one");  (yyval.node)->childs.push_back((yyvsp[-1].node));}
#line 1606 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 28:
#line 97 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_decl", "int_plist");  (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1612 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 29:
#line 98 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_decl", "float_plist");  (yyval.node)->childs.push_back((yyvsp[-1].node));}
#line 1618 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 30:
#line 99 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_decl", "void_plist");  (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1624 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 100 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_decl", "int_none");}
#line 1630 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 32:
#line 101 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_decl", "float_none");}
#line 1636 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 33:
#line 102 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_decl", "void_none");}
#line 1642 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 34:
#line 106 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("decl_plist", "decl_type_more");  (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1648 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 35:
#line 107 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("decl_plist", "defn_type_more");  (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1654 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 36:
#line 108 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("decl_plist", "decl_type_one");  (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1660 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 37:
#line 109 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("decl_plist", "defn_type_one");  (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1666 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 38:
#line 113 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_call", ""); (yyval.node)->childs.push_back((yyvsp[-3].node)); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1672 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 39:
#line 117 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("pm_list", "more");  (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1678 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 40:
#line 118 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("pm_list", "one");  (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1684 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 41:
#line 122 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("func_defn", ""); (yyval.node)->childs.push_back((yyvsp[-1].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1690 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 126 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("decl_pm", "int"); }
#line 1696 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 127 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("decl_pm", "flt"); }
#line 1702 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 131 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("defn_pm", "int"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1708 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 132 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("defn_pm", "flt"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1714 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 136 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("statements", "more");  (yyval.node)->childs.push_back((yyvsp[-1].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1720 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 47:
#line 137 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("statements", "one");  (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1726 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 141 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("statement", "non_condl");  (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1732 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 142 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("statement", "condl");  (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1738 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 146 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "block");  (yyval.node)->childs.push_back((yyvsp[0].node));  }
#line 1744 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 147 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "loop");  (yyval.node)->childs.push_back((yyvsp[0].node));  }
#line 1750 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 148 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "var_decl");  (yyval.node)->childs.push_back((yyvsp[0].node));  }
#line 1756 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 149 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "expr_semi");  (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1762 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 150 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "brk_semi"); }
#line 1768 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 151 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "cont_semi");}
#line 1774 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 56:
#line 152 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "ret_semi");  (yyval.node)->childs.push_back((yyvsp[-1].node));  }
#line 1780 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 153 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("non_condl", "semi"); }
#line 1786 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 157 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("block", ""); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1792 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 161 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("loop", "for"); (yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1798 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 162 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("loop", "condl"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1804 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 166 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("for", "condl"); (yyval.node)->childs.push_back((yyvsp[-3].node));(yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1810 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 167 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("for", "none"); (yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1816 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 63:
#line 171 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("init_stmt", "expr"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1822 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 64:
#line 172 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("init_stmt", "semi"); }
#line 1828 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 65:
#line 176 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condl_block", "if_else"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1834 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 66:
#line 177 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condl_block", "switch"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1840 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 181 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("if_else", "if"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1846 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 182 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("if_else", "if_else"); (yyval.node)->childs.push_back((yyvsp[-4].node)); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1852 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 69:
#line 186 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("switch", "const"); (yyval.node)->childs.push_back((yyvsp[-4].node)); (yyval.node)->childs.push_back((yyvsp[-1].node));}
#line 1858 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 70:
#line 187 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("switch", "var"); (yyval.node)->childs.push_back((yyvsp[-4].node));(yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1864 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 71:
#line 191 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("switch_body", "case"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1870 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 72:
#line 192 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("switch_body", "deafult"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1876 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 73:
#line 196 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "par_cond"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1882 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 74:
#line 197 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "not_cond"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1888 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 75:
#line 198 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "or"); (yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1894 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 76:
#line 199 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "and"); (yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1900 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 200 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "lt"); (yyval.node)->childs.push_back((yyvsp[-2].node));(yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1906 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 201 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "gt"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1912 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 79:
#line 202 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "lte"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1918 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 203 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "gte"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1924 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 204 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "eq"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1930 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 82:
#line 205 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("condition", "neq"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1936 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 83:
#line 209 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "real"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1942 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 84:
#line 210 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "par_exp"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 1948 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 85:
#line 211 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "plus"); (yyval.node)->childs.push_back((yyvsp[-2].node));	(yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1954 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 86:
#line 212 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "minus"); (yyval.node)->childs.push_back((yyvsp[-2].node));	(yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1960 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 87:
#line 213 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "times"); (yyval.node)->childs.push_back((yyvsp[-2].node));	(yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1966 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 88:
#line 214 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "divide"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1972 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 89:
#line 215 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "modulo"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 1978 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 90:
#line 216 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("const_expr", "neg"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1984 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 91:
#line 220 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "real"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1990 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 92:
#line 221 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "var"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 1996 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 93:
#line 222 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "val_asgn"); (yyval.node)->childs.push_back((yyvsp[0].node));}
#line 2002 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 94:
#line 223 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "func_call"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2008 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 95:
#line 224 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "var_incr"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 2014 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 96:
#line 225 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "var_decr"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 2020 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 97:
#line 226 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "incr_var"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2026 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 98:
#line 227 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "decr_var"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2032 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 99:
#line 228 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "par_exp"); (yyval.node)->childs.push_back((yyvsp[-1].node)); }
#line 2038 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 100:
#line 229 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "plus"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2044 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 101:
#line 230 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "minus"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2050 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 102:
#line 231 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "times"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2056 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 103:
#line 232 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "divide"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2062 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 104:
#line 233 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "modulo"); (yyval.node)->childs.push_back((yyvsp[-2].node)); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2068 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 105:
#line 234 "parser.y" /* yacc.c:1667  */
    { (yyval.node) = new Node("expr", "neg"); (yyval.node)->childs.push_back((yyvsp[0].node)); }
#line 2074 "parser.tab.c" /* yacc.c:1667  */
    break;


#line 2078 "parser.tab.c" /* yacc.c:1667  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 237 "parser.y" /* yacc.c:1918  */


 int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
 }
