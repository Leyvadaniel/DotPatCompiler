//
//  LinkedListC.h
//  proyecto lenguajes
//
//  Created by Oscar Villarreal on 11/12/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef LinkedListC_h
#define LinkedListC_h

#include <iostream>
#include <fstream>
#include <string>
#include "nodoC.h"

using namespace std;

class LinkedListC
{
public:
    int count;
    LinkedListC();
    ~LinkedListC();
    bool isEmpty();
    void addFirst(string data);
    void addLast(string data);
    bool add(string data, int pos);
    string del(int pos);
    string get(int pos);
    string set(string data, int pos);
    int deleteAll();
    int getCount();
    void print(ofstream& out);
    void replaceDir(int pos, string dir);
    
private:
    nodoC *head;
    void borra();
};

void LinkedListC::borra()
{
    nodoC *aux = head;
    while (aux != NULL)
    {
        head = head->getNext();
        delete aux;
        aux = head;
    }
}

LinkedListC::~LinkedListC()
{
    borra();
}

LinkedListC::LinkedListC()
{
    head = NULL;
    count = 0;
}

bool LinkedListC::isEmpty()
{
    return (head == NULL);
}

void LinkedListC::addFirst(string data)
{
    head = new nodoC(data, head);
    count++;
}

void LinkedListC::addLast(string data)
{
    if (this->isEmpty())
        this->addFirst(data);
    else
    {
        nodoC *aux = this->head;
        while (aux->getNext() != NULL)
        {
            aux=aux->getNext();
        }
        aux->setNext(new nodoC(data));
        count++;
    }
}

bool LinkedListC::add(string data, int pos)
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
        nodoC *aux = head; //
        for (int i = 1; i<pos; i++)//se consigue el aux del nodoC que va antes que el que vamos a crear
        {
            aux = aux -> getNext();
        }
        aux -> setNext(new nodoC(data, aux->getNext() )); //se modifica el NEXT del nodoC anterior
        count++;
    }
    return true;
}

string LinkedListC::del(int pos)
{
    /*if (pos >= count)
     {
     return NULL;
     }*/
    nodoC *aux = head;
    for (int i=1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    nodoC *aux2 = aux->getNext();
    string dataAux = aux2 -> getData();
    aux -> setNext(aux2->getNext());
    delete aux2;
    count--;
    return dataAux;
}

int LinkedListC::deleteAll()
{
    int cont = count;
    borra();
    count = 0;
    return cont;
}

string LinkedListC::get(int pos)
{
    /*if (pos < 0 ||  pos >= count)
     {
     return NULL;
     }*/
    nodoC *aux = head;
    for (int i = 0; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    string dataTemp = aux -> getData();
    return dataTemp;
}

string LinkedListC::set(string data,int pos)
{
    nodoC *aux = head;
    for (int i = 1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    aux -> setData(data);
    string dataTemp = aux -> getData();
    return dataTemp;
}

int LinkedListC::getCount()
{
    return count;
}

void LinkedListC::replaceDir(int pos, string dir) 
{ 
	nodoC *aux = head; int i,y=0;
	for (i = 0; i<pos; i++) 
	{ 
		aux = aux -> getNext(); }
	string cuad = aux -> getData();
	while (cuad[y]) { 
		y++;
		if (cuad[y] == '#') 
		{ 
			cuad.erase(y,1);
			cuad.insert(y, dir); 
			aux -> setData(cuad);
		} 
	} 
	string dataTemp = aux -> getData(); 
}

void LinkedListC::print(ofstream& out)
{
	int num = 1;        
	nodoC *aux = this->head;
        while (aux != NULL)
        {
		string cuad = aux -> getData();
		/*
	    	if(num < 10)
            	{cout <<" "<<num<<".- "<< cuad << endl;}
	    	else{cout <<num<<".- "<< cuad << endl;}
            	aux=aux->getNext(); num++;
		*/
	    	cout << cuad << endl;
		out << cuad << endl;
	    	aux=aux->getNext();
        }

}



#endif /* LinkedListC_h */
