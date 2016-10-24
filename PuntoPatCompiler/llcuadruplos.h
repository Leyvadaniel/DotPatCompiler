//
//  llcuadruplos.h
//  Decoder
//
//  Created by Oscar Villarreal on 11/17/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef llcuadruplos_h
#define llcuadruplos_h

#include <iostream>
#include <string>
#include "nodoCuadruplos.h"

using namespace std;

class llcuadruplos{
public:
    int count;
    llcuadruplos();
    void addFirst (string data, string temp);
    void addLast (string data, string temp);
    bool isEmpty();
    void borra();
    void deleteFirst();
    void deleteLast();
    int deleteAll();
    bool search(string nameProc);
    void del(int pos);
    string sus(string tempIN);
private:
    nodoCuadruplos *head;
};

llcuadruplos::llcuadruplos()
{
    head = NULL;
    count = 0;
}
bool llcuadruplos::isEmpty()
{
    return (head == NULL);
}
void llcuadruplos::addFirst( string dat, string temp){
    head = new nodoCuadruplos(dat,temp);
    count++;
}
void llcuadruplos::addLast(string dat, string temp){
    if(this-> isEmpty()){
        this->addFirst(dat, temp);
    }
    else{
        nodoCuadruplos *aux = this -> head;
        while( aux-> getNext() != NULL){
            aux = aux->getNext();
        }
        aux-> setNext(new nodoCuadruplos(dat, temp));
        count++;
    }
}
int llcuadruplos::deleteAll(){
    int cont = count;
    borra();
    count = 0;
    return cont;
}

void llcuadruplos::borra(){
    nodoCuadruplos *aux = head;
    while (aux != NULL){
        head = head->getNext();
        delete aux;
        aux = head;
    }
}

void llcuadruplos::del(int pos)
{
    if (pos == 0)
    {
        return this -> deleteFirst();
    }
    if (pos == count -1)
    {
        return this -> deleteLast();
    }
    nodoCuadruplos *aux = head;
    for (int i=1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    nodoCuadruplos *aux2 = aux->getNext();
    string dataAux = aux2 -> getData();
    aux -> setNext(aux2->getNext());
    delete aux2;
    count--;
}

void llcuadruplos::deleteFirst()
{
    string dataAux = head -> getData();
    nodoCuadruplos *aux = head;
    head = head->getNext();
    delete aux;
    count --;
}

void llcuadruplos::deleteLast()
{
    if (count <= 1)
    {
        return this->deleteFirst();
    }
    nodoCuadruplos *aux = head;
    while (aux -> getNext() -> getNext() != NULL) //checa que el siguente siguente sea NULL(o sea el fin)
    {
        aux = aux -> getNext();
    }
    nodoCuadruplos *aux2 = aux ->getNext();
    string dataAux = aux2 -> getData();
    aux -> setNext(NULL);
    delete aux2;
    count--;
}


bool llcuadruplos::search(string nameProc)
{
    int i;
    nodoCuadruplos *aux = head;
    for (i = 0; i<count; i++)
    {
        string tempN = aux->getName();
        if(nameProc == tempN)
        {
            return true;
        }
        aux = aux -> getNext();
    }
    return false;
}

string llcuadruplos::sus(string tempIN)
{
    string t;int i;
    nodoCuadruplos *aux = head;
    for (i = 0; i<count; i++)
    {
        string tempN = aux->getName();
        if(tempIN == tempN)
        {
            t = aux -> getData();
            t = "(" + t+ ")";
            del(i);
        }
        aux = aux -> getNext();
    }
    return t;
}

#endif /* llcuadruplos_h */
