#include <stdio.h>
//#include "myscanner.h"

extern "C" int yylex();
extern int yylineno;
extern char* yytext;

int main(void){

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken){

		printf("TOKEN %d\n", ntoken);
		ntoken = yylex();
	}
return 0;
}

