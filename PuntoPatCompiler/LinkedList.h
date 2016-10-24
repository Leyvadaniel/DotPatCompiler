//
//  LinkedList.h
//  LinkedList
//
//  Created by Oscar Villarreal on 2/3/15.
//  Copyright (c) 2015 Oscar Villarreal. All rights reserved.
//

#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h

#include <iostream>
#include "nodo.h"
#include "VarT.h"

using namespace std;

//template <class VarT>
class LinkedList
{
public:
    int count;
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(VarT data);
    void addLast(VarT data);
    bool add(VarT data, int pos);
    VarT deleteFirst();
    VarT deleteLast();
    VarT del(int pos);
    VarT get(int pos);
    VarT set(VarT data, int pos);
    int deleteAll();
    void print();
    
private:
    nodo *head;
    void borra();
};

////template <typename VarT>
void LinkedList::borra()
{
    nodo *aux = head;
    while (aux != NULL)
    {
        head = head->getNext();
        delete aux;
        aux = head;
    }
}

////template <typename VarT>
LinkedList::~LinkedList()
{
    borra();
}

////template <typename VarT>
LinkedList::LinkedList()
{
    head = NULL;
    count = 0;
}

//template <typenme VarT>
bool LinkedList::isEmpty()
{
    return (head == NULL);
}

////template <typename VarT>
void LinkedList::addFirst(VarT data)
{
    head = new nodo(data, head);
    count++;
}

////template <typename VarT>
void LinkedList::addLast(VarT data)
{
    if (this->isEmpty())
        this->addFirst(data);
    else
    {
        nodo *aux = this->head;
        while (aux->getNext() != NULL)
        {
            aux=aux->getNext();
        }
        aux->setNext(new nodo(data));
        count++;
    }
}

////template <typename VarT>
bool LinkedList::add(VarT data, int pos)
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
        nodo *aux = head; //
        for (int i = 1; i<pos; i++)//se consigue el aux del nodo que va antes que el que vamos a crear
        {
            aux = aux -> getNext();
        }
        aux -> setNext(new nodo(data, aux->getNext() )); //se modifica el NEXT del nodo anterior
        count++;
    }
    return true;
}

////template<typename VarT>
VarT LinkedList::deleteFirst()
{
    /*if (this -> isEmpty())
    {
        return NULL;
    }*/
    VarT dataAux = head -> getData();
    nodo *aux = head;
    head = head->getNext();
    delete aux;
    count --;
    return dataAux;
}

////template<typename VarT>
VarT LinkedList::deleteLast()
{
    if (count <= 1)
    {
        return this->deleteFirst();
    }
    nodo *aux;
    while (aux -> getNext() -> getNext() != NULL) //checa que el siguente siguente sea NULL(o sea el fin)
    {
        aux = aux -> getNext();
    }
    nodo *aux2 = aux ->getNext();
    VarT dataAux = aux2 -> getData();
    aux -> setNext(NULL);
    delete aux2;
    count--;
    return dataAux;
}

////template<typename VarT>
VarT LinkedList::del(int pos)
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
    nodo *aux = head;
    for (int i=1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    nodo *aux2 = aux->getNext();
    VarT dataAux = aux2 -> getData();
    aux -> setNext(aux2->getNext());
    delete aux2;
    count--;
    return dataAux;
}

////template<typename VarT>
int LinkedList::deleteAll()
{
    int cont = count;
    borra();
    count = 0;
    return cont;
}

VarT LinkedList::get(int pos)
{
    /*if (pos < 0 ||  pos >= count)
    {
        return NULL;
    }*/
    nodo *aux = head;
    for (int i = 1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    VarT dataTemp = aux -> getData();
    return dataTemp;
}

VarT LinkedList::set(VarT data,int pos)
{
    nodo *aux = head;
    for (int i = 1; i<pos; i++)
    {
        aux = aux -> getNext();
    }
    aux -> setData(data);
    VarT dataTemp = aux -> getData();
    return dataTemp;
}

void LinkedList::print()
{
    nodo *aux = head;
    int c;
    for (int i = 0; i<count; i++)
    {
        cout << "   Nombre: "<<aux->getData().getName()<<endl;
	cout << "   Tipo: "<<aux->getData().getClase()<<endl;
	cout <<endl;
	aux = aux -> getNext();
    }
}


#endif
