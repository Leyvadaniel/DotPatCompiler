%{
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

//Funciones
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

//Variables Globales
int contadorFunc = 0, contadorVar = 0, numProc = -1,cuadCont =0, paint = 0, tempnum =1;
string tipoA, cuad, ListaCuad,enviarT,ModN;
stack<int> procAct, PilaBrinco, PilaRet, PilaElse;
queue<string> listaVar,listaPar;
LinkedListV *DirdeProc = new LinkedListV();
LinkedListC *DirdeCuad = new LinkedListC();
bool error;
ofstream CuadFile;

//int 0, float 1, bool 2 char 3 error 4
int cuboSem[5][4][4] =
					  {{{0,1,4,3},{1,1,4,4},{4,4,2,4},{3,4,4,3}},		
					   {{0,1,4,3},{1,1,4,4},{4,4,2,4},{3,4,4,3}},		
					   {{0,1,4,4},{1,1,4,4},{4,4,4,4},{4,4,4,4}},		
					   {{0,1,4,4},{1,1,4,4},{4,4,4,4},{4,4,4,4}},
					   {{2,2,2,2},{2,2,2,4},{2,2,2,4},{2,4,4,2}}};	
//Pilas para Cuádruplos
stack<string> PilaO;
stack<string> Poper;
stack<string> PilaTipo;
%}

%union{
	int y_int;
	double y_double;
	bool y_bool;
	char *y_operadores;
	char *y_l_comm;
}
%token <y_int> CTE_I  
%token <y_operadores> L_GVLIST L_PROGRAM L_MAIN L_VLIST  L_VAR L_INT L_BOOL L_FLOAT L_CHAR L_RECEIVE L_PRINT L_SENDD L_SENDB L_SENDBOOL L_IF L_ELSE L_LOOP L_MAS L_MENOS L_MULT L_DIV L_BREAK L_DONE L_THEN L_DO L_END OP_MEN OP_MAY OP_MENIGU OP_MAYIGU OP_IGUIGU OP_NOTIGU CTE_CHAR L_ID L_BRA1 L_BRA2 L_SEMICOLON L_COMMA L_PAR1 L_PAR2 L_VOID L_CALL L_IGUAL 
%token <y_double> CTE_F
%token <y_bool> CTE_TRUE CTE_FALSE
%start PROG

%%
PROG	 		: {error = false; ProgProcess();}PROG_A PROG_M MAIN;

PROG_A			: 
				| L_GVLIST VAR;

PROG_M			:
				| MODULO PROG_M; 

MODULO			: L_VOID L_ID {addProc(yytext);} L_PAR1 MODULO_A {cuad = "pend mod";	
		 							  ListaCuad += cuad; cuadCont++;
       									  DirdeCuad -> addLast(cuad);}
			L_PAR2 L_BRA1 MAIN_A MAIN_B L_BRA2  {cuad = "return mod";
							     ListaCuad += cuad; cuadCont++;
       		 					     DirdeCuad -> addLast(cuad);};

MODULO_A 		:
                | TYPE L_ID {addToDirP(yytext);checaPar();addToDir(yytext); contadorVar++;} MODULO_B;

MODULO_B 		:
				| L_COMMA TYPE L_ID {addToDirP(yytext);checaPar();addToDir(yytext);contadorVar++;} MODULO_B;

MAIN			: L_MAIN {jumpCD(); addProc("main");} L_BRA1 MAIN_A MAIN_B L_BRA2 
			{DirdeProc->print();eliminaProc(); imprimirCuad();};

MAIN_A			:
				| L_VLIST VAR {contadorFunc++;};

MAIN_B			: 
				| BODY BODY_R;

BODY_R			:
				| BODY BODY_R;

VAR 			: L_BRA1 VAR_A L_BRA2;

VAR_A    		: TYPE L_ID {addToDir(yytext); contadorVar++;} ID_C {checaVar();} L_SEMICOLON VAR_B;

VAR_B           :
                | TYPE L_ID {addToDir(yytext);} ID_C {checaVar();} L_SEMICOLON VAR_B;

ID_C 			:
				| L_COMMA L_ID {addToDir(yytext);} ID_C;

				//int 0, float 1, bool 2 char 3 error 4
TYPE			: L_INT 	{tipoA = "int";}
				| L_FLOAT	{tipoA = "float";}
				| L_CHAR 	{tipoA = "char";}
				| L_BOOL 	{tipoA = "bool";};

ASIGNACION		: L_ID {busq(yytext);} L_IGUAL{Poper.push(yytext);} EXP {checaI();}L_SEMICOLON;

IMPRIMIR 		: L_PRINT L_PAR1  EXP {checaPrint();} IMPRIMIR_A L_PAR2 L_SEMICOLON;

IMPRIMIR_A 		: 
				| L_COMMA EXP {checaPrint();} IMPRIMIR_A;

RECIBIR 		: L_RECEIVE L_PAR1 L_ID {checaRec(yytext);} L_PAR2 L_SEMICOLON;

ENVIAR 			: SEND_TYPE {enviarT = yytext;} L_PAR1 ENVIAR_A {checaSend(yytext);} L_PAR2 L_SEMICOLON;

ENVIAR_A 		: L_ID
				| CTE_FALSE;
				| CTE_TRUE;
				| CTE_I;

CONDICION 		: L_IF L_PAR1 EXP L_PAR2 {jumpC(0,0);} L_THEN BODY BODY_R L_DONE {cuad = "ifend mod";
	ListaCuad += cuad; cuadCont++;
        DirdeCuad -> addLast(cuad);} CONDICION_A;

CONDICION_A 		: {jumpCD();}
				| {jumpElse();jumpCD();} L_ELSE BODY BODY_R L_DONE {jumpElseD();};

SEND_TYPE 		: L_SENDD
				| L_SENDB
				| L_SENDBOOL;

BODY 			: CICLO
				| CONDICION
				| ENVIAR
				| IMPRIMIR
				| RECIBIR
				| ASIGNACION
				| LLAMADA_F;

LLAMADA_F 		: L_CALL L_ID{ModN=yytext;} L_PAR1 EXP {checaCall();} LLAMADA_A L_PAR2 {checaCall2();} L_SEMICOLON{paint =0;};

LLAMADA_A		: 
				| L_COMMA EXP {checaCall();} LLAMADA_A;

CICLO 			: L_LOOP L_PAR1 CICLO_A L_PAR2 {jumpC(0,1);} L_DO BODY BODY_R {jumpC(1,1);} L_END{jumpCD();};

CICLO_A 		: L_ID{busq(yytext); loopFunc(yytext);}
				| CTE_I{loopFunc(yytext);};


EXP 			: EXP_S EXP_A;

EXP_A 			:
				| OP_MEN {Poper.push(yytext);} EXP_S {checaCO();}
				| OP_MAY {Poper.push(yytext);} EXP_S {checaCO();}
				| OP_MENIGU {Poper.push(yytext);} EXP_S {checaCO();}
				| OP_MAYIGU {Poper.push(yytext);} EXP_S {checaCO();}
				| OP_IGUIGU {Poper.push(yytext);} EXP_S {checaCO();}
				| OP_NOTIGU {Poper.push(yytext);} EXP_S {checaCO();};

EXP_S 			: EXP_T {checaSR();} EXP_S_A;

EXP_S_A			:
				| EXP_S_B EXP_S;

EXP_S_B 		: L_MAS   {Poper.push(yytext);}
				| L_MENOS {Poper.push(yytext);};

EXP_T			: EXP_F {checaMD();} EXP_T_A;

EXP_T_A			:
				| EXP_T_B EXP_T;

EXP_T_B			: L_MULT {Poper.push(yytext);}
				| L_DIV {Poper.push(yytext);};

EXP_F			: CTE_I { PilaO.push(yytext);PilaTipo.push("int");}
				| L_ID {busq(yytext);}
				| CTE_F { PilaO.push(yytext);PilaTipo.push("float");}
				| L_PAR1 {Poper.push(yytext);} EXP L_PAR2{Poper.pop();}
				| CTE_CHAR {PilaO.push(yytext);PilaTipo.push("char");}
				| CTE_TRUE {PilaO.push(yytext);PilaTipo.push("bool");}
				| CTE_FALSE {PilaO.push(yytext);PilaTipo.push("bool");}

%% 
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
