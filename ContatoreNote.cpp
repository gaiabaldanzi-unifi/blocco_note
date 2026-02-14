//
// Created by Gaia Baldanzi on 14/02/26.
//

#include "ContatoreNote.h"
#include <iostream>
using namespace std;

ContatoreNote::ContatoreNote(){}
ContatoreNote::~ContatoreNote(){}
void ContatoreNote::update(bool b, const string &n, const string &c, int i){
    if (b) {
        cout<<"Nella collezione "<<c<<" è stata aggiunta la nota "<<n<<". Ora ci sono "<<i<<" note."<<endl;
    }
    else {
        cout<<"Nella collezione "<<c<<" è stata rimossa la nota "<<n<<". Ora ci sono "<<i<<" note."<<endl;
    }
};