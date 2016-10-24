%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YY_DECL extern "C" int yylex()
int numeroLinea = 1;	
#include "y.tab.h"
%}

%%
"program" 	{printf("I found a keyword: %s\n", yytext); return L_PROGRAM;}
"main"		{printf("I found a keyword: %s\n", yytext);return L_MAIN;}
"VList"		{printf("I found a keyword: %s\n", yytext);return L_VLIST;}
"void"		{printf("I found a keyword: %s\n", yytext);return L_VOID;}
"GVList"	{printf("I found a keyword: %s\n", yytext);return L_GVLIST;}
"var"		{printf("I found a keyword: %s\n", yytext); return L_VAR; }
"int"		{printf("I found a keyword: %s\n", yytext);return L_INT;}
"bool"		{printf("I found a keyword: %s\n", yytext);return L_BOOL;}
"float"		{printf("I found a keyword: %s\n", yytext);return L_FLOAT;}
"char"		{printf("I found a keyword: %s\n", yytext);return L_CHAR;}
"receive"	{printf("I found a keyword: %s\n", yytext);return L_RECEIVE;}
"print"		{printf("I found a keyword: %s\n", yytext);return L_PRINT;}
"send_d"	{printf("I found a keyword: %s\n", yytext);return L_SENDD;}
"send_b"	{printf("I found a keyword: %s\n", yytext);return L_SENDB;}
"send_bool"	{printf("I found a keyword: %s\n", yytext);return L_SENDBOOL;}
"call"		{printf("I found a keyword: %s\n", yytext);return L_CALL;}
"if"		{printf("I found a keyword: %s\n", yytext);return L_IF;}
"else"		{printf("I found a keyword: %s\n", yytext);return L_ELSE;}
"loop"		{printf("I found a keyword: %s\n", yytext);return L_LOOP;}
"break"		{printf("I found a keyword: %s\n", yytext);return L_BREAK;}
"done"		{printf("I found a keyword: %s\n", yytext);return L_DONE;}
"then"		{printf("I found a keyword: %s\n", yytext);return L_THEN;}
"do"		{printf("I found a keyword: %s\n", yytext);return L_DO;}
"end"		{printf("I found a keyword: %s\n", yytext);return L_END;}
"{"			{printf("I found a left curly brace: %s\n", yytext);return L_BRA1;}
"}"			{printf("I found a right curly brace: %s\n", yytext);return L_BRA2;}
";"			{printf("I found a semicolon: %s\n", yytext);return L_SEMICOLON;}
","			{printf("I found a comma: %s\n", yytext);return L_COMMA;}
"("			{printf("I found a left parenthesis: %s\n", yytext);return L_PAR1;}
")"			{printf("I found a right parenthesis: %s\n", yytext);return L_PAR2;}
"*"					{printf("I found a multiplication: %s\n", yytext); return L_MULT;}
"/"					{printf("I found a division: %s\n", yytext); return L_DIV;}
"+"					{printf("I found an addition: %s\n", yytext);return L_MAS;}
"-"					{printf("I found a subtraction: %s\n", yytext);return L_MENOS;}

"<"				{printf("I found a relational operator: %s\n", yytext);return OP_MEN;}
">" 				{printf("I found a relational operator: %s\n", yytext);return OP_MAY;}
"<="				{printf("I found a relational operator: %s\n", yytext);return OP_MENIGU;}
">="				{printf("I found a relational operator: %s\n", yytext);return OP_MAYIGU;}
"=="				{printf("I found a relational operator: %s\n", yytext);return OP_IGUIGU;}
"!="				{printf("I found a relational operator: %s\n", yytext);return OP_NOTIGU;}
"=" 				{printf("I found equals: %s\n", yytext);return L_IGUAL;}
"'"[a-zA-Z0-9]"'"			{printf("I found a char: %s\n", yytext);return CTE_CHAR;}
"true"				{printf("I found a keyword: %s\n", yytext);return CTE_TRUE;}
"false"				{printf("I found a keyword: %s\n", yytext);return CTE_FALSE;}	
[0-9][0-9]*			{printf("I found an integer number: %s\n", yytext);return CTE_I;}
[0-9]*\.[0-9]*			{printf("I found a floating point number: %s\n", yytext);return CTE_F;}
[a-zA-Z][_a-zA-Z0-9]* 		{printf("I found an ID: %s\n", yytext);return L_ID;}
[ \t\r]						;
\n {numeroLinea++;}
.							printf("Undefined character\n");
%%

int yywrap(void)
{
	return 1;
}
