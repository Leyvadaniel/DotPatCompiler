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
extern YYSTYPE yylval;
