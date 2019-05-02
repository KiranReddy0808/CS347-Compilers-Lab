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
void yyerror(string s);
bool syntax_error = false;
DataType declType = dt_none;
int level;
Node* parseTree = new Node("parse_tree","");
vector <FuncNode*> funcTable;
vector <SymbolNode*> globalVars;

FuncNode* activeFuncPtr;

extern int yylineno;

FuncNode* functionFinder(string name){
	for (int i=0; i<funcTable.size(); i++){
		if (funcTable[i]->name == name){
			return funcTable[i];
		}
	}
	return NULL;
}

SymbolNode* paramExists(vector <SymbolNode*> &paramList, string name){
	for (int i=0; i<paramList.size(); i++){
		if (paramList[i]->name == name){
			return paramList[i];
		}
	}
	return NULL;
}

int convertParamList(vector <Node*> &nodeList ,vector <SymbolNode*> &paramList, string funcName){
	int retValue = 0;
	for (int i=nodeList.size()-1; i>=0; i--){
		if (nodeList[i]->dataType == "decl_pm"){
			if(nodeList[i]->valueType == "int"){
				paramList.push_back(new SymbolNode("",false,1,dt_int));
			}
			else if(nodeList[i]->valueType == "flt"){
				paramList.push_back(new SymbolNode("",false,1,dt_flt));
			}
		}
		else if(nodeList[i]->dataType == "defn_pm"){
			if (paramExists(paramList, nodeList[i]->childs[0]->valueType)==NULL){
				if(nodeList[i]->valueType == "int"){
					paramList.push_back(new SymbolNode(nodeList[i]->childs[0]->valueType,false,1,dt_int));
				}
				else if(nodeList[i]->valueType == "flt"){
					paramList.push_back(new SymbolNode(nodeList[i]->childs[0]->valueType,false,1,dt_flt));
				}
			}
			else{
				cout << "Parameter "<<nodeList[i]->childs[0]->valueType<<" defined again in function: "<<funcName<<endl;
				retValue = -1;
			}
		}
	}
	return retValue;
}

SymbolNode *varExists(string name){
	if (functionFinder(name)!=NULL){
		return new SymbolNode(name, false, 0, dt_void);
	}
	if (activeFuncPtr!=NULL){
		for (int i=activeFuncPtr->localVar.size()-1; i>=0; i--){
			if (activeFuncPtr->localVar[i]->name == name){
				return activeFuncPtr->localVar[i];
			}
		}
	}
	for (int i=0; i<globalVars.size(); i++){
		if (globalVars[i]->name == name){
			return globalVars[i];
		}
	}
	return NULL;
}

void addVariable(string name){
	if (activeFuncPtr==NULL){
		globalVars.push_back(new SymbolNode(name, false, 1, declType));
	}
	else{
		activeFuncPtr->localVar.push_back(new SymbolNode(name, false, level, declType));
	}
}

void clearLevel(){
	if (activeFuncPtr!=NULL){
		for (int i=activeFuncPtr->localVar.size()-1; i>=0; i--){
			if (activeFuncPtr->localVar[i]->level == level){
				activeFuncPtr->localVar.pop_back();
			}
			else{
				break;
			}
		}
	}
}

bool isNumber(string s){
	try{
		stoi(s);
	}
	catch(exception e){
		return false;
	}
	return true;
}

#line 189 "parser.tab.c" /* yacc.c:337  */
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
# define YYERROR_VERBOSE 1
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
    REAL = 298,
    ID = 299,
    ERROR = 300,
    END = 301,
    NEG = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 121 "parser.y" /* yacc.c:352  */

	Node *node;

#line 284 "parser.tab.c" /* yacc.c:352  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   156,   156,   157,   161,   165,   182,   189,   195,   204,
     207,   210,   214,   242,   275,   302,   337,   342,   351,   362,
     371,   378,   386,   392,   400,   417,   433,   449,   455,   461,
     470,   478,   485,   491,   500,   509,   516,   525,   554,   558,
     565,   570,   578,   587,   598,   606,   617,   625,   633,   644,
     652,   657,   662,   670,   678,   689,   698,   710,   720,   732,
     740,   747,   753,   762,   771,   784,   796,   817,   831,   843,
     856,   870,   881,   892,   904,   916,   932,   948,   964,   980,
     996,  1015,  1028,  1035,  1050,  1065,  1080,  1095,  1111,  1120,
    1133,  1151,  1172,  1178,  1197,  1216,  1235,  1254,  1260,  1279,
    1298,  1317,  1336,  1356,  1371,  1375,  1379
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GTE", "LTE", "LT", "GT", "NEQ", "EQ",
  "ASGN", "AND", "OR", "NOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "MODULO",
  "INCREMENT", "DECREMENT", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "CONTINUE", "THEN", "WHILE", "FOR", "OPEN_PAR", "OPEN_CURLY",
  "CLOSE_PAR", "CLOSE_CURLY", "COMMA", "SEMI", "OPEN_BRAC", "CLOSE_BRAC",
  "COLON", "INT", "FLOAT", "VOID", "RETURN", "REAL", "ID", "ERROR", "END",
  "NEG", "$accept", "Input", "Global_Statement", "Var_Decl",
  "Data_Type_Flt", "Data_Type_Int", "Data_Type_None", "Var_List", "Var",
  "Var_Asgn", "Dim_List", "Brac_Dim_List", "Func_Decl", "Decl_Param_List",
  "Func_Call", "Param_List", "Func_Defn", "Decl_Param", "Defn_Param",
  "Statements", "Statement", "Non_Conditional_Statement", "Block",
  "Loop_Block", "For_Control", "Init_Statement", "Conditional_Block",
  "If_Else_Block", "Switch_Block", "Switch_Body", "Condition",
  "Constant_Expression", "Expression", "Level_PP", "Level_MM",
  "Clear_Level", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -182

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-182)))

#define YYTABLE_NINF -12

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     287,  -182,  -182,   -37,  -182,    18,   287,  -182,   -15,  -182,
     -21,   -10,    26,  -182,  -182,  -182,  -182,  -182,    -3,     3,
       8,    47,    -3,    61,    66,   161,   179,    74,  -182,  -182,
     179,    65,    65,    83,  -182,  -182,    71,    75,    93,   112,
     118,   179,    65,    65,   124,   127,   126,   137,   144,   148,
     179,  -182,  -182,  -182,   179,  -182,    27,  -182,    55,  -182,
    -182,  -182,   161,  -182,  -182,  -182,  -182,  -182,  -182,   153,
     221,   105,  -182,   343,   146,  -182,  -182,   167,  -182,  -182,
    -182,  -182,   109,   109,  -182,  -182,  -182,   141,    25,  -182,
    -182,   141,    40,   283,    65,    65,   236,   179,  -182,  -182,
    -182,  -182,   179,   179,   179,   179,   179,  -182,   179,   166,
    -182,   181,  -182,   210,  -182,  -182,   141,   141,    90,   338,
       5,     5,  -182,   235,   303,   100,  -182,   237,   121,   246,
    -182,  -182,   238,   259,   244,   224,   195,   160,  -182,  -182,
     241,   269,   179,  -182,  -182,  -182,  -182,   131,   211,   141,
     141,  -182,   179,   179,   179,   179,   179,   179,  -182,   308,
     248,     5,     5,     5,     5,     5,   256,  -182,  -182,   179,
       2,  -182,  -182,   179,  -182,  -182,   179,   231,  -182,   184,
     184,   161,   343,   343,   343,   343,   343,   343,  -182,   197,
     249,   275,   240,  -182,  -182,   197,   161,   161,   343,   179,
    -182,  -182,  -182,     5,   242,   271,   272,  -182,  -182,   343,
    -182,   216,  -182,  -182,  -182,  -182,  -182,   281,  -182,   161,
    -182,  -182,  -182,   161,  -182,   161,  -182,  -182,  -182,  -182,
     197,  -182,   197,  -182,  -182,  -182
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     9,     0,     3,     0,     0,     4,     0,     6,
       0,     0,     0,     1,     2,   104,     5,    37,    16,     0,
      14,    15,    16,     0,     0,     0,     0,     0,    18,    11,
       0,     0,     0,     0,    11,    29,    38,    39,     0,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    10,     9,     0,    89,    16,    48,    90,    91,
      92,   106,    43,    44,    46,    47,    45,    61,    62,     0,
       0,     0,     7,    19,    16,    12,    13,     0,     8,    40,
      41,    26,     0,     0,   103,    95,    96,     0,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,    93,    94,
     105,    42,     0,     0,     0,     0,     0,    49,     0,    23,
      27,     0,    28,     0,    30,    31,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,    60,     0,     0,     0,
      97,    52,     0,    36,     0,    98,    99,   100,   101,   102,
       0,    21,     0,    22,    24,    25,    72,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   104,     0,
       0,    59,    34,     0,    54,    17,     0,     0,    71,    74,
      73,     0,    78,    77,    75,    76,    80,    79,    82,     0,
      83,    84,    85,    86,    87,     0,     0,     0,    58,     0,
      35,    20,   106,     0,     0,     0,     0,   106,   106,    57,
     105,     0,   104,    66,    65,   105,   105,    63,   104,     0,
      56,    55,   104,     0,   106,     0,   106,   105,   106,   105,
      70,   105,    69,    68,    64,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,   305,  -182,   108,   261,   257,    38,    -6,    -2,     0,
     154,   220,  -182,   230,  -182,   158,  -182,  -182,  -182,   -61,
    -175,  -182,   324,  -182,  -182,  -182,  -182,  -182,  -182,  -181,
     -29,  -118,   -26,  -115,    79,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    57,    11,    10,    27,    19,    58,    59,
     140,    28,     8,    38,    60,   132,     9,    39,    40,    61,
      62,    63,    64,    65,   127,   128,    66,    67,    68,   205,
     118,   124,    69,    25,   134,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   101,   158,   159,    73,    23,   202,    12,    20,    20,
      21,    21,   149,   150,   206,    84,    15,    30,    13,   120,
      16,   207,   208,    18,    93,    75,    76,   -11,    96,    20,
      20,    21,    21,    26,    22,   121,   181,   199,    29,   120,
      85,    86,    31,   190,   191,   192,   193,   194,   122,   233,
     228,   235,   196,   197,    41,   121,    24,    97,    42,    43,
      33,   119,   125,    26,    30,   119,   129,    72,   122,    74,
      50,   133,    78,    98,    99,   126,   135,   136,   137,   138,
     139,    32,   141,    55,    56,   211,   123,   146,   147,    23,
     119,   148,    20,    20,    21,    21,    34,   219,    35,   170,
     149,   150,   119,   223,    71,    36,    37,   225,     7,    74,
     149,   150,   210,    77,     7,    79,   177,   215,   216,    80,
     179,   180,   151,   119,   119,    81,   182,   183,   184,   185,
     186,   187,   167,   116,   227,    41,   229,   110,   231,    42,
      43,   149,   150,   198,    36,    37,    82,   133,    36,    37,
     141,   117,    83,   116,    87,    41,   169,    88,   224,    42,
      43,    89,   226,   178,    55,    56,   102,   103,   104,   105,
     106,   117,    90,   209,    91,    41,   105,   106,    92,    42,
      43,    44,    26,    45,    55,    56,    46,    47,   107,    48,
      49,    50,    15,    41,   149,   150,    51,    42,    43,   112,
      52,    53,   142,    54,    55,    56,    36,    37,   102,    50,
     104,   105,   106,   144,   152,   153,   154,   155,   156,   157,
     203,   204,    55,    56,   102,   103,   104,   105,   106,   161,
     162,   163,   164,   165,   102,   103,   104,   105,   106,   104,
     105,   106,   145,   130,   102,   103,   104,   105,   106,   102,
     103,   104,   105,   106,   218,   108,   164,   165,   109,   102,
     103,   104,   105,   106,   163,   164,   165,   160,   109,   168,
     172,   131,   102,   103,   104,   105,   106,   174,   175,   189,
     212,   171,   102,   103,   104,   105,   106,   195,   161,   217,
     163,   164,   165,   173,   220,   221,   102,   103,   104,   105,
     106,   111,   222,   176,   213,   214,   230,   113,   232,    94,
     234,    14,   114,   115,    95,   130,   161,   162,   163,   164,
     165,   161,   162,   163,   164,   165,     1,     2,     3,   143,
     201,   200,    17,     4,     0,   166,     0,     0,     0,     0,
     188,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   102,   103,   104,   105,
     106
};

static const yytype_int16 yycheck[] =
{
      26,    62,   120,   121,    30,    11,   181,    44,    10,    11,
      10,    11,    10,    11,   195,    41,    31,     9,     0,    14,
      35,   196,   197,    44,    50,    31,    32,    30,    54,    31,
      32,    31,    32,    36,    44,    30,   151,    35,    35,    14,
      42,    43,    34,   161,   162,   163,   164,   165,    43,   230,
     225,   232,   167,   168,    14,    30,    30,    30,    18,    19,
      22,    87,    91,    36,     9,    91,    92,    29,    43,    44,
      30,    97,    34,    18,    19,    35,   102,   103,   104,   105,
     106,    34,   108,    43,    44,   203,    88,   116,   117,    95,
     116,   117,    94,    95,    94,    95,    35,   212,    32,   128,
      10,    11,   128,   218,    30,    39,    40,   222,     0,    44,
      10,    11,   202,    30,     6,    44,   142,   207,   208,    44,
     149,   150,    32,   149,   150,    32,   152,   153,   154,   155,
     156,   157,    32,    12,   224,    14,   226,    32,   228,    18,
      19,    10,    11,   169,    39,    40,    34,   173,    39,    40,
     176,    30,    34,    12,    30,    14,    35,    30,   219,    18,
      19,    35,   223,    32,    43,    44,    13,    14,    15,    16,
      17,    30,    35,   199,    30,    14,    16,    17,    30,    18,
      19,    20,    36,    22,    43,    44,    25,    26,    35,    28,
      29,    30,    31,    14,    10,    11,    35,    18,    19,    32,
      39,    40,    36,    42,    43,    44,    39,    40,    13,    30,
      15,    16,    17,    32,     3,     4,     5,     6,     7,     8,
      23,    24,    43,    44,    13,    14,    15,    16,    17,    13,
      14,    15,    16,    17,    13,    14,    15,    16,    17,    15,
      16,    17,    32,    32,    13,    14,    15,    16,    17,    13,
      14,    15,    16,    17,    38,    34,    16,    17,    37,    13,
      14,    15,    16,    17,    15,    16,    17,    32,    37,    32,
      32,    35,    13,    14,    15,    16,    17,    33,    37,    31,
      38,    35,    13,    14,    15,    16,    17,    31,    13,   210,
      15,    16,    17,    34,   215,   216,    13,    14,    15,    16,
      17,    71,    21,    34,    33,    33,   227,    77,   229,    52,
     231,     6,    82,    83,    53,    32,    13,    14,    15,    16,
      17,    13,    14,    15,    16,    17,    39,    40,    41,   109,
     176,   173,     8,    46,    -1,    32,    -1,    -1,    -1,    -1,
      32,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    13,    14,    15,    16,
      17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,    41,    46,    49,    50,    51,    60,    64,
      53,    52,    44,     0,    49,    31,    35,    70,    44,    55,
      56,    57,    44,    55,    30,    81,    36,    54,    59,    35,
       9,    34,    34,    54,    35,    32,    39,    40,    61,    65,
      66,    14,    18,    19,    20,    22,    25,    26,    28,    29,
      30,    35,    39,    40,    42,    43,    44,    51,    56,    57,
      62,    67,    68,    69,    70,    71,    74,    75,    76,    80,
      80,    30,    54,    80,    44,    55,    55,    30,    54,    44,
      44,    32,    34,    34,    80,    56,    56,    30,    30,    35,
      35,    30,    30,    80,    53,    52,    80,    30,    18,    19,
      83,    67,    13,    14,    15,    16,    17,    35,    34,    37,
      32,    61,    32,    61,    61,    61,    12,    30,    78,    80,
      14,    30,    43,    56,    79,    78,    35,    72,    73,    80,
      32,    35,    63,    80,    82,    80,    80,    80,    80,    80,
      58,    80,    36,    59,    32,    32,    78,    78,    80,    10,
      11,    32,     3,     4,     5,     6,     7,     8,    79,    79,
      32,    13,    14,    15,    16,    17,    32,    32,    32,    35,
      78,    35,    32,    34,    33,    37,    34,    80,    32,    78,
      78,    81,    80,    80,    80,    80,    80,    80,    32,    31,
      79,    79,    79,    79,    79,    31,    81,    81,    80,    35,
      63,    58,    68,    23,    24,    77,    77,    68,    68,    80,
      83,    79,    38,    33,    33,    83,    83,    82,    38,    81,
      82,    82,    21,    81,    67,    81,    67,    83,    68,    83,
      82,    83,    82,    77,    82,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    51,    51,    52,
      53,    54,    55,    55,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    62,    63,    63,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     5,     5,     0,
       0,     0,     3,     3,     1,     1,     1,     6,     2,     3,
       3,     1,     4,     3,     7,     7,     5,     6,     6,     4,
       3,     3,     1,     1,     4,     3,     1,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     1,     6,     8,     8,     4,     3,     2,
       1,     1,     1,     8,    13,     7,     7,     8,     7,     7,
       6,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     2,     0,     0,     0
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
#line 156 "parser.y" /* yacc.c:1667  */
    {  }
#line 1563 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 3:
#line 157 "parser.y" /* yacc.c:1667  */
    { YYABORT; }
#line 1569 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 4:
#line 162 "parser.y" /* yacc.c:1667  */
    { 
			parseTree->childs.push_back((yyvsp[0].node));
		}
#line 1577 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 5:
#line 166 "parser.y" /* yacc.c:1667  */
    {
			if ((yyvsp[-1].node)->elemType != dt_err){
				FuncNode *funcExists = functionFinder(activeFuncPtr->name);
				if (funcExists == NULL){
					for (int i=0; i<activeFuncPtr->paramList.size(); i++){
						activeFuncPtr->paramList[i]->name = "";
					}
					funcTable.push_back(activeFuncPtr);
				}
				else{
					cout << "Duplicate declaration for function : "<< activeFuncPtr->name << endl;
					(yyvsp[-1].node)->elemType = dt_err;
				}
			}
			parseTree->childs.push_back((yyvsp[-1].node));
		}
#line 1598 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 6:
#line 183 "parser.y" /* yacc.c:1667  */
    { 
			parseTree->childs.push_back((yyvsp[0].node));
		}
#line 1606 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 7:
#line 190 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_decl", "int");
			(yyval.node)->childs.push_back((yyvsp[-2].node));

		}
#line 1616 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 196 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_decl", "flt");
			(yyval.node)->childs.push_back((yyvsp[-2].node));

		}
#line 1626 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 9:
#line 204 "parser.y" /* yacc.c:1667  */
    {declType = dt_flt;}
#line 1632 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 207 "parser.y" /* yacc.c:1667  */
    {declType = dt_int;}
#line 1638 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 210 "parser.y" /* yacc.c:1667  */
    {declType = dt_none;}
#line 1644 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 215 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_list", "var_more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType != dt_err){
				SymbolNode *temp = varExists((yyvsp[-2].node)->childs[0]->valueType);
				if (temp==NULL){
					addVariable((yyvsp[-2].node)->childs[0]->valueType);
				}
				else{
					if (temp->level == 1 && level==2){
						(yyval.node)->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<(yyvsp[-2].node)->childs[0]->valueType<<endl;
					}
					else if (temp->level != level || temp->type != dt_void){
						addVariable((yyvsp[-2].node)->childs[0]->valueType);
					}
					else{
						(yyval.node)->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<(yyvsp[-2].node)->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1676 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 243 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_list", "var_asgn_more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType != dt_err){
				SymbolNode *temp = varExists((yyvsp[-2].node)->childs[0]->childs[0]->valueType);
				if (temp==NULL){
					if (temp->level == 1 && level==2){
						(yyval.node)->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<(yyvsp[-2].node)->childs[0]->childs[0]->valueType<<endl;
					}
					else if ((yyvsp[-2].node)->childs[1]->elemType != dt_err){
						addVariable((yyvsp[-2].node)->childs[0]->childs[0]->valueType);
					}
					else{
						(yyval.node)->elemType = dt_err;
					}
				}
				else{
					if (temp->level != level && temp->type != dt_void){
						addVariable((yyvsp[-2].node)->childs[0]->childs[0]->valueType);
					}
					else{
						(yyval.node)->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<(yyvsp[-2].node)->childs[0]->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1713 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 276 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_list", "var");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType != dt_err){
				SymbolNode *temp = varExists((yyvsp[0].node)->childs[0]->valueType);
				if (temp==NULL){
					addVariable((yyvsp[0].node)->childs[0]->valueType);
				}
				else{
					if (temp->level == 1 && level==2){
						(yyval.node)->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<(yyvsp[0].node)->childs[0]->valueType<<endl;
					}
					else if (temp->level != level || temp->type != dt_void){
						addVariable((yyvsp[0].node)->childs[0]->valueType);
					}
					else{
						(yyval.node)->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<(yyvsp[0].node)->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1744 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 303 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_list", "var_asgn");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->childs[0]->elemType != dt_err){
				SymbolNode *temp = varExists((yyvsp[0].node)->childs[0]->childs[0]->valueType);
				if (temp==NULL){
					if ((yyvsp[0].node)->childs[1]->elemType != dt_err){
						addVariable((yyvsp[0].node)->childs[0]->childs[0]->valueType);
					}
					else{
						(yyval.node)->elemType = dt_err;
					}
				}
				else{
					if (temp->level == 1 && level==2){
						(yyval.node)->elemType = dt_err;
						cout << "Declaration of variable with same name as parameter: "<<(yyvsp[0].node)->childs[0]->childs[0]->valueType<<endl;
					}
					else if (temp->level != level && temp->type != dt_void){
						addVariable((yyvsp[0].node)->childs[0]->childs[0]->valueType);
					}
					else{
						(yyval.node)->elemType = dt_err;
						cout << "Duplicate declaration of variable: "<<(yyvsp[0].node)->childs[0]->childs[0]->valueType<<endl;
					}
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1780 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 16:
#line 338 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var", "id");
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 1789 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 343 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var", "id_dim_list");
			(yyval.node)->childs.push_back((yyvsp[-5].node));
			(yyval.node)->childs.push_back((yyvsp[-3].node));
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->elemType = dt_err;
			cout << "Arrays not implemented" << endl;
		}
#line 1802 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 352 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var", "id_brac");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->elemType = dt_err;
			cout << "Arrays not implemented" << endl;
		}
#line 1814 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 19:
#line 363 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("var_asgn", "default");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 1824 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 372 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("dim_list", "more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 1834 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 21:
#line 379 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("dim_list", "one");
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 1843 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 22:
#line 387 "parser.y" /* yacc.c:1667  */
    {			
			(yyval.node) = new Node("brac_list", "more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 1853 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 393 "parser.y" /* yacc.c:1667  */
    {						
			(yyval.node) = new Node("brac_list", "one");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
		}
#line 1862 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 24:
#line 401 "parser.y" /* yacc.c:1667  */
    {
			level = 1;
			(yyval.node) = new Node("func_decl", "int_plist");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->paramList = (yyvsp[-1].node)->paramList;
			vector <SymbolNode*> paramList;
			if (convertParamList((yyval.node)->paramList, paramList, (yyvsp[-4].node)->valueType)==0){
				FuncNode *funcEntry = new FuncNode((yyvsp[-4].node)->valueType, dt_int);
				funcEntry->paramList = paramList;
				funcEntry->localVar = paramList;
				activeFuncPtr = funcEntry;
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1883 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 25:
#line 418 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_decl", "float_plist");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->paramList = (yyvsp[-1].node)->paramList;
			vector <SymbolNode*> paramList;
			if (convertParamList((yyval.node)->paramList, paramList, (yyvsp[-4].node)->valueType)==0){
				FuncNode *funcEntry = new FuncNode((yyvsp[-4].node)->valueType, dt_flt);
				funcEntry->paramList = paramList;
				funcEntry->localVar = paramList;
				activeFuncPtr = funcEntry;
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1903 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 26:
#line 434 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_decl", "void_plist");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->paramList = (yyvsp[-1].node)->paramList;
			vector <SymbolNode*> paramList;
			if (convertParamList((yyval.node)->paramList, paramList, (yyvsp[-3].node)->valueType)==0){
				FuncNode *funcEntry = new FuncNode((yyvsp[-3].node)->valueType, dt_void);
				funcEntry->paramList = paramList;
				funcEntry->localVar = paramList;
				activeFuncPtr = funcEntry;
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 1923 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 450 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_decl", "int_none");
			FuncNode *funcEntry = new FuncNode((yyvsp[-3].node)->valueType, dt_int);
			activeFuncPtr = funcEntry;
		}
#line 1933 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 28:
#line 456 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_decl", "float_none");
			FuncNode *funcEntry = new FuncNode((yyvsp[-3].node)->valueType, dt_flt);
			activeFuncPtr = funcEntry;
		}
#line 1943 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 29:
#line 462 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_decl", "void_none");
			FuncNode *funcEntry = new FuncNode((yyvsp[-2].node)->valueType, dt_void);
			activeFuncPtr = funcEntry;
		}
#line 1953 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 30:
#line 471 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("decl_plist", "decl_type_more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->paramList = (yyvsp[0].node)->paramList;
			(yyval.node)->paramList.push_back((yyvsp[-2].node));
		}
#line 1965 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 479 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("decl_plist", "defn_type_more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->paramList = (yyvsp[0].node)->paramList;
			(yyval.node)->paramList.push_back((yyvsp[-2].node));
		}
#line 1976 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 32:
#line 486 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("decl_plist", "decl_type_one");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->paramList.push_back((yyvsp[0].node));
		}
#line 1986 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 33:
#line 492 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("decl_plist", "defn_type_one");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->paramList.push_back((yyvsp[0].node));
		}
#line 1996 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 34:
#line 501 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_call", "");
			(yyval.node)->childs.push_back((yyvsp[-3].node));
			(yyval.node)->childs.push_back((yyvsp[-1].node));
		}
#line 2006 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 35:
#line 510 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("pm_list", "more");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));

		}
#line 2017 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 36:
#line 517 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("pm_list", "one");
			(yyval.node)->childs.push_back((yyvsp[0].node));

		}
#line 2027 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 37:
#line 526 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("func_defn", "");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			int defnParams = -1;
			for (int i=0; i<activeFuncPtr->paramList.size(); i++){
				if (activeFuncPtr->paramList[i]->name==""){
					defnParams = i;
					break;
				}
			}
			if (defnParams == -1){
				if ((yyvsp[0].node)->elemType == dt_err){
					(yyval.node)->elemType = dt_err;
				}
				else{
					
				}
			}
			else{
				cout << "Error in function definition, parameter has no name" << endl;
				(yyval.node)->elemType = dt_err;
			}

		}
#line 2057 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 38:
#line 555 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("decl_pm", "int");
		}
#line 2065 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 39:
#line 559 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("decl_pm", "flt");
		}
#line 2073 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 40:
#line 566 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("defn_pm", "int");
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 2082 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 41:
#line 571 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("defn_pm", "flt");
			(yyval.node)->childs.push_back((yyvsp[0].node));
		}
#line 2091 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 579 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("statements", "more");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-1].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2104 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 588 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("statements", "one");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2116 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 599 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("statement", "non_condl");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2128 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 607 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("statement", "condl");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2140 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 618 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "block");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2152 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 47:
#line 626 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "loop");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2164 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 634 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "var_decl");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else{

			}
		}
#line 2179 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 645 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "expr_stmt");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			if ((yyvsp[-1].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2191 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 653 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "brk_stmt");

		}
#line 2200 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 658 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "cont_stmt");

		}
#line 2209 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 663 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "ret_stmt");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			if ((yyvsp[-1].node)->elemType != activeFuncPtr->retType){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2221 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 671 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("non_condl", "semi");

		}
#line 2230 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 679 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("block", "");
			(yyval.node)->childs.push_back((yyvsp[-3].node));
			if ((yyvsp[-3].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2242 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 690 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("loop", "for");
			(yyval.node)->childs.push_back((yyvsp[-5].node));
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			if ((yyvsp[-5].node)->elemType == dt_err || (yyvsp[-2].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2255 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 56:
#line 699 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("loop", "condl");
			(yyval.node)->childs.push_back((yyvsp[-5].node));
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			if ((yyvsp[-5].node)->elemType == dt_err || (yyvsp[-2].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2268 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 711 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("for", "condl");
			(yyval.node)->childs.push_back((yyvsp[-3].node));
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-3].node)->elemType == dt_err || (yyvsp[-2].node)->elemType != dt_bool || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2282 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 721 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("for", "none");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2295 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 733 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("init_stmt", "expr");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			if ((yyvsp[-1].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2307 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 741 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("init_stmt", "semi");
		}
#line 2315 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 748 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condl_block", "if_else");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->elemType = (yyvsp[0].node)->elemType;
		}
#line 2325 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 754 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condl_block", "switch");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->elemType = (yyvsp[0].node)->elemType;
		}
#line 2335 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 63:
#line 763 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("if_else", "if");
			(yyval.node)->childs.push_back((yyvsp[-5].node));
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			if ((yyvsp[-5].node)->elemType != dt_bool || (yyvsp[-2].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2348 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 64:
#line 772 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("if_else", "if_else");
			(yyval.node)->childs.push_back((yyvsp[-10].node));
			(yyval.node)->childs.push_back((yyvsp[-7].node));
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			if ((yyvsp[-10].node)->elemType != dt_bool || (yyvsp[-7].node)->elemType == dt_err || (yyvsp[-2].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2362 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 65:
#line 785 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("switch", "const");
			(yyval.node)->childs.push_back((yyvsp[-4].node));
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			if ((yyvsp[-4].node)->elemType == dt_int && (yyvsp[-1].node)->elemType != dt_err){
				
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2378 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 66:
#line 797 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("switch", "var");
			(yyval.node)->childs.push_back((yyvsp[-4].node));
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			if ((yyvsp[-4].node)->valueType == "id"){
				SymbolNode *temp=varExists((yyvsp[-4].node)->childs[0]->valueType);
				if ((yyvsp[-4].node)->elemType == dt_int && (yyvsp[-1].node)->elemType != dt_err && temp!=NULL){
					
				}
				else{
					(yyval.node)->elemType = dt_err;
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2400 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 818 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("switch_body", "case_more");
			(yyval.node)->childs.push_back((yyvsp[-6].node));
			(yyval.node)->childs.push_back((yyvsp[-3].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-6].node)->elemType == dt_int && (yyvsp[-3].node)->elemType != dt_err && (yyvsp[0].node)->elemType != dt_err){
				
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
			
		}
#line 2418 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 832 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("switch_body", "deafult_more");
			(yyval.node)->childs.push_back((yyvsp[-3].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-3].node)->elemType != dt_err && (yyvsp[0].node)->elemType != dt_err){
				
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2434 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 69:
#line 844 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("switch_body", "case_one");
			(yyval.node)->childs.push_back((yyvsp[-5].node));
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			if ((yyvsp[-5].node)->elemType == dt_int && (yyvsp[-2].node)->elemType != dt_err){
				
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
			
		}
#line 2451 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 70:
#line 857 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("switch_body", "deafult_one");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			if ((yyvsp[-2].node)->elemType != dt_err){
				
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2466 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 71:
#line 871 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "par_cond");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			if ((yyvsp[-1].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2481 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 72:
#line 882 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "not_cond");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2496 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 73:
#line 893 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "or");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2512 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 74:
#line 905 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "and");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2528 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 75:
#line 917 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "lt");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for < operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2548 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 76:
#line 933 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "gt");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for > operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2568 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 949 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "lte");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for <= operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2588 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 965 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "gte");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for >= operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2608 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 79:
#line 981 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "eq");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for == operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2628 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 997 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("condition", "neq");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for != operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_bool;
			}
		}
#line 2648 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 1016 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "real");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if (isNumber((yyvsp[0].node)->valueType)){
				(yyval.node)->elemType = dt_int;
				(yyval.node)->nodeValInt = stoi((yyvsp[0].node)->valueType);
			}
			else{
				(yyval.node)->elemType = dt_flt;
				(yyval.node)->nodeVal = stof((yyvsp[0].node)->valueType);
			}
		}
#line 2665 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 82:
#line 1029 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "par_exp");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->elemType = (yyvsp[-1].node)->elemType;
		}
#line 2675 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 83:
#line 1036 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "plus");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 2694 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 84:
#line 1051 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "minus");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 2713 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 85:
#line 1066 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "times");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 2732 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 86:
#line 1081 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "divide");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 2751 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 87:
#line 1096 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "modulo");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for %% operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 2771 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 88:
#line 1112 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("const_expr", "neg");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->elemType = (yyvsp[0].node)->elemType;
		}
#line 2781 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 89:
#line 1121 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "real");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if (isNumber((yyvsp[0].node)->valueType)){
				(yyval.node)->elemType = dt_int;
				(yyval.node)->nodeValInt = stoi((yyvsp[0].node)->valueType);
			}
			else{
				(yyval.node)->elemType = dt_flt;
				(yyval.node)->nodeVal = stof((yyvsp[0].node)->valueType);
			}
		}
#line 2798 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 90:
#line 1134 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "var");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->elemType != dt_err){
				SymbolNode *temp = varExists((yyvsp[0].node)->childs[0]->valueType);
				if (temp!=NULL){
					(yyval.node)->elemType = temp->type;
				}
				else{
					(yyval.node)->elemType = dt_err;
					cout << "Variable "<< (yyvsp[0].node)->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2820 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 91:
#line 1152 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "val_asgn");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[0].node)->childs[0]->elemType != dt_err){
				SymbolNode *temp = varExists((yyvsp[0].node)->childs[0]->childs[0]->valueType);
				if (temp != NULL){
					DataType exprType = (yyvsp[0].node)->childs[1]->childs[0]->elemType;
					if (exprType == dt_err){
						(yyval.node)->elemType = dt_err;
					}
					else{
						(yyval.node)->elemType = temp->type;
					}
				}
				else{
					(yyval.node)->elemType = dt_err;
					cout << "Variable "<< (yyvsp[0].node)->childs[0]->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
		}
#line 2845 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 92:
#line 1173 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "func_call");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			(yyval.node)->elemType = (yyvsp[0].node)->elemType;
		}
#line 2855 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 93:
#line 1179 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "var_incr");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			SymbolNode *temp;
			if ((yyvsp[-1].node)->valueType == "id"){
				temp=varExists((yyvsp[-1].node)->childs[0]->valueType);
				if (temp!=NULL){
					(yyval.node)->elemType = temp->type;
				}
				else{
					(yyval.node)->elemType = dt_err;
					cout << "Variable "<< (yyvsp[-1].node)->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2878 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 94:
#line 1198 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "var_decr");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			SymbolNode *temp;
			if ((yyvsp[-1].node)->valueType == "id"){
				temp=varExists((yyvsp[-1].node)->childs[0]->valueType);
				if (temp!=NULL){
					(yyval.node)->elemType = temp->type;
				}
				else{
					(yyval.node)->elemType = dt_err;
					cout << "Variable "<< (yyvsp[-1].node)->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2901 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 95:
#line 1217 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "incr_var");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			SymbolNode *temp;
			if ((yyvsp[0].node)->valueType == "id"){
				temp=varExists((yyvsp[0].node)->childs[0]->valueType);
				if (temp!=NULL){
					(yyval.node)->elemType = temp->type;
				}
				else{
					(yyval.node)->elemType = dt_err;
					cout << "Variable "<< (yyvsp[0].node)->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2924 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 96:
#line 1236 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "decr_var");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			SymbolNode *temp;
			if ((yyvsp[0].node)->valueType == "id"){
				temp=varExists((yyvsp[0].node)->childs[0]->valueType);
				if (temp!=NULL){
					(yyval.node)->elemType = temp->type;
				}
				else{
					(yyval.node)->elemType = dt_err;
					cout << "Variable "<< (yyvsp[0].node)->childs[0]->valueType << " used without declaration"<<endl;
				}
			}
			else{
				(yyval.node)->elemType = dt_err;
			}
		}
#line 2947 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 97:
#line 1255 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "par_exp");
			(yyval.node)->childs.push_back((yyvsp[-1].node));
			(yyval.node)->elemType = (yyvsp[-1].node)->elemType;
		}
#line 2957 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 98:
#line 1261 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "plus");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for + operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 2980 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 99:
#line 1280 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "minus");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for - operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 3003 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 100:
#line 1299 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "times");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for * operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 3026 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 101:
#line 1318 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "divide");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_flt;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for / operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 3049 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 102:
#line 1337 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "modulo");
			(yyval.node)->childs.push_back((yyvsp[-2].node));
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if ((yyvsp[-2].node)->elemType == dt_err || (yyvsp[0].node)->elemType == dt_err){
				(yyval.node)->elemType = dt_err;
			}
			else if((yyvsp[-2].node)->elemType == dt_flt || (yyvsp[0].node)->elemType == dt_flt){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for %% operation"<<endl;
			}
			else if((yyvsp[-2].node)->elemType == dt_void || (yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for %% operation"<<endl;
			}
			else{
				(yyval.node)->elemType = dt_int;
			}
		}
#line 3073 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 103:
#line 1357 "parser.y" /* yacc.c:1667  */
    {
			(yyval.node) = new Node("expr", "neg");
			(yyval.node)->childs.push_back((yyvsp[0].node));
			if((yyvsp[0].node)->elemType == dt_void){
				(yyval.node)->elemType = dt_err;
				cout << "Incompatible types for - operation"<<endl;
			}
			else{
				(yyval.node)->elemType = (yyvsp[0].node)->elemType;
			}
		}
#line 3089 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 104:
#line 1371 "parser.y" /* yacc.c:1667  */
    {level++;}
#line 3095 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 105:
#line 1375 "parser.y" /* yacc.c:1667  */
    {level--;}
#line 3101 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 106:
#line 1379 "parser.y" /* yacc.c:1667  */
    {clearLevel();}
#line 3107 "parser.tab.c" /* yacc.c:1667  */
    break;


#line 3111 "parser.tab.c" /* yacc.c:1667  */
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
#line 1381 "parser.y" /* yacc.c:1918  */


void yyerror(string s){
	cout<<"Syntax Error in:\nLine Number " << yylineno <<" : "<<s<<endl;
	syntax_error = true;
}

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	cout << "***********";
	printTree(parseTree);
	return 0;
}
