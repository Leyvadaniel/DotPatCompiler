//
//  nodoCuadruplos.h
//  Decoder
//
//  Created by Oscar Villarreal on 11/17/15.
//  Copyright © 2015 Oscar Villarreal. All rights reserved.
//

#ifndef nodoCuadruplos_h
#define nodoCuadruplos_h

#include <iostream>
#include <string.h>

using namespace std;

class nodoCuadruplos{
public:
    nodoCuadruplos(string dat, string temp);
    string getData();
    string getName();
    nodoCuadruplos * getNext();
    void setData(string dat);
    void setNext(nodoCuadruplos *nex);
private:
    string temporal;
    string data;
    nodoCuadruplos *next;
};

nodoCuadruplos::nodoCuadruplos(string dat, string temp){
    this -> data = dat;
    this -> temporal = temp;
    this -> next = NULL;
}
string nodoCuadruplos::getData(){
    return data;
}

string nodoCuadruplos::getName(){
    return temporal;
}

nodoCuadruplos* nodoCuadruplos::getNext(){
    return this->next;
}
void nodoCuadruplos::setData(string dat){
    this -> data = dat;
}
void nodoCuadruplos::setNext(nodoCuadruplos *nex){
    this-> next = nex;
}
#endif /* nodoCuadruplos_h */
