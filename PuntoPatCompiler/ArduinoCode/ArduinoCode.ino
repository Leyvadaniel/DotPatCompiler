/*
 |                             _)          _ \   \ __ __|
 |  _ \ __ \   _` | |   |  _` | |  _ \    |   | _ \   |  
 |  __/ |   | (   | |   | (   | |  __/    ___/ ___ \  |  
_|\___|_|  _|\__, |\__,_|\__,_| |\___| _)_|  _/    _\_|  
             |___/          ___/                         

  ___|                    |                           _ \                               __ \             _)      |
 |      __| _ \  _` |  _` |  _ \   __ \   _ \   __|  |   |  __|  __|  _` |  __|  |   |  |   |  _` | __ \  |  _ \ |
 |     |    __/ (   | (   | (   |  |   | (   | |     |   |\__ \ (    (   | |     |   |  |   | (   | |   | |  __/ |
\____|_|  \___|\__,_|\__,_|\___/   .__/ \___/ _|    \___/ ____/\___|\__,_|_|    \__, | ____/ \__,_|_|  _|_|\___|_|
                                  _|                                            ____/                             
*/
#include <IRremote.h> // Biblioteca del recibidor de infrarrojo

#define receivePin 11 // Pin al que va connectado el recibidor de infrarrojo

//Salidas a los leds
#define led1       2
#define led2       5 
#define led3       4 
#define led4       3
#define led5       6
#define led6       9
#define led7       8
#define led8       7

//Definicion de botones del control
#define B1        0xFFA25D
#define B2        0xFF629D
#define B3        0xFFE21D
#define B4        0xFF22DD
#define B5        0xFF02FD
#define B6        0xFFC23D
#define B7        0xFFE01F
#define B8        0xFFA857
#define B9        0xFF906F
#define B10       0xFF6897
#define B11       0xFF9867
#define B12       0xFFB04F
#define B13       0xFF30CF
#define B14       0xFF18E7 
#define B15       0xFF7A85
#define B16       0xFF10EF
#define B17       0xFF38C7
#define B18       0xFF5AA5
#define B19       0xFF42BD
#define B20       0xFF4AB5
#define B21       0xFF52AD

IRrecv Irrecv(receivePin);//inicializacion de la entrada del recibidor de infrarrojo
decode_results results;// variable del boton reconocido
int ledPins[8]={led4, led3, led2, led1 ,led8,led7,led6,led5}; //Acomodacion de las salidas cuando se despliega en displays
int ledPinsB[8]={led8,led7,led6,led5,led4, led3, led2, led1};// Acomodacion de las salidas cuando se despliega en los leds
int buttonVal; //variable global donde se guarda un valor unico para cada boton
// inicializacion del arduino 
void setup() {
  Serial.begin(9600); // valor del BaudRate que se tiene que igualar en el monitor serial 
  Irrecv.enableIRIn();// comienza el recibidor;
  // Declaracion de salidas como OUTPUTS
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}
// Funcion que despliega en los displays un numero entre 0 y 99
void displayWrite(int num){
  int dec,uni, aux;
  if(num > 99){num = 99;}//Tope de 99
  if(num < 0){num = 0;}// Tope inferior de 00 
  dec = num / 10; // sacar las decimas
  uni = num % 10; // sacar las unidades
  int divi[4]={8,4,2,1};
  // convertidor a binario de decimas
  for(int i = 0; i < 4; i++){
      aux = dec/divi[i];
      // se despliegan
      if(aux==1){ 
        digitalWrite(ledPins[i+4], HIGH);
      }
      else{digitalWrite(ledPins[i+4], LOW);}
      dec -= divi[i]* aux;
  }
  aux = 0;
  // convertidor a binario de unidades
  for(int i = 0; i < 4; i++){
    aux = uni/divi[i];
    // se despliega
      if(aux==1){ 
        digitalWrite(ledPins[i], HIGH);
      }
      else{digitalWrite(ledPins[i], LOW);}
      uni -= divi[i]* aux;
  }
  delay(2000);// Delay para que se que se pueda reconocer el numero desplegado
}
// funcion para desplegar en los leds un numero binario entre 0 y 255
void binaryWrite(int num){
  int aux;
  if(num > 255){num = 255;}// tope de 255
  if(num < 0){num = 0;} // tope inferior de 0
  int Numero = num;
  int divi[8]={128,64,32,16,8,4,2,1}; 
  // convertidor de decimal a binario 
  for(int i = 0; i < 8; i++){
      aux = Numero/divi[i];
      // se despliega en los leds
      if(aux==1){ 
        digitalWrite(ledPinsB[i], HIGH);
      }
      else{digitalWrite(ledPinsB[i], LOW);}
      Numero -= divi[i]* aux;
  }
  delay(2000);// delay para que se que se pueda apreciar lo desplegado     
}
// funcion para desplegar un booleano en leds
void boolWrite(bool x){
  if(x){ binaryWrite(255); } // en caso de ser verdadero se prenden todos los leds
  else{ binaryWrite(0); } // en caso de ser falso se apagan todos los leds
}
// funcion para recibir el boton presionado y convertirlo al numero unico por boton
void getButton()
{
  bool tempB = true; 
  do{
    if (Irrecv.decode(&results))// si un boton fue presionado y se recibio correctamente 
    {
      tempB = false;
      Irrecv.resume(); // sigue recibiendo botones presionados 
      //decodificacion del boton presionado al numero unico por boton
      switch(results.value){
        case B1:
          buttonVal = -1;
          break;
        case B2:
          buttonVal = -2;
          break;
        case B3:
          buttonVal = -3;
          break;
        case B4:
          buttonVal = -4;
          break;
        case B5:
          buttonVal = -5;
          break;
        case B6:
          buttonVal = -6;
          break;
        case B7:
          buttonVal = -7;
          break;
        case B8:
          buttonVal = -8;
          break;
        case B9:
          buttonVal = -9;
          break;
        case B10:
          buttonVal = 0;
          break;
        case B11:
          buttonVal = -10;
          break;
        case B12:
          buttonVal = -11;
          break;
        case B13:
          buttonVal = 1;
          break;
        case B14:
          buttonVal = 2;
          break;
        case B15:
          buttonVal = 3;
          break;
        case B16:
          buttonVal = 4;
          break;
        case B17:
          buttonVal = 5;
          break;
        case B18:
          buttonVal = 6;
          break;
        case B19:
          buttonVal = 7;
          break;
        case B20:
          buttonVal = 8;
          break;
        case B21:
          buttonVal = 9;
          break;
      }
    }  
  }
  while(tempB);
}
void loop() {
	int valorLlegadaUno;
	int valorLlegadaDos;
	int valorLlegadaTres;
	int suma;
	int resta;
	int mult;
	int termina;
	int respuesta;
	bool x;
	suma=0-3;
	resta=0-1;
	mult=0-2;
	termina=0-4;
	x=true;
	while (x==true) {
		Serial.print('V');
		Serial.print('1');
		getButton();
		valorLlegadaUno = buttonVal;
		Serial.print(valorLlegadaUno);
		binaryWrite(valorLlegadaUno);
		Serial.print('V');
		Serial.print('2');
		getButton();
		valorLlegadaDos = buttonVal;
		Serial.print(valorLlegadaDos);
		binaryWrite(valorLlegadaDos);
		Serial.print('O');
		Serial.print('P');
		getButton();
		valorLlegadaTres = buttonVal;
		Serial.print(valorLlegadaTres);
		boolWrite(true);
		boolWrite(false);
		boolWrite(true);
		boolWrite(false);
		if (valorLlegadaTres==suma) {
			respuesta=valorLlegadaUno+valorLlegadaDos;
			binaryWrite(respuesta);
		}
		if (valorLlegadaTres==resta) {
			respuesta=valorLlegadaUno-valorLlegadaDos;
			binaryWrite(respuesta);
		}
		if (valorLlegadaTres==mult) {
			respuesta=valorLlegadaUno*valorLlegadaDos;
			binaryWrite(respuesta);
		}
		if (valorLlegadaTres==termina) {
			x=false;
		}
		Serial.print('R');
		Serial.print(respuesta);
	}
	while(1){}
}
