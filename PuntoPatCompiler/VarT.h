//
//  VarT.h
//  proyecto lenguajes
//
//  Created by Oscar Villarreal on 10/29/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef VarT_h
#define VarT_h

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class VarT
{
public:
    VarT(string name, string clase, int dir);
    VarT(string nombre, string clase);
    VarT();
    string getName();
    string getClase();
    int getDir();
    void print();
    
private:
    string nombre;
    string clase;
    int dir;
};

VarT::VarT()
{
    this -> nombre = "nombre";
    this -> clase = "clase";
    this -> dir = 0;
}

VarT::VarT(string nombre, string clase)
{
    this -> nombre = nombre;
    this -> clase = clase;
    this -> dir = 0;
}

VarT::VarT(string nombre, string clase, int dir)
{
    this -> nombre = nombre;
    this -> clase = clase;
    this -> dir = dir;
}

string VarT::getName()
{
    return nombre;
}

string VarT::getClase()
{
    return clase;
}

int VarT::getDir()
{
    return dir;
}

void VarT::print()
{
    cout << "Nombre: " << this -> nombre << endl;
    cout << "Clase: " <<this -> clase << endl<<endl;
}


#endif /* VarT_h */
