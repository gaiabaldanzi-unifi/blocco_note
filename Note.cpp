//
// Created by Gaia Baldanzi on 14/02/26.
//

#include "Note.h"
#define

Note::Note (const string &ti, const string &te, bool im): Titolo(ti), Testo(te), Bloccata(false), Importante(im) {};
Note::~Note(){};

void Note:: bloccata(bool a) {
    if (Bloccata == a) {cout<<"La nota è già ad "<<a<<endl;}
    else Bloccata = a;
}
void Note:: setTesto(const string &te) {
    if (!Bloccata) Testo = te;
    else cout<<"Impossibile modificare il testo, la nota è bloccata"<<endl;
}

void Note:: setTitolo(const string &ti) {
    if (!Bloccata) Titolo = ti;
    else cout<<"Impossibile modificare il titolo, la nota è bloccata"<<endl;
}

