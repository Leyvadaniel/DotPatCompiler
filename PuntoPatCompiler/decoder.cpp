#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "llcuadruplos.h"
#include "nodoCuadruplos.h"

using namespace std;

llcuadruplos *TempList;
queue<string> tempQ;
string cuadruplo,codigo;
string stemp, ptemp, partemp, eme[3];
int counter, depth = 0;
bool parEntra = true, error = false, flagTemp = false;
string icode = "/*\n |                             _)          _ \\   \\ __ __|\n |  _ \\ __ \\   _` | |   |  _` | |  _ \\    |   | _ \\   |  \n |  __/ |   | (   | |   | (   | |  __/    ___/ ___ \\  |  \n_|\\___|_|  _|\\__, |\\__,_|\\__,_| |\\___| _)_|  _/    _\\_|  \n             |___/          ___/                         \n\n  ___|                    |                           _ \\                               __ \\             _)      |\n |      __| _ \\  _` |  _` |  _ \\   __ \\   _ \\   __|  |   |  __|  __|  _` |  __|  |   |  |   |  _` | __ \\  |  _ \\ |\n |     |    __/ (   | (   | (   |  |   | (   | |     |   |\\__ \\ (    (   | |     |   |  |   | (   | |   | |  __/ |\n\\____|_|  \\___|\\__,_|\\__,_|\\___/   .__/ \\___/ _|    \\___/ ____/\\___|\\__,_|_|    \\__, | ____/ \\__,_|_|  _|_|\\___|_|\n                                  _|                                            ____/                             \n*/\n#include <IRremote.h> // Biblioteca del recibidor de infrarrojo\n\n#define receivePin 11 // Pin al que va connectado el recibidor de infrarrojo\n\n//Salidas a los leds\n#define led1       2\n#define led2       5 \n#define led3       4 \n#define led4       3\n#define led5       6\n#define led6       9\n#define led7       8\n#define led8       7\n\n//Definicion de botones del control\n#define B1        0xFFA25D\n#define B2        0xFF629D\n#define B3        0xFFE21D\n#define B4        0xFF22DD\n#define B5        0xFF02FD\n#define B6        0xFFC23D\n#define B7        0xFFE01F\n#define B8        0xFFA857\n#define B9        0xFF906F\n#define B10       0xFF6897\n#define B11       0xFF9867\n#define B12       0xFFB04F\n#define B13       0xFF30CF\n#define B14       0xFF18E7 \n#define B15       0xFF7A85\n#define B16       0xFF10EF\n#define B17       0xFF38C7\n#define B18       0xFF5AA5\n#define B19       0xFF42BD\n#define B20       0xFF4AB5\n#define B21       0xFF52AD\n\nIRrecv Irrecv(receivePin);//inicializacion de la entrada del recibidor de infrarrojo\ndecode_results results;// variable del boton reconocido\nint ledPins[8]={led4, led3, led2, led1 ,led8,led7,led6,led5}; //Acomodacion de las salidas cuando se despliega en displays\nint ledPinsB[8]={led8,led7,led6,led5,led4, led3, led2, led1};// Acomodacion de las salidas cuando se despliega en los leds\nint buttonVal; //variable global donde se guarda un valor unico para cada boton\n// inicializacion del arduino \nvoid setup() {\n  Serial.begin(9600); // valor del BaudRate que se tiene que igualar en el monitor serial \n  Irrecv.enableIRIn();// comienza el recibidor;\n  // Declaracion de salidas como OUTPUTS\n  pinMode(led1, OUTPUT);\n  pinMode(led2, OUTPUT);\n  pinMode(led3, OUTPUT);\n  pinMode(led4, OUTPUT);\n  pinMode(led5, OUTPUT);\n  pinMode(led6, OUTPUT);\n  pinMode(led7, OUTPUT);\n  pinMode(led8, OUTPUT);\n}\n// Funcion que despliega en los displays un numero entre 0 y 99\nvoid displayWrite(int num){\n  int dec,uni, aux;\n  if(num > 99){num = 99;}//Tope de 99\n  if(num < 0){num = 0;}// Tope inferior de 00 \n  dec = num / 10; // sacar las decimas\n  uni = num % 10; // sacar las unidades\n  int divi[4]={8,4,2,1};\n  // convertidor a binario de decimas\n  for(int i = 0; i < 4; i++){\n      aux = dec/divi[i];\n      // se despliegan\n      if(aux==1){ \n        digitalWrite(ledPins[i+4], HIGH);\n      }\n      else{digitalWrite(ledPins[i+4], LOW);}\n      dec -= divi[i]* aux;\n  }\n  aux = 0;\n  // convertidor a binario de unidades\n  for(int i = 0; i < 4; i++){\n    aux = uni/divi[i];\n    // se despliega\n      if(aux==1){ \n        digitalWrite(ledPins[i], HIGH);\n      }\n      else{digitalWrite(ledPins[i], LOW);}\n      uni -= divi[i]* aux;\n  }\n  delay(2000);// Delay para que se que se pueda reconocer el numero desplegado\n}\n// funcion para desplegar en los leds un numero binario entre 0 y 255\nvoid binaryWrite(int num){\n  int aux;\n  if(num > 255){num = 255;}// tope de 255\n  if(num < 0){num = 0;} // tope inferior de 0\n  int Numero = num;\n  int divi[8]={128,64,32,16,8,4,2,1}; \n  // convertidor de decimal a binario \n  for(int i = 0; i < 8; i++){\n      aux = Numero/divi[i];\n      // se despliega en los leds\n      if(aux==1){ \n        digitalWrite(ledPinsB[i], HIGH);\n      }\n      else{digitalWrite(ledPinsB[i], LOW);}\n      Numero -= divi[i]* aux;\n  }\n  delay(2000);// delay para que se que se pueda apreciar lo desplegado     \n}\n// funcion para desplegar un booleano en leds\nvoid boolWrite(bool x){\n  if(x){ binaryWrite(255); } // en caso de ser verdadero se prenden todos los leds\n  else{ binaryWrite(0); } // en caso de ser falso se apagan todos los leds\n}\n// funcion para recibir el boton presionado y convertirlo al numero unico por boton\nvoid getButton()\n{\n  bool tempB = true; \n  do{\n    if (Irrecv.decode(&results))// si un boton fue presionado y se recibio correctamente \n    {\n      tempB = false;\n      Irrecv.resume(); // sigue recibiendo botones presionados \n      //decodificacion del boton presionado al numero unico por boton\n      switch(results.value){\n        case B1:\n          buttonVal = -1;\n          break;\n        case B2:\n          buttonVal = -2;\n          break;\n        case B3:\n          buttonVal = -3;\n          break;\n        case B4:\n          buttonVal = -4;\n          break;\n        case B5:\n          buttonVal = -5;\n          break;\n        case B6:\n          buttonVal = -6;\n          break;\n        case B7:\n          buttonVal = -7;\n          break;\n        case B8:\n          buttonVal = -8;\n          break;\n        case B9:\n          buttonVal = -9;\n          break;\n        case B10:\n          buttonVal = 0;\n          break;\n        case B11:\n          buttonVal = -10;\n          break;\n        case B12:\n          buttonVal = -11;\n          break;\n        case B13:\n          buttonVal = 1;\n          break;\n        case B14:\n          buttonVal = 2;\n          break;\n        case B15:\n          buttonVal = 3;\n          break;\n        case B16:\n          buttonVal = 4;\n          break;\n        case B17:\n          buttonVal = 5;\n          break;\n        case B18:\n          buttonVal = 6;\n          break;\n        case B19:\n          buttonVal = 7;\n          break;\n        case B20:\n          buttonVal = 8;\n          break;\n        case B21:\n          buttonVal = 9;\n          break;\n      }\n    }  \n  }\n  while(tempB);\n}";
bool tempDetect(string x)
{
    string t = "temp."; int i,count = 0;
    for (i = 0; i < 5; i++) {
        if (t[i] == x[i])
        { count++;}
    }
    if (count ==5) {
        return true;
    }
    return false;
}

string tempDetect2(string x)
{
    string t = "temp.", a; int i,j,count = 0;
    for (i = 0; i < 5; i++) {
        if (t[i] == x[i])
        { count++;}
    }
    if (count ==5) {
        for (j = 0; j<3; j++) {
            a = a + eme[j];
        }
        return a;
    }
    return x;
}

bool checaOP(string x)
{
    if((x == "+")|(x == "-")|(x == "*")|(x == "/"))
    { return true;}
    if((x == "<")|(x == ">")|(x == "<=")|(x == ">=")|(x == "==")|(x == "!="))
    { return true;}
    return false;
}

int atoi(string sEntrada, int n, int ini)
{
    int iSale = 0;
    for (int iA = ini; iA<n; iA++)
    {iSale = (iSale*10 + sEntrada[iA] - '0');}
    return iSale;
}

string tab()
{
    string te;
    for (int i = 0; i < depth; i++)
    { te = "\t" + te;}
    return te;
}

void decode(ifstream& codigoIntermedio, ofstream& codigoFinal, bool cycle, int breakInt)
{
    string delimitador = " ";
    while (getline (codigoIntermedio,cuadruplo))
    {
        if (error) { break;}
        string elementos[4]  = {};
        counter++;
        cout << cuadruplo << endl;/// empieza toda la decodificación
        size_t pos = 0;
        string token;
        int contadorDePosiciones = 0;
        
        while ((pos = cuadruplo.find(delimitador)) != string::npos)
        {
            token = cuadruplo.substr(0, pos);
            elementos[contadorDePosiciones]= token;
            cuadruplo.erase(0, pos + delimitador.length());
            contadorDePosiciones++;
        }
        elementos[3]= cuadruplo;
        
        cout<<"elementos :"<<elementos[0]<<" "<<elementos[1]<<" "<<elementos[2]<<" "<<elementos[3]<<endl;
        
        //MODULOS
        if (elementos[0] == "mod")
        {
            depth++;
            if (elementos[3] == "main")
            {
                codigoFinal<<"\nvoid loop() {\n";
                decode(codigoIntermedio,codigoFinal, true, 10000);
                codigoFinal<<tab()<<"while(1){}\n";
                codigoFinal<<"}\n";
            }
            else
            {
                codigoFinal<<"\nvoid "<<elementos[3]<<"(";
                decode(codigoIntermedio,codigoFinal, true, 10000);
                codigoFinal<<") {\n";
                decode(codigoIntermedio,codigoFinal, true, 10000);
                codigoFinal<<"}\n";
            }
            ptemp.clear();
            depth--;
        }
        
        //VARIABLES
        if (elementos[0] == "var")
        {
            codigoFinal<<tab()<<elementos[1]<<" "<<elementos[3]<<";"<<endl;
        }
        
        //PARAMETROS
        if (elementos[0] == "par")
        {
            ptemp= ptemp+elementos[1]+" "+elementos[3]+",";
        }
        
        //OPERACIONES
        if (checaOP(elementos[0]))
        {
            string stringt,stringt2;/*
            if((!tempDetect(elementos[1])&(!tempDetect(elementos[2]))&flagTemp))
                {
                    tempQ.push(stemp);
                }
            if((!tempDetect(elementos[1])&(!tempDetect(elementos[2]))&flagTemp))
            {
                tempQ.push(stemp); cout << "Push Q    "<<stemp<<endl;
            }
            if((tempDetect(elementos[1])&(tempDetect(elementos[2]))&flagTemp))
            {
                //elementos[2]=tempQ.front(); tempQ.pop();
                elementos[1]=tempQ.front(); tempQ.pop(); tempQ.pop();
                
            }*/
            
            if(tempDetect(elementos[1])){
                stringt=TempList -> sus(elementos[1]);
                elementos[1]=stringt;
            }
            if(tempDetect(elementos[2])){
                stringt2=TempList -> sus(elementos[2]);
                elementos[2]=stringt2;
            }
            
            stemp = elementos[1]+elementos[0]+elementos[2];
            
            TempList ->addLast(stemp,elementos[3]);
            
            eme[0]= elementos[1];
            eme[1]= elementos[0];
            eme[2]= elementos[2];
            cout << "STEMP    "<<stemp<<endl;
        }
        
        
        //ASIGNACION
        if ((elementos[0] == "="))
        {
            if(tempDetect(elementos[1]))
            { elementos[1]=stemp;}
            codigoFinal<<tab()<<elementos[3]<<elementos[0]<<elementos[1]<<";"<<endl;
        }
        
        //IF
        if (elementos[0] == "gotof")
        {
            if(tempDetect(elementos[1]))
            { elementos[1]=stemp;}
            codigoFinal<<tab()<<"if ("<<elementos[1]<<") {\n";
            depth++;
            decode(codigoIntermedio,codigoFinal, true, 10000);
            depth--;
            codigoFinal<<tab()<<"}\n";
        }
        
        if(elementos[0]== "else")
        {
            codigoFinal<<tab()<<"else {\n";
            depth++;
            decode(codigoIntermedio,codigoFinal, true, 10000);
            depth--;
            codigoFinal<<tab()<<"}\n";
        }
        
        //LOOP
        if (elementos[0] == "gotoF")
        {
            if(tempDetect(elementos[1]))
            { elementos[1]=stemp;}
            codigoFinal<<tab()<<"while ("<<elementos[1]<<") {\n";
            depth++;
            int vueltas = atoi(elementos[3], elementos[3].length(),0) - (counter+1);
            decode(codigoIntermedio,codigoFinal, true, vueltas);
            depth--;
            codigoFinal<<tab()<<"}\n";
        }
        
        //IMPRIMIR
        if ((elementos[0] == "print"))
        {
            if(tempDetect(elementos[1]))
            { elementos[1]=stemp;}
            codigoFinal<<tab()<<"Serial.print("<<elementos[3]<<");"<<endl;
        }
        
        //LLAMADA
        if ((elementos[0] == "gosub"))
        {
            partemp.erase(partemp.length()-1,1);
            partemp = tempDetect2(partemp);
            codigoFinal<<tab()<<elementos[3]<<"("<<partemp<<");\n";
            partemp.clear();
            parEntra = true;
        }
        
        //PARAMETROS
        if (elementos[0] == "param")
        {
            partemp= partemp+elementos[1]+",";
            //cout<<"partemp: "<<partemp<<endl;
        }
        
        //RECIVIR
        if (elementos[0] == "recieve")
        {
            codigoFinal<<tab()<<"getButton();\n";
            codigoFinal<<tab()<<elementos[3]<<" = buttonVal;\n";
        }
        
        //ENVIAR DISPLAY
        if (elementos[0] == "send_d")
        {
            codigoFinal<<tab()<<"displayWrite("<<elementos[3]<<");\n";
        }
        
        //ENVIAR BIN
        if (elementos[0] == "send_b")
        {
            codigoFinal<<tab()<<"binaryWrite("<<elementos[3]<<");\n";
        }
        
        //ENVIAR BOOL
        if (elementos[0] == "send_bool")
        {
            codigoFinal<<tab()<<"boolWrite("<<elementos[3]<<");\n";
        }
        
        //ERROR
        if (elementos[0] == "ERROR") {
            cout<<"Error de compilación"<<endl;
            error = true;
            break;
        }
        
        //salida de ciclo
        if (cycle & (breakInt > 0))
        { breakInt--; }
        if (cycle & (breakInt == 1))
        { break; }
        
        //salida if
        if (elementos[0] == "ifend")
        { break; }
        
        //salida de else
        if (elementos[0] == "elsend")
        { break; }
        
        //salida de modulo
        if (cycle &(elementos[0] == "return"))
        {break;}
        
        //salida de parametros
        if (elementos[0] == "pend")
        {
            ptemp.erase(ptemp.length()-1,1);
            codigoFinal<<ptemp;
            ptemp.clear();
            break;
        }
        
        //fin del archivo
        if (elementos[0] == "end")
        {break;}
    }
}
int main(){
    string archivo;
    archivo = "Cuadruplos.txt";
    cout << "Abriendo el archivo: " << archivo << endl;
    //ifstream codigoIntermedio;
	const char *chr_arch = archivo.c_str();
	ifstream codigoIntermedio(chr_arch);

    
    ofstream codigoFinal;
	codigoFinal.open("ArduinoCode.ino");
   // codigoIntermedio.open(archivo);
	TempList = new llcuadruplos();
    
    if (codigoIntermedio.is_open()){
        /////////////////////lectura de archivo ///////////////////
        
        codigo = icode;
        codigoFinal << codigo;
        
        decode(codigoIntermedio,codigoFinal, false, 1);
        
        ////////////////////// termina lectura de archivo /////////////////
        
        cout << "termina archivo \n";
        codigoIntermedio.close();codigoFinal.close();
        }
    
    else{ cout << "Archivo no encontrado, ERROR\n"; return -1; }
    
}
