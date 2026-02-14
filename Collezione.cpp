//
// Created by Gaia Baldanzi on 14/02/26.
//

#include "Collezione.h"

#include <iostream>
#include <list>
using namespace std;

Collezione::Collezione (const string &no): Nome(no){};
Collezione::~Collezione(){};

void Collezione::aggiungiNota(Note *n) {
    if (n->isBloccata()) { cout<<"Impossibile aggiungere la nota "<<n->getTitolo()<<", è bloccata"<<endl; }
    else {
        NoteCollezionate.push_back(n);
        int i=NoteCollezionate.size();
        notify(true, n->getTitolo(), Nome, i);
    }
}

void Collezione::rimuoviNota(Note *n) {
    if (n->isBloccata()) { cout<<"Impossibile rimuovere la nota "<<n->getTitolo()<<", è bloccata"<<endl; }
    else {
        NoteCollezionate.remove(n);
        int i=NoteCollezionate.size();
        notify(false, n->getTitolo(), Nome, i);
    }
}

void Collezione::notify(bool b, const string &n, const string &c, int i){
    for (Observer *o : Obs) {
        o->update(b, n, c, i);
    }
}

void Collezione::attach(Observer *o){Obs.push_back(o);}
void Collezione::detach(Observer *o){Obs.remove(o);}
