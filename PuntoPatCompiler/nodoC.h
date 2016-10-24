//
//  nodoC.h
//  proyecto lenguajes
//
//  Created by Oscar Villarreal on 11/12/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef nodoC_h
#define nodoC_h

#include <iostream>

using namespace std;

class nodoC
{
public:
    nodoC(string data);
    //nodoC(string OP, string OP1, string OP2,string RES);
    nodoC(string data, nodoC *next);
    string getData();
    nodoC* getNext();
    void setData(string data);
    void setNext(nodoC *next);
    
private:
    string data;
    nodoC *next; //apuntado a nodoC
};

nodoC::nodoC(string data)
{
    this->data = data;
    this->next = NULL;
}

/*
nodoC::nodoC(string OP, string OP1, string OP2,string RES)
{
    this -> data = OP+" "+OP1+" "+OP2+" "+RES+",";
    this->next = NULL;
}*/


nodoC::nodoC(string data, nodoC *next)
{
    this->data = data;
    this->next = next;
}

string nodoC::getData()
{
    return this->data;
}

nodoC* nodoC::getNext()
{
    return this->next;
}

void nodoC::setData(string data)
{
    this->data = data;
}

////template <typename string>
void nodoC::setNext(nodoC *next)
{
    this->next = next;
}


#endif /* nodoCC_h */
