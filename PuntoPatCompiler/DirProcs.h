//
//  DirProcs.h
//  proyecto lenguajes
//
//  Created by Oscar Villarreal on 10/29/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef DirProcs_h
#define DirProcs_h
#include <stdio.h>
#include <stdlib.h>
#include "VarT.h"
#include "nodo.h"
#include "LinkedList.h"

using namespace std;


class DirProc
{
public:
    DirProc(string nombre1, int dirI);
    DirProc(string nombre);
    DirProc();
    string getName();
    int getDirIn();
    int getNumProc();
    int getParaCount();
    int getCount();
    void setCantVar(int x);
    void setNumProc(int x);
    void writeVarT(string nombre, string clase);
    void writePara(string nombre, string clase);
    bool search(string input);
    bool searchPara(string input);
    string searchTipo(string input);
    void imprimirVarT();
    LinkedList* getTablaVars();    

private:
    string nombre;
    int dirInicio;
    int cantidadVar;
    int cantidadPara;
    int numProc;
    LinkedList *tablaVars;
    LinkedList *tablaPara;
};

DirProc::DirProc()
{
    this -> nombre = "nombre";
    this -> cantidadVar = 50;
    this -> cantidadPara = 10;
    tablaVars = new LinkedList();
    tablaPara = new LinkedList();
    numProc = 0;
}

DirProc::DirProc(string nombre1, int dirI)
{
    this -> nombre = nombre1;
    this -> numProc = dirI;
    this -> cantidadVar = 50;
    this -> cantidadPara = 10;
    tablaVars = new LinkedList();
    tablaPara = new LinkedList();
    //numProc = 0;
}

DirProc::DirProc(string nombre)
{
    this -> nombre = nombre;
    this -> cantidadVar = 50;
    this -> cantidadPara = 10;
    tablaVars = new LinkedList();
    tablaPara = new LinkedList();
    numProc = 0;
}

string DirProc::getName()
{
    return nombre;
}

int DirProc::getDirIn()
{
    return dirInicio;
}

int DirProc::getNumProc()
{
    return numProc;
}

void DirProc::setCantVar(int x)
{
    this -> cantidadVar = x;
}

void DirProc::setNumProc(int x)
{
    this -> numProc = x;
}

void DirProc::writeVarT(string nombre, string clase)
{
    VarT tempV = VarT(nombre, clase);
    tablaVars ->addLast(tempV);
    this -> cantidadVar = cantidadVar + 1;
    //cout << "cantidadVar = " << this->cantidadVar<<endl;
}

void DirProc::writePara(string nombre, string clase)
{
    VarT tempV = VarT(nombre, clase);
    tablaPara ->addLast(tempV);
    this -> cantidadPara = cantidadPara + 1;
    //cout << "cantidadVar = " << this->cantidadPara<<endl;
}

bool DirProc::search(string input)
{
    int i;
    string name;
    VarT varactual;
    name = getName();
    int countt = tablaVars -> count;
    for (i=1; i < countt+1; i++)
    {
        if(tablaVars->isEmpty()){return false;}
        varactual = tablaVars->get(i);
        name = varactual.getName();
        if (name == input)
        {
            return true;
        }
    }
    return false;
}

bool DirProc::searchPara(string input)
{
    int i;
    string name;
    VarT varactual;
    name = getName();
    int countt = tablaPara -> count; 
    for (i=1; i < countt+1; i++)
    {
        if(tablaPara->isEmpty()){return false;}
        varactual = tablaPara->get(i);
        name = varactual.getName(); cout<<endl;cout<<"param cycle: "<<name<<endl;
        if (name == input)
        {
            return true;
        }
    }
    return false;
}

string DirProc::searchTipo(string input)
{
    int i;
    string name;
    VarT varactual;
    name = getName();
    int countt = tablaVars -> count;
    for (i=1; i < countt+1; i++)
    {
        varactual = tablaVars->get(i);
        name = varactual.getName();
        if (name == input)
        {
            return varactual.getClase();
        }
    }
    return "error";
}

void DirProc::imprimirVarT()
{
    int i;
    VarT varactual;
    //cout << this -> nombre << endl;
    int countt = tablaVars -> count;
    for (i=0; i < countt; i++)
    {
        tablaVars->get(i).print();
    }
}

int DirProc::getParaCount()
{
	return tablaPara -> count;
}

int DirProc::getCount()
{
	return tablaVars -> count;
}

LinkedList* DirProc::getTablaVars()
{
	return tablaVars;
}


#endif /* DirProcs_h */
