//
//  nodoV.h
//  proyecto lenguajes
//
//  Created by Oscar Villarreal on 11/3/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef nodoV_h
#define nodoV_h

#include <iostream>
#include "DirProcs.h"

using namespace std;

//template <class DirProc>
class nodoV
{
public:
    nodoV(DirProc data);
    nodoV(DirProc data, nodoV *next);
    DirProc getData();
    nodoV* getNext();
    void setData(DirProc data);
    void setNext(nodoV *next);
    
private:
    DirProc data;
    nodoV *next; //apuntado a nodoV
};

nodoV::nodoV(DirProc data)
{
    this->data = data;
    this->next = NULL;
}

////template <typename DirProc>
nodoV::nodoV(DirProc data, nodoV *next)
{
    this->data = data;
    this->next = next;
}

////template <typename DirProc>
DirProc nodoV::getData()
{
    return this->data;
}

////template <typename DirProc>
nodoV* nodoV::getNext()
{
    return this->next;
}

////template <typename DirProc>
void nodoV::setData(DirProc data)
{
    this->data = data;
}

////template <typename DirProc>
void nodoV::setNext(nodoV *next)
{
    this->next = next;
}


#endif /* nodoVV_h */
