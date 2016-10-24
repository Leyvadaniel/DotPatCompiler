//
//  nodo.h
//  LinkedList
//
//  Created by Oscar Villarreal on 2/3/15.
//  Copyright (c) 2015 Oscar Villarreal. All rights reserved.
//

#ifndef LinkedList_nodo_h
#define LinkedList_nodo_h

#include <iostream>
#include "VarT.h"

using namespace std;

//template <class VarT>
class nodo
{
public:
    nodo(VarT data);
    nodo(VarT data, nodo *next);
    VarT getData();
    nodo* getNext();
    void setData(VarT data);
    void setNext(nodo *next);
    
private:
    VarT data;
    nodo *next; //apuntado a nodo
};

nodo::nodo(VarT data)
{
    this->data = data;
    this->next = NULL;
}

////template <typename VarT>
nodo::nodo(VarT data, nodo *next)
{
    this->data = data;
    this->next = next;
}

////template <typename VarT>
VarT nodo::getData()
{
    return this->data;
}

////template <typename VarT>
nodo* nodo::getNext()
{
    return this->next;
}

////template <typename VarT>
void nodo::setData(VarT data)
{
    this->data = data;
}

////template <typename VarT>
void nodo::setNext(nodo *next)
{
    this->next = next;
}



#endif
