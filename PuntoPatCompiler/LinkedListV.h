//
//  LinkedListV.h
//  proyecto lenguajes
//
//  Created by Oscar Villarreal on 11/3/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef LinkedListV_h
#define LinkedListV_h

#include <iostream>
#include "nodoV.h"
#include "DirProcs.h"
#include "VarT.h"
#include "nodo.h"
#include "LinkedList.h"

using namespace std;

class LinkedListV
{
public:
    int count;
    LinkedListV();
    ~LinkedListV();
    bool isEmpty();
    void addFirst(DirProc data);
    void addLast(DirProc data);
    bool add(DirProc data, int pos);
    DirProc deleteFirst();
    DirProc deleteLast();
    DirProc del(int pos);
    DirProc get(int pos);
    DirProc set(DirProc data, int pos);
    DirProc GetByName(string nameProc);
    int SearchProc(int numProc);
    bool SearchName(string nameProc);
    int deleteAll();
    void print();
    
private:
    nodoV *head;
    void borra();
};

void LinkedListV::borra()
{
    nodoV *aux = head;
    while (aux != NULL)
    {
        head = head->getNext();
        delete aux;
        aux = head;
    }
}

LinkedListV::~LinkedListV()
{
    borra();
}

LinkedListV::LinkedListV()
{
    head = NULL;
    count = 0;
}

bool LinkedListV::isEmpty()
{
    return (head == NULL);
}

void LinkedListV::addFirst(DirProc data)
{
    head = new nodoV(data, head);
    count++;
}

void LinkedListV::addLast(DirProc data)
{
    if (this->isEmpty())
        this->addFirst(data);
    else
    {
        nodoV *aux = this->head;
        while (aux->getNext() != NULL)
        {
            aux=aux->getNext();
        }
        aux->setNext(new nodoV(data));
        count++;
    }
}

bool LinkedListV::add(DirProc data, int pos)
{
    if (pos < 0 || pos > count)
    {
        return false;
    }
    if (pos == 0)
    {
        this -> addFirst(data);
    }
    else if (pos == count)
    {
        this -> addLast(data);
    }
    else
    {
        nodoV *aux = head; //
        for (int i = 1; i<pos; i++)//se consigue el aux del nodoV que va antes que el que vamos a crear
        {
            aux = aux -> getNext();
        }
        aux -> setNext(new nodoV(data, aux->getNext() )); //se modifica el NEXT del nodoV anterior
        count++;
    }
    return true;
}

DirProc LinkedListV::deleteFirst()
{
    /*if (this -> isEmpty())
     {
     return NULL;
     }*/
    DirProc dataAux = head -> getData();
    nodoV *aux = head;
    head = head->getNext();
    delete aux;
    count --;
    return dataAux;
}

DirProc LinkedListV::deleteLast()
{
    if (count <= 1)
    {
        return this->deleteFirst();
    }
    nodoV *aux = head;
    while (aux -> getNext() -> getNext() != NULL) //checa que el siguente siguente sea NULL(o sea el fin)
    {
        aux = aux -> getNext();
    }
    nodoV *aux2 = aux ->getNext();
    DirProc dataAux = aux2 -> getData();
    aux -> setNext(NULL);
    delete aux2;
    count--;
    return dataAux;
}

DirProc LinkedListV::del(int pos)
{
    /*if (pos >= count)
     {
     return NULL;
     }*/
    if (pos == 0)
    {
        return this -> deleteFirst();
    }
    if (pos == count -1)
    {
        return this -> deleteLast();
    }
    nodoV *aux = head;
    for (int i=1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    nodoV *aux2 = aux->getNext();
    DirProc dataAux = aux2 -> getData();
    aux -> setNext(aux2->getNext());
    delete aux2;
    count--;
    return dataAux;
}

int LinkedListV::SearchProc(int numProc)
{
    int i;
    nodoV *aux = head;
    for (i = 0; i<count; i++)
    {
        DirProc temp = aux->getData();
        if(numProc == temp.getNumProc())
        {
            return i;
        }
        aux = aux -> getNext();
    }    
    return -1;
}

bool LinkedListV::SearchName(string nameProc)
{
    int i;
    nodoV *aux = head;
    for (i = 0; i<count; i++)
    {
	string tempN = aux->getData().getName();        
        if(nameProc == tempN)
        {
            return true;
        }
        aux = aux -> getNext();
    }    
    return false;
}

DirProc LinkedListV::GetByName(string nameProc)
{
    int i;
    nodoV *aux = head;
    for (i = 0; i<count; i++)
    {
	string tempN = aux->getData().getName(); 
        if(nameProc == tempN)
        {
            return aux->getData();
        }
        aux = aux -> getNext();
    }    
    
}

int LinkedListV::deleteAll()
{
    int cont = count;
    borra();
    count = 0;
    return cont;
}

DirProc LinkedListV::get(int pos)
{
    /*if (pos < 0 ||  pos >= count)
     {
     return NULL;
     }*/
    nodoV *aux = head;
    for (int i = 0; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    DirProc dataTemp = aux -> getData();
    //cout<<pos<< "TempData from LinkedListV\n";
    return dataTemp;
}

DirProc LinkedListV::set(DirProc data,int pos)
{
    nodoV *aux = head;
    for (int i = 1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    aux -> setData(data);
    DirProc dataTemp = aux -> getData();
    return dataTemp;
}

void LinkedListV::print()
{
    nodoV *aux = head;
    int c;
    for (int i = 0; i<count; i++)
    {
        cout << "Modulo: "<<aux->getData().getName()<<endl;
	aux ->getData().getTablaVars() -> print();
	cout << endl;
	aux = aux -> getNext();
    }
}


#endif /* LinkedListV_h */
