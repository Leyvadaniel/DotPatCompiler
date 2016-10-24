#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "proyecto.y"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include "DirProcs.h"
#include "LinkedList.h"
#include "LinkedListV.h"
#include "nodo.h"
#include "nodoV.h"
#include "LinkedListC.h"
#include "nodoC.h"
#include "VarT.h"
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
void yyerror(const char *s);
extern char* yytext;
extern int numeroLinea; 

/*Funciones*/
int tipo2num(string tipo); int op2num(string tipo); string num2tipo(int tipo);
int cuboSemRes(string op1t,string op2t,string op);
void cuadruplo();
void checaMD();void checaSR();void checaI();void checaCO();
void addToDir(string id);void addToDirP(string id);
void busq(string id);
int ProgProcess();
int addProc(string nm);
int Modulo_AProcess();
int eliminaProc();
int ModuloProcess();
void imprimirCuad();
void jumpC(int x, int y); void jumpCD(); void jumpElse(); void jumpElseD();
char* itoa(int val, int base);
void loopFunc(string x);
void checaSend(string id); void checaRec(string id); void checaPrint(); void checaCall();void checaCall2();
int revision(string OP);
void checaVar();void checaPar();

/*Variables Globales*/
int contadorFunc = 0, contadorVar = 0, numProc = -1,cuadCont =0, paint = 0, tempnum =1;
string tipoA, cuad, ListaCuad,enviarT,ModN;
stack<int> procAct, PilaBrinco, PilaRet, PilaElse;
queue<string> listaVar,listaPar;
LinkedListV *DirdeProc = new LinkedListV();
LinkedListC *DirdeCuad = new LinkedListC();
bool error;
ofstream CuadFile;

/*int 0, float 1, bool 2 char 3 error 4*/
int cuboSem[5][4][4] =
					  {{{0,1,4,3},{1,1,4,4},{4,4,2,4},{3,4,4,3}},		
					   {{0,1,4,3},{1,1,4,4},{4,4,2,4},{3,4,4,3}},		
					   {{0,1,4,4},{1,1,4,4},{4,4,4,4},{4,4,4,4}},		
					   {{0,1,4,4},{1,1,4,4},{4,4,4,4},{4,4,4,4}},
					   {{2,2,2,2},{2,2,2,4},{2,2,2,4},{2,4,4,2}}};	
/*Pilas para Cuádruplos*/
stack<string> PilaO;
stack<string> Poper;
stack<string> PilaTipo;
#line 69 "proyecto.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	int y_int;
	double y_double;
	bool y_bool;
	char *y_operadores;
	char *y_l_comm;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 100 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define CTE_I 257
#define L_GVLIST 258
#define L_PROGRAM 259
#define L_MAIN 260
#define L_VLIST 261
#define L_VAR 262
#define L_INT 263
#define L_BOOL 264
#define L_FLOAT 265
#define L_CHAR 266
#define L_RECEIVE 267
#define L_PRINT 268
#define L_SENDD 269
#define L_SENDB 270
#define L_SENDBOOL 271
#define L_IF 272
#define L_ELSE 273
#define L_LOOP 274
#define L_MAS 275
#define L_MENOS 276
#define L_MULT 277
#define L_DIV 278
#define L_BREAK 279
#define L_DONE 280
#define L_THEN 281
#define L_DO 282
#define L_END 283
#define OP_MEN 284
#define OP_MAY 285
#define OP_MENIGU 286
#define OP_MAYIGU 287
#define OP_IGUIGU 288
#define OP_NOTIGU 289
#define CTE_CHAR 290
#define L_ID 291
#define L_BRA1 292
#define L_BRA2 293
#define L_SEMICOLON 294
#define L_COMMA 295
#define L_PAR1 296
#define L_PAR2 297
#define L_VOID 298
#define L_CALL 299
#define L_IGUAL 300
#define CTE_F 301
#define CTE_TRUE 302
#define CTE_FALSE 303
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    2,    0,    1,    1,    3,    3,    7,    9,    6,    8,
   14,    8,   13,   15,   13,   16,    4,   10,   10,   11,
   11,   18,   18,    5,   21,   22,   19,   23,   24,   25,
   23,   20,   26,   20,   12,   12,   12,   12,   28,   30,
   31,   27,   34,   32,   33,   35,   33,   37,   36,   40,
   42,   38,   41,   41,   41,   41,   44,   46,   43,   45,
   47,   45,   39,   39,   39,   17,   17,   17,   17,   17,
   17,   17,   50,   52,   53,   49,   51,   54,   51,   56,
   57,   48,   55,   55,   29,   59,   60,   59,   61,   59,
   62,   59,   63,   59,   64,   59,   65,   59,   68,   58,
   67,   67,   69,   69,   72,   66,   71,   71,   73,   73,
   70,   70,   70,   74,   70,   70,   70,   70,
};
static const short yylen[] = {                            2,
    0,    4,    0,    2,    0,    2,    0,    0,   11,    0,
    0,    4,    0,    0,    5,    0,    6,    0,    2,    0,
    2,    0,    2,    3,    0,    0,    7,    0,    0,    0,
    7,    0,    0,    4,    1,    1,    1,    1,    0,    0,
    0,    7,    0,    7,    0,    0,    4,    0,    6,    0,
    0,    7,    1,    1,    1,    1,    0,    0,   11,    0,
    0,    5,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    0,    0,    0,   10,    0,    0,    4,    0,
    0,   10,    1,    1,    2,    0,    0,    3,    0,    3,
    0,    3,    0,    3,    0,    3,    0,    3,    0,    3,
    0,    2,    1,    1,    0,    3,    0,    2,    1,    1,
    1,    1,    1,    0,    4,    1,    1,    1,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    4,    0,    0,    0,   35,
   38,   36,   37,    0,    0,    7,   16,    2,    6,   25,
   24,    0,    0,    0,    0,    0,    0,   26,    8,    0,
    0,    0,   33,    0,    0,   11,   19,    0,    0,   63,
   64,   65,    0,    0,   39,    0,    0,    0,   71,   69,
   70,   68,   50,   67,   66,   72,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   73,   17,    0,   21,    0,
   34,    0,   27,    0,    0,   12,   48,  111,  116,  112,
  114,  113,  117,  118,   43,    0,   99,  105,    0,   84,
   83,    0,   40,    0,   23,    0,   29,    0,    0,    0,
    0,    0,   87,   89,   91,   93,   95,   97,   85,    0,
    0,   57,   80,    0,    0,   56,   53,   55,   54,   51,
    0,    0,   14,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  103,  104,  100,    0,  109,  110,  106,
    0,    0,    0,   41,   74,    0,   30,    9,    0,   49,
  115,   46,    0,   88,   90,   92,   94,   96,   98,  102,
  108,    0,    0,    0,    0,    0,    0,   15,    0,   44,
    0,    0,   42,    0,    0,   52,    0,   47,    0,   81,
   78,   75,   31,   58,    0,    0,    0,    0,   82,   79,
   76,   59,    0,    0,    0,    0,   62,
};
static const short yydgoto[] = {                          1,
    4,    2,    8,   18,    6,    9,   22,   29,   35,   32,
   47,   72,   76,   60,  149,   23,   68,   69,   15,   28,
   24,   34,   73,  121,  167,   57,   49,   65,   85,  114,
  164,   50,  127,  102,  169,   51,  100,   52,   53,   70,
  120,  146,   54,  142,  192,  188,  193,   55,   56,   94,
  175,  165,  187,  186,   92,  143,  185,   86,  109,  128,
  129,  130,  131,  132,  133,   87,  136,  110,  137,   88,
  140,  111,  141,  101,
};
static const short yysindex[] = {                         0,
    0, -248, -286, -290, -181,    0, -269, -234, -290,    0,
    0,    0,    0, -255, -259,    0,    0,    0,    0,    0,
    0, -254, -249, -258, -181, -215, -243,    0,    0, -236,
 -286, -239,    0, -235, -233,    0,    0, -229, -210,    0,
    0,    0, -208, -207,    0, -228, -231, -239,    0,    0,
    0,    0,    0,    0,    0,    0, -258, -181, -201, -194,
 -189, -252, -252, -250, -197,    0,    0, -239,    0, -182,
    0, -176,    0, -215, -181,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -177,    0,    0, -180,    0,
    0, -178,    0, -174,    0, -246,    0, -239, -171, -170,
 -252, -172,    0,    0,    0,    0,    0,    0,    0, -263,
 -257,    0,    0, -252, -252,    0,    0,    0,    0,    0,
 -258, -164,    0, -173, -165, -252, -157, -252, -252, -252,
 -252, -252, -252,    0,    0,    0, -252,    0,    0,    0,
 -252, -148, -141,    0,    0, -155,    0,    0, -194,    0,
    0,    0, -151,    0,    0,    0,    0,    0,    0,    0,
    0, -239, -239, -140, -149, -139, -138,    0, -172,    0,
 -239, -239,    0, -252, -137,    0, -181,    0, -122,    0,
    0,    0,    0,    0, -124, -149, -133,    0,    0,    0,
    0,    0, -110, -239, -239, -116,    0,
};
static const short yyrindex[] = {                         0,
    0, -251,    0,  -95,    0,    0,    0,    0,  -95,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -128, -130, -175,    0,    0,    0,    0,
    0, -125,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -123,    0,    0,
    0,    0,    0,    0,    0,    0, -128, -121,    0, -126,
    0,    0,    0,    0,    0,    0,    0, -222,    0,    0,
    0,    0,    0, -175,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -225,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -125,    0,    0,
    0, -120,    0,    0,    0,    0,    0,    0,    0, -270,
 -150,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -128,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -126,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -119,    0,    0,    0, -120,    0,
 -111, -109,    0,    0,    0,    0, -121,    0,    0,    0,
    0,    0,    0,    0,    0, -119,    0, -193,    0,    0,
    0,    0,    0,    0, -111,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  164,    0,  144,    0,    0,    0,    0,  102,
   81,   -2,   31,    0,    0,    0,  -32,  -67,    0,  -53,
    0,    0,    4,    0,    0,    0,    0,    0,  -61,    0,
    0,    0,   13,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -3,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,   43,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 184
static const short yytable[] = {                         48,
   95,   89,   14,   71,   78,    5,   90,    7,    3,    3,
  116,  134,  135,  101,  101,  101,  101,  101,  101,  138,
  139,   16,   30,  101,  101,   17,  101,   38,   39,   40,
   41,   42,   43,   21,   44,   20,   27,   79,   80,  125,
   91,   25,   26,   81,  117,   31,    3,   33,   82,   83,
   84,   45,  144,  145,   36,  118,  119,   22,   58,   46,
   22,   67,   66,   59,  152,   48,   61,  147,   86,   86,
   22,   86,   99,   60,   60,   60,   60,   60,   60,   61,
   60,   10,   11,   12,   13,   62,   60,   63,   64,   60,
   74,   18,   18,   18,   18,   18,   18,   60,   18,   60,
   75,   77,   93,  179,  180,   60,  103,  104,  105,  106,
  107,  108,  181,   96,   97,   18,  112,   18,  113,  123,
  150,  115,  126,   18,  107,  107,  124,  196,  148,  171,
  172,  151,  162,  107,  107,  107,  107,  107,  107,  153,
  163,  166,  170,  107,  107,  174,  107,  154,  155,  156,
  157,  158,  159,  173,  176,  177,  160,  184,  189,  182,
  191,  195,  194,  197,    5,   32,   10,   20,   22,   22,
   13,   28,   19,   22,   37,   98,   45,   77,  122,  168,
  183,  178,  190,  161,
};
static const short yycheck[] = {                         32,
   68,   63,    5,   57,  257,  292,  257,  298,  260,  258,
  257,  275,  276,  284,  285,  286,  287,  288,  289,  277,
  278,  291,   25,  294,  295,  260,  297,  267,  268,  269,
  270,  271,  272,  293,  274,  291,  295,  290,  291,  101,
  291,  296,  292,  296,  291,  261,  298,  291,  301,  302,
  303,  291,  114,  115,  291,  302,  303,  280,  294,  299,
  283,  293,  291,  297,  126,   98,  296,  121,  294,  295,
  293,  297,   75,  267,  268,  269,  270,  271,  272,  273,
  274,  263,  264,  265,  266,  296,  280,  296,  296,  283,
  292,  267,  268,  269,  270,  271,  272,  291,  274,  293,
  295,  291,  300,  171,  172,  299,  284,  285,  286,  287,
  288,  289,  174,  296,  291,  291,  297,  293,  297,  291,
  294,  296,  295,  299,  275,  276,  297,  195,  293,  162,
  163,  297,  281,  284,  285,  286,  287,  288,  289,  297,
  282,  297,  294,  294,  295,  295,  297,  128,  129,  130,
  131,  132,  133,  294,  294,  294,  137,  280,  283,  297,
  294,  194,  273,  280,  260,  294,  297,  293,  280,  293,
  297,  293,    9,  283,   31,   74,  297,  297,   98,  149,
  177,  169,  186,  141,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CTE_I","L_GVLIST","L_PROGRAM",
"L_MAIN","L_VLIST","L_VAR","L_INT","L_BOOL","L_FLOAT","L_CHAR","L_RECEIVE",
"L_PRINT","L_SENDD","L_SENDB","L_SENDBOOL","L_IF","L_ELSE","L_LOOP","L_MAS",
"L_MENOS","L_MULT","L_DIV","L_BREAK","L_DONE","L_THEN","L_DO","L_END","OP_MEN",
"OP_MAY","OP_MENIGU","OP_MAYIGU","OP_IGUIGU","OP_NOTIGU","CTE_CHAR","L_ID",
"L_BRA1","L_BRA2","L_SEMICOLON","L_COMMA","L_PAR1","L_PAR2","L_VOID","L_CALL",
"L_IGUAL","CTE_F","CTE_TRUE","CTE_FALSE","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : PROG",
"$$1 :",
"PROG : $$1 PROG_A PROG_M MAIN",
"PROG_A :",
"PROG_A : L_GVLIST VAR",
"PROG_M :",
"PROG_M : MODULO PROG_M",
"$$2 :",
"$$3 :",
"MODULO : L_VOID L_ID $$2 L_PAR1 MODULO_A $$3 L_PAR2 L_BRA1 MAIN_A MAIN_B L_BRA2",
"MODULO_A :",
"$$4 :",
"MODULO_A : TYPE L_ID $$4 MODULO_B",
"MODULO_B :",
"$$5 :",
"MODULO_B : L_COMMA TYPE L_ID $$5 MODULO_B",
"$$6 :",
"MAIN : L_MAIN $$6 L_BRA1 MAIN_A MAIN_B L_BRA2",
"MAIN_A :",
"MAIN_A : L_VLIST VAR",
"MAIN_B :",
"MAIN_B : BODY BODY_R",
"BODY_R :",
"BODY_R : BODY BODY_R",
"VAR : L_BRA1 VAR_A L_BRA2",
"$$7 :",
"$$8 :",
"VAR_A : TYPE L_ID $$7 ID_C $$8 L_SEMICOLON VAR_B",
"VAR_B :",
"$$9 :",
"$$10 :",
"VAR_B : TYPE L_ID $$9 ID_C $$10 L_SEMICOLON VAR_B",
"ID_C :",
"$$11 :",
"ID_C : L_COMMA L_ID $$11 ID_C",
"TYPE : L_INT",
"TYPE : L_FLOAT",
"TYPE : L_CHAR",
"TYPE : L_BOOL",
"$$12 :",
"$$13 :",
"$$14 :",
"ASIGNACION : L_ID $$12 L_IGUAL $$13 EXP $$14 L_SEMICOLON",
"$$15 :",
"IMPRIMIR : L_PRINT L_PAR1 EXP $$15 IMPRIMIR_A L_PAR2 L_SEMICOLON",
"IMPRIMIR_A :",
"$$16 :",
"IMPRIMIR_A : L_COMMA EXP $$16 IMPRIMIR_A",
"$$17 :",
"RECIBIR : L_RECEIVE L_PAR1 L_ID $$17 L_PAR2 L_SEMICOLON",
"$$18 :",
"$$19 :",
"ENVIAR : SEND_TYPE $$18 L_PAR1 ENVIAR_A $$19 L_PAR2 L_SEMICOLON",
"ENVIAR_A : L_ID",
"ENVIAR_A : CTE_FALSE",
"ENVIAR_A : CTE_TRUE",
"ENVIAR_A : CTE_I",
"$$20 :",
"$$21 :",
"CONDICION : L_IF L_PAR1 EXP L_PAR2 $$20 L_THEN BODY BODY_R L_DONE $$21 CONDICION_A",
"CONDICION_A :",
"$$22 :",
"CONDICION_A : $$22 L_ELSE BODY BODY_R L_DONE",
"SEND_TYPE : L_SENDD",
"SEND_TYPE : L_SENDB",
"SEND_TYPE : L_SENDBOOL",
"BODY : CICLO",
"BODY : CONDICION",
"BODY : ENVIAR",
"BODY : IMPRIMIR",
"BODY : RECIBIR",
"BODY : ASIGNACION",
"BODY : LLAMADA_F",
"$$23 :",
"$$24 :",
"$$25 :",
"LLAMADA_F : L_CALL L_ID $$23 L_PAR1 EXP $$24 LLAMADA_A L_PAR2 $$25 L_SEMICOLON",
"LLAMADA_A :",
"$$26 :",
"LLAMADA_A : L_COMMA EXP $$26 LLAMADA_A",
"$$27 :",
"$$28 :",
"CICLO : L_LOOP L_PAR1 CICLO_A L_PAR2 $$27 L_DO BODY BODY_R $$28 L_END",
"CICLO_A : L_ID",
"CICLO_A : CTE_I",
"EXP : EXP_S EXP_A",
"EXP_A :",
"$$29 :",
"EXP_A : OP_MEN $$29 EXP_S",
"$$30 :",
"EXP_A : OP_MAY $$30 EXP_S",
"$$31 :",
"EXP_A : OP_MENIGU $$31 EXP_S",
"$$32 :",
"EXP_A : OP_MAYIGU $$32 EXP_S",
"$$33 :",
"EXP_A : OP_IGUIGU $$33 EXP_S",
"$$34 :",
"EXP_A : OP_NOTIGU $$34 EXP_S",
"$$35 :",
"EXP_S : EXP_T $$35 EXP_S_A",
"EXP_S_A :",
"EXP_S_A : EXP_S_B EXP_S",
"EXP_S_B : L_MAS",
"EXP_S_B : L_MENOS",
"$$36 :",
"EXP_T : EXP_F $$36 EXP_T_A",
"EXP_T_A :",
"EXP_T_A : EXP_T_B EXP_T",
"EXP_T_B : L_MULT",
"EXP_T_B : L_DIV",
"EXP_F : CTE_I",
"EXP_F : L_ID",
"EXP_F : CTE_F",
"$$37 :",
"EXP_F : L_PAR1 $$37 EXP L_PAR2",
"EXP_F : CTE_CHAR",
"EXP_F : CTE_TRUE",
"EXP_F : CTE_FALSE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 212 "proyecto.y"
 
int main()
{
	//comandos para compilar
	//yacc -d archivo.y
	//lex archivo.l
	//g++ lex.yy.c y.tab.c -o Ejecutable
	
	while(1) {

		printf("Ingrese Nombre de Archivo: ");
		char nombreArchivo[20];
		scanf("%s", nombreArchivo);
		numeroLinea = 1;
		const char* MODOLECTURA = "r";
		FILE* codigo;
		//imprime codigo
		codigo = fopen(nombreArchivo, MODOLECTURA);
		printf("%d", numeroLinea++);
		char caracter = fgetc(codigo);
		while(caracter != EOF){
			if(caracter == '\n'){
				numeroLinea++;
				printf("%d", numeroLinea);
			}
			printf("%c", caracter);
			caracter = fgetc(codigo);
		}
		fclose(codigo);

		codigo = fopen(nombreArchivo, MODOLECTURA);
		numeroLinea = 1;
		yyin = codigo; 
		CuadFile.open("Cuadruplos.txt");
		yyparse();
		break;
	}
}

void yyerror(const char* error){
	cout << "error in line number: " << numeroLinea <<  " text: " << yytext << "  " << error <<endl;
}

void addToDir(string id)
{
    if(!(DirdeProc->get(procAct.top()).search(id)))
    {   
	DirdeProc->get(procAct.top()).writeVarT(id,tipoA);
	//cout<<endl;cout<<"add to dir: "<<id<<endl;
	if(!(DirdeProc->get(procAct.top()).searchPara(id))){	
		listaVar.push(id);
		cout<<endl;cout<<"add to listaVar: "<<id<<endl;
	}
    }
    else
    { cout << "Variable "<<id<<" ya declarada" << endl; }
}

void addToDirP(string id)
{
   if(!(DirdeProc->get(procAct.top()).searchPara(id))){
       DirdeProc->get(procAct.top()).writePara(id,tipoA);
       listaPar.push(id);
	//out<<endl;cout<<"PARA "<<id<<endl; 
   }
   else
    { cout << "Parámetro  "<<id<<" ya declarada" << endl; }

}

void busq(string id)
{
	int t;	
	if(revision(id) == 3){
		cuad = "ERROR VAR"; 
		ListaCuad += cuad; cuadCont++; DirdeCuad -> addLast(cuad);
		cout << " "<<id<<" ya declarada" << endl;}
	if(revision(id) == 2) {t = 0;}	
	if(revision(id) == 1) {t = procAct.top();}
	PilaO.push(id);
	string ti = DirdeProc->get(t).searchTipo(id);
	PilaTipo.push(ti);
}

int ProgProcess(){
	DirdeProc -> addLast(DirProc("Global",numProc));
	procAct.push(numProc); numProc++;
	cuad = "goto #"; PilaBrinco.push(cuadCont);	
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);
	return 1;
}
int ModuloProcess(){
	procAct.pop(); 
	DirdeProc->del(DirdeProc->SearchProc(procAct.top()));
	return 1; 
}

int eliminaProc(){
	DirdeProc->del(DirdeProc->SearchProc(procAct.top()));
	procAct.pop();
	return 1; 
}

int addProc(string nm){
	if((DirdeProc->SearchName(nm)))
	{
		cout << "Modulo ya declarado"<<nm<<endl;
		cuad = "ERROR addProc ";	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);
	}	
	else
	{	
		DirdeProc -> addLast(DirProc(nm,numProc)); 
		numProc++; 
		procAct.push(numProc);
		cuad = "mod "+nm;	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);
	}
	return 1;
} 

void cuadruplo()
{
    	string OP = Poper.top(); Poper.pop();
    	string OP2 = PilaO.top(); PilaO.pop();
	string OP2T = PilaTipo.top();PilaTipo.pop();
    	string OP1 = PilaO.top();PilaO.pop();
    	string OP1T = PilaTipo.top(); PilaTipo.pop();
    
    	int cuboRes = cuboSemRes(OP1T,OP2T,OP); 
    	//cout << cuboRes<<"   "<<OP<<" "<<OP2<<" "<<OP2T<<" "<<OP1<<" "<<OP1T<<" "<<endl;
    	if(cuboRes > 4){
		cout << "Tipos de variables invalidas en + - * / o Comp" << endl;
		cuad = "ERROR OPERACION"; ListaCuad += cuad; cuadCont++;
    	DirdeCuad -> addLast(cuad);}
    	string pach = itoa(tempnum,10);
	string temp = "temp."+pach;
	tempnum++;
    	cuad = OP+" "+OP1+" "+OP2+" "+temp; ListaCuad += cuad; cuadCont++;
    	DirdeCuad -> addLast(cuad);
    	PilaO.push(temp);
    	PilaTipo.push(num2tipo(cuboRes));
    	cout << cuad<<"\n";
    
}

void checaMD()
{
	if(!Poper.empty())
	{
		if((Poper.top() == "*")|(Poper.top()=="/"))
		{cuadruplo();} 
	}
	//else{cout<<"Error en multiplicación o división "<<endl;}
}

void checaSR()
{
	if(!Poper.empty())
	{
		if((Poper.top() == "+")|(Poper.top()=="-"))
		{cuadruplo();} 
	}
	//else{cout<<"Error en suma o resta"<<endl;}
}

void checaI()
{
	if(!Poper.empty())
	{
		if((Poper.top() == "="))
		{
			 string OP = Poper.top(); Poper.pop();
          		 string OP1 = PilaO.top();PilaO.pop();
    			 string OP1T = PilaTipo.top(); PilaTipo.pop();
          		 string RES = PilaO.top();PilaO.pop();
			 string REST = PilaTipo.top(); PilaTipo.pop();
			 cout <<"   "<<OP<<"   "<<OP1<<" "<<OP1T<<" "<<RES<<" "<<REST<<endl;
    			 if(REST != OP1T){
    				cout << "Tipos de variables invalidas en asignación" << endl;
				cuad = "ERROR ="; ListaCuad += cuad; cuadCont++;
    				DirdeCuad -> addLast(cuad); 
    			 }

    			 cuad = OP+" "+OP1+" "+RES; ListaCuad += cuad; cuadCont++;
			 DirdeCuad -> addLast(cuad);
		}
		else{cout<<"Error en asignación"<<endl;} 
	}
}

void checaCO()
{
	if(!Poper.empty())
	{
		if((Poper.top()=="<")|(Poper.top()==">")|(Poper.top()=="<=")|(Poper.top()==">=")|(Poper.top()=="=="))
		{cuadruplo();} 
	}
}

void jumpC(int x, int y)
{
	if(x == 0){
		string OP1 = PilaO.top();PilaO.pop();
		if(y == 0){cuad = "gotof "+OP1+" "+"#"; ListaCuad += cuad;}
		if(y == 1){cuad = "gotoF "+OP1+" "+"#"; ListaCuad += cuad;}
		cuadCont++;
        	DirdeCuad -> addLast(cuad);
		PilaBrinco.push(cuadCont);}
	else{
		string PR = itoa(PilaRet.top()+1,10);
		cuad = "goto "+PR;
		PilaRet.pop();
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);}
}

void jumpCD()
{
	int bri = PilaBrinco.top(); PilaBrinco.pop();
	string da;
	da = itoa(cuadCont+1,10);
	DirdeCuad->replaceDir(bri-1, da);
}

void jumpElse()
{	
	cuad = "goto #";
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);
	PilaElse.push(cuadCont-1);
	cuad = "else mod";
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);	
}

void jumpElseD()
{
	int bri = PilaElse.top(); PilaElse.pop();
	string da;
	da = itoa(cuadCont+2,10);
	DirdeCuad->replaceDir(bri, da);
	cuad = "elsend mod";
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);
}

void loopFunc(string x)
{
	int t;	
	string pach = itoa(tempnum,10);
	string temp = "temp."+pach;
    	tempnum++;	
	if(revision(x) == 2) {t = 0;}	
	if(revision(x) == 1) {t = procAct.top();}
	PilaRet.push(cuadCont);
	string ti = DirdeProc->get(t).searchTipo(x);
	if(ti == "bool"){cuad = "== "+x+" true "+temp;}
	else{cuad = "> "+x+" 0 "+temp;}
	ListaCuad += cuad; cuadCont++;
	PilaO.push(temp);
    	PilaTipo.push("bool");
	DirdeCuad -> addLast(cuad);
}

int cuboSemRes(string op1t,string op2t,string op)
{
    int cubo1, cubo2, cubo3;
    cubo1 = tipo2num(op1t);
    cubo2 = tipo2num(op2t);
    cubo3 = op2num(op);
    return cuboSem[cubo3][cubo2][cubo1];
}

int tipo2num(string tipo)
{
	if(tipo == "int"){return 0;}
        if(tipo == "float"){return 1;}
        if(tipo == "bool"){return 2;}
        if(tipo == "char"){return 3;}
        return 4;
}

int op2num(string tipo)
{
        if(tipo == "+"){return 0;}
        if(tipo == "-"){return 1;}
        if(tipo == "*"){return 2;}
        if(tipo == "/"){return 3;}
        if((tipo == "<")|| (tipo ==">")||(tipo =="<=")||(tipo ==">=")||(tipo =="==")){return 4;}
        return 5;
 }

string num2tipo(int tipo)
{
     if(tipo == 0){return "int";}
     if(tipo == 1){return "float";}
     if(tipo == 2){return "bool";}
     if(tipo == 3){return "char";}
     return "error";
}

void checaSend(string id)
{
	string ti = DirdeProc->get(procAct.top()).searchTipo(id); cuad = "w";
     	if((enviarT == "send_d")|(ti == "int")){cuad = "send_d "+id;}
     	if((enviarT == "send_b")|(ti == "int")){cuad = "send_b "+id;}
     	if((enviarT == "send_bool")|(ti == "bool")){cuad = "send_bool "+id;}
	if(cuad == "w"){
		cout<<"Error de tipos"<<endl;
		cuad = "ERROR SEND"; ListaCuad += cuad; cuadCont++;
    		DirdeCuad -> addLast(cuad);}
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);
}

void checaRec(string id)
{
	string ti = DirdeProc->get(procAct.top()).searchTipo(id); cuad = "w";	
	if((ti == "int") | (ti == "float")){	
		cuad = "recieve "+id;	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);}
	else{	
		cuad = "ERROR RECEIVE"+id;	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);}
}

void checaPrint()
{
	string id = PilaO.top(); PilaO.pop();	
	cuad = "print "+id;	
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);
}

void checaCall()
{
	paint++;	
	string id = PilaO.top(); PilaO.pop();
	string pach = itoa(paint,10);
	string param = "param."+pach;
	cuad = "param "+id+" "+param;	
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);
}

void checaCall2()
{
	string nte; int countt;
	if(!(DirdeProc->SearchName(ModN)))
	{cout << "No se declaró el modulo "<<ModN<<endl;}
	else{
		countt = DirdeProc->GetByName(ModN).getParaCount();
		if(countt != paint)
		{cout << "Error en la cantidad de parametros: "<< paint << " de "<< countt<<endl;}
		else
		{
			cuad = "gosub "+ModN;	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);}
	}
	
}

int revision(string OP)
{
	if(DirdeProc->get(procAct.top()).search(OP))
    	{return 1;}
    	else
    	{
		if(DirdeProc->get(0).search(OP))
    		{return 2;}
    		else
    		{
			cout<< "Error: "<<OP<< " variable inexistente en este scope"<<endl;
			return 3;
		}
	}
}

void checaVar()
{
	while(!listaVar.empty())
	{
		cuad = "var "+tipoA+" "+listaVar.front();	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);
		listaVar.pop();
	}
}

void checaPar()
{
	while(!listaPar.empty())
	{
				
		cuad = "par "+tipoA+" "+listaPar.front();
		listaPar.pop();	
		ListaCuad += cuad; cuadCont++;
        	DirdeCuad -> addLast(cuad);
	}
}

void imprimirCuad()
{
	cuad = "end file";	
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);	
	cout<<endl<<"Cuadruplos"<<endl;
	DirdeCuad->print(CuadFile);
	CuadFile.close();
}

char* itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
	buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}
#line 944 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 83 "proyecto.y"
	{error = false; ProgProcess();}
break;
case 7:
#line 91 "proyecto.y"
	{addProc(yytext);}
break;
case 8:
#line 91 "proyecto.y"
	{cuad = "pend mod";	
		 							  ListaCuad += cuad; cuadCont++;
       									  DirdeCuad -> addLast(cuad);}
break;
case 9:
#line 94 "proyecto.y"
	{cuad = "return mod";
							     ListaCuad += cuad; cuadCont++;
       		 					     DirdeCuad -> addLast(cuad);}
break;
case 11:
#line 99 "proyecto.y"
	{addToDirP(yytext);checaPar();addToDir(yytext); contadorVar++;}
break;
case 14:
#line 102 "proyecto.y"
	{addToDirP(yytext);checaPar();addToDir(yytext);contadorVar++;}
break;
case 16:
#line 104 "proyecto.y"
	{jumpCD(); addProc("main");}
break;
case 17:
#line 105 "proyecto.y"
	{DirdeProc->print();eliminaProc(); imprimirCuad();}
break;
case 19:
#line 108 "proyecto.y"
	{contadorFunc++;}
break;
case 25:
#line 118 "proyecto.y"
	{addToDir(yytext); contadorVar++;}
break;
case 26:
#line 118 "proyecto.y"
	{checaVar();}
break;
case 29:
#line 121 "proyecto.y"
	{addToDir(yytext);}
break;
case 30:
#line 121 "proyecto.y"
	{checaVar();}
break;
case 33:
#line 124 "proyecto.y"
	{addToDir(yytext);}
break;
case 35:
#line 127 "proyecto.y"
	{tipoA = "int";}
break;
case 36:
#line 128 "proyecto.y"
	{tipoA = "float";}
break;
case 37:
#line 129 "proyecto.y"
	{tipoA = "char";}
break;
case 38:
#line 130 "proyecto.y"
	{tipoA = "bool";}
break;
case 39:
#line 132 "proyecto.y"
	{busq(yytext);}
break;
case 40:
#line 132 "proyecto.y"
	{Poper.push(yytext);}
break;
case 41:
#line 132 "proyecto.y"
	{checaI();}
break;
case 43:
#line 134 "proyecto.y"
	{checaPrint();}
break;
case 46:
#line 137 "proyecto.y"
	{checaPrint();}
break;
case 48:
#line 139 "proyecto.y"
	{checaRec(yytext);}
break;
case 50:
#line 141 "proyecto.y"
	{enviarT = yytext;}
break;
case 51:
#line 141 "proyecto.y"
	{checaSend(yytext);}
break;
case 57:
#line 148 "proyecto.y"
	{jumpC(0,0);}
break;
case 58:
#line 148 "proyecto.y"
	{cuad = "ifend mod";
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);}
break;
case 60:
#line 152 "proyecto.y"
	{jumpCD();}
break;
case 61:
#line 153 "proyecto.y"
	{jumpElse();jumpCD();}
break;
case 62:
#line 153 "proyecto.y"
	{jumpElseD();}
break;
case 73:
#line 167 "proyecto.y"
	{ModN=yytext;}
break;
case 74:
#line 167 "proyecto.y"
	{checaCall();}
break;
case 75:
#line 167 "proyecto.y"
	{checaCall2();}
break;
case 76:
#line 167 "proyecto.y"
	{paint =0;}
break;
case 78:
#line 170 "proyecto.y"
	{checaCall();}
break;
case 80:
#line 172 "proyecto.y"
	{jumpC(0,1);}
break;
case 81:
#line 172 "proyecto.y"
	{jumpC(1,1);}
break;
case 82:
#line 172 "proyecto.y"
	{jumpCD();}
break;
case 83:
#line 174 "proyecto.y"
	{busq(yytext); loopFunc(yytext);}
break;
case 84:
#line 175 "proyecto.y"
	{loopFunc(yytext);}
break;
case 87:
#line 181 "proyecto.y"
	{Poper.push(yytext);}
break;
case 88:
#line 181 "proyecto.y"
	{checaCO();}
break;
case 89:
#line 182 "proyecto.y"
	{Poper.push(yytext);}
break;
case 90:
#line 182 "proyecto.y"
	{checaCO();}
break;
case 91:
#line 183 "proyecto.y"
	{Poper.push(yytext);}
break;
case 92:
#line 183 "proyecto.y"
	{checaCO();}
break;
case 93:
#line 184 "proyecto.y"
	{Poper.push(yytext);}
break;
case 94:
#line 184 "proyecto.y"
	{checaCO();}
break;
case 95:
#line 185 "proyecto.y"
	{Poper.push(yytext);}
break;
case 96:
#line 185 "proyecto.y"
	{checaCO();}
break;
case 97:
#line 186 "proyecto.y"
	{Poper.push(yytext);}
break;
case 98:
#line 186 "proyecto.y"
	{checaCO();}
break;
case 99:
#line 188 "proyecto.y"
	{checaSR();}
break;
case 103:
#line 193 "proyecto.y"
	{Poper.push(yytext);}
break;
case 104:
#line 194 "proyecto.y"
	{Poper.push(yytext);}
break;
case 105:
#line 196 "proyecto.y"
	{checaMD();}
break;
case 109:
#line 201 "proyecto.y"
	{Poper.push(yytext);}
break;
case 110:
#line 202 "proyecto.y"
	{Poper.push(yytext);}
break;
case 111:
#line 204 "proyecto.y"
	{ PilaO.push(yytext);PilaTipo.push("int");}
break;
case 112:
#line 205 "proyecto.y"
	{busq(yytext);}
break;
case 113:
#line 206 "proyecto.y"
	{ PilaO.push(yytext);PilaTipo.push("float");}
break;
case 114:
#line 207 "proyecto.y"
	{Poper.push(yytext);}
break;
case 115:
#line 207 "proyecto.y"
	{Poper.pop();}
break;
case 116:
#line 208 "proyecto.y"
	{PilaO.push(yytext);PilaTipo.push("char");}
break;
case 117:
#line 209 "proyecto.y"
	{PilaO.push(yytext);PilaTipo.push("bool");}
break;
case 118:
#line 210 "proyecto.y"
	{PilaO.push(yytext);PilaTipo.push("bool");}
break;
#line 1420 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
